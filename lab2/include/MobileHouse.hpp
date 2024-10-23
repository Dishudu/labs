#ifndef MOBILEHOUSE_HPP
#define MOBILEHOUSE_HPP

#include "Building.hpp"
#include "Moveable.hpp"

class MobileHouse: public Building, public Moveable{
    public:
        MobileHouse(int id, const std::string& name, int x, int y, bool built);
        void move(int newX, int newY) override;
};

#endif
