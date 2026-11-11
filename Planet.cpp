#include "Planet.h"

Planet::Planet(std::string n, double m, Vector3D pos, Vector3D vel){

    name = n;
    mass = m;
    position = pos;
    velocity = vel;

}

void Planet::updatePosition(double dt){

    position.x += velocity.x * dt;
    position.y += velocity.y * dt;
    position.z += velocity.z * dt;
}