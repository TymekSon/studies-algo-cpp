#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <stdexcept> 

template <typename Key, typename Value>
class HashTable {
private:
    struct KeyValuePair {
        Key key;
        Value value;
    };

    std::vector<std::list<KeyValuePair>> table; 
    size_t numElements;                         
    size_t capacity;                            
    static constexpr double loadFactor = 0.75; 

    size_t hashFunction(const Key& key) const {
        return std::hash<Key>{}(key) % capacity;
    }

    void resize() {
        size_t newCapacity = capacity * 2;
        std::vector<std::list<KeyValuePair>> newTable(newCapacity);

        for (const auto& bucket : table) {
            for (const auto& pair : bucket) {
                size_t newIndex = std::hash<Key>{}(pair.key) % newCapacity;
                newTable[newIndex].push_back(pair);
            }
        }

        table = std::move(newTable);
        capacity = newCapacity;
    }

public:
    HashTable(size_t initialCapacity = 8) : table(initialCapacity), numElements(0), capacity(initialCapacity) {}

    void insert(const Key& key, const Value& value) {
        if ((double)numElements / capacity > loadFactor) {
            resize();
        }

        size_t index = hashFunction(key);
        for (auto& pair : table[index]) {
            if (pair.key == key) {
                pair.value = value; 
                return;
            }
        }

        table[index].push_back({ key, value });
        ++numElements;
    }

    Value get(const Key& key) const {
        size_t index = hashFunction(key);
        for (const auto& pair : table[index]) {
            if (pair.key == key) {
                return pair.value;
            }
        }
        throw std::runtime_error("Key not found");
    }

    void remove(const Key& key) {
        size_t index = hashFunction(key);
        auto& bucket = table[index];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->key == key) {
                bucket.erase(it);
                --numElements;
                return;
            }
        }
        throw std::runtime_error("Key not found");
    }

    bool contains(const Key& key) const {
        size_t index = hashFunction(key);
        for (const auto& pair : table[index]) {
            if (pair.key == key) {
                return true;
            }
        }
        return false;
    }
};