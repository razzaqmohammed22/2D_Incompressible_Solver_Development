
#ifndef BOUNDARYCONDITIONS_H
#define BOUNDARYCONDITIONS_H

#include "Field.h"

class BoundaryConditions
{
public:

    double lidVelocity;

    BoundaryConditions(double velocity)
    {
        lidVelocity = velocity;
    }

    void apply(Field& flow)
    {
        int Nx = flow.Nx;
        int Ny = flow.Ny;

        // Left wall
        for (int j = 1; j <= Ny; j++)
        {
            flow.U(0, j) = -flow.U(1, j);
            flow.V(0, j) = -flow.V(1, j);
        }

        // Right wall
        for (int j = 1; j <= Ny; j++)
        {
            flow.U(Nx + 1, j) = -flow.U(Nx, j);
            flow.V(Nx + 1, j) = -flow.V(Nx, j);
        }

        // Bottom wall
        for (int i = 1; i <= Nx; i++)
        {
            flow.U(i, 0) = -flow.U(i, 1);
            flow.V(i, 0) = -flow.V(i, 1);
        }

        // Moving top wall
        for (int i = 1; i <= Nx; i++)
        {
            flow.U(i, Ny + 1) =
                2.0 * lidVelocity - flow.U(i, Ny);

            flow.V(i, Ny + 1) = -flow.V(i, Ny);
        }
    }
};

#endif
