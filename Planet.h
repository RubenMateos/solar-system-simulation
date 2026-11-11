#pragma once
#include <string>
#include "Vector3D.h"

struct Planet {
    //Properties
    std::string name;
    double mass;
    Vector3D position;
    Vector3D velocity;

    //Constructor
    Planet(std::string n, double m, Vector3D pos, Vector3D vel);

    void updatePosition(double dt);


};
