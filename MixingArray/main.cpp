#include<iostream>
#include"mixingArray.h"

int main() {
    HashTable<std::string, int> hashTable;

    hashTable.insert("Alice", 25);
    hashTable.insert("Bob", 30);
    hashTable.insert("Charlie", 35);

    std::cout << "Alice's age: " << hashTable.get("Alice") << std::endl;
    std::cout << "Bob's age: " << hashTable.get("Bob") << std::endl;

    hashTable.remove("Bob");

    std::cout << "Contains Bob? " << (hashTable.contains("Bob") ? "Yes" : "No") << std::endl;

    return 0;
}