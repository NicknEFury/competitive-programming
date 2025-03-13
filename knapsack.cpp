#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <functional>
#include <utility>

#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < n; i++)

using namespace std;

int n, W;
vector<int> w;
vector<int> cost;

int knapsackEnumIter() {
    int ans = 0;
    forn(i, 1 << n) {
        int sum = 0;
        forn(j, 1 << n) {
            if (i & (1 << j)) {
                sum += w[j];
            }
        }
        if (sum <= W) {
            ans = max(ans, sum);
        }
    }
    return ans;
    //2**n * n
}

void knapsackEnumRecHelper(int i, int sum, int& ans) {
    if (i == n) {
        if (sum <= W) {
            ans = max(ans, sum);
        }
        return;
    }
    knapsackEnumRecHelper(i + 1, sum, ans);
    knapsackEnumRecHelper(i + 1, sum + w[i], ans);
    //2**n
}

int knapsackDP() {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    forn(i, n) {
        forn(j, W + 1) {
            dp[i + 1][j] = dp[i][j];
            if (j >= w[i]) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - w[i]] + w[i]);
            }
        }
    }
    return dp[n][W];
    //n * W
}

int knapsackDPBoolean() {
    vector<vector<char>> f(n + 1, vector<char>(W + 1, false));
    f[0][0] = true;
    
    forn(i, n) {
        forn(x, W + 1) {
            f[i + 1][x] = f[i][x];
            if (x >= w[i] && f[i][x - w[i]]) {
                f[i + 1][x] = true;
            }
        }
    }

    for (int x = W; x >= 0; x--) {
        if (f[n][x]) 
            return x;
    }
    return 0;
}

bool knapsackMeetInTheMiddle(){
    vector<int> A, B;

    function<void(int,int,int, vector<int>&)> f = [&](int i, int end, int sum, vector<int>& ans){
        if (i == end){
            ans.push_back(sum);
            return;
        }
        f(i + 1, end, sum, ans);
        f(i + 1, end, sum + w[i], ans);
    };

    f(0, n / 2, 0, A);
    f(n / 2, n, 0, B);

    unordered_set<int> table;
    for (int a : A) table.insert(a);
    for (int b : B) 
        if (table.count(W - b))
            return true;

    return false;    


    //2**(n/2)
}

int knapsackMeetInTheMiddleCost(){
    vector<pair<int, int>> A, B;

    function<void(int, int, int, int, vector<pair<int,int>>&)> f = [&](int i, int end, int sw, int sc, vector<pair<int,int>>& v){
        if (i == end){
            v.push_back({sw, sc});
            return;
        }
        f(i + 1, end, sw, sc, v);
        f(i + 1, end, sw + w[i], sc + cost[i], v);
    };

    f(0, n / 2, 0, 0, A);
    f(n / 2, n, 0, 0, B);

    sort(all(A));
    sort(all(B));

    int j = 0, maxCost = 0, ans = 0;
    for (int i = A.size() - 1; i >= 0; i--){
        while (j < B.size() && B[j].first + A[i].first <= W){
            maxCost = max(maxCost, B[j].second);
            j++;
        }
        ans = max(ans, A[i].second + maxCost);
    }
    return ans;
}

int main() {
    cin >> n >> W;
    w.resize(n);
    cost.resize(n);
    forn (i, n)
        cin >> w[i] >> cost[i];
    
    cout << knapsackMeetInTheMiddleCost();
    return 0;
}

