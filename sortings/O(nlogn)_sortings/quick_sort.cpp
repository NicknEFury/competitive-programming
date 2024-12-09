#include <iostream>
#include <vector>

using namespace std;

// Реализация алгоритма быстрой сортировки на C++ с использованием using namespace std
// Алгоритм:
// 1. Выбор «pivot» из входного массива. (Его выбор может существенно повлиять на производительность алгоритма.
// Это может быть: первый, последний или случайный элемент).
// 2. Разделение элементов массива так, чтобы все элементы меньше «pivot» находились перед ним,
// а все элементы выше «pivot» — после него.
// 3. Рекурсивное применение алгоритма быстрой сортировки к подмассиву элементов, меньших опорного,
// и к подмассиву элементов, превышающих опорный.
// 4. Продолжайте этот процесс, пока весь массив не будет отсортирован.

int partition(vector<int>& array, int low, int high) {
    int pivot = array[high];
    int i = low - 1; 

    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            swap(array[i], array[j]); 
        }
    }
    swap(array[i + 1], array[high]); 
    return i + 1; 
}

void quickSort(vector<int>& array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);

        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}


int main() {
    int n;
    cin >> n; 
    vector<int> P(n);

    for (int i = 0; i < n; i++) {
        cin >> P[i]; 
    }

    quickSort(P, 0, n - 1); 

    for (int i : P)
        cout << i << " ";

    return 0;
}

// Сложность алгоритма:
// В лучшем случае: O(n log n)
// В среднем: O(n log n)
// В худшем: O(n^2)
// Память: O(log n)
// Устойчивость: Нет
// Обмены (в среднем): O(n)
