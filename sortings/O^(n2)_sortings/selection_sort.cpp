// На i-ом шаге алгоритма находим минимальный среди последних n − i + 1
//, и меняем его местами с i - ым элементом в массиве.

#include <iostream>
#include <vector>

using namespace std;

vector<int> selection_sort(vector<int> vec, int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (vec[j] < vec[minIndex]) {
        minIndex = j;
      }
    }
    swap(vec[i], vec[minIndex]);
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

  vector<int> P1 = selection_sort(P, n);

  for (int i = 0; i < n; i++) {
    cout << P1[i];
  }

  return 0;
}

// Лучшее время: O(n^2)
// Среднее время: O(n^2)
// Худшее время: O(n^2)
// Память: O(1)
// Устойчивость: No
// Обмены (в среднем): O(n)
