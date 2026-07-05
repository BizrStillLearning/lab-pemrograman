#include <iostream>
#include <list>
#include <unordered_map>

class LRUCache {
private:
    int capacity;
    std::list<std::pair<int, int>> items;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache;

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        items.splice(items.begin(), items, cache[key]);
        return cache[key]->second;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key]->second = value;
            items.splice(items.begin(), items, cache[key]);
            return;
        }

        if (items.size() == capacity) {
            cache.erase(items.back().first);
            items.pop_back();
        }

        items.push_front({key, value});
        cache[key] = items.begin();
    }

    void printCacheState() {
        std::cout << "[Depan (Baru) -> Belakang (Lama)]: ";
        for (auto const& pair : items) {
            std::cout << "{" << pair.first << ":" << pair.second << "} ";
        }
        std::cout << "\n";
    }
};

int main() {
    std::cout << "Membuat LRU Cache dengan kapasitas 3...\n";
    LRUCache lru(3);

    lru.put(1, 100);
    lru.put(2, 200);
    lru.put(3, 300);
    lru.printCacheState();

    std::cout << "\nMengakses key 1 (get(1)): " << lru.get(1) << "\n";
    std::cout << "Elemen 1 akan pindah ke depan...\n";
    lru.printCacheState();

    std::cout << "\nMemasukkan key baru (4:400). Karena penuh, key 2 akan ditendang.\n";
    lru.put(4, 400);
    lru.printCacheState();

    std::cout << "\nMengakses key 2 (get(2)): " << lru.get(2) << " (Harusnya -1 karena sudah dihapus)\n";

    return 0;
}

