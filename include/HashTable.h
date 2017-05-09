#include "Record.h"
#include <vector>
template <typename K, typename V>
class HashTable {
public:
    HashTable(unsigned int size = 16);
    void Put(K key, V value);
    unsigned int Size();
    bool ContainsKey(K key);
    //bool ContainsValue(V value);
    V getValue(K key);

private:
    unsigned int size_;
    std::vector<Record<K, V>>record_;
    void HashCode(K key, V value);
    virtual void ConflictResolution() = 0;
};
template <typename K, typename V>
HashTable<K, V>::HashTable(unsigned int size = 16) {
    if (!size) {
        throw std::runtime_error("size can't be equals zero")
    }
    size_ = size;
    record_.resize(size_);
}

template <typename K, typename V>
unsigned int HashTable<K, V>::Size() {
    return size_;
}

template <typename K, typename V>
bool HashTable<K, V>::ContainsKey(K key) {
    bool result = false;
    if (getValue(key) != -1) {
        return true;
    }
}

template <typename K, typename V>
V HashTable<K, V>::getValue(K key) {
    V result = -1;
    for (int i = 0; i < record_.size(); i++) {
        if (record_[i].GetKey() == key) {
            //скорее всего, переделать в виртуальный
            result = record_[i].GetValue();
        }

    }
    return result;
}