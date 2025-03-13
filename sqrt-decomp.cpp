#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>

#define all(x) x.begin(), x.end()
#define fori(x, a, b) for (int i = x; i < a; i += b)
#define forj(x, a, b) for (int j = x; j < a; j += b)
#define fork(x, a, b) for (int k = x; k < a; k += b)

using namespace std;

void solve1() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);

    fori(0, m, 1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);

    auto cmp = [&](int a, int b) {
        return adj[a].size() < adj[b].size()
        || (adj[a].size() == adj[b].size() && a < b);
    };

    sort(all(p), cmp);

    fori(0, n, 1)
        sort(all(adj[i]), cmp);

    unordered_set<int> vtow;

    for (auto v : p) {
        for (int w : adj[v])
            vtow.insert(w);

        for (auto u : adj[v]) {
            if (cmp(v, u))
                break;

            for (auto w : adj[u]) {
                if (cmp(u, w))
                    break;

                if (vtow.count(w)) {
                    cout << v + 1 << " " << u + 1 << " " << w + 1;
                    return;
                }
            }
        }
        vtow.clear();
    }
}

