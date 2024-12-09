#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

// Алгоритм:
// 1. Разделение входного массива на более мелкие сегменты, называемые «runs».
// Минимальный размер run (minrun) определяется на основе n.
// 2. Сортировка runs с помощью сортировки вставками.
// 3. Объединение соседних runs с помощью сортировки слияния.

const int MIN_RUN = 32;

void insertionSort(vector<int>& array, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= left && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void merge(vector<int>& array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    int i = 0; 
    int j = 0; 
    int k = left; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void timSort(vector<int>& array) {
    int n = array.size();

    for (int i = 0; i < n; i += MIN_RUN) {
        insertionSort(array, i, min((i + MIN_RUN - 1), (n - 1)));
    }

    for (int size = MIN_RUN; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = min(left + size - 1, n - 1); 
            int right = min((left + 2 * size - 1), (n - 1));

            if (mid < right) {
                merge(array, left, mid, right);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> P(n);

    for (int i = 0; i < n; i++) {
        cin >> P[i]; 
    }

    timSort(P); 

    for (int i = 0; i < n; i++) {
        cout << P[i] << " ";
    }
    cout << endl;

    return 0;
}

// Сложность алгоритма:
// В лучшем случае: O(n)
// В среднем: O(n log n)
// В худшем: O(n log n)
// Память: O(n)
// Устойчивость: Yes
// Обмены: O(n log n)
