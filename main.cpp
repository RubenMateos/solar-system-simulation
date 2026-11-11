#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "SolarSystem.h"
#include "Planet.h"
#include "constants.h"
#include "Vector3D.h"
#include <fstream>


int main(){

    //Parameters
    double dt{3600.0};
    size_t totalSteps{24*365*80};

    //File output
    std::ofstream outFile("trajectories.csv");
    outFile << "Planet,X,Y,Z\n";

    SolarSystem system;
    
    //We create our Planets and Sun
    // Sun
    Vector3D sunPos{ 0.0, 0.0, 0.0 };
    Vector3D sunVel{ 0.0, 0.0, 0.0 };
    double sunMass{ 1.989e30 };
    Planet sun{ "Sun", sunMass, sunPos, sunVel };

    // Mercury
    Vector3D mercuryPos{ 0.387 * Physics::AU, 0.0, 0.0 };
    Vector3D mercuryVel{ 0.0, 47400.0, 0.0 };
    double mercuryMass{ 3.301e23 };
    Planet mercury{ "Mercury", mercuryMass, mercuryPos, mercuryVel };

    // Venus
    Vector3D venusPos{ 0.723 * Physics::AU, 0.0, 0.0 };
    Vector3D venusVel{ 0.0, 35020.0, 0.0 };
    double venusMass{ 4.867e24 };
    Planet venus{ "Venus", venusMass, venusPos, venusVel };

    // Earth
    Vector3D earthPos{ Physics::AU, 0.0, 0.0 };
    Vector3D earthVel{ 0.0, 29780.0, 0.0 };
    double earthMass{ 5.972e24 };
    Planet earth{ "Earth", earthMass, earthPos, earthVel };

    // Moon
    Vector3D moonPos{ Physics::AU + 3.844e8, 0.0, 0.0 };
    Vector3D moonVel{ 0.0, 29780.0 + 1022.0, 0.0 };
    double moonMass{ 7.342e22 };
    Planet moon{ "Moon", moonMass, moonPos, moonVel };

    // Mars
    Vector3D marsPos{ 1.524 * Physics::AU, 0.0, 0.0 };
    Vector3D marsVel{ 0.0, 24070.0, 0.0 };
    double marsMass{ 6.417e23 };
    Planet mars{ "Mars", marsMass, marsPos, marsVel };

    // Jupiter
    Vector3D jupiterPos{ 5.204 * Physics::AU, 0.0, 0.0 };
    Vector3D jupiterVel{ 0.0, 13070.0, 0.0 };
    double jupiterMass{ 1.898e27 };
    Planet jupiter{ "Jupiter", jupiterMass, jupiterPos, jupiterVel };

    // Io
    Vector3D ioPos{ (5.204 * Physics::AU) + 4.217e8, 0.0, 0.0 };
    Vector3D ioVel{ 0.0, 13070.0 + 17334.0, 0.0 };
    double ioMass{ 8.931e22 };
    Planet io{ "Io", ioMass, ioPos, ioVel };

    // Saturn
    Vector3D saturnPos{ 9.582 * Physics::AU, 0.0, 0.0 };
    Vector3D saturnVel{ 0.0, 9680.0, 0.0 };
    double saturnMass{ 5.683e26 };
    Planet saturn{ "Saturn", saturnMass, saturnPos, saturnVel };

    // Uranus
    Vector3D uranusPos{ 19.201 * Physics::AU, 0.0, 0.0 };
    Vector3D uranusVel{ 0.0, 6800.0, 0.0 };
    double uranusMass{ 8.681e25 };
    Planet uranus{ "Uranus", uranusMass, uranusPos, uranusVel };

    // Neptune
    Vector3D neptunePos{ 30.047 * Physics::AU, 0.0, 0.0 };
    Vector3D neptuneVel{ 0.0, 5430.0, 0.0 };
    double neptuneMass{ 1.024e26 };
    Planet neptune{ "Neptune", neptuneMass, neptunePos, neptuneVel };
    
    //We add them to the System
    system.addPlanet(sun);
    system.addPlanet(mercury);
    system.addPlanet(venus);
    system.addPlanet(earth);
    system.addPlanet(moon);
    system.addPlanet(mars);
    system.addPlanet(jupiter);
    system.addPlanet(io);
    system.addPlanet(saturn);
    system.addPlanet(uranus);
    system.addPlanet(neptune);

    for(size_t i = 0; i < totalSteps; i++){
        system.simulateStep(dt);
        //Record of the position of every planet each day
        if (i % (24) == 0){
            system.saveState(outFile);

        }
    }


outFile.close();
std::cout << "Simulation finished. Data saved in 'trajectories.csv'.\n";


return 0;

}



