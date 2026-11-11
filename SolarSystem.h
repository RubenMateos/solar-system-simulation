#pragma once
#include <vector>
#include "Planet.h"
#include <fstream>

class SolarSystem {

    private:
        std::vector<Planet> planets; //Container of every planet

    public:

    //Control functions
    void addPlanet(const Planet& p);
    void simulateStep(double dt);
    void saveState(std::ofstream& out) const;
}; 
