#include <iostream>
#include <vector>
#include <algorithm> 
#include <queue>

using namespace std;

vector<int> patienceSort(vector<int>& array) {
    vector<vector<int>> piles;

    for (int card : array) {
        auto it = lower_bound(piles.begin(), piles.end(), vector<int>{card});

        if (it == piles.end()) {
            piles.push_back(vector<int>{card}); 
        } else {
            *it = vector<int>{card}; 
        }
    }

    vector<int> sortedArray;
    for (auto& pile : piles) {
        sortedArray.push_back(pile.back()); 
    }

    while (!sortedArray.empty()) {
        int minIndex = 0;
        for (int i = 1; i < piles.size(); ++i) {
            if (piles[i].back() < piles[minIndex].back()) {
                minIndex = i;
            }
        }
        sortedArray.push_back(piles[minIndex].back());
        piles[minIndex].pop_back(); // Убираем элемент из стопки

        if (piles[minIndex].empty()) {
            piles.erase(piles.begin() + minIndex);
        }
    }

    return sortedArray;
}

int main() {
    int n;
    cin >> n; 
    vector<int> P(n);

    for (int i = 0; i < n; i++) {
        cin >> P[i];
    }

    vector<int> sortedArray = patienceSort(P);

    for (int i = 0; i < sortedArray.size(); i++) {
        cout << sortedArray[i] << " ";
    }
    cout << endl;

    return 0;
}
// Сложность алгоритма: O(n log n)
// Память: O(n) — для хранения стопок
// Устойчивость: Нет (алгоритм не сохраняет относительный порядок равных элементов)
// Обмены: O(n log n)
