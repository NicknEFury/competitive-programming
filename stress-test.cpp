#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <functional>

using namespace std;

#define all(x) x.begin(), x.end()
#define fori(x, a, b) for (int i = x; i < a; i += b)
#define forj(x, a, b) for (int j = x; j < a; j += b)
#define fork(x, a, b) for (int k = x; k < a; k += b)

void exampleStressTestSimple(){
    int n = 10;
    vector<int> a(n);
    
    int tn = 0;
    while (true){
        printf("Test #%d\n", tn++);
        
        fori(0, n, 1) a[i] = rand() % 10;
        auto b = a;
        
        fori(0, n - 2, 1)
            forj(0, n - 1, 1)
                if (a[j] > a[j + 1])
                    swap(a[j], a[j + 1]);
        
        bool flag = 1;
        forj(0, n - 1, 1) if (a[j] > a[j + 1]) flag = 0;
        if (!flag){
            fori(0, n, 1) cout << b[i] << " ";
            cout << '\n';
            fori(0, n, 1) cout << a[i] << " ";
            cout << '\n';
            cout << "Found";
            break;
        }
    }
}

void exampleStressTestHard() {
    srand((int)time(0));
    int tn = 0;
    int l = 5;
    
    function<vector<int>(vector<int>&)> mergeSort = [&](vector<int>& a) {
        int n = (int)a.size();
        if (n <= 1)
            return a;
        
        int k = (n + 1) / 2;
        vector<int> left(a.begin(), a.begin() + k);
        vector<int> right(a.begin() + k, a.end());
        
        auto a1 = mergeSort(left);
        auto a2 = mergeSort(right);
        
        a1.push_back(INT_MAX);
        a2.push_back(INT_MAX);
        
        vector<int> res;
        int i = 0, j = 0;
        fork(0, n, 1) {
            if(a1[i] <= a2[j]) res.push_back(a1[i++]);
            else res.push_back(a2[j++]);
        }
        return res;
    };

    auto slowSolution = [&](vector<int>& a) {
        vector<int> tmp = a;
        sort(all(tmp));
        return tmp;
    };

    while(1) {
        printf("Test#%d\n", tn++);
        vector<int> a(l);
        fori(0, l, 1) a[i] = rand() % 11;
        
        vector<int> out = mergeSort(a);
        vector<int> ans = slowSolution(a);
        
        cout << "input = ";
        for(auto x : a) cout << x << " ";
        cout << "\noutput = ";
        for(auto x : out) cout << x << " ";
        cout << "\nanswer = ";
        for(auto x : ans) cout << x << " ";
        cout << "\n\n";
        
        if (out != ans) {
            cout << "ERROR!\n";
            break;
        }
    }
}
