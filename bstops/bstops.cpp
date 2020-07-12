#include <iostream>
#include <vector>
using namespace std;

//This challenge is to implement a binary search tree. Oh boy. take me back to CS384.
//This seems to work on all the cases I can think to give it, but it seg faults on the website.
//see bstops_cheat.cpp to see the code i copied from someone else (to practice).


class BST {
public:
	BST * left;
	BST * right;
	BST * parent;
	int key;
	unsigned long int pos;
	unsigned long int value;
	BST(int root, BST * prnt);
	void insert(int x);
	void delete_val(int x);
	BST * find_right();
};

BST::BST(int root, BST * prnt) {
	parent = prnt;
	if(prnt != nullptr){
		if(root < prnt->key){
			pos = 2*(prnt->pos);
		}else{
			pos = ((2*prnt->pos)+1);
		}
	}else{
		pos = 1;
	}
	value = pos;
	key = root;
	left = nullptr;
	right = nullptr;
}

BST * BST::find_right(){
	if(right != nullptr){
		right->find_right();
	}else{
		if(left != nullptr){
			parent->right = left;
		}else{
			parent->right = nullptr;
		}
		return this;
	}
}

void BST::insert(int x){
	if (x < key){
		if(left != nullptr){
			left->insert(x);
		}
		else{
			left = new BST(x, this);
			std::cout<<left->value<<"\n";
		}
	}else{
		if(right != nullptr){
			right->insert(x);
		}
		else{
			right = new BST(x, this);
			std::cout<<right->value<<"\n";
		}
	}
}

void BST::delete_val(int x){
	if (x == key){
		//root node
		if (left == nullptr && right == nullptr){
			//no children
			if (key > (parent->key)){
				parent->right = nullptr;
				std::cout<<this->value<<"\n";
			}else{
				parent->left = nullptr;
				std::cout<<this->value<<"\n";
			}
		}else if (left == nullptr && right != nullptr){
			if (key < parent->key){
				parent->left = right;
			}else{
				parent->right = right;
			}
			std::cout<<this->value<<"\n";
		}else if (right == nullptr && left != nullptr){
			if (key < parent->key){
				parent->left = left;
			}else{
				parent->right = left;
			}
			std::cout<<this->value<<"\n";
		}else{
			std::cout<<this->value<<"\n";
			//find rightmost value of left subtree
			BST *child = left->find_right();
			key = child->key;
			value = child->value;
		}
	}else if(x < key){
		//go left to find
		left->delete_val(x);
	}else{
		//go right to find
		right->delete_val(x);
	}
}


int main() {
	//get number of ops to perform
	int q;
	cin >> q;

	//get first insertion to make base tree
	char op;
	cin >> op;
	int root;
	cin >> root;
	BST tree(root, nullptr);
	std::cout<<tree.value<<"\n";

	//process all the input instructions
	vector<char> ops;
	vector<int> nums;
	while(q-- > 1){
		cin >> op;
		ops.push_back(op);
		cin >> root;
		nums.push_back(root);
	}

	//loop to actually modify the tree
	for (int i = 0; i < ops.size(); i++){
		if(ops[i] == 'i'){
			tree.insert(nums[i]);
		}else{
			tree.delete_val(nums[i]);
		}
	}
	
return 0;
}


