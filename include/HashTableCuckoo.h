#pragma once
#include "HashTable.h"
template<typename V>
class HashTableCuckoo : public HashTable <V> {
public:
    HashTableCuckoo(unsigned int size = 16) : HashTable(size) { 
        srand(time(NULL));
        CountHashCoeff();
        Table1.resize(size);
        Table2.resize(size);
    }

    bool ContainsKey(int key);
    void Delete(int key);
    void Insert(int key, V value);
    void Insert(Record<V> *r);
    V Search(int key);

private:
    int a1, b1;
    int a2, b2;
    int p; // >= size_
    const int MAX_RETRIES = 10;

    std::vector<Record<V> *> Table1;
    std::vector<Record<V> *> Table2;

    int h1(int key);
    int h2(int key);
    void CountHashCoeff();
    void ConflictResolution();
};

template <typename V>
void HashTableCuckoo<V>::CountHashCoeff() {
    p = size_ + rand() % (int)(std::numeric_limits<int>::max() - size_ + 1);
    a1 = 1 + rand() % (int)(p-1); 
    a2 = 1 + rand() % (int)(p-1);

    b1 = rand() % p;
    b2 = rand() % p;
    // number = min + (rand() % (int)(max - min + 1))
}

template <typename V>
int HashTableCuckoo<V>::h1(int key) {
    return ((a1 * key + b1) % p) % size_;
}

template <typename V>
int HashTableCuckoo<V>::h2(int key) {
    return ((a2 * key + b2) % p) % size_;
}

template <typename V>
bool HashTableCuckoo<V>::ContainsKey(int key){
    return (Table1[h1(key)] == key)||(Table2[h2(key)] == key);
}

template <typename V>
V HashTableCuckoo<V>::Search(int key){
    if (Table1[h1(key)] == key) return Table1[h1(key)]->GetValue();
    if (Table2[h2(key)] == key) return Table2[h2(key)]->GetValue();
    return 0;
}

template <typename V>
void HashTableCuckoo<V>::Delete(int key){
    if (Table1[h1(key)] == key) {
        delete Table1[h1(key)];
        Table1[h1(key)] = 0;
    }
    if (Table2[h2(key)] == key){
        delete Table2[h2(key)];
        Table2[h2(key)] = 0;
    }
    data_count_--;
    return;
}

template <typename V>
void HashTableCuckoo<V>::Insert(int key, V value){
    Record *r = new Record(key, value);
    Insert(r);
}

template <typename V>
void HashTableCuckoo<V>::Insert(Record<V> *r){
    if (ContainsKey(r->GetKey())) return; // throw?

    int retries = 0;
    Record<V> *buf;
    for(retries < MAX_RETRIES; retries++){
        if (Table1[h1(r->GetKey())] == 0){
            Table1[h1(r->GetKey())] = r;
            return;
        }
        buf = Table1[h1(r->GetKey())];
        Table1[h1(r->GetKey())] = r;
        r = buf;

        if (Table2[h2(r->GetKey())] == 0){
            Table2[h2(r->GetKey())] = r;
            return;
        }
        buf = Table2[h2(r->GetKey())];
        Table2[h2(r->GetKey())] = r;
        r = buf;
    }
    if (retries == MAX_RETRIES){
        ConflictResolution();
        Insert(r);
    } // infinie loop?
    data_count_++;
}

template <typename V>
void HashTableCuckoo<V>::ConflictResolution(){
    std::vector<Record<V> *> t1(size_);
    std::vector<Record<V> *> t2(size_);
    t1.swap(Table1);
    t2.swap(Table2);

    CountHashCoeff();

    for( int i = 0 i < size_; i++){
        if (t1[i] != 0) Insert(t1[i]);
        if (t2[i] != 0) Insert(t2[i]);
    }
}

template <typename V>
bool HashTableCuckoo<V>::IsFull() {
    return data_count_ == 2*size_;
}