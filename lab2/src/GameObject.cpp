#include "GameObject.hpp"

GameObject::GameObject(int id, const std::string& name, int x, int y):
    id(id), name(name), x(x), y(y){}

int GameObject::getId() const{
    return id;
}

std::string GameObject::getName() const{
    return name;
}

int GameObject::getX() const{
    return x;
}

int GameObject::getY() const{
    return y;
}
