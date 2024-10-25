// Необычный и в значительной степени непрактичный алгоритм сортировки,
// основанный на принципах подсчета.
//
// Каждый элемент несортированного списка представляет собой набор бусинок на
// наборе стержней. Каждый стержень соответствует индексу, а количество бусин на
// каждом стержне представляет значение этим индексом в массиве. Пусть сила
// тяжести потянет бусины вниз, заставляя их скапливаться в нижней части каждого
// стержня. Количество бусин в каждой стопке соответствует количеству элементов
// с определенной цифрой в несортированном списке. После того, как сила тяжести
// потянет бусины вниз, перенесите бусины со стержней обратно в исходный список,
// сформировав новый список.

#include <iostream>
#include <vector>

using namespace std;

vector<int> bead_sort(vector<int> arr, int n) {
  int maxVal = *max_element(arr.begin(), arr.end());
  vector<vector<bool>> beads(n, vector<bool>(maxVal, false));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < arr[i]; j++) {
      beads[i][j] = true;
    }
  }

  for (int j = 0; j < maxVal; j++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (beads[i][j]) {
        sum++;
        beads[i][j] = false;
      }
    }
    for (int i = n - sum; i < n; i++) {
      beads[i][j] = true;
    }
  }

  vector<int> result(n);
  for (int i = 0; i < n; i++) {
    int count = 0;
    for (int j = 0; j < maxVal && beads[i][j]; j++) {
      count++;
    }
    result[i] = count;
  }

  return result;
}

int main() {
  int n;
  cin >> n;
  vector<int> P(n);

  for (int i = 0; i < n; i++) {
    cin >> P[i];
  }

  vector<int> P1 = bead_sort(P, n);

  for (int i = 0; i < n; i++) {
    cout << P1[i];
  }

  return 0;
}

// Лучшее время: O(n)
// Среднее время: O(n * sqrt(n))
// Худшее время: O(n^2)
// Память: O(n * maxVal)
// Устойчивость: No
// Обмены (в среднем): O(n * sqrt(n))
