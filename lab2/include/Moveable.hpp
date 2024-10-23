#ifndef MOVEABLE_HPP
#define MOVEABLE_HPP

class Moveable {
    public:
        virtual void move(int newX, int newY) = 0;
        virtual ~Moveable() = default;
};

#endif