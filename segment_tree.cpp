//#include <vector>
//
//#define all(x) x.begin(), x.end()
//#define fori(x, a, b) for (int i = x; i < a; i += b)
//#define forj(x, a, b) for (int j = x; j < a; j += b)
//
//struct SegmentTreeBasic {
//    vector<int> t;
//
//    SegmentTreeBasic(vector<int> a) {
//        int n = (int)a.size();
//        t.resize(4 * n);
//        build(a, 1, 0, n - 1);
//    }
//
//    void build(vector<int> a, int v, int tl, int tr) {
//        if (tl == tr) {
//            t[v] = a[tl];
//        } else {
//            int tm = (tl + tr) / 2;
//            build(a, v * 2, tl, tm);
//            build(a, v * 2 + 1, tm + 1, tr);
//            t[v] = t[v * 2] + t[v * 2 + 1];
//        }
//    }
//
//    int sum(int v, int tl, int tr, int l, int r) {
//        if (l > r) {
//            return 0;
//        }
//        if (l == tl && r == tr) {
//            return t[v];
//        }
//        int tm = (tl + tr) / 2;
//        return sum(v * 2, tl, tm, l, min(r, tm)) +
//               sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
//    }
//
//    void update(int v, int tl, int tr, int pos, int x) {
//        if (tl == tr) {
//            t[v] = x;
//        } else {
//            int tm = (tl + tr) / 2;
//            if (pos <= tm) {
//                update(v * 2, tl, tm, pos, x);
//            } else {
//                update(v * 2 + 1, tm + 1, tr, pos, x);
//            }
//            t[v] = t[v * 2] + t[v * 2 + 1];
//        }
//    }
//    
//    int func(int l, int r){
//        return sum(1, 0, n - 1, l, r);
//    }
//};
//
//struct SegmentTreeVectors {
//    vector<vector<int>> tree;
//    int n;
//
//    void build(int v, int tl, int tr, vector<int> arr) {
//        if (tl == tr) {
//            tree[v].push_back(arr[tl]);
//            return;
//        }
//        int tm = (tl + tr) / 2;
//        build(2 * v, tl, tm, arr);
//        build(2 * v + 1, tm + 1, tr, arr);
//        merge(
//            all(tree[2 * v]),
//            all(tree[2 * v + 1]),
//            back_inserter(tree[v])
//        );
//    }
//
//    int query(int v, int tl, int tr, int l, int r, int x) {
//        if (tr < l || tl > r) return 0;
//        if (l <= tl && tr <= r) {
//            return upper_bound(tree[v].begin(), tree[v].end(), x) - tree[v].begin();
//        }
//        int m = (tl + tr) / 2;
//        return query(2 * v, tl, m, l, r, x) +
//               query(2 * v + 1, m + 1, tr, l, r, x);
//    }
//
//    SegmentTreeVectors(vector<int> arr) {
//        n = (int)arr.size();
//        tree.resize(4 * n);
//        build(1, 0, n - 1, arr);
//    }
//
//    int func(int L, int R, int x) {
//        return query(1, 0, n - 1, L, R, x);
//    }
//};
