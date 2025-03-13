#include <vector>

using namespace std;

bool binsearch(int n, vector<int> &arr, int ans) {
    int l = 0, r = n;
    while (l <= r) {
        int m = (l + r) / 2;
        if (arr[m] > ans)
            r = m - 1;
        else if (arr[m] < ans)
            l = m + 1;
        else
            return true;
    }
    return false;
}

int lbinsearch(int n, vector<int> &arr, int ans) {
    int l = -1, r = n - 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (arr[m] >= ans)
            r = m;
        else l = m;
    }
    return r;
}

int rbinsearch(int n, vector<int> &arr, int ans) {
    int l = 0, r = n;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (arr[m] > ans)
            r = m;
        else l = m;
    }
    return l;
}

int nearestbinsearch(int n, vector<int> &arr, int x) {
    int l = 0, r = n - 1;
    if (x < arr[0]) {
        return 0;
    }
    if (x > arr[r]) {
        return r;
    }
    int mid;
    while (r - l > 1) {
        mid = (l + r) / 2;
        if (arr[mid] < x)
            l = mid;
        else
            r = mid;
    }
    if (x - arr[l] <= arr[r] - x)
        return l;
    else
        return r;

}
