#include <vector>
#include <bitset>
#include <unordered_set>

#define all(x) x.begin(), x.end()
#define fori(x, a, b) for (int i = x; i < a; i += b)
#define forj(x, a, b) for (int j = x; j < a; j += b)
#define fork(x, a, b) for (int k = x; k < a; k += b)

using namespace std;

struct myBitset {
    vector<uint64_t> a;
    
    myBitset(int n) {
        a.resize(n / 64 + 1);
    }
    
    myBitset& operator |= (const myBitset &x) {
        fori(0, a.size(), 1)
            a[i] |= x.a[i];

        return *this;
    }
    
    int count() {
        int cnt = 0;
        fori(0, a.size(), 1)
            cnt += popcount(a[i]);
    
        return cnt;
    }
};

void findTrianglesBitset(){
    const int N = 1e4;
    int n, m;
    cin >> n >> m;
    vector<bitset<N>> g(n);
    vector<pair<int, int>> es;
    
    int a, b;
    while (m--){
        cin >> a >> b;
        a--; b--;
        g[a][b] = 1;
        g[b][a] = 1;
        es.emplace_back(a,b);
    }
    
    for (auto [a, b] : es){
        if ((g[a] & g[b]).count() == 1){
            cout << "yes";
            return;
        }
    }
    cout << "no";
}

void setIntersection(){
    const int N = 1e4;
    int n;
    cin >> n;
    vector<bitset<N>> sets(n);
    int k, temp;
    fori(0, n, 1){
        cin >> k;
        while (k--){
            cin >> temp;
            sets[i][temp] = 1;
        }
    }
    
    int ansSet = 0;
    fori(0, n, 1){
        int mind = 1e9;
        forj(0, n, 1){
            if (i != j && mind > (int)(sets[i]^sets[j]).count()){
                mind = (int)(sets[i]^sets[j]).count();
                ansSet = j;
            }
        }
        cout << ansSet + 1 << ' ' << mind << '\n';
    }
}

void threeSum() {
    const int N = 1e5 + 1;
    int n, s;
    cin >> n;
    bitset<N> a1, a2, a3;
    vector<int> b(n);

    fori(0, n, 1) {
        cin >> b[i];
        a1[b[i]] = 1;
    }
    
    for (int x : b)
        a2 |= a1 << x;
    
    for (int x : b)
        a3 |= a2 << x;

    cin >> s;

    if (a3[s] == 1)
        for (int x : b)
            if (a2[s - x])
                for (int y : b)
                    if (a1[s - x - y]) {
                        printf("%d %d %d\n", x, y, s - x - y);
                        return;
                    }
    
}


