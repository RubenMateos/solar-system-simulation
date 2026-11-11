#include "SolarSystem.h"
#include "constants.h"
#include <cmath>
#include <iostream>
#include <fstream>

void SolarSystem::addPlanet(const Planet& p){
    planets.push_back(p);

}

void SolarSystem::simulateStep(double dt){
    // Phase 1: Calculate accelerations and update velocities (Future)
    for(size_t i = 0; i < planets.size(); i++){
        for (size_t j = 0; j < planets.size(); j++){

            if(i != j){
                double dx = planets[j].position.x - planets[i].position.x;
                double dy = planets[j].position.y - planets[i].position.y;
                double dz = planets[j].position.z - planets[i].position.z;

                double distanceSquared { dx*dx + dy*dy + dz*dz };
                double distance { sqrt(distanceSquared)};

                // Calculate 3D acceleration using d^3 to combine gravity (1/d^2) and vector normalization (1/d) efficiently.
                double scalar = (Physics::G*planets[j].mass)/(distanceSquared*distance);
                
                double ax = scalar*dx;
                double ay = scalar*dy;
                double az = scalar*dz;

                planets[i].velocity.x += ax*dt;
                planets[i].velocity.y += ay*dt;
                planets[i].velocity.z += az*dt;

            }

        }
    }
    // Phase 2: Update positions using the updated velocities (Euler Semi-implicit)
    for(int i = 0; i < planets.size(); i++){
        planets[i].updatePosition(dt);
    }
}


void SolarSystem::saveState(std::ofstream& out) const {
for(size_t i = 0; i < planets.size(); i++){
        out << planets[i].name << ", " << planets[i].position.x << ", " << planets[i].position.y << ", " << planets[i].position.z << "\n";

    }

}