#include <iostream>

#include "HashTable.cpp"

using namespace std;

int main() {
    // Hash Table
    HashTable hashTable = HashTable();

    char key[7] = {'B', 'L', 'o', 'w', 'e', 's', 't'};
    int value = 155;

    cout << "Add key and value to hash table\n\n";
    cout << "Key:" << (string) key << '\n' << "Value: " << value << '\n\n';
    if (hashTable.add(key, value)) cout << "Success" << "\n\n";
    else cout << "Fail" << "\n\n";

    cout << "Key:" << (string) key << '\n' << "Value: " << value << '\n';
    if (hashTable.add(key, value)) cout << "Success" << "\n\n";
    else cout << "Fail" << "\n\n";

    cout << "Get value by key\n\n";
    cout << "Key:" << (string) key << '\n';
    cout << hashTable.getValue(key) << '\n';
}
