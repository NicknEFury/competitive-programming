// Алгоритм:
// 1. Проход вправо :
// Сравниваем соседние элементы с крайнего левого элемента.
// Если текущий элемент больше следующего элемента, меняем их местами.
// Продолжайте этот процесс, перемещаясь слева направо, пока не дойдете до
// конца списка.После этого прохода самый большой элемент «всплывает» в конец
// списка.

// 2. Проход влево :
// Теперь выполните проход справа налево, сравнивая и меняя местами соседние
// элементы.
// Если текущий элемент меньше предыдущего, поменяйте их местами.
// Продолжайте этот процесс, перемещаясь справа налево, но остановитесь перед
// последним отсортированным элементом.После этого прохода наименьший элемент
// «всплывает» в начало списка.

#include <iostream>
#include <vector>

using namespace std;

vector<int> shaker_sort(vector<int> vec, int n) {
  bool swapped = true;
  int start = 0;
  int end = n - 1;

  while (swapped) {
    swapped = false;

    for (int i = start; i < end; i++) {
      if (vec[i] > vec[i + 1]) {
        swap(vec[i], vec[i + 1]);
        swapped = true;
      }
    }

    if (!swapped) break;

    swapped = false;
    end--;

    for (int i = end - 1; i >= start; i--) {
      if (vec[i] > vec[i + 1]) {
        swap(vec[i], vec[i + 1]);
        swapped = true;
      }
    }

    start++;
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

  vector<int> P1 = shaker_sort(P, n);

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
// Обмены (в среднем): O(n^2)
