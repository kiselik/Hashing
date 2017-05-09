#pragma once
template<typename K, typename V>
class Record
{
public:
    Record(K key, V value);
    void SetKey(K key); 
    K GetKey();
    void SetValue(V value);
    V GetValue();
private:
    K key_;
    V value_;
};

