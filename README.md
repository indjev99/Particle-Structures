# Particles
Simulates particles of different randomly generated types.

Each particle type has a mass, radius and colour.

The radius of a particle follows this equation:

`Pi * radius^2 * density = mass` where `density` is some fixed particle density.

Each pair of particle types has an associated randomly generated interaction.

The interaction is a force along their distance vector with magnitude:

`4 * strength * ( (eqDist / r) - (eqDist / r) ^ 2 )` where `r` is the distance (scalar).

The value `eqDist` determines the distance at which the two particles experience no force, while `strength` determines the maximum possible attraction. Notice that at a distance smaller than `eqDist` the particles repel each other and at a higher one they attract each other.

The particles evolve through time by interacting with each other and experiencing drag. The drag is also a force and follows this equation:

`F = -dragCoeff * 2 * radius * velocity` (it is proportional to the area the particle covers in a unit of time)

Finally, for each particle we get its accelaration by dividing the total force by its mass.

These rules result in various clusters of particle lattices forming.

Two further additions have been introduced:

1. Asymmetric forces. We can toggle asymmetry of the forces which usually leads to particles chasing each other and thus moving the whole cluster of particles.

2. Particle decay. Each particle type has a halflife/mean lifetime, when the particle decays it produces some number of other particles. Conservation of mas, conservation of energy and Galilean relativity are not currently followed (though conservation of momentum is).

This project uses the GLFW library and OpenGL.
