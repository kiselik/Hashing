#pragma once
#include "HashTable.h"
#include <list>

template<typename V>
class HashTableChain : public HashTable <V> {
public:
    HashTableChain(unsigned int size = 16) : HashTable(size) {
    	srand(time(NULL));
        CountHashCoeff();
    	record_.resize(size_);
    }
    ~HashTableChain(){
        for (int i = 0; i < size_; i++){
            while (!record_[i].empty()) delete record_[i].front(), record_[i].pop_front();
        }
    }

    bool ContainsKey(int key);
    void Delete(int key);
    void Insert(int key, V value);
    void Insert(Record<V> *r);
    Record<V>* Search(int key);

private:
	//std::vector<Record<V>*>record_; было
    std::vector< std::list<Record<V> *> >record_; // массив из списков
	int a,b;	//  ((ax+b)mod p) mod size_; 
	int p;		//  p = rand && p >=size_

    int getHashCode(int key);
    void CountHashCoeff();
    void ConflictResolution();
    bool IsFull() { return data_count_ == size_; }
};

template <typename V>
bool HashTableChain<V>::ContainsKey(int key) {
    if (Search(key) == NULL)
        return false;
    else
        return true;
}

template <typename V>
Record<V>* HashTableChain<V>::Search(int key) {
    Record<V> r(key, 1);
    // оператор сравнения перегружен - две записи равны, если их ключи совпадают
    for (std::list<Record<V>* >::iterator findIter = record_[getHashCode(key)].begin(); 
        findIter != record_[getHashCode(key)].end(); findIter++) {
        if ((*findIter)->GetKey() == r.GetKey()) return *findIter;
    }
    return NULL;
}

template <typename V>
void HashTableChain<V>::Delete(int key) {
    if (IsEmpty()) {
        throw std::runtime_error("HashTable is Empty. Can't delete element");
    }
    record_[getHashCode(key)].remove(Search(key));
    data_count_--;
}

template <typename V>
void HashTableChain<V>::Insert(int key, V value) {
    Record<V> *r = new Record<V>(key, value);
    Insert(r);
}

template <typename V>
void HashTableChain<V>::Insert(Record<V> *r) {
    if (IsFull()) {
        throw std::runtime_error("HashTable is Full");
    }
    record_[getHashCode(r->GetKey())].push_back(r);
    data_count_++;
}

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
