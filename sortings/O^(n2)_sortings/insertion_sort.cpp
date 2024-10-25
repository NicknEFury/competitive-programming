// На каждом шаге алгоритма мы выбираем один из элементов входных данных
// и вставляем его на нужную позицию в уже отсортированной части массива до
// тех пор, пока весь набор входных данных не будет отсортирован.

#include <iostream>
#include <vector>

using namespace std;

vector<int> insertion_sort(vector<int> vec, int n) {
  for (int i = 1; i < n; i++) {
    int key = vec[i];
    int j = i - 1;
    while (j >= 0 && vec[j] > key) {
      vec[j + 1] = vec[j];
      j--;
    }
    vec[j + 1] = key;
  }
  return vec;
}

int main() {
  int n;
  cin >> n;
  vector<int> P(n);

  for (int i = 0; i < n; i++) {
    cin >> P[i];
  }

  vector<int> P1 = insertion_sort(P, n);

  for (int i = 0; i < n; i++) {
    cout << P1[i];
  }

  return 0;
}

// Лучшее время: O(n log2 n)
// Среднее время: Нельзя сказать
// Худшее время: O(n^2)
// Память: O(1)
// Устойчивость: No
// Обмены (в среднем): O(n)
