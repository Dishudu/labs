#include <iostream>
#include <memory>
#include <string>

class Sofa {
public:
    virtual void sitOn() const = 0;
};

class Table {
public:
    virtual void use() const = 0;
};


class ModernSofa : public Sofa {
public:
    void sitOn() const override {
        std::cout << "Sitting on a modern sofa." << std::endl;
    }
};

class ModernTable : public Table {
public:
    void use() const override {
        std::cout << "Using a modern table." << std::endl;
    }
};


class ClassicSofa : public Sofa {
public:
    void sitOn() const override {
        std::cout << "Sitting on a classic sofa." << std::endl;
    }
};

class ClassicTable : public Table {
public:
    void use() const override {
        std::cout << "Using a classic table." << std::endl;
    }
};


class FurnitureFactory {
public:
    virtual std::unique_ptr<Sofa> createSofa() const = 0;
    virtual std::unique_ptr<Table> createTable() const = 0;
};

class ModernFurnitureFactory : public FurnitureFactory {
public:
    std::unique_ptr<Sofa> createSofa() const override {
        return std::make_unique<ModernSofa>();
    }

    std::unique_ptr<Table> createTable() const override {
        return std::make_unique<ModernTable>();
    }
};

class ClassicFurnitureFactory : public FurnitureFactory {
public:
    std::unique_ptr<Sofa> createSofa() const override {
        return std::make_unique<ClassicSofa>();
    }

    std::unique_ptr<Table> createTable() const override {
        return std::make_unique<ClassicTable>();
    }
};

int main() {
    std::unique_ptr<FurnitureFactory> factory = std::make_unique<ModernFurnitureFactory>();
    auto sofa = factory->createSofa();
    auto table = factory->createTable();
    sofa->sitOn();
    table->use();

    factory = std::make_unique<ClassicFurnitureFactory>();
    sofa = factory->createSofa();
    table = factory->createTable();
    sofa->sitOn();
    table->use();

    return 0;
}
