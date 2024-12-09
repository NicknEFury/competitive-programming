#include <iostream>
#include <vector>

using namespace std;

// Алгоритм:
// 1. Преобразование входного массива в максимальную кучу.
// 2. Начиная с конца кучи (последний элемент массива), поменяйте местами корневой элемент (максимальный элемент в куче) с последним элементом.
// 3. После каждой замены уменьшите размер кучи на единицу и убедитесь, что свойство max-heap сохраняется для остальных элементов.
// 4. Повторяйте этот процесс, пока весь массив не будет отсортирован.

void heapify(vector<int>& array, int n, int i) {
    int largest = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest != i) {
        swap(array[i], array[largest]);

        heapify(array, n, largest);
    }
}

void heapSort(vector<int>& array) {
    int n = array.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

int main() {
    int n;
    cin >> n; 
    vector<int> P(n);

    for (int i = 0; i < n; i++) {
        cin >> P[i]; 
    }

    heapSort(P); 

    for (int i = 0; i < n; i++) {
        cout << P[i] << " "; 
    }
    cout << endl;

    return 0;
}

// Сложность алгоритма: O(n log n) в любом случае
// Память: O(1) — не требует дополнительной памяти для сортировки
// Устойчивость: Нет (алгоритм не сохраняет относительный порядок равных элементов)
// Обмены: O(n log n) — каждый элемент перемещается несколько раз
