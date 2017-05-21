#include "include/HashTableCuckoo.h"
#include "include/HashTableChain.h"
#include <ctime>
#include <iostream>
#include <map>

using namespace std;

int SIZE;
int COUNT;

double Insert_Time_Cuckoo() {
	HashTableCuckoo<int> Table(SIZE);
	
	clock_t begin = clock();

	for( int i = 0; i < COUNT; i++)
		Table.Insert(i,i);

	clock_t end = clock();
	
	return double(end - begin) / (CLOCKS_PER_SEC*COUNT);
}

double Search_Time_Cuckoo() {
    HashTableCuckoo<int> Table(SIZE);
    for (int i = 0; i < COUNT; i++)
        Table.Insert(i, i);
    int res;
    std::vector<Record<int> *> v(SIZE);

    clock_t begin = clock();

    for (int i = 0; i < COUNT; i++)
        v[i] = Table.Search(i);

    clock_t end = clock();

    for (int i = 0; i < COUNT; i++) {
        if (v[i]->GetKey() != i) {
            printf("Error int search\n");
            break;
        }
    }

    return double(end - begin) / (CLOCKS_PER_SEC*COUNT);
}

double Insert_Time_Chain() {
    HashTableChain<int> Table(SIZE);

    clock_t begin = clock();

    for (int i = 0; i < COUNT; i++)
        Table.Insert(i, i);

    clock_t end = clock();

    return double(end - begin) / (CLOCKS_PER_SEC*COUNT);
}

double Search_Time_Chain() {
    HashTableChain<int> Table(SIZE);
    for (int i = 0; i < COUNT; i++)
        Table.Insert(i, i);
    std::vector<int> v(SIZE);
    clock_t begin = clock();

    for (int i = 0; i < COUNT; i++)
        v[i] = (Table.Search(i))->GetKey();

    clock_t end = clock();

    for (int i = 0; i < COUNT; i++)
        if (v[i] != i)
            cout << "Error in search";

    return double(end - begin) / (CLOCKS_PER_SEC*COUNT);
}

double Insert_Time_Map() {
	std::map<int, int> Map;
	
	clock_t begin = clock();

	for( int i = 0; i < COUNT; i++)
        Map[i] = i;

	clock_t end = clock();

	return double(end - begin) / (CLOCKS_PER_SEC*COUNT);
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

    return double(end - begin) / (CLOCKS_PER_SEC*COUNT);
}

double Delete_Time_Cuckoo() {
    HashTableCuckoo<int> Table(SIZE);

    for (int i = 0; i < COUNT; i++)
        Table.Insert(i, i);

    clock_t begin = clock();

    for (int i = 0; i < COUNT; i++)
        Table.Delete(i);

    clock_t end = clock();

    return double(end - begin) / (CLOCKS_PER_SEC*COUNT);
}

double Delete_Time_Chain() {
    HashTableChain<int> Table(SIZE);

    for (int i = 0; i < COUNT; i++)
        Table.Insert(i, i);

    clock_t begin = clock();

    for (int i = 0; i < COUNT; i++)
        Table.Delete(i);

    clock_t end = clock();

    return double(end - begin) / (CLOCKS_PER_SEC*COUNT);
}

double Delete_Time_Map() {
    std::map<int, int> Map;

    for (int i = 0; i < COUNT; i++)
        Map[i] = i;

    clock_t begin = clock();

    for (int i = 0; i < COUNT; i++)
        Map.erase(i);

    clock_t end = clock();

    return double(end - begin) / (CLOCKS_PER_SEC*COUNT);
}



int main() {
    // время суммируется, надо делить его на число элементов?
    printf("Input size of table\n", SIZE);
    scanf("%d", &SIZE);
    printf("Input number of elements to insert\n", COUNT);
    scanf("%d", &COUNT);
    getchar();
	printf("Cuckoo insert time: %.9lf", Insert_Time_Cuckoo() );
    getchar();
	printf("Chain insert time:  %.9lf", Insert_Time_Chain() );
    getchar();
    printf("Std map insert time:%.9lf\n", Insert_Time_Map());
   
    getchar();
    printf("Cuckoo search time: %.9lf", Search_Time_Cuckoo());
    getchar();
    printf("Chain search time:  %.9lf", Search_Time_Chain());
    getchar();
    printf("Std map search time:%.9lf\n", Search_Time_Map());

    getchar();
    printf("Cuckoo delete time: %.9lf", Delete_Time_Cuckoo());
    getchar();
    printf("Chain delete time:  %.9lf", Delete_Time_Chain());
    getchar();
    printf("Std map delete time:%.9lf\n", Delete_Time_Map());

    getchar();
}