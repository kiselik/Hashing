#pragma once
#include "HashTable.h"
template<typename V>
class HashTableCuckoo : public HashTable <V> {
public:
    HashTableCuckoo(unsigned int size = 16) : HashTable(size) { 
        if (size == 0) {
            throw "Size can't be equals zero";
        }
        srand(time(NULL));
        CountHashCoeff();
        Table1.resize(size);
        Table2.resize(size);
        rehash_retries = 0;
    }
    ~HashTableCuckoo() {
        for (int i = 0; i < size_; i++){
            if (Table1[i] != 0) delete Table1[i];
            if (Table2[i] != 0) delete Table2[i];
        }
    }


    bool ContainsKey(int key);
    void Delete(int key);
    void Insert(int key, V value);
    void Insert(Record<V> *r);
    //V Search(int key); // 
    Record<V>* Search(int key);

private:
    int a1, b1;
    int a2, b2;
    int p; // >= size_
    const int MAX_TRANSFER_RETRIES = 15;
    int rehash_retries;

    std::vector<Record<V> *> Table1;
    std::vector<Record<V> *> Table2;

    int h1(int key);
    int h2(int key);
    void CountHashCoeff();
    void ConflictResolution();
    bool IsFull() { return data_count_ == 2* size_; }
    
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
    Record<V> *r1 = Table1[h1(key)];
    Record<V> *r2 = Table2[h2(key)];
    return ( (r1 && r1->GetKey() == key) || (r2 && r2->GetKey() == key) );
}

template <typename V>
Record<V>* HashTableCuckoo<V>::Search(int key){
    Record<V> *r1 = Table1[h1(key)];
    Record<V> *r2 = Table2[h2(key)];
    if (r1 && r1->GetKey() == key) return r1;
    if (r2 && r2->GetKey() == key) return r2;
    return NULL;
}

template <typename V>
void HashTableCuckoo<V>::Delete(int key){
    if (Table1[h1(key)]) {
        Record<V> *r = Table1[h1(key)];
        if (r->GetKey() == key){
            delete r;
            Table1[h1(key)] = 0;
            data_count_--;
            return;
        }
    }
    if (Table2[h2(key)]){
        Record<V> *r = Table2[h2(key)];
        if (r->GetKey() == key){
            delete r;
            Table2[h2(key)] = 0;
            data_count_--;
            return;
        }
    }
    return;
}

template <typename V>
void HashTableCuckoo<V>::Insert(int key, V value){
    Record<V> *r = new Record<V>(key, value);
    Insert(r);
}

template <typename V>
void HashTableCuckoo<V>::Insert(Record<V> *r){
    if (ContainsKey(r->GetKey())) {
        printf("Element with key alreadyin table");
        return; // throw?
    }
    if (IsFull()) {
        printf("HashTable is Full\n");
    }
    Record<V> *buf;
    int retries = 0;
    for (; retries < MAX_TRANSFER_RETRIES; retries++){
        if (Table1[h1(r->GetKey())] == 0){
            Table1[h1(r->GetKey())] = r;
            data_count_++;
            return;
        }
        buf = Table1[h1(r->GetKey())];
        Table1[h1(r->GetKey())] = r;
        r = buf;

        if (Table2[h2(r->GetKey())] == 0){
            Table2[h2(r->GetKey())] = r;
            data_count_++;
            return;
        }
        buf = Table2[h2(r->GetKey())];
        Table2[h2(r->GetKey())] = r;
        r = buf;
    }
    if (retries == MAX_TRANSFER_RETRIES){
        ConflictResolution();
        rehash_retries++;
        if (rehash_retries > 10){
            printf("Too many rehash\n");
            throw "Too many rehash";
        }
        Insert(r); 
    } // infinie loop?
    rehash_retries = 0;
}

template <typename V>
void HashTableCuckoo<V>::ConflictResolution(){
    std::vector<Record<V> *> t1(size_);
    std::vector<Record<V> *> t2(size_);
    t1.swap(Table1);
    t2.swap(Table2);

    CountHashCoeff();

    data_count_ = 0;

    for (int i = 0; i < size_; i++){
        if (t1[i] != 0) Insert(t1[i]);
        if (t2[i] != 0) Insert(t2[i]);
    }
}
