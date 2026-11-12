
#ifndef PRESSURESOLVER_H
#define PRESSURESOLVER_H

#include <cmath>
#include <algorithm>

#include "Grid.h"
#include "Field.h"

class PressureSolver {
public:

    double rho;
    double dt;
    double tolerance;
    int maxIterations;

    double finalMaxUpdate;

    PressureSolver(double density,
                   double timeStep,
                   double tol,
                   int maxIter)
    {
        rho = density;
        dt = timeStep;
        tolerance = tol;
        maxIterations = maxIter;
        finalMaxUpdate = 0.0;
    }

    // Neumann pressure-correction boundary conditions
    void applyPressureBC(Field& correction)
    {
        int Nx = correction.Nx;
        int Ny = correction.Ny;

        // Left and right boundaries
        for (int j = 1; j <= Ny; j++) {
            correction.P(0, j) = correction.P(1, j);
            correction.P(Nx + 1, j) = correction.P(Nx, j);
        }

        // Bottom and top boundaries
        for (int i = 1; i <= Nx; i++) {
            correction.P(i, 0) = correction.P(i, 1);
            correction.P(i, Ny + 1) = correction.P(i, Ny);
        }
    }

    // Calculate divergence of intermediate velocity
    double divergence(const Field& star,
                      const Grid& grid,
                      int i,
                      int j)
    {
        double dudx =
            (star.U(i + 1, j) - star.U(i - 1, j))
            / (2.0 * grid.dx);

        double dvdy =
            (star.V(i, j + 1) - star.V(i, j - 1))
            / (2.0 * grid.dy);

        return dudx + dvdy;
    }

    // Solve pressure Poisson equation using Gauss-Seidel
    int solve(const Field& star,
              const Grid& grid,
              Field& correction)
    {
        int Nx = star.Nx;
        int Ny = star.Ny;

        // Start with zero pressure correction
        std::fill(correction.p.begin(),
                  correction.p.end(), 0.0);

        double idx2 = 1.0 / (grid.dx * grid.dx);
        double idy2 = 1.0 / (grid.dy * grid.dy);

        double denominator = 2.0 * (idx2 + idy2);

        int iterations = 0;

        for (int iter = 0; iter < maxIterations; iter++) {

            applyPressureBC(correction);

            double maxUpdate = 0.0;

            for (int j = 1; j <= Ny; j++) {

                for (int i = 1; i <= Nx; i++) {

                    // Fix one pressure value as reference
                    if (i == 1 && j == 1) {
                        correction.P(i, j) = 0.0;
                        continue;
                    }

                    double rhs =
                        (rho / dt) *
                        divergence(star, grid, i, j);

                    double pNew =
                        (
                            (correction.P(i + 1, j)
                            + correction.P(i - 1, j)) * idx2

                            +

                            (correction.P(i, j + 1)
                            + correction.P(i, j - 1)) * idy2

                            - rhs
                        ) / denominator;

                    double update =
                        std::abs(pNew - correction.P(i, j));

                    maxUpdate = std::max(maxUpdate, update);

                    correction.P(i, j) = pNew;
                }
            }

            iterations = iter + 1;

            if (maxUpdate < tolerance) {
                finalMaxUpdate = maxUpdate;
                break;
            }

            finalMaxUpdate = maxUpdate;
        }

        applyPressureBC(correction);

        return iterations;
    }
};

#endif
