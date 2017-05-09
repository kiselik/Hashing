#include <vector>
template <typename K, typename V>
class HashTable {
public:
    HashTable(unsigned int size = 16);
    void Put(K key, V value);
    unsigned int Size();
    bool ContainsKey(K key);
    bool ContainsValue(V value);
    V getValue(K key);

private:
    unsigned int size_;
    std::vector<K> keys;
    std::vector<V> values;
    virtual void ConflictResolution() = 0;
};


