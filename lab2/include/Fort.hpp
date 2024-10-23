#ifndef FORT_HPP
#define FORT_HPP

#include "Building.hpp"
#include "Attacker.hpp"

class Fort: public Building, public Attacker{
    public:
        Fort(int id, std::string&  name, int x, int y, bool built);
        void attack(Unit& target) override;
};

#endif