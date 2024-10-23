#ifndef ATTACKER_HPP
#define ATTACKER_HPP

class Unit;

class Attacker{
    public:
        virtual void attack(Unit& target) = 0;  // Чисто виртуальный метод
        virtual ~Attacker() = default;
    };

#endif