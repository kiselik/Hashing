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

    bool ContainsKey(int key);
    void Delete(int key);
    void Insert(int key, V value);
    V Search(int key);

private:
	//std::vector<Record<V>*>record_; было
    std::vector< std::list<Record<V>> >record_; // массив из списков
	int a,b;	//  ((ax+b)mod p) mod size_; 
	int p;		//  p = rand && p >=size_

    int getHashCode(int key);
    void CountHashCoeff();
    void ConflictResolution();
    bool IsFull() { return data_count_ == size_; }
};

template <typename V>
bool HashTableChain<V>::ContainsKey(int key) {
    Record<V> r(key, 1);  // оператор сравнения перегружен - две записи равны, если их ключи совпадают
    std::list<Record<V>>::iterator findIter = std::find(
        record_[getHashCode(key)].begin(), record_[getHashCode(key)].end(), r);
    if (findIter != record_[getHashCode(key)].end()) 
        // если итератор указывает на end(), то ничего не найдено.
        return true;
    return false;
}

template <typename V>
V HashTableChain<V>::Search(int key) {
    Record<V> r(key, 1);  // оператор сравнения перегружен - две записи равны, если их ключи совпадают
    std::list<Record<V>>::iterator findIter = std::find(
        record_[getHashCode(key)].begin(), record_[getHashCode(key)].end(), r);
    if (findIter != record_[getHashCode(key)].end())
        return его значение;
}

template <typename V>
void HashTableChain<V>::Delete(int key) {
    if (IsEmpty) {
        throw std::runtime_error("HashTable is Empty. Can't delete element")
    }
    //считаем хэш
    //далее,все зависит от метода разрешения колллизий
    data_count_--;
}

template <typename V>
void HashTableChain<V>::Insert(int key, V value) {
    if (IsFull) {
        throw std::runtime_error("HashTable is Full");
    }
//считаем хэш, ячейку
// кладем. Как, зависит от метода разрешения коллицизий
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
