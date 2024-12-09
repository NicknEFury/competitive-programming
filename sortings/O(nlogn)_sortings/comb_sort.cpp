#include <iostream>
#include <vector>

using namespace std;

// Алгоритм:
// Шаг 1: Инициализируем gap. Обычно он равен длине массива, деленной на 1,3.
// Шаг 2: Сравниваем элементы, расположенные на текущем промежутке. Если элементы не в правильном порядке, поменяйте их местами.
// Шаг 3: Каждый раз по окончании прохода через весь массив с текущим значением gap, мы уменьшаем его на фиксированный коэффициент 1,3.
// Шаг 4: Когда gap = 1, выполните последний проход по массиву. Наш массив отсортирован.

void combSort(vector<int>& array) {
    int n = array.size();
    float gap = n; 
    bool swapped = true;

    while (gap > 1 || swapped) {
        gap = gap / 1.3;
        int intGap = static_cast<int>(gap);
        swapped = false; 

        for (int i = 0; i + intGap < n; i++) {
            if (array[i] > array[i + intGap]) {
                swap(array[i], array[i + intGap]);
                swapped = true; 
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

    combSort(P); 

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        cout << P[i] << " ";
    }
    cout << endl;

    return 0;
}
// Сложность алгоритма: O(n log(n))
// Память: O(1) — не требует дополнительной памяти для сортировки
// Устойчивость: Нет (алгоритм не сохраняет относительный порядок равных элементов)
// Обмены: O(n) — в среднем происходит O(n log n) обменов
