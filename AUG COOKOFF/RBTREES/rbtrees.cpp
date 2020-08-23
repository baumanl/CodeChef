#include <bits/stdc++.h>
#define ll long long int
#define f(n) for(int i=0;i<n;i++)
#define p(x) cout<<x<<endl;
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

//notcompleted



struct Node
{
	vector<Node *>children;
	int key;
	char color;
}

Node *newNODE(int key)
{
	Node *temp = new Node;
	temp->key = key;
	return temp;
}

Node *find(int u, Node *root){
	if ((root->key) == u){
		return root;
	}else{
		if (!root->children.empty()){
			for (int i = 0; i < root->children.size(); i++){
				find(u, (root->children[i]));
			}
		}
	}
}

int main(){
	fastio;
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	int t, n, u, v;
	char c;
	cin>>t;
	while(t>0){
		t--;
		cin>>n;
		Node *root = newNODE(1);
		for (int i = 0; i < (n-1)*2; i++){
			cin>>u>>v;
			(find(u, root)->children).push_back(newNODE(v));
		}
		for (int i = 0; i < n; i++){
			cin>>c;
			(find(i, root)->color)=c;
			if (c == '0'){

			}
		}

	}

	return 0;
}