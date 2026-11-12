
#ifndef FIELD_H
#define FIELD_H

#include <vector>

class Field
{
public:

    int Nx, Ny;
    int NxTotal, NyTotal;

    std::vector<double> u;
    std::vector<double> v;
    std::vector<double> p;

    Field(int nx, int ny)
    {
        Nx = nx;
        Ny = ny;

        NxTotal = Nx + 2;
        NyTotal = Ny + 2;

        u.resize(NxTotal * NyTotal, 0.0);
        v.resize(NxTotal * NyTotal, 0.0);
        p.resize(NxTotal * NyTotal, 0.0);
    }

    // Convert 2D indices to 1D
    int index(int i, int j) const
    {
        return i + j * NxTotal;
    }

    double& U(int i, int j)
    {
        return u[index(i, j)];
    }

    double& V(int i, int j)
    {
        return v[index(i, j)];
    }

    double& P(int i, int j)
    {
        return p[index(i, j)];
    }



    // Read-only accessors

    double U(int i, int j) const
    {
        return u[index(i, j)];
    }

    double V(int i, int j) const
    {
        return v[index(i, j)];
    }

    double P(int i, int j) const
    {
        return p[index(i, j)];
    }


};

#endif