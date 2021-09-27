#include <bits/stdc++.h>
using namespace std;

struct TreapNode {
	int key, priority;
	TreapNode *left = nullptr, *right = nullptr;
};

TreapNode *rightRotate(TreapNode *y) {
	TreapNode *x = y->left, *T2 = x->right;

	x->right = y;
	y->left = T2;

	return x;
}

TreapNode *leftRotate(TreapNode *x) {
	TreapNode *y = x->right, *T2 = y->left;

	y->left = x;
	x->right = T2;

	return y;
}

TreapNode* newNode(int key, int priority) {
	TreapNode* temp = new TreapNode;
	temp->key = key;
	temp->priority = priority;
	temp->left = temp->right = nullptr;
	return temp;
}

// C function to search a given key in a given BST
TreapNode* search(TreapNode* root, int key) {

	if (root == nullptr || root->key == key)
        return root;

	if (root->key < key)
        return search(root->right, key);

	return search(root->left, key);
}

TreapNode* insert(TreapNode* root, int key, int priority) {
	if (!root)
		return newNode(key, priority);

	if (key <= root->key) {
		root->left = insert(root->left, key, priority);
		if (root->left->priority > root->priority)
			root = rightRotate(root);
	} else {
		root->right = insert(root->right, key, priority);
		if (root->right->priority > root->priority)
			root = leftRotate(root);
	}
	return root;
}

TreapNode* deleteNode(TreapNode* root, int key) {
	if (root == NULL)
		return root;

	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	// IF KEY IS AT ROOT

	// If left is NULL
	else if (root->left == nullptr) {
		TreapNode *temp = root->right;
		delete(root);
		root = temp; // Make right child as root
	}

	// If Right is NULL
	else if (root->right == nullptr) {
		TreapNode *temp = root->left;
		delete(root);
		root = temp; // Make left child as root
	}

	// If ksy is at root and both left and right are not NULL
	else if (root->left->priority < root->right->priority) {
		root = leftRotate(root);
		root->left = deleteNode(root->left, key);
	}
	else {
		root = rightRotate(root);
		root->right = deleteNode(root->right, key);
	}

	return root;
}

// A utility function to print tree
void inorder(TreapNode* root) {
	if (root)
	{
		inorder(root->left);
		cout << "key: "<< root->key << " | priority:  "
			<< root->priority;

		if (root->left)
			cout << " | left child: " << root->left->key;

		if (root->right)
			cout << " | right child: " << root->right->key;
		cout << endl;

		inorder(root->right);
	}
}


int main() {
	TreapNode *root = nullptr;
	root = insert(root, 4, 6);
	root = insert(root, 0, 3);
	root = insert(root, 3, 3);
	root = insert(root, 2, 4);
	root = insert(root, 5, 1);
	root = insert(root, 6, 2);

	cout << "Inorder traversal of the given tree \n";
	inorder(root);

	cout << "\nTEST DELETE\n";
	root = deleteNode(root, 6);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	cout << "\nTEST DELETE\n";
	root = deleteNode(root, 4);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

    cout << "\nTEST SEARCH\n";
	TreapNode *res = search(root, 6);
	(res == NULL) ? cout << "Element Not Found \n":
				cout << "Element Found\n";

    cout << "\nTEST SEARCH\n";
	TreapNode *res1 = search(root, 3);
	(res1 == NULL) ? cout << "Element Not Found \n":
				cout << "Element Found\n";
	return 0;
}
