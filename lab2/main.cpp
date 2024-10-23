#include <iostream>
#include "Archer.hpp"
#include "Fort.hpp"
#include "MobileHouse.hpp"

int main() {
    Archer archer(1, std::string("Elven Archer"), 10, 20, 100);
    Fort fort(2, std::string("Castle Fort"), 30, 40, true);
    MobileHouse house(3, std::string("Wagon House"), 15, 25, true);

    // Демонстрация перемещения
    house.move(20, 30);
    std::cout << "House moved to: (" << house.getX() << ", " << house.getY() << ")\n";

    // Атака крепости по лучнику
    fort.attack(archer);
    std::cout << "Archer HP after fort attack: " << archer.getHp() << "\n";

    return 0;
}