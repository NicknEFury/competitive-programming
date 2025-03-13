#include <iostream>

#define all(x) x.begin(), x.end()
#define fori(x, a, b) for (int i = x; i < a; i += b)
#define forj(x, a, b) for (int j = x; j < a; j += b)
#define fork(x, a, b) for (int k = x; k < a; k += b)

using namespace std;

void useLCA () {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    int temp;
    vector<int> tin(n);
    vector<int> tout(n);
    vector<vector<int>> up(n);
    int timer = 0;
    
    fori(1, n, 1){
        cin >> temp;
        temp--;
        g[i].push_back(temp);
        g[temp].push_back(i);
    }
    
    int l = 1;
    while ((1<<l) <= n)
        l++;
    
    fori(0, n, 1)
        up[i].resize(l+1);
    
    function<void(int, int)> dfs = [&](int v, int p) {
        tin[v] = timer++;
        up[v][0] = p;
        
        fori(1, l + 1, 1)
            up[v][i] = up[up[v][i-1]][i-1];
        
        for (auto x : g[v])
            if (x != p)
                dfs(x, v);
        
        tout[v] = timer++;
    };
    
    dfs(0, 0);
    
    auto upper = [&](int a, int b) {
        return tin[a] <= tin[b] && tout[a] >= tout[b];
    };
    
    function<int(int, int)> LCA = [&](int a, int b){
        if (upper (a, b))
            return a;
        
        if (upper (b, a))
            return b;
        
        for (int i = l; i >= 0; i--)
            if (!upper(up[a][i], b))
                a = up[a][i];
        
        return up[a][0];
    };
    
    int m;
    cin >> m;
    int a, b;
    while (m--){
        cin >> a >> b;
        a--; b--;
        cout << LCA(a, b) + 1 << '\n';
    }
}
