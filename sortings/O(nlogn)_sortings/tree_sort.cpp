#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// Добавляем по очереди вершины в сбалансированное дерево поиска, проходим по всем вершинам в порядке возрастания.

class TreeNode {
public:
    int value;
    unique_ptr<TreeNode> left;
    unique_ptr<TreeNode> right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    unique_ptr<TreeNode> root;

    void insert(int value) {
        root = insertHelper(move(root), value);
    }

    void inOrderTraversal(vector<int>& sortedArray) {
        inOrderHelper(root.get(), sortedArray);
    }

private:
    unique_ptr<TreeNode> insertHelper(unique_ptr<TreeNode> node, int value) {
        if (!node) {
            return make_unique<TreeNode>(value);
        }
        if (value < node->value) {
            node->left = insertHelper(move(node->left), value);
        } else {
            node->right = insertHelper(move(node->right), value);
        }
        return move(node);
    }

    void inOrderHelper(TreeNode* node, vector<int>& sortedArray) {
        if (!node) return;
        inOrderHelper(node->left.get(), sortedArray);
        sortedArray.push_back(node->value);
        inOrderHelper(node->right.get(), sortedArray);
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
    cin >> n;
    vector<int> P(n);

    for (int i = 0; i < n; i++) {
        cin >> P[i];
    }

    vector<int> sortedArray = treeSort(P);

    for (int i = 0; i < sortedArray.size(); i++) {
        cout << sortedArray[i] << " "; 
    }
    cout << endl;

    return 0;
}

// Сложность алгоритма:
// В лучшем случае: O(n)
// В среднем: O(n log n)
// В худшем: O(n log n)
// Память: O(n)
// Устойчивость: Да
// Обмены: O(n)
