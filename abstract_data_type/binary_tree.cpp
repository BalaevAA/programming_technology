#include<iostream>

class BinTree {
public:
    BinTree() = default;
    BinTree(int value): data(value), left(nullptr), right(nullptr) {}
    BinTree* Insert(BinTree* root, int value);
    BinTree* Search(BinTree* root, int key);
    void Inorder(BinTree* root);
    int GetData(BinTree* a) {
        return (a == nullptr) ? 0 : a->data;
    }
private:
    int data = 0;
    BinTree* left = nullptr;
    BinTree* right = nullptr;
};


BinTree* BinTree::Search(BinTree* root, int key) {
	if (root == nullptr || root->data == key)
        return root;

	if (root->data < key)
        return Search(root->right, key);

	return Search(root->left, key);
}


BinTree* BinTree::Insert(BinTree* root, int value) {
    if(!root) {
        return new BinTree(value);
    }
    if(value > root->data) {
        root->right = Insert(root->right, value);
    } else {
        root->left = Insert(root->left, value);
    }
    return root;
}

void BinTree::Inorder(BinTree* root) {
    if(!root) return ;
    Inorder(root->left);
    std::cout << root->data << " ";
    Inorder(root->right);
}

int main() {
    BinTree a , *root = nullptr, *b = nullptr;
    root = a.Insert(root, 6);
    a.Insert(root, 4);
    a.Insert(root, 9);
    a.Insert(root, 1);
    a.Insert(root, 5);
    b = a.Search(root, 0);
    std::cout << a.GetData(b) << "   |    ";
    a.Inorder(root);
    return 0;
}
