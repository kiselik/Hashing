#pragma once
#include "HashTable.h"
template<typename V>
class HashTableChain : public HashTable <V> {
public:
    HashTableChain(unsigned int size = 16) : HashTable(size) {
    	srand(time(NULL));
        CountHashCoeff();
    	record_.resize(size_);
    }

    bool ContainsKey(int key);
    void Delete(int key);
    void Insert(int key, V value);
    void Insert(Record<V> *r);
    V Search(int key);

private:
	std::vector<Record<V> *>record_;	//  vector of pointers
	int a,b;	//  ((ax+b)mod p) mod size_; 
	int p;		//  p = rand && p >=size_

    int getHashCode(int key);
    void CountHashCoeff();
    void ConflictResolution();
};

template <typename V>
void HashTableChain<V>::CountHashCoeff() {
	p = size_ + rand() % (int)(std::numeric_limits<int>::max() - size_ + 1);
    a = 1 + rand() % (int)(p-1);
    b = rand() % p;
}

template <typename V>
int HashTableChain<V>::getHashCode(int key) {
    return ((a * key + b) % p) % size_;
}

template <typename V>
void HashTableChain<V>::ConflictResolution() {

}

template <typename V>
void HashTableChain<V>::Insert(int key, V value){
    Record *r = new Record(key, value);
    Insert(r);
}
