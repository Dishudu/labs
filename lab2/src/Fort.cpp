#include "Fort.hpp"
#include "Unit.hpp"

Fort::Fort(int id, std::string& name, int x, int y, bool built):
    Building(id, name, x, y, built){}

void Fort::attack(Unit& target){
    if(isBuilt())
        target.receiveDamage(20);
}
