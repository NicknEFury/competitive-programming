// Является модификацией сортировки вставками.
// Сортируем между собой элементы,
// стоящие на кратных нашему шагу местах.

#include <iostream>
#include <vector>

using namespace std;

vector<int> shell_sort(vector<int> vec, int n) {
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
      int temp = vec[i];
      int j;
      for (j = i; j >= gap && vec[j - gap] > temp; j -= gap) {
        vec[j] = vec[j - gap];
      }
      vec[j] = temp;
    }
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

  vector<int> P1 = shell_sort(P, n);

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
