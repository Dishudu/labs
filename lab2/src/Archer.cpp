#include "Archer.hpp"
#include "Unit.hpp"

Archer::Archer(int id, const std::string& name, int x, int y, double hp):
    Unit(id, name, x, y, hp){}

bool Archer::isAlive() const{
    return hp>0;
}

void Archer::attack(Unit& target){
    if(isAlive())
        target.receiveDamage(10);
}

void Archer::move(int newX, int newY){
    x = newX;
    y = newY;
}
