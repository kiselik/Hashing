#include "Record.h"
#include <vector>

template <typename V>
class HashTable {
public:
    HashTable(unsigned int size = 16);
    virtual bool ContainsKey(int key) = 0;
    virtual void Delete(int key) = 0;
    virtual void Insert(int key, V value) = 0;
    virtual V SearchValue(int Key) = 0;
protected:
    unsigned int size_;
    unsigned int data_count_;

	virtual void CountHashCoeff() = 0;
    virtual void ConflictResolution() = 0;
    bool IsEmpty() { return data_count_ == 0; }
    bool IsFull(); { return data_count_ == size_; } // i have different implementation
};

template <typename V>
HashTable<V>::HashTable(unsigned int size = 16) {
    if (!size) {
        throw std::runtime_error("Size can't be equals zero");
    }
    size_ = size;
    data_count_ = 0;
}

/*
template <typename V>
bool HashTable<V>::ContainsKey(int key) {
}

template <typename V>
V HashTable<V>::SearchValue(int key) {
    V result = -1;
    for (int i = 0; i < record_.size(); i++) {
        if (record_[i].GetKey() == key) {
            //скорее всего, переделать в виртуальный
            result = record_[i].SearchValue();
        }

    }
    return result;
}

template <typename V>
void HashTable<V>::Delete(int key, V value) {
    if (IsEmpty) {
        throw std::runtime_error("HashTable is Empty. Can't delete element")
    }
    //считаем хэш
    //далее,все зависит от метода разрешения колллизий
    data_count_--;
}

template <typename V>
void HashTable<V>::Insert(int key, V value) {
    if (IsFull) {
        throw std::runtime_error("HashTable is Full");
    }
    //считаем хэш, ячейку
    // кладем. Как, зависит от метода разрешения коллицизий
}

*/

