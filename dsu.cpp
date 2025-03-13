#include <vector>

#define all(x) x.begin(), x.end()
#define fori(x, a, b) for (int i = x; i < a; i += b)
#define forj(x, a, b) for (int j = x; j < a; j += b)
#define fork(x, a, b) for (int k = x; k < a; k += b)

using namespace std;

struct DSU {
    vector<int> p;
    vector<int> rank;

    DSU(int n) {
        p.resize(n);
        rank.assign(n, 0);
        fori(0, n, 1)
            p[i] = i;
    }

    int find(int v) {
        if (v == p[v])
            return v;
        return p[v] = find(p[v]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            p[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
};
