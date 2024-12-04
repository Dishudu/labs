#include <iostream>
#include <memory>
#include <string>

class HeatingSystemConfig {
private:
    static HeatingSystemConfig* instance;
    int temperature;
    std::string mode;

    HeatingSystemConfig() : temperature(22), mode("Eco") {}

public:
    static HeatingSystemConfig* getInstance() {
        if (!instance) {
            instance = new HeatingSystemConfig();
        }
        return instance;
    }

    void setTemperature(int temp) { temperature = temp; }
    int getTemperature() const { return temperature; }

    void setMode(const std::string& new_mode) { mode = new_mode; }
    std::string getMode() const { return mode; }

    void showConfig() const {
        std::cout << "Current Temperature: " << temperature << "°C, Mode: " << mode << std::endl;
    }
};

HeatingSystemConfig* HeatingSystemConfig::instance = nullptr;

int main() {
    HeatingSystemConfig* config = HeatingSystemConfig::getInstance();
    config->showConfig();

    config->setTemperature(25);
    config->setMode("Comfort");
    config->showConfig();

    return 0;
}
