#include <iostream>
#include <memory>

class Implementor {
public:
    virtual void operationImpl() const = 0;
    virtual ~Implementor() = default;
};

class ConcreteImplementorA : public Implementor {
public:
    void operationImpl() const override {
        std::cout << "ConcreteImplementorA: Operation\n";
    }
};

class ConcreteImplementorB : public Implementor {
public:
    void operationImpl() const override {
        std::cout << "ConcreteImplementorB: Operation\n";
    }
};

class Abstraction {
protected:
    std::shared_ptr<Implementor> implementor;

public:
    explicit Abstraction(std::shared_ptr<Implementor> impl) : implementor(std::move(impl)) {}
    virtual void operation() const {
        implementor->operationImpl();
    }
    virtual ~Abstraction() = default;
};

class RefinedAbstraction : public Abstraction {
public:
    using Abstraction::Abstraction;
    void operation() const override {
        std::cout << "RefinedAbstraction: Extended Operation -> ";
        implementor->operationImpl();
    }
};

int main() {
    auto implA = std::make_shared<ConcreteImplementorA>();
    auto implB = std::make_shared<ConcreteImplementorB>();

    RefinedAbstraction abstractionA(implA);
    RefinedAbstraction abstractionB(implB);

    abstractionA.operation(); 
    abstractionB.operation(); 

    return 0;
}
