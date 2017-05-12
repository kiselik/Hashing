#pragma once
#include "HashTable.h"
template<typename V>
class HashTableChain : public HashTable <V> {
public:
    HashTableChain(unsigned int size = 16) : HashTable(size) {}
private:
    int getHashCode(int key);
    void CountHashCoeff();
    virtual void ConflictResolution();
};
template <typename V>
void HashTableChain<V>::CountHashCoeff() {
    coeff1 = rand() % size_;
    coeff2 = rand() % size_;
}

template <typename V>
int HashTableChain<V>::getHashCode(int key) {
    return (coeff1 * key + coeff2) % size_;
}
template <typename V>
virtual void HashTableChain<V>::ConflictResolution() {

}
