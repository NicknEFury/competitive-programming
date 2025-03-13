using namespace std;

static const int NUMBERS = 0;

class Node {
private:
    int value, number;
    Node* left;
    Node* right;
public:
    Node(int v) {
        this->value = v;
        this->number = 1;
        this->left = nullptr;
        this->right = nullptr;
    }

    int GetValue() const {
        return value;
    }

    int GetNumber() const {
        return number;
    }

    int CountChilds() {
        return (this->left != nullptr) + (this->right != nullptr);
    }

    void add(int v) {
        if (v > this->value) {
            if (this->right == nullptr)
                this->right = new Node(v);
            else
                this->right->add(v);
        } else if (v < this->value) {
            if (this->left == nullptr) {
                this->left = new Node(v);
            }
            else
                this->left->add(v);
        }
        else this->number++;
    }

    int SubtreeSize() {
        return (this->left != nullptr ? this->left->SubtreeSize() : 0) + (this->right != nullptr ? this->right->SubtreeSize() : 0) + 1;
    }

    int SubtreeHeight() {
        return max((this->left != nullptr ? this->left->SubtreeHeight() : 0), (this->right != nullptr ? this->right->SubtreeHeight() : 0)) + 1;
    }

    int IsBalanced() {
        int LeftHeight = (this->left != nullptr ? this->left->IsBalanced() : 0);
        int RightHeight = (this->right != nullptr ? this->right->IsBalanced() : 0);
        if (min(LeftHeight, RightHeight) == -1)
            return -1;
        return (abs(LeftHeight - RightHeight) > 1 ? -1 : max(LeftHeight, RightHeight) + (NUMBERS ? this->number : 1));
    }

    int FindMaximum() {
        return (this->right != nullptr ? this->right->FindMaximum() : this->value);
    }

    int FindSecondMaximum(int v) {
        if (this->right == nullptr)
            return (this->left != nullptr ? this->left->FindMaximum() : v);
        return this->right->FindSecondMaximum(this->value);
    }

    void PrintSubtree() {
        if (this->left != nullptr)
            this->left->PrintSubtree();
        if (NUMBERS) cout << this->value << " " << this->number << "\n";
        else cout << this->value << "\n";
        if (this->right != nullptr)
            this->right->PrintSubtree();
    }

    void PrintLeaves() {
        if (this->left != nullptr)
            this->left->PrintLeaves();
        if (this->left == nullptr && this->right == nullptr) {
            if (NUMBERS) cout << this->value << " " << this->number << "\n";
            else cout << this->value << "\n";
        }
        if (this->right != nullptr)
            this->right->PrintLeaves();
    }

    void Print(int k) {
        if (this->left != nullptr)
            this->left->Print(k);
        if (this->CountChilds() == k) {
            if (NUMBERS) cout << this->value << " " << this->number << "\n";
            else cout << this->value << "\n";
        }
        if (this->right != nullptr)
            this->right->Print(k);
    }
};
