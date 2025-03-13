#include <iostream>

#define all(x) x.begin(), x.end()
#define fori(x, a, b) for (int i = x; i < a; i += b)
#define forj(x, a, b) for (int j = x; j < a; j += b)
#define fork(x, a, b) for (int k = x; k < a; k += b)

using namespace std;

struct hashTable {
    static const int n = 1e6;
    static const int N = 2 * n;
    vector<int> key;
    vector<int> value;

    hashTable() : key(N, -1), value(N) {}

    int ind(int i) {
        int index = i % N;
        while (key[index] != -1 && key[index] != i)
            index = (index + 1) % N;
        return index;
    }

    void put(int i, int x) {
        int index = ind(i);
        key[index] = i;
        value[index] = x;
    }

    int get(int i) {
        int index = ind(i);
        return key[index] != i ? -1 : value[index];
    }
    
    bool count(int i){
        return key[ind(i)] == i;
    }
};
