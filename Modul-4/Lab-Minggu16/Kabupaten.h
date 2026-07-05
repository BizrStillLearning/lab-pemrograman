#ifndef KABUPATEN_H
#define KABUPATEN_H
#include "Region.h"

class Kabupaten : public Region {
private:
    std::string province;
public:
    Kabupaten(int c, const std::string& n, const std::string& prov, long pop, double area, double h, double pov)
        : Region(c, n, pop, area, h, pov), province(prov) {}

    const std::string& getProvince() const { return province; }

    void displayInfo() const override {
        std::cout << "Kab. " << name << " (" << province << ") "
                  << "| Pop: " << population << " | HDI: " << hdi << " | Pov: " << povertyRate << "%\n";
    }
};
#endif