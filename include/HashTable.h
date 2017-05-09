#include "Record.h"
#include <vector>
template <typename V>
class HashTable {
public:
    HashTable(unsigned int size = 16);
    void Put(int key, V value);
    int GetSize();
    bool ContainsKey(int key);
    //bool ContainsValue(V value);
    V getValue(int key);

private:
    unsigned int size_;
    std::vector<Record<V>>record_;
    //void HashCode(K key, V value);
    //virtual void ConflictResolution() = 0;
};
template <typename V>
HashTable<V>::HashTable(unsigned int size = 16) {
    if (!size) {
        throw std::runtime_error("size can't be equals zero");
    }
    size_ = size;
    record_.resize(size_);
}

template <typename V>
int HashTable<V>::GetSize() {
    return (int)size_;
}

template <typename V>
bool HashTable<V>::ContainsKey(int key) {
    bool result = false;
    if (getValue(key) != -1) {
        return true;
    }
}

template <typename V>
V HashTable<V>::getValue(int key) {
    V result = -1;
    for (int i = 0; i < record_.size(); i++) {
        if (record_[i].GetKey() == key) {
            //скорее всего, переделать в виртуальный
            result = record_[i].GetValue();
        }

    }
    return result;
}