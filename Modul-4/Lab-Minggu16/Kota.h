#ifndef KOTA_H
#define KOTA_H
#include "Region.h"

class Kota : public Region {
private:
    std::string province;
public:
    Kota(int c, const std::string& n, const std::string& prov, long pop, double area, double h, double pov)
        : Region(c, n, pop, area, h, pov), province(prov) {}

    const std::string& getProvince() const { return province; }

    void displayInfo() const override {
        std::cout << "Kota " << name << " (" << province << ") "
                  << "| Pop: " << population << " | Density: " << getDensity() << "/km2 | HDI: " << hdi << "\n";
    }
};
#endif