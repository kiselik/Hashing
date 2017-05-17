#pragma once

template<typename V>
class Record{
public:
    Record();
    Record(int key, V value);
    void SetKey(int key); 
    int GetKey();
    void SetValue(V value);
    V GetValue();
private:
    int key_;
    V value_;
};

template<typename V>
Record<V>::Record() : key_(0), value_(V()) {}

template<typename V>
Record<V>::Record(int key, V value) {
    key_ = key;
    value_ = value;
}

template<typename V>
void Record<V>::SetKey(int key) {
    key_ = key;
}

template<typename V>
int Record<V>::GetKey() {
    return key_;
}

template<typename V>
void Record<V>::SetValue(V value) {
    value_ = value;
}

template<typename V>
V Record<V>::GetValue() {
    return value_;
}

