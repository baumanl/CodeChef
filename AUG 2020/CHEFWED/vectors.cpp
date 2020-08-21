#include <bits/stdc++.h>
#define ll long long int
#define f(n) for(int i=0;i<n;i++)
#define p(x) cout<<x<<endl;
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void vec_print(vector<int> a, int size){
	for (int i = 0; i < size; i++){
		cout << a[i] << " ";
	}
	cout << "\n";
}

int main(){
	fastio;
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	vector<int> v (10, 1);
	vec_print(v, v.size());

	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it){
		p(*it);
	}

	vector<int> x (5, 2);
	vector<int> z (3, 10);
	vector<int> temp;

	vector<vector<int>> folder;
	folder.push_back(v);
	folder.push_back(x);
	folder.push_back(z);

	for (vector<vector<int>>::iterator it = folder.begin(); it != folder.end(); ++it){
		//vec_print(*it, (*it).size());
		temp = *it;
		p("hi "<< temp[0]);
		for (vector<int>::iterator two = (*it).begin(); two != (*it).end(); ++two){
			p(*two);
		}
	}




	return 0;
}