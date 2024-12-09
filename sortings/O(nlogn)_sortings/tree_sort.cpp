#include <iostream>
#include <vector>

using namespace std;

// Добавляем по очереди вершины в сбалансированное дерево поиска, проходим по всем вершинам в порядке возрастания.

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertHelper(root, value);
    }

    void inOrderTraversal(vector<int>& sortedArray) {
        inOrderHelper(root, sortedArray);
    }

private:
    TreeNode* insertHelper(TreeNode* node, int value) {
        if (!node) {
            return new TreeNode(value);
        }
        if (value < node->value) {
            node->left = insertHelper(node->left, value);
        } else {
            node->right = insertHelper(node->right, value);
        }
        return node;
    }

    void inOrderHelper(TreeNode* node, vector<int>& sortedArray) {
        if (!node) return;
        inOrderHelper(node->left, sortedArray);
        sortedArray.push_back(node->value);
        inOrderHelper(node->right, sortedArray);
    }
};

vector<int> treeSort(vector<int>& array) {
    BinaryTree tree;
    for (int value : array) {
        tree.insert(value);
    }

    vector<int> sortedArray;
    tree.inOrderTraversal(sortedArray);
    return sortedArray;
}

int main() {
    int n;
    cin >> n; // Ввод размера массива
    vector<int> P(n);

    for (int i = 0; i < n; i++) {
        cin >> P[i]; // Ввод элементов массива
    }

    vector<int> sortedArray = treeSort(P); // Применение сортировки с помощью бинарного дерева

    for (int i = 0; i < sortedArray.size(); i++) {
        cout << sortedArray[i] << " "; // Вывод отсортированного массива
    }
    cout << endl;

    return 0;
}

// Сложность алгоритма:
// В лучшем случае: O(n)
// В среднем: O(n log n)
// В худшем: O(n log n)
// Память: O(n) — для хранения узлов дерева
// Устойчивость: Да (сохраняет относительный порядок равных элементов)
// Обмены: O(n)
