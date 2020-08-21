#include <iostream>
using namespace std;

struct BST
{
	BST *left, *right, *parent;
	int key;
	unsigned long int pos;
	unsigned long int val;

	BST();
	BST(int k);
	BST * Insert(BST *root, int k);
	BST * delete_val(BST *root, int k);	
};

BST::BST(){
	left = right = parent = NULL;
	key = pos = val = 0;
}

BST::BST(int k){
	left = right = parent = NULL;
	key = k;
	pos = 1;
	val = 0;
}

BST* BST::Insert(BST *root, int k){
	if(!root){
		BST *temp = new BST(k);
		cout<<temp->val<<endl;
		return temp;
	}else if (k > root->key){
		root->right = Insert(root->right, k);
		root->right->pos = root->right->val = 2*(root->pos)+1;
		root->right->parent = root;
	}else{
		root->left = Insert(root->left, k);
		root->left->pos = root->left->val = 2*(root->pos);
		root->left->parent = root;
	}
	return root;
}

int main() {
	int q;
	cin >> q;

	char op;
	int k;
	BST b, *root = NULL;
	cin >> op;
	cin >> k;
	root = b.Insert(root, k);
	while (q-- > 1){
		cin >> op;
		cin >> k;
		if (op == 'i'){
			b.Insert(root, k);
		}else{
			//b.Delete(root, k);
		}
	}
	return 0;
}