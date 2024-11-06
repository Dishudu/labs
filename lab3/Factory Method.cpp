#include <iostream>
#include <memory>
#include <string>

class Vehicle {
public:
    virtual void drive() const = 0;
};

class Car : public Vehicle {
public:
    void drive() const override {
        std::cout << "Driving a car." << std::endl;
    }
};

class Bicycle : public Vehicle {
public:
    void drive() const override {
        std::cout << "Riding a bicycle." << std::endl;
    }
};

// Фабрика транспортных средств
class VehicleFactory {
public:
    virtual std::unique_ptr<Vehicle> createVehicle() const = 0;
};

class CarFactory : public VehicleFactory {
public:
    std::unique_ptr<Vehicle> createVehicle() const override {
        return std::make_unique<Car>();
    }
};

class BicycleFactory : public VehicleFactory {
public:
    std::unique_ptr<Vehicle> createVehicle() const override {
        return std::make_unique<Bicycle>();
    }
};

int main() {
    std::unique_ptr<VehicleFactory> factory = std::make_unique<CarFactory>();
    auto vehicle = factory->createVehicle();
    vehicle->drive();

    factory = std::make_unique<BicycleFactory>();
    vehicle = factory->createVehicle();
    vehicle->drive();

    return 0;
}
