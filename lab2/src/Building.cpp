#include "Building.hpp"

Building::Building(int id, const std::string& name, int x, int y, bool built):
    GameObject(id, name, x, y), built(built){}

bool Building::isBuilt(){
    return built;
}
