import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# Read C++ solver output
data = pd.read_csv("results.csv")

# Convert CSV columns into 2D arrays
x = np.sort(data["x"].unique())
y = np.sort(data["y"].unique())

X, Y = np.meshgrid(x, y)

U = data.pivot(index="y", columns="x", values="u").values
V = data.pivot(index="y", columns="x", values="v").values

P = data.pivot(
    index="y",
    columns="x",
    values="pressure"
).values

Velocity = np.sqrt(U**2 + V**2)

# Plot 1: Velocity magnitude
plt.figure(figsize=(7, 5))

contour = plt.contourf(
    X, Y, Velocity,
    levels=20
)

plt.colorbar(contour, label="Velocity magnitude (m/s)")

plt.title("Lid-Driven Cavity - Velocity Magnitude")
plt.xlabel("x (m)")
plt.ylabel("y (m)")
plt.axis("equal")
plt.tight_layout()
plt.savefig("velocity_magnitude.png", dpi=300)
plt.show()

# Plot 2: Velocity vectors
plt.figure(figsize=(7, 5))

plt.quiver(X, Y, U, V)

plt.title("Lid-Driven Cavity - Velocity Vectors")
plt.xlabel("x (m)")
plt.ylabel("y (m)")
plt.axis("equal")
plt.tight_layout()
plt.savefig("velocity_vectors.png", dpi=300)
plt.show()

# Plot 3: Pressure contours
plt.figure(figsize=(7, 5))

contour = plt.contourf(
    X, Y, P,
    levels=20
)

plt.colorbar(contour, label="Pressure (Pa)")

plt.title("Lid-Driven Cavity - Pressure Contours")
plt.xlabel("x (m)")
plt.ylabel("y (m)")
plt.axis("equal")
plt.tight_layout()
plt.savefig("pressure_contours.png", dpi=300)
plt.show()

print("Visualization completed!")
print("Maximum velocity:", np.max(Velocity), "m/s")
print("Minimum velocity:", np.min(Velocity), "m/s")
print("Maximum pressure:", np.max(P), "Pa")
print("Minimum pressure:", np.min(P), "Pa")