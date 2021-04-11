//
// Created by N on 2021/03/04.
//

#include "HashTable.h"
#include <iostream>

#define HASH_MAX 13
#define A 1
#define B 5
using namespace std;

class HashTable {

    int hashTable[HASH_MAX];

public:

    // Constructor
    HashTable() {
    }

private:

    int strLen(char *input) {
        int cnt = 0;
        while (input[cnt] != '\0') cnt++;

        return cnt;
    }

    int split(char *str) {
        int ret = 0;

        int len = strLen(str);
        for (int i = 0; i < len; i++) ret += str[i] - '0';

        return ret;
    }

    int getIndex(char key[]) {
        return (A * split(key) + B) % HASH_MAX; // Hash function => H(x) = (A * x +B) mod HASH_MAX
    }

public:

    bool add(char key[], int value) {
        int index = getIndex(key); // Bucket index

        if (!hashTable[index]) {
            hashTable[index] = value;
            return true;
        }

        else {
           return false;
        }
    }

    int getValue(char key[]) {
        int index = getIndex(key);

        return hashTable[index];
    }

};