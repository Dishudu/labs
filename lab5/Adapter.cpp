#include <iostream>

class Target {
public:
    virtual void request() const {
        std::cout << "Target: Default behavior.\n";
    }
    virtual ~Target() = default;
};

class Adaptee {
public:
    void specificRequest() const {
        std::cout << "Adaptee: Specific behavior.\n";
    }
};

class Adapter : public Target {
private:
    Adaptee adaptee;

public:
    void request() const override {
        std::cout << "Adapter: Translating request.\n";
        adaptee.specificRequest();
    }
};

int main() {
    Target* target = new Adapter();
    target->request();
    delete target;
    return 0;
}
