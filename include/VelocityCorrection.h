
#ifndef VELOCITYCORRECTION_H
#define VELOCITYCORRECTION_H

#include "Grid.h"
#include "Field.h"

#include <cmath>
#include <algorithm>

class VelocityCorrection {
public:

    double rho;
    double dt;

    VelocityCorrection(double density, double timeStep)
    {
        rho = density;
        dt = timeStep;
    }

    void correct(const Field& star,
                 const Field& pressureCorrection,
                 const Grid& grid,
                 Field& corrected)
    {
        // Start with the intermediate velocity field
        corrected = star;

        for (int j = 1; j <= star.Ny; j++) {

            for (int i = 1; i <= star.Nx; i++) {

                // Pressure correction gradients
                double dpdx =
                    (pressureCorrection.P(i + 1, j)
                    - pressureCorrection.P(i - 1, j))
                    / (2.0 * grid.dx);

                double dpdy =
                    (pressureCorrection.P(i, j + 1)
                    - pressureCorrection.P(i, j - 1))
                    / (2.0 * grid.dy);

                // Correct velocity
                corrected.U(i, j) =
                    star.U(i, j) - (dt / rho) * dpdx;

                corrected.V(i, j) =
                    star.V(i, j) - (dt / rho) * dpdy;
            }
        }
    }

    // Calculate maximum absolute divergence
    double maxDivergence(const Field& flow,
                         const Grid& grid)
    {
        double maximum = 0.0;

        for (int j = 1; j <= flow.Ny; j++) {

            for (int i = 1; i <= flow.Nx; i++) {

                double dudx =
                    (flow.U(i + 1, j) - flow.U(i - 1, j))
                    / (2.0 * grid.dx);

                double dvdy =
                    (flow.V(i, j + 1) - flow.V(i, j - 1))
                    / (2.0 * grid.dy);

                double div = dudx + dvdy;

                maximum = std::max(maximum, std::abs(div));
            }
        }

        return maximum;
    }
};

#endif
