#include <vector>
#include <iostream>

#define all(x) x.begin(), x.end()
#define fori(x, a, b) for (int i = x; i < a; i += b)
#define forj(x, a, b) for (int j = x; j < a; j += b)

using namespace std;

static vector<vector<int>> g;
static vector<int> ans;
static vector<char> used;
static vector<short> cycle;
static vector<int> p;
static vector<int> d;

void dfsIter(int s){
    stack<int> st;
    st.push(s);
    used[s] = true;
    while (!st.empty()){
        int x = st.top();
        st.pop();
        for (int u : g[x]){
            if (!used[u]){
                used[u] = true;
                st.push(u);
            }
        }
        ans.push_back(x);
    }
}

void bfs(int s){
    queue<int> q;
    q.push(s);
    used[s] = true;
    d[s] = 0;
    p[s] = -1;
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto u : g[x]){
            if (!used[u]){
                used[u] = true;
                d[u] = d[x] + 1;
                p[u] = x;
                q.push(u);
            }
        }
    }
}

void compXDfs(){
    int n, m, x;
    cin >> n >> m;
    used.resize(n, false);
    g.resize(n);
    
    int a, b;
    while (m--){
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    cin >> x;
    x--;
    dfsIter(x);
    cout << count(all(used), true);
}

bool dfsCycle (int v) {
    cycle[v] = 1;
    for (auto u : g[v]){
        if (used[u] == 0) {
            p[u] = v;
            if (dfsCycle(u))
                return true;
        }
        else if (used[u] == 1)
            return true;
    }
    cycle[v] = 2;
    return false;
}

void topsort() {
    int n, m;
    cin >> n >> m;
    vector<char> used(n, false);
    vector<vector<int>> g(n);

    int a, b;
    while (m--){
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }
    
    function<void(int)> dfs = [&](int v) {
        used[v] = true;
        for (int u : g[v]){
            if (!used[u])
                dfs(u);
        }
        ans.push_back(v);
    };
    
    fori(0, n , 1)
        if (!used[i])
            dfs(i);
    
    for (int i = n - 1; i >= 0; i--)
        cout << ans[i] + 1 << ' ';
}
