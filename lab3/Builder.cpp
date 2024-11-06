#include <iostream>
#include <string>
#include <memory>

class Burger {
public:
    std::string bun;
    std::string patty;
    std::string toppings;

    void show() const {
        std::cout << "Burger with " << bun << ", " << patty << ", " << toppings << std::endl;
    }
};

// Абстрактный строитель для бургера
class BurgerBuilder {
public:
    virtual void buildBun() = 0;
    virtual void buildPatty() = 0;
    virtual void buildToppings() = 0;
    virtual std::unique_ptr<Burger> getResult() = 0;
};

// Конкретный строитель для классического бургера
class ClassicBurgerBuilder : public BurgerBuilder {
private:
    std::unique_ptr<Burger> burger;

public:
    ClassicBurgerBuilder() { burger = std::make_unique<Burger>(); }

    void buildBun() override { burger->bun = "Sesame bun"; }
    void buildPatty() override { burger->patty = "Beef patty"; }
    void buildToppings() override { burger->toppings = "Lettuce, tomato, cheese"; }

    std::unique_ptr<Burger> getResult() override {
        return std::move(burger);
    }
};

// Директор
class Chef {
public:
    std::unique_ptr<Burger> makeBurger(BurgerBuilder& builder) {
        builder.buildBun();
        builder.buildPatty();
        builder.buildToppings();
        return builder.getResult();
    }
};

int main() {
    ClassicBurgerBuilder builder;
    Chef chef;
    auto burger = chef.makeBurger(builder);
    burger->show();

    return 0;
}
