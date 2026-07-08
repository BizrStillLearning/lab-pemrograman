#ifndef DATABASE_H
#define DATABASE_H
#include <vector>
#include <string>
#include "Region.h"

class Database {
private:
    std::vector<Region*> records;

public:
    ~Database();
    
    void loadFromCSV(const std::string& filename);
    void listAll() const;
    void searchByName(const std::string& query) const;
    void filterByProvince(const std::string& prov) const;
    void sortData();

    void sortByCode();
    Region* binarySearchByCode(int targetCode);
    void showTopKHDI(int K, const std::string& targetProvince);

    void calculateAverageDensity(const std::string& prov) const;
    void sortByPovertyRate();
};
#endif