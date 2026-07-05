#ifndef REGION_H
#define REGION_H
#include <string>
#include <iostream>

class Region {
protected:
    int code;
    std::string name;
    long population;
    double area_km2;
    double hdi;
    double povertyRate;

public:
    Region(int c, const std::string& n, long pop, double area, double h, double pov)
        : code(c), name(n), population(pop), area_km2(area), hdi(h), povertyRate(pov) {}
    
    virtual ~Region() = default;

    int getCode() const { return code; }
    const std::string& getName() const { return name; }
    long getPopulation() const { return population; }
    double getArea() const { return area_km2; }
    double getHDI() const { return hdi; }
    double getPovertyRate() const { return povertyRate; }
    double getDensity() const { return population / area_km2; }

    virtual void displayInfo() const {
        std::cout << "[" << code << "] " << name 
                  << " | Pop: " << population 
                  << " | HDI: " << hdi << "\n";
    }
};
#endif