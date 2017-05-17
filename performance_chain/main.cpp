#include "include/HashTableCuckoo.h"
// заменить на #include "include/HashTableChain.h"
#include <ctime>
#include <iostream>
#include <map>

using namespace std;

const int SIZE = 120000;
const int COUNT = 100000;

double Insert_Time_Cuckoo() {
	HashTableCuckoo<int> Table(SIZE);
	
	clock_t begin = clock();

	for( int i = 0; i < COUNT; i++)
		Table.Insert(i,i);

	clock_t end = clock();
	
	return double(end - begin) / CLOCKS_PER_SEC;
}

double Search_Time_Cuckoo() {
    HashTableCuckoo<int> Table(SIZE);
    for (int i = 0; i < COUNT; i++)
        Table.Insert(i, i);
    int res;

    clock_t begin = clock();

    for (int i = 0; i < COUNT; i++)
        res = Table.Search(i);

    clock_t end = clock();

    return double(end - begin) / CLOCKS_PER_SEC;
}

double Insert_Time_Map() {
	std::map<int, int> Map;
	
	clock_t begin = clock();

	for( int i = 0; i < COUNT; i++)
        Map[i] = i;

	clock_t end = clock();

	return double(end - begin) / CLOCKS_PER_SEC;
}

double Search_Time_Map() {
    std::map<int, int> Map;
    for (int i = 0; i < COUNT; i++)
        Map[i] = i;
    int res;

    clock_t begin = clock();

    for (int i = 0; i < COUNT; i++)
        res = Map.at(i);

    clock_t end = clock();

    return double(end - begin) / CLOCKS_PER_SEC;
}



int main() {
    // время суммируется, надо делить его на число элементов?
    printf("Size %d \n", SIZE);
    getchar();
	printf("Cuckoo avg insert time: %.4lf", Insert_Time_Cuckoo() );
    getchar();
    printf("Std map insert time:    %.4lf\n", Insert_Time_Map());

    getchar();
    printf("Cuckoo avg search time: %.4lf", Search_Time_Cuckoo());
    getchar();
    printf("Std map search time:    %.4lf", Search_Time_Map());

}