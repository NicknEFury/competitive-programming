// Алгоритм:
//  1. Инициализируйте переменную pos значением 0.
//  2. Для каждого элемента массива сравните его со всеми остальными элементами
//  справа от него. Если есть какие - либо элементы, которые меньше текущего
//  элемента, увеличьте pos.
//  3. Если pos по - прежнему равен 0 после сравнения первого элемента со всеми
//  остальными элементами, перейдите к следующему элементу и повторите шаг 2.
//  4. Как только будет найден меньший элемент, замените текущий элемент первым
//  элементом в его цикле. Затем цикл продолжается до тех пор, пока текущий
//  элемент не вернется в исходное положение.

#include <iostream>
#include <vector>

using namespace std;

vector<int> cycle_sort(vector<int> vec, int n) {
  for (int cycleStart = 0; cycleStart < n - 1; cycleStart++) {
    int item = vec[cycleStart];
    int pos = cycleStart;

    for (int i = cycleStart + 1; i < n; i++) {
      if (vec[i] < item) {
        pos++;
      }
    }

    if (pos == cycleStart) {
      continue;
    }

    while (item == vec[pos]) {
      pos++;
    }

    swap(item, vec[pos]);

    while (pos != cycleStart) {
      pos = cycleStart;

      for (int i = cycleStart + 1; i < n; i++) {
        if (vec[i] < item) {
          pos++;
        }
      }

      while (item == vec[pos]) {
        pos++;
      }

      swap(item, vec[pos]);
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

  vector<int> P1 = cycle_sort(P, n);

  for (int i = 0; i < n; i++) {
    cout << P1[i];
  }

  return 0;
}

// Лучшее время: O(n)
// Среднее время: O(n^2)
// Худшее время: O(n^2)
// Память: O(1)
// Устойчивость: No
// Обмены (в среднем): O(n)
