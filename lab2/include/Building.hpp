#ifndef BUILDING_HPP
#define BUILDING_HPP

#include "GameObject.hpp"

class Building: public GameObject{
    public:
        Building(int id, const std::string& name, int x, int y, bool built);
        bool isBuilt();
    private:
        bool built;
};

#endif