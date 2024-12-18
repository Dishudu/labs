#include <iostream>
#include <memory>

class Subject {
public:
    virtual void request() const = 0;
    virtual ~Subject() = default;
};

class RealSubject : public Subject {
public:
    void request() const override {
        std::cout << "RealSubject: Handling request.\n";
    }
};

class Proxy : public Subject {
private:
    std::unique_ptr<RealSubject> realSubject;

public:
    void request() const override {
        if (!realSubject) {
            std::cout << "Proxy: Initializing RealSubject.\n";
            realSubject = std::make_unique<RealSubject>();
        }
        std::cout << "Proxy: Delegating request to RealSubject.\n";
        realSubject->request();
    }
};

int main() {
    Proxy proxy;
    proxy.request(); 
    proxy.request(); 
    return 0;
}
