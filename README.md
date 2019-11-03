# Particles
Simulates particles of different randomly generated types.

Each type has a mass and a colour. Each pair of types have an associated randomly generated interaction.

The interaction is a force with magnitude: 4 * s * ( d^2 / x^2 - d / x)

The value of d determines the distance at which the particles are at an equilibrium, while s determines the maximum possible attraction.

The particles evolve through time by interacting with each other and experiencing drag.

This results in different clusters of particle lattices forming.

This project uses the GLFW library and OpenGL.
