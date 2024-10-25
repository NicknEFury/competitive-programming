// Пусть input[] — входной список, а output[] — выходной список.
//
// 1. Создайте еще один пустой список sublist и переместите в него первый
// элемент input.
// 2. Для каждого элемента x из input проверьте, превышает ли x последний
// добавленный элемент в список. Если да, удалите x из input и добавьте в конец
// sublist. Если нет, игнорируйте x(сохраните его в input)
// 3. Объединить подсписок в outputp.
//
// Повторите для оставшихся элементов в input и текущих элементов в output.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> strand_sort(vector<int> arr) {
  vector<int> output;

  while (!arr.empty()) {
    vector<int> sublist;
    sublist.push_back(arr[0]);
    arr.erase(arr.begin());

    for (auto it = arr.begin(); it != arr.end();) {
      if (*it > sublist.back()) {
        sublist.push_back(*it);
        it = arr.erase(it);
      } else {
        it++;
      }
    }

    output.insert(output.end(), sublist.begin(), sublist.end());
  }

  return output;
}
int main() {
  int n;
  cin >> n;
  vector<int> P(n);

  for (int i = 0; i < n; i++) {
    cin >> P[i];
  }

  vector<int> P1 = strand_sort(P);

  for (int i = 0; i < n; i++) {
    cout << P1[i];
  }

  return 0;
}

// Лучшее время: O(n log n)
// Среднее время: O(n^2)
// Худшее время: O(n^2)
// Память: O(n)
// Устойчивость: Yes
// Обмены (в среднем): O(n log n)
