#include "include/HashTableChain.h"
#include "include/HashTableCuckoo.h"
#include <ctime>
#include <iostream>
#include <map>
#include <windows.h>

using namespace std;

int kSIZE;
int COUNT;
int kADD = 7000;

double Insert_Time_Chain() {
	HashTableChain<int> Table(kSIZE);
	for( int i = 0; i < COUNT; i++)
		Table.Insert(i,i);

    clock_t begin = clock();

    for (int i = COUNT; i < COUNT + kADD; i++)
        Table.Insert(i, i);

	clock_t end = clock();
	
    return double(end - begin) / CLOCKS_PER_SEC;
}

double Delete_Time_Chain() {
    HashTableChain<int> Table(kSIZE);
    for (int i = 0; i < COUNT + kADD; i++)
        Table.Insert(i, i);

    clock_t begin = clock();

    for (int i = COUNT; i < COUNT + kADD; i++)
        Table.Delete(i);

    clock_t end = clock();

    return double(end - begin) / CLOCKS_PER_SEC;
}

double Insert_Time_Cuckoo() {
    HashTableCuckoo<int> Table(kSIZE);
    for (int i = 0; i < COUNT; i++)
        Table.Insert(i, i);

    clock_t begin = clock();

    for (int i = COUNT; i < COUNT + kADD; i++)
        Table.Insert(i, i);

    clock_t end = clock();

    return double(end - begin) / CLOCKS_PER_SEC;
}

double Search_Time_Cuckoo() {
    HashTableCuckoo<int> Table(kSIZE);
    for (int i = 0; i < COUNT + kADD; i++)
        Table.Insert(i, i);

    clock_t begin = clock();

    for (int i = 0; i < kADD; i++)
        Table.Search(i);

    clock_t end = clock();

    return double(end - begin) / CLOCKS_PER_SEC;
}

double Delete_Time_Cuckoo() {
    HashTableCuckoo<int> Table(kSIZE);
    for (int i = 0; i < COUNT + kADD; i++)
        Table.Insert(i, i);

    clock_t begin = clock();

    for (int i = COUNT; i < COUNT + kADD; i++)
        Table.Delete(i);

    clock_t end = clock();

    return double(end - begin) / CLOCKS_PER_SEC;
}

double Search_Time_Chain() {
    HashTableChain<int> Table(kSIZE);
    for (int i = 0; i < COUNT + kADD; i++)
        Table.Insert(i, i);

    clock_t begin = clock();
    for (int i = 0; i < kADD; i++)
        Table.Search(i);

    clock_t end = clock();

    return double(end - begin) / CLOCKS_PER_SEC;
}



double Insert_Time_Map() {
	std::map<int, int> Map;
    for (int i = 0; i < COUNT; i++)
        Map[i] = i;
	
	clock_t begin = clock();

    for (int i = 0; i < kADD; i++)
        Map[i] = i;

	clock_t end = clock();

	return double(end - begin) / CLOCKS_PER_SEC;
}

double Search_Time_Map() {
    std::map<int, int> Map;
    for (int i = 0; i < COUNT + kADD; i++)
        Map[i] = i;

    clock_t begin = clock();

    for (int i = 0; i < kADD; i++)
        int r = Map.at(i);

    clock_t end = clock();

    return double(end - begin) / CLOCKS_PER_SEC;
}

double Delete_Time_Map() {
    std::map<int, int> Map;
    for (int i = 0; i < COUNT + kADD; i++)
        Map[i] = i;

    clock_t begin = clock();

    for (int i = COUNT; i < COUNT+kADD; i++)
        Map.erase(i);

    clock_t end = clock();

    return double(end - begin) / CLOCKS_PER_SEC;
}

typedef double(*function)();
const int kCountArr[] = { 150000, 200000, 250000, 300000, 350000, 400000, 450000, 500000};

double getTime(function f){
    double sum = 0;
    for (int i = 0; i < 20 & sum < 0.0000001; i++)
        sum += f();
    return sum;
}

void measure(function f){
    double arr[9];
    for (int i = 0; i < 8; i++){
        COUNT = kCountArr[i];
        kSIZE = COUNT * 1.15;
        arr[i] = getTime(f);
    }
    for (int i = 0; i < 8; i++){
        printf("%d: ", kCountArr[i]);
        printf("%.9lf\n", arr[i]);
    }
    printf("--------------------------------------\nPRESS KEY TO CONTINUE\n");
    getchar();
}


int main() {
    printf("Cuckoo insert time(wait):\n");
    measure(Insert_Time_Cuckoo);

    printf("Cuckoo search time(wait):\n");
    measure(Search_Time_Cuckoo);

    printf("Cuckoo delete time(wait):\n");
    measure(Delete_Time_Cuckoo);

    printf("Chain insert time(wait):\n");
    measure(Insert_Time_Chain);

    printf("Chain search time(wait):\n");
    measure(Search_Time_Chain);

    printf("Chain delete time(wait):\n");
    measure(Delete_Time_Chain);

    printf("Map insert time(wait):\n");
    measure(Insert_Time_Map);

    printf("Map search time(wait):\n");
    measure(Search_Time_Map);

    printf("Map delete time(wait):\n");
    measure(Delete_Time_Map);
    getchar();
    getchar();
    getchar();

}