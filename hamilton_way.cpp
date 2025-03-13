using namespace std;

#define all(x) x.begin(), x.end()
#define fori(x, a, b) for (int i = x; i < a; i += b)
#define forj(x, a, b) for (int j = x; j < a; j += b)

void hamWay(vector<vector<int>>& g) {
    int n = (int)g.size();
    vector<vector<int>> is(1 << n, vector<int>(n, -1));
    vector<int> path;
    
    function<bool(int, int)> rec = [&](int A, int v) {
        if (A == (1 << n) - 1) {
            path.push_back(v);
            return true;
        }
        if (is[A][v] != -1)
            return is[A][v] == 1;
        
        bool found = false;
        for (int x : g[v]) {
            if (!(A & (1 << x))) {
                if (rec(A | (1 << x), x)) {
                    found = true;
                    path.push_back(v);
                    break;
                }
            }
        }
        
        is[A][v] = found ? true : false;
        return found;
    };

    fori(0, n, 1) {
        path.clear();
        if (rec(1 << i, i)) {
            for (int u : path) cout << u + 1 << " ";
            return;
        }
    }

    cout << "no";
}
