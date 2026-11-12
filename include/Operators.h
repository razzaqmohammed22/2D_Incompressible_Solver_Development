
#ifndef OPERATORS_H
#define OPERATORS_H

#include "Field.h"
#include "Grid.h"

class Operators
{
public:

    // Laplacian of horizontal velocity
    static double laplacianU(
        const Field& flow,
        const Grid& grid,
        int i,
        int j)
    {
        double uP = flow.u[flow.index(i, j)];

        double uE = flow.u[flow.index(i + 1, j)];
        double uW = flow.u[flow.index(i - 1, j)];

        double uN = flow.u[flow.index(i, j + 1)];
        double uS = flow.u[flow.index(i, j - 1)];

        double d2udx2 =
            (uE - 2.0 * uP + uW)
            / (grid.dx * grid.dx);

        double d2udy2 =
            (uN - 2.0 * uP + uS)
            / (grid.dy * grid.dy);

        return d2udx2 + d2udy2;
    }

    // Laplacian of vertical velocity
    static double laplacianV(
        const Field& flow,
        const Grid& grid,
        int i,
        int j)
    {
        double vP = flow.v[flow.index(i, j)];

        double vE = flow.v[flow.index(i + 1, j)];
        double vW = flow.v[flow.index(i - 1, j)];

        double vN = flow.v[flow.index(i, j + 1)];
        double vS = flow.v[flow.index(i, j - 1)];

        double d2vdx2 =
            (vE - 2.0 * vP + vW)
            / (grid.dx * grid.dx);

        double d2vdy2 =
            (vN - 2.0 * vP + vS)
            / (grid.dy * grid.dy);

        return d2vdx2 + d2vdy2;
    }

    static double dudx(
        const Field& flow, const Grid& grid, int i, int j)
    {
        return (flow.u[flow.index(i + 1, j)]
              - flow.u[flow.index(i - 1, j)])
              / (2.0 * grid.dx);
    }

    static double dudy(
        const Field& flow, const Grid& grid, int i, int j)
    {
        return (flow.u[flow.index(i, j + 1)]
              - flow.u[flow.index(i, j - 1)])
              / (2.0 * grid.dy);
    }

    static double dvdx(
        const Field& flow, const Grid& grid, int i, int j)
    {
        return (flow.v[flow.index(i + 1, j)]
              - flow.v[flow.index(i - 1, j)])
              / (2.0 * grid.dx);
    }

    static double dvdy(
        const Field& flow, const Grid& grid, int i, int j)
    {
        return (flow.v[flow.index(i, j + 1)]
              - flow.v[flow.index(i, j - 1)])
              / (2.0 * grid.dy);
    }

    static double dpdx(
        const Field& flow, const Grid& grid, int i, int j)
    {
        return (flow.p[flow.index(i + 1, j)]
              - flow.p[flow.index(i - 1, j)])
              / (2.0 * grid.dx);
    }

    static double dpdy(
        const Field& flow, const Grid& grid, int i, int j)
    {
        return (flow.p[flow.index(i, j + 1)]
              - flow.p[flow.index(i, j - 1)])
              / (2.0 * grid.dy);
    }
};

#endif
