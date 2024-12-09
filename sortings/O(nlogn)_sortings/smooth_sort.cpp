#include <iostream>
#include <vector>

using namespace std;

// Реализация алгоритма плавной сортировки на C++ с использованием using namespace std
// Алгоритм:
// Smoothsort — это модификация сортировки кучей, которая использует K-ую кучу Леонардо вместо двоичной кучи.
// 1. Создайте последовательность куч Леонардо, которая формирует массив.
// 2. Сортируйте элементы, добавляя их в окончательную кучу.
// 3. Выполните слияние для получения отсортированного результата.

void smoothsort(vector<int>& array) {
    int n = array.size();
    if (n < 2) return; 

    vector<int> heap;

    for (int i = 0; i < n; i++) {
        heap.push_back(array[i]);
        int j = heap.size() - 1;

        while (j > 0) {
            int p = (j - 1) / 2;
            if (heap[j] > heap[p]) {
                swap(heap[j], heap[p]); 
                j = p; 
            } else {
                break;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        array[i] = heap[0];
        heap[0] = heap.back(); 
        heap.pop_back(); 


        int j = 0;
        while (true) {
            int left = 2 * j + 1;
            int right = 2 * j + 2;
            int largest = j;

            if (left < heap.size() && heap[left] > heap[largest])
                largest = left;

            if (right < heap.size() && heap[right] > heap[largest])
                largest = right;

            if (largest != j) {
                swap(heap[j], heap[largest]); 
                j = largest;
            } else {
                break;
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

    smoothsort(P);

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
// Память: O(1)
// Устойчивость: Нет
// Обмены: O(n log n)
