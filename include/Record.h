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
template<typename K, typename V>
Record<K, V>::Record(K key, V value) {
    key_ = key;
    value_ = value;
}
template<typename K, typename V>
void Record<K, V>::SetKey(K key) {
    key_ = key;
}
template<typename K, typename V>
K Record<K, V>::GetKey() {
    return key_;
}
template<typename K, typename V>
void Record<K, V>::SetValue(Vvalue) {
    value_ = value;
}
template<typename K, typename V>
K Record<K, V>::GetValue() {
    return value_;
}
