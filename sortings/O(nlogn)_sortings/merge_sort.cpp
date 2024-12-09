#include <iostream>
#include <vector>

using namespace std;

// Реализация алгоритма сортировки слиянием на C++ с использованием using namespace std
// Алгоритм:
// 1. Рекурсивно разделите входной массив на две половины, пока каждый подмассив не будет содержать только один элемент.
// 2. Отсортируйте каждый из подмассивов индивидуально.
// 3. Объедините отсортированные подмассивы вместе, чтобы создать один полностью отсортированный массив. 
// Это достигается путем сравнения элементов двух подмассивов и их объединения в порядке возрастания.
// 4. Объединенный результат представляет собой отсортированный массив.
// Сложность алгоритма:
// В лучшем случае: O(n log n)
// В среднем: O(n log n)
// В худшем: O(n log n)

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

void mergeSort(vector<int>& array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}

void printArray(const vector<int>& array) {
    for (int i : array)
        cout << i << " ";
    cout << endl;
}

int main() {
    vector<int> array = {38, 27, 43, 3, 9, 82, 10};
    
    cout << "Исходный массив: ";
    printArray(array);

    mergeSort(array, 0, array.size() - 1);

    cout << "Отсортированный массив: ";
    printArray(array);

    return 0;
}
