// К этим сортировкам относятся те, чье лучшее время O(n)

// Алгоритм состоит в повторяющихся проходах по сортируемому массиву.
// На каждой итерации последовательно сравниваются соседние элементы.
// Если порядок в паре неверный, то элементы меняют местами.

#include <iostream>
#include <vector>

using namespace std;

vector<int> advanced_bubble_sort(vector<int> vec, int n) {
  for (int i = 0; i < n; i++) {
    bool swapped = false;
    for (int j = 0; j < n - i - 1; j++) {
      if (vec[j] > vec[j + 1]) {
        swap(vec[j], vec[j + 1]);
        swapped = true;
      }
    }
    if (!swapped) break;
  }
  return vec;
}

int main() {
  long long n;
  cin >> n;
  vector<int> P(n);

  for (int i = 0; i < n; i++) {
    cin >> P[i];
  }

  vector<int> P1 = advanced_bubble_sort(P, n);

  return 0;
}

// Лучшее время: O(n)
// Среднее время: O(n^2)
// Худшее время: O(n^2)
// Память: O(1)
// Устойчивость: Yes
// Обмены (в среднем): O(n^2)
