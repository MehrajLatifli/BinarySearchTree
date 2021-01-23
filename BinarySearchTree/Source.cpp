#include<iostream>
using namespace std;

class TreeNode {
public:
	int data;
	TreeNode* right;
	TreeNode* left;
};

class BinarySearchTree {

	void insert(TreeNode*, int);
	bool search(int, TreeNode*);
	void inorder(TreeNode*);
	void preorder(TreeNode*);
	void postorder(TreeNode*);
public:
	TreeNode* root;
	BinarySearchTree()
	{
		root = NULL;
	}
	int max();
	int min();
	void insert(int);
	bool search(int data);
	void inorder();
	void preorder();
	void postorder();
	TreeNode* deleteNode(int);

};

void BinarySearchTree::insert(TreeNode* node, int data) {
	if (data < node->data) {
		if (node->left != NULL) {
			insert(node->left, data);
		}
		else {
			node->left = new TreeNode;
			node->left->data = data;
			node->left->left = NULL;
			node->left->right = NULL;
		}
	}
	else if (data >= node->data) {
		if (node->right != NULL) {
			insert(root->right, data);
		}
		else {
			node->right = new TreeNode;
			node->right->data = data;
			node->right->left = NULL;
			node->right->right = NULL;
		}

	}
}


void BinarySearchTree::insert(int data) {
	if (root != NULL) {
		insert(root, data);
	}
	else {
		root = new TreeNode;
		root->data = data;
		root->right = NULL;
		root->left = NULL;
	}
}


void BinarySearchTree::inorder(TreeNode* node) {
	if (node != NULL) {
		inorder(node->left);
		cout << node->data << " ";
		inorder(node->right);

	}
}

void BinarySearchTree::inorder() {
	if (root == NULL) {
		cout << " Tree is empty " << endl;

	}

	else {
		inorder(root);
	}
}


void BinarySearchTree::preorder(TreeNode* node) {
	if (node != NULL) {
		cout << node->data << " ";
		preorder(node->left);
		preorder(node->right);

	}


}

void BinarySearchTree::preorder() {
	if (root == NULL) {
		cout << " Tree is empty " << endl;

	}

	else {
		preorder(root);
	}
}


void BinarySearchTree::postorder() {
	if (root == NULL) {
		cout << " Tree is empty " << endl;

	}

	else {
		postorder(root);
	}
}

void BinarySearchTree::postorder(TreeNode* node) {
	if (node != NULL) {
		cout << node->data << " ";
		postorder(node->right);
		postorder(node->left);

	}


}

bool BinarySearchTree::search(int data) {
	if (root == NULL) {
		return false;
	}
	else {
		return search(data, root);
	}
}

bool BinarySearchTree::search(int data, TreeNode* node) {
	bool answer = false;
	if (node == NULL) {
		return false;
	}
	if (data == node->data) {
		return true;
	}
	else if (data < node->data) {
		answer = search(data, node->left);
		cout << " left ->";
	}
	else {

		answer = search(data, node->right);
		cout << " right ->";
	}
	return answer;
}

int BinarySearchTree::max() {
	TreeNode* temp = root;
	while (temp->right != NULL)
	{
		temp = temp->right;
	}
	return temp->data;
}

int BinarySearchTree::min() {
	TreeNode* temp = root;
	while (temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp->data;
}


int main() {
	BinarySearchTree bst;
	int data;
	cout << "\n                56 " << endl;
	cout << "                /\\ " << endl;
	cout << "               /  \\ " << endl;
	cout << "              /    \\ " << endl;
	cout << "             /      \\ " << endl;
	cout << "            /        \\ " << endl;
	cout << "           /          \\ " << endl;
	cout << "         42           72  " << endl;
	cout << "         /\\           /\\ " << endl;
	cout << "        /  \\         /  \\ " << endl;
	cout << "       /    \\       /    \\ " << endl;
	cout << "      17    47     57    75   " << endl;
	cout << endl << endl;
	bst.insert(56);
	bst.insert(42);
	bst.insert(17);
	bst.insert(47);
	bst.insert(72);
	bst.insert(57);
	bst.insert(75);
	cout << " Inorder: \t";
	bst.inorder();
	cout << endl;
	cout << " Preorder: \t";
	bst.preorder();
	cout << endl;
	cout << " Postorder: \t";
	bst.postorder();
	cout << endl;
	cout << "\n Max: \t" << bst.max();
	cout << endl;
	cout << "\n Min: \t" << bst.min();
	cout << endl;
	cout << "\n Enter the number for search: ";
	cin >> data;
	if (bst.search(data)) {
		cout << " " << data << " found. " << endl;
	}
	else {
		cout << " Data did not find. " << endl;
	}

}