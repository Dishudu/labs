#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <string>

class GameObject{
    public:
        GameObject(int id, const std::string& name, int x, int y);
        int getId() const; //возвращает идентификатор объекта
        std::string getName() const; //возвращает имя объекта
        int getX() const; //где находится объект по X координате
        int getY() const; //где находится объект по Y координате
    protected:
        int id;
        std::string name;
        int x;
        int y;
};

#endif 