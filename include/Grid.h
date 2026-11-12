
#ifndef GRID_H
#define GRID_H

class Grid
{
public:

    // Physical grid dimensions
    int Nx, Ny;

    // Grid dimensions including ghost cells
    int NxTotal, NyTotal;

    // Domain dimensions
    double Lx, Ly;

    // Cell dimensions
    double dx, dy;

    // Cell area
    double cellArea;

    // Constructor
    Grid(int nx, int ny, double lx, double ly)
    {
        Nx = nx;
        Ny = ny;

        // Add one ghost cell on each side
        NxTotal = Nx + 2;
        NyTotal = Ny + 2;

        Lx = lx;
        Ly = ly;

        dx = Lx / Nx;
        dy = Ly / Ny;

        cellArea = dx * dy;
    }

};

#endif
