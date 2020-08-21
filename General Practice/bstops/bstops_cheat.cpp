#include <iostream>
using namespace std;

//this is not my code. copied from https://www.codechef.com/viewsolution/28036241
//my code was pretty close, but I didn't realize I should pass in pos as an argument 
//instead of as a property of my class/struct definition. 

struct node {
	int data;
	int pos;
	node* left;
	node* right;
};

node* Insert(node* root, int data, int pos){
	if (root == NULL){
		cout << pos << "\n";
		node* n = new node();
		n->data = data;
		n->pos = pos;
		n->left = NULL;
		n->right = NULL;
		return n;
	}
	else if(data < root->data){
		root->left = Insert(root->left, data, 2*pos);
		return root;
	}else{
		root->right = Insert(root->right, data, 2*pos+1);
		return root;
	}
}

node* Delete(node* root, int data){
	if (root == NULL) return root;
	if (data < root->data){
		root->left = Delete(root->left, data);
	}else if(data > root->data){
		root->right = Delete(root->right, data);
	}else{
		cout << root->pos << "\n";
		if(root->left == NULL){
			node* temp = root->right;
			delete root;
			return temp;
		}else if(root->right == NULL){
			node* temp = root->left;
			delete root;
			return temp;
		}else{
			node* temp = root->right;
			while(temp->left){
				temp = temp->left;
			}
			root->data = temp->data;
			root->right = Delete(root->right, root->data);
		}
	}
}

int main(){
	node* root = NULL;
	int t;
	cin >> t;
	while(t--){
		char ch;
		int a;
		cin >> ch >> a;
		if(ch == 'i'){
			root = Insert(root,a,1);
		}else{
			root = Delete(root,a);
		}
	}
	return 0;
}