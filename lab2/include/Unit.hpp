#ifndef UNIT_HPP
#define UNIT_HPP

#include "GameObject.hpp"

class Unit: public GameObject{
    public:
        Unit(int id, const std::string &name, int x, int y, double hp);
        virtual bool isAlive() const = 0; //возвращает, жив ли юнит
        double getHp() const; //возвращает количество здоровья у юнита
        virtual void receiveDamage(double damage); //метод, который вызывается для получения урона этим юнитом
    protected:
        double hp;
};

#endif