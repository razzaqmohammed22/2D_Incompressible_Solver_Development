
#ifndef MOMENTUMSOLVER_H
#define MOMENTUMSOLVER_H

#include "Grid.h"
#include "Field.h"
#include "Operators.h"

class MomentumSolver
{
public:

    double rho;
    double nu;
    double dt;

    MomentumSolver(double density,
                   double viscosity,
                   double timeStep)
    {
        rho = density;
        nu = viscosity;
        dt = timeStep;
    }

    void predict(
        const Field& flow,
        const Grid& grid,
        Field& star)
    {
        // Preserve the current field
        star = flow;

        // Calculate intermediate velocities
        for (int j = 1; j <= flow.Ny; j++)
        {
            for (int i = 1; i <= flow.Nx; i++)
            {
                double u = flow.U(i, j);
                double v = flow.V(i, j);

                // Convection terms
                double convectionU =
                    u * Operators::dudx(flow, grid, i, j)
                  + v * Operators::dudy(flow, grid, i, j);

                double convectionV =
                    u * Operators::dvdx(flow, grid, i, j)
                  + v * Operators::dvdy(flow, grid, i, j);

                // Pressure gradients
                double pressureX =
                    Operators::dpdx(flow, grid, i, j);

                double pressureY =
                    Operators::dpdy(flow, grid, i, j);

                // Viscous diffusion
                double diffusionU =
                    nu * Operators::laplacianU(
                        flow, grid, i, j);

                double diffusionV =
                    nu * Operators::laplacianV(
                        flow, grid, i, j);

                // Horizontal momentum equation
                double rhsU =
                    -convectionU
                    - pressureX / rho
                    + diffusionU;

                // Vertical momentum equation
                double rhsV =
                    -convectionV
                    - pressureY / rho
                    + diffusionV;

                // Update intermediate velocities
                star.U(i, j) = u + dt * rhsU;

                star.V(i, j) = v + dt * rhsV;
            }
        }
    }
};

#endif
