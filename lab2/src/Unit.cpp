#include "Unit.hpp"

Unit::Unit(int id, const std::string& name, int x, int y, double hp):
    GameObject(id, name, x, y), hp(hp){}

double Unit::getHp() const{
    return hp;
}

void Unit::receiveDamage(double damage){
    hp-=damage;
    if(hp<0)
        hp = 0;
}