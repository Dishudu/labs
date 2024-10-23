#ifndef ARCHER_HPP
#define ARCHER_HPP

#include "Unit.hpp"
#include "Moveable.hpp"
#include "Attacker.hpp"

class Archer: public Unit, public Attacker, public Moveable{
    public:
        Archer(int id, const std::string& name, int x, int y, double hp);
        bool isAlive() const override;
        void attack(Unit& target) override;
        void move(int newX, int newY) override;
};

#endif