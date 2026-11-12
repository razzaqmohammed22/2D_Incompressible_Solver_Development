
// #include <iostream>

// int main()
// {
//     std::cout << "=================================\n";
//     std::cout << "      2D CFD SOLVER PROJECT      \n";
//     std::cout << "=================================\n";

//     // Physical properties
//     double density = 1.0;
//     double viscosity = 0.01;

//     // Cavity dimensions
//     double length = 1.0;
//     double height = 1.0;

//     // Lid velocity
//     double lidVelocity = 1.0;

//     // Reynolds number
//     double Re = (density * lidVelocity * length)
//                 / (density * viscosity);

//     std::cout << "Density          : " << density << "\n";
//     std::cout << "Dynamic viscosity: " << density * viscosity << "\n";
//     std::cout << "Cavity length    : " << length << "\n";
//     std::cout << "Cavity height    : " << height << "\n";
//     std::cout << "Lid velocity     : " << lidVelocity << "\n";
//     std::cout << "Reynolds number  : " << Re << "\n";

//     return 0;
// }







// #include <iostream>
// #include "Grid.h"

// int main()
// {
//     std::cout << "===== 2D CFD SOLVER =====\n\n";

//     // Physical domain
//     double Lx = 1.0;
//     double Ly = 1.0;

//     // Number of cells
//     int Nx = 10;
//     int Ny = 10;

//     // Create computational grid
//     Grid grid(Nx, Ny, Lx, Ly);

//     // Display grid information
//     std::cout << "Grid Information\n";

//     std::cout << "Number of cells in X: "
//               << grid.Nx << "\n";

//     std::cout << "Number of cells in Y: "
//               << grid.Ny << "\n";

//     std::cout << "Cell width (dx): "
//               << grid.dx << "\n";

//     std::cout << "Cell height (dy): "
//               << grid.dy << "\n";

//     std::cout << "Cell area: "
//               << grid.cellArea << "\n";

//     return 0;
// }





// #include <iostream>

// #include "Grid.h"
// #include "Field.h"

// int main()
// {
//     std::cout << "===== 2D CFD SOLVER =====\n\n";

//     // Computational domain
//     int Nx = 10;
//     int Ny = 10;

//     double Lx = 1.0;
//     double Ly = 1.0;

//     // Create grid
//     Grid grid(Nx, Ny, Lx, Ly);

//     // Create flow field
//     Field flow(Nx, Ny);

//     // Set some test values
//     flow.U(2, 3) = 1.5;
//     flow.V(2, 3) = 0.5;
//     flow.P(2, 3) = 100.0;

//     // Display grid information
//     std::cout << "Grid: "
//               << grid.Nx << " x " << grid.Ny << "\n";

//     std::cout << "Cell size: "
//               << grid.dx << " x " << grid.dy << "\n\n";

//     // Display flow field values
//     std::cout << "Flow Field at Cell (2,3)\n";

//     std::cout << "Horizontal velocity (u): "
//               << flow.U(2, 3) << "\n";

//     std::cout << "Vertical velocity (v): "
//               << flow.V(2, 3) << "\n";

//     std::cout << "Pressure (p): "
//               << flow.P(2, 3) << "\n";

//     // Display initial values at another cell
//     std::cout << "\nFlow Field at Cell (0,0)\n";

//     std::cout << "u: " << flow.U(0, 0) << "\n";
//     std::cout << "v: " << flow.V(0, 0) << "\n";
//     std::cout << "p: " << flow.P(0, 0) << "\n";

//     return 0;
// }




// #include <iostream>
// #include "Grid.h"
// #include "Field.h"
// #include "BoundaryConditions.h"

// int main()
// {
//     std::cout << "===== 2D CFD SOLVER =====\n\n";

//     // Computational domain
//     int Nx = 10;
//     int Ny = 10;

//     double Lx = 1.0;
//     double Ly = 1.0;

//     // Physical properties
//     double lidVelocity = 1.0;

//     // Create grid
//     Grid grid(Nx, Ny, Lx, Ly);

//     // Create flow field
//     Field flow(Nx, Ny);

//     // Create boundary conditions
//     BoundaryConditions bc(lidVelocity);

//     // Apply boundary conditions
//     bc.apply(flow);

//     std::cout << "Boundary Conditions\n\n";

//     // Top wall
//     std::cout << "Top wall (u, v): "
//               << flow.U(5, Ny - 1) << ", "
//               << flow.V(5, Ny - 1) << "\n";

//     // Bottom wall
//     std::cout << "Bottom wall (u, v): "
//               << flow.U(5, 0) << ", "
//               << flow.V(5, 0) << "\n";

//     // Left wall
//     std::cout << "Left wall (u, v): "
//               << flow.U(0, 5) << ", "
//               << flow.V(0, 5) << "\n";

//     // Right wall
//     std::cout << "Right wall (u, v): "
//               << flow.U(Nx - 1, 5) << ", "
//               << flow.V(Nx - 1, 5) << "\n";

//     return 0;
// }






// #include <iostream>

// #include "Grid.h"
// #include "Field.h"
// #include "BoundaryConditions.h"

// int main()
// {
//     int Nx = 10;
//     int Ny = 10;

//     double Lx = 1.0;
//     double Ly = 1.0;

//     double lidVelocity = 1.0;

//     // Create grid
//     Grid grid(Nx, Ny, Lx, Ly);

//     // Create flow field
//     Field flow(Nx, Ny);

//     // Set test values in interior cells
//     flow.U(5, 10) = 0.4;
//     flow.V(5, 10) = 0.2;

//     flow.U(5, 1) = 0.3;
//     flow.V(5, 1) = 0.1;

//     // Apply ghost-cell boundary conditions
//     BoundaryConditions bc(lidVelocity);
//     bc.apply(flow);

//     std::cout << "===== GHOST CELL TEST =====\n\n";

//     std::cout << "Physical grid: "
//               << grid.Nx << " x " << grid.Ny << "\n";

//     std::cout << "Total grid: "
//               << grid.NxTotal << " x "
//               << grid.NyTotal << "\n\n";

//     std::cout << "Top wall ghost velocity:\n";

//     std::cout << "u ghost = "
//               << flow.U(5, Ny + 1) << "\n";

//     std::cout << "v ghost = "
//               << flow.V(5, Ny + 1) << "\n\n";

//     std::cout << "Bottom wall ghost velocity:\n";

//     std::cout << "u ghost = "
//               << flow.U(5, 0) << "\n";

//     std::cout << "v ghost = "
//               << flow.V(5, 0) << "\n";

//     return 0;
// }






// #include <iostream>
// #include <iomanip>

// #include "Grid.h"
// #include "Field.h"
// #include "Operators.h"

// int main()
// {
//     // Grid dimensions
//     int Nx = 10;
//     int Ny = 10;

//     double Lx = 1.0;
//     double Ly = 1.0;

//     // Create grid and field
//     Grid grid(Nx, Ny, Lx, Ly);
//     Field flow(Nx, Ny);

//     // Initialize manufactured velocity field:
//     // u(x,y) = x^2 + y^2

//     for (int j = 0; j < flow.NyTotal; j++)
//     {
//         for (int i = 0; i < flow.NxTotal; i++)
//         {
//             // Cell-center coordinates,
//             // including extrapolated ghost-cell centers
//             double x = (i - 0.5) * grid.dx;
//             double y = (j - 0.5) * grid.dy;

//             flow.U(i, j) = x * x + y * y;
//         }
//     }

//     // Select an interior cell
//     int i = 5;
//     int j = 5;

//     // Calculate numerical Laplacian
//     double numericalLaplacian =
//         Operators::laplacianU(flow, grid, i, j);

//     // Analytical result
//     double analyticalLaplacian = 4.0;

//     std::cout << std::fixed << std::setprecision(6);

//     std::cout << "===== LAPLACIAN TEST =====\n\n";

//     std::cout << "Test function: u = x^2 + y^2\n";

//     std::cout << "Cell location: ("
//               << i << ", " << j << ")\n\n";

//     std::cout << "Numerical Laplacian: "
//               << numericalLaplacian << "\n";

//     std::cout << "Analytical Laplacian: "
//               << analyticalLaplacian << "\n";

//     std::cout << "Absolute error: "
//               << std::abs(
//                   numericalLaplacian -
//                   analyticalLaplacian
//               ) << "\n";

//     return 0;
// }





// #include <iostream>
// #include <iomanip>

// #include "Grid.h"
// #include "Field.h"
// #include "BoundaryConditions.h"
// #include "MomentumSolver.h"

// int main()
// {
//     // Grid configuration
//     int Nx = 10;
//     int Ny = 10;

//     double Lx = 1.0;
//     double Ly = 1.0;

//     // Physical properties
//     double rho = 1.0;
//     double nu = 0.01;
//     double lidVelocity = 1.0;

//     // Time step
//     double dt = 0.0001;

//     // Create grid
//     Grid grid(Nx, Ny, Lx, Ly);

//     // Create flow fields
//     Field flow(Nx, Ny);
//     Field star(Nx, Ny);

//     // Create boundary conditions
//     BoundaryConditions bc(lidVelocity);

//     // Apply boundary conditions to old field
//     bc.apply(flow);

//     // Create momentum solver
//     MomentumSolver momentum(rho, nu, dt);

//     // Calculate intermediate velocities
//     momentum.predict(flow, grid, star);

//     // Apply boundary conditions to predicted field
//     bc.apply(star);

//     std::cout << std::fixed
//               << std::setprecision(6);

//     std::cout << "===== MOMENTUM PREDICTOR TEST =====\n\n";

//     std::cout << "Grid: "
//               << Nx << " x " << Ny << "\n";

//     std::cout << "Reynolds number: "
//               << lidVelocity * Lx / nu << "\n";

//     std::cout << "Time step: "
//               << dt << "\n\n";

//     std::cout << "Intermediate velocity at cell (5,10)\n";

//     std::cout << "u* = "
//               << star.U(5, Ny) << "\n";

//     std::cout << "v* = "
//               << star.V(5, Ny) << "\n";

//     std::cout << "\nInterior velocity at cell (5,5)\n";

//     std::cout << "u* = "
//               << star.U(5, 5) << "\n";

//     std::cout << "v* = "
//               << star.V(5, 5) << "\n";

//     return 0;
// }






// #include <iostream>
// #include <iomanip>

// #include "Grid.h"
// #include "Field.h"
// #include "BoundaryConditions.h"
// #include "MomentumSolver.h"
// #include "PressureSolver.h"

// int main()
// {
//     // Physical parameters
//     int Nx = 10;
//     int Ny = 10;

//     double Lx = 1.0;
//     double Ly = 1.0;

//     double rho = 1.0;
//     double nu = 0.01;

//     double lidVelocity = 1.0;
//     double dt = 0.0001;

//     // Numerical parameters
//     double tolerance = 1e-8;
//     int maxIterations = 10000;

//     // Create grid and fields
//     Grid grid(Nx, Ny, Lx, Ly);

//     Field flow(Nx, Ny);
//     Field star(Nx, Ny);
//     Field pressureCorrection(Nx, Ny);

//     BoundaryConditions bc(lidVelocity);

//     // Apply velocity boundary conditions
//     bc.apply(flow);

//     // Momentum predictor
//     MomentumSolver momentum(rho, nu, dt);

//     momentum.predict(flow, grid, star);

//     bc.apply(star);

//     // Pressure Poisson solver
//     PressureSolver pressure(
//         rho,
//         dt,
//         tolerance,
//         maxIterations
//     );

//     int iterations = pressure.solve(
//         star,
//         grid,
//         pressureCorrection
//     );

//     // Display results
//     std::cout << std::fixed << std::setprecision(10);

//     std::cout << "===== PRESSURE POISSON SOLVER TEST =====\n\n";

//     std::cout << "Grid: "
//               << Nx << " x " << Ny << "\n";

//     std::cout << "Reynolds number: "
//               << lidVelocity * Lx / nu << "\n";

//     std::cout << "Time step: "
//               << dt << "\n\n";

//     std::cout << "Pressure solver iterations: "
//               << iterations << "\n";

//     std::cout << "Final maximum update: "
//               << pressure.finalMaxUpdate << "\n\n";

//     std::cout << "Pressure correction at cell (5,5): "
//               << pressureCorrection.P(5,5) << "\n";

//     std::cout << "Pressure correction at cell (5,10): "
//               << pressureCorrection.P(5,10) << "\n";

//     return 0;
// }







// #include <iostream>
// #include <iomanip>

// #include "Grid.h"
// #include "Field.h"
// #include "BoundaryConditions.h"
// #include "MomentumSolver.h"
// #include "PressureSolver.h"
// #include "VelocityCorrection.h"

// int main()
// {
//     // Physical parameters
//     int Nx = 10;
//     int Ny = 10;

//     double Lx = 1.0;
//     double Ly = 1.0;

//     double rho = 1.0;
//     double nu = 0.01;

//     double lidVelocity = 1.0;
//     double dt = 0.0001;

//     // Numerical parameters
//     double tolerance = 1e-8;
//     int maxIterations = 10000;

//     // Create grid and fields
//     Grid grid(Nx, Ny, Lx, Ly);

//     Field flow(Nx, Ny);
//     Field star(Nx, Ny);
//     Field pressureCorrection(Nx, Ny);
//     Field corrected(Nx, Ny);

//     BoundaryConditions bc(lidVelocity);

//     // Apply initial boundary conditions
//     bc.apply(flow);

//     // STEP 1: Momentum prediction
//     MomentumSolver momentum(rho, nu, dt);

//     momentum.predict(flow, grid, star);

//     bc.apply(star);

//     // STEP 2: Pressure Poisson equation
//     PressureSolver pressure(
//         rho,
//         dt,
//         tolerance,
//         maxIterations
//     );

//     int iterations = pressure.solve(
//         star,
//         grid,
//         pressureCorrection
//     );

//     // STEP 3: Velocity correction
//     VelocityCorrection velocityCorrection(rho, dt);

//     double divergenceBefore =
//         velocityCorrection.maxDivergence(star, grid);

//     velocityCorrection.correct(
//         star,
//         pressureCorrection,
//         grid,
//         corrected
//     );

//     // Reapply velocity ghost-cell boundary conditions
//     bc.apply(corrected);

//     double divergenceAfter =
//         velocityCorrection.maxDivergence(corrected, grid);

//     // Display results
//     std::cout << std::fixed << std::setprecision(10);

//     std::cout << "===== VELOCITY CORRECTION TEST =====\n\n";

//     std::cout << "Grid: "
//               << Nx << " x " << Ny << "\n";

//     std::cout << "Reynolds number: "
//               << lidVelocity * Lx / nu << "\n";

//     std::cout << "Time step: "
//               << dt << "\n\n";

//     std::cout << "Pressure iterations: "
//               << iterations << "\n";

//     std::cout << "Final pressure update: "
//               << pressure.finalMaxUpdate << "\n\n";

//     std::cout << "Maximum divergence before correction: "
//               << divergenceBefore << "\n";

//     std::cout << "Maximum divergence after correction: "
//               << divergenceAfter << "\n\n";

//     std::cout << "Corrected velocity at cell (5,5)\n";

//     std::cout << "u = "
//               << corrected.U(5,5) << "\n";

//     std::cout << "v = "
//               << corrected.V(5,5) << "\n";

//     return 0;
// }







#include <cmath>
#include <fstream>
#include <iostream>
#include <iomanip>

#include "Grid.h"
#include "Field.h"
#include "BoundaryConditions.h"
#include "MomentumSolver.h"
#include "PressureSolver.h"
#include "VelocityCorrection.h"

// Apply zero-normal-gradient pressure boundary conditions
void applyPressureBC(Field& flow)
{
    int Nx = flow.Nx;
    int Ny = flow.Ny;

    for (int j = 1; j <= Ny; j++) {
        flow.P(0, j) = flow.P(1, j);
        flow.P(Nx + 1, j) = flow.P(Nx, j);
    }

    for (int i = 1; i <= Nx; i++) {
        flow.P(i, 0) = flow.P(i, 1);
        flow.P(i, Ny + 1) = flow.P(i, Ny);
    }
}

int main()
{
    // Physical parameters
    int Nx = 20;
    int Ny = 20;

    double Lx = 1.0;
    double Ly = 1.0;

    double rho = 1.0;
    double nu = 0.01;

    double lidVelocity = 1.0;
    double dt = 0.001;

    Grid grid(Nx, Ny, Lx, Ly);

    // Simulation parameters
    int numberOfSteps = 1000;

    double tolerance = 1e-6;
    int maxIterations = 5000;

    // Create flow fields
    Field flow(Nx, Ny);
    Field star(Nx, Ny);
    Field pressureCorrection(Nx, Ny);
    Field corrected(Nx, Ny);

    // Create solver objects
    BoundaryConditions bc(lidVelocity);

    MomentumSolver momentum(rho, nu, dt);

    PressureSolver pressure(
        rho,
        dt,
        tolerance,
        maxIterations
    );

    VelocityCorrection velocityCorrection(rho, dt);

    // Initial boundary conditions
    bc.apply(flow);
    applyPressureBC(flow);

    double divergenceBefore = 0.0;
    double divergenceAfter = 0.0;

    int pressureIterations = 0;

    std::cout << std::fixed << std::setprecision(10);

    std::cout << "===== TRANSIENT CFD SIMULATION =====\n\n";

    std::cout << "Grid: "
              << Nx << " x " << Ny << "\n";

    std::cout << "Reynolds number: "
              << lidVelocity * Lx / nu << "\n";

    std::cout << "Time step: "
              << dt << "\n";

    std::cout << "Total time steps: "
              << numberOfSteps << "\n\n";


    // =========================================
    // MAIN SIMULATION LOOP
    // =========================================

    for (int step = 1; step <= numberOfSteps; step++)
    {
        // STEP 1: Apply velocity boundary conditions
        bc.apply(flow);

        // STEP 2: Momentum prediction
        momentum.predict(flow, grid, star);

        bc.apply(star);

        // STEP 3: Solve pressure Poisson equation
        pressureIterations = pressure.solve(
            star,
            grid,
            pressureCorrection
        );

        // STEP 4: Measure divergence before correction
        divergenceBefore =
            velocityCorrection.maxDivergence(star, grid);

        // STEP 5: Correct intermediate velocities
        velocityCorrection.correct(
            star,
            pressureCorrection,
            grid,
            corrected
        );

        // STEP 6: Update physical pressure
        for (int j = 1; j <= Ny; j++) {
            for (int i = 1; i <= Nx; i++) {

                corrected.P(i, j) =
                    flow.P(i, j) + pressureCorrection.P(i, j);
            }
        }

        // Apply boundary conditions
        bc.apply(corrected);
        applyPressureBC(corrected);

        // STEP 7: Measure divergence after correction
        divergenceAfter =
            velocityCorrection.maxDivergence(corrected, grid);

        // STEP 8: Advance to the next time step
        flow = corrected;

        // Display progress
        if (step % 100 == 0 || step == 1) {

            std::cout << "Time step: " << step
                      << " / " << numberOfSteps << "\n";

            std::cout << "Simulation time: "
                      << step * dt << " s\n";

            std::cout << "Pressure iterations: "
                      << pressureIterations << "\n";

            std::cout << "Divergence before: "
                      << divergenceBefore << "\n";

            std::cout << "Divergence after:  "
                      << divergenceAfter << "\n";

            std::cout << "----------------------------------\n";
        }
    }


    // =========================================
    // STEP 9: EXPORT FINAL RESULTS TO CSV
    // =========================================

    std::ofstream outputFile("results.csv");

    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create results.csv\n";
        return 1;
    }

    outputFile << "x,y,u,v,pressure,velocity_magnitude\n";

    for (int j = 1; j <= Ny; j++) {

        for (int i = 1; i <= Nx; i++) {

            // Cell-centre coordinates
            double x = (i - 0.5) * grid.dx;
            double y = (j - 0.5) * grid.dy;

            double u = flow.U(i, j);
            double v = flow.V(i, j);

            double p = flow.P(i, j);

            double velocityMagnitude =
                std::sqrt(u * u + v * v);

            outputFile
                << x << ","
                << y << ","
                << u << ","
                << v << ","
                << p << ","
                << velocityMagnitude << "\n";
        }
    }

    outputFile.close();

    std::cout << "\nResults exported to results.csv\n";


    // =========================================
    // FINAL SIMULATION INFORMATION
    // =========================================

    std::cout << "\n===== SIMULATION COMPLETED =====\n\n";

    std::cout << "Final simulation time: "
              << numberOfSteps * dt << " s\n";

    std::cout << "Final maximum divergence: "
              << divergenceAfter << "\n";

    std::cout << "Final velocity at cell (5,5)\n";

    std::cout << "u = "
              << flow.U(5,5) << "\n";

    std::cout << "v = "
              << flow.V(5,5) << "\n";

    std::cout << "Pressure at cell (5,5) = "
              << flow.P(5,5) << "\n";

    return 0;
}
