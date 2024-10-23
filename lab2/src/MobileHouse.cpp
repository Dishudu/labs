#include "MobileHouse.hpp"

MobileHouse::MobileHouse(int id, const std::string& name, int x, int y, bool built)
    : Building(id, name, x, y, built) {}

void MobileHouse::move(int newX, int newY) {
    x = newX;
    y = newY;
}