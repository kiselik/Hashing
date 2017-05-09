#include "Record.h"
#include <vector>
template <typename V>
class HashTable {
public:
    HashTable(unsigned int size = 16);
    int GetSize();
    bool ContainsKey(int key);
    void Delete(int key, V value);
    void Insert(int key, V value);
    bool IsEmpty();
    bool IsFull();
    virtual V SearchValue(int Key) = 0;
protected:
    unsigned int size_;
    int data_count_ = 0;
    std::vector<Record<V>>record_;
    //void HashCode(K key, V value);
    virtual void ConflictResolution() = 0;
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
    if (SearchValue(key) != -1) {
        return true;
    }
}

/*template <typename V>
V HashTable<V>::SearchValue(int key) {
    V result = -1;
    for (int i = 0; i < record_.size(); i++) {
        if (record_[i].GetKey() == key) {
            //скорее всего, переделать в виртуальный
            result = record_[i].SearchValue();
        }

    }
    return result;
}*/
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
bool HashTable<V>::IsEmpty() {
    return data_count_ == 0;
}

template <typename V>
bool HashTable<V>::IsFull() {
    return data_count_ == size_;
}

template <typename V>
void HashTable<V>::Insert(int key, V value) {
    if (IsFull) {
        throw std::runtime_error("HashTable is Full");
    }
    //считаем хэш, ячейку
    // кладем. Как, зависит от метода разрешения коллицизий
}