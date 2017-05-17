#include "Record.h"
#include <vector>

template <typename V>
class HashTable {
public:
    HashTable(unsigned int size = 16);
    virtual bool ContainsKey(int key) = 0;
    virtual void Delete(int key) = 0;
    virtual void Insert(int key, V value) = 0;
    virtual Record<V>* Search(int Key) = 0;
    int GetSize() { return data_count_; } // Number of inserted elements
protected:
    unsigned int size_;
    unsigned int data_count_;
	virtual void CountHashCoeff() = 0;
    virtual void ConflictResolution() = 0;
    bool IsEmpty() { return data_count_ == 0; }
    virtual bool IsFull() = 0; // i have different implementation
};

template <typename V>
HashTable<V>::HashTable(unsigned int size = 16) {
    if (!size) {
        throw std::runtime_error("Size can't be equals zero");
    }
    size_ = size;
    data_count_ = 0;
}



