#include <iostream>
#include <memory>

enum class RequestType { TYPE_A, TYPE_B };

class Request {
private:
    RequestType type;
public:
    explicit Request(RequestType type) : type(type) {}
    RequestType getType() const { return type; }
};

class Handler {
protected:
    std::shared_ptr<Handler> nextHandler;
public:
    virtual void handleRequest(const Request& request) = 0;
    void setNextHandler(std::shared_ptr<Handler> next) {
        nextHandler = next;
    }
    virtual ~Handler() = default;
};

class ConcreteHandlerA : public Handler {
public:
    void handleRequest(const Request& request) override {
        if (request.getType() == RequestType::TYPE_A) {
            std::cout << "ConcreteHandlerA handled the request.\n";
        } else if (nextHandler) {
            nextHandler->handleRequest(request);
        }
    }
};

class ConcreteHandlerB : public Handler {
public:
    void handleRequest(const Request& request) override {
        if (request.getType() == RequestType::TYPE_B) {
            std::cout << "ConcreteHandlerB handled the request.\n";
        } else if (nextHandler) {
            nextHandler->handleRequest(request);
        }
    }
};

int main() {
    auto handlerA = std::make_shared<ConcreteHandlerA>();
    auto handlerB = std::make_shared<ConcreteHandlerB>();

    handlerA->setNextHandler(handlerB);

    Request requestA(RequestType::TYPE_A);
    Request requestB(RequestType::TYPE_B);

    handlerA->handleRequest(requestA); 
    handlerA->handleRequest(requestB); 

    return 0;
}
