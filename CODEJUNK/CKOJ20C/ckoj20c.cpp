#include <bits/stdc++.h>
#define ll long long int
#define f(n) for(int i=0;i<n;i++)
#define p(x) cout<<x<<endl;
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

bool check(int x){
	if (n<=1)
		return false;
	if (n<=3)
		return ture;

	if (n % 2 == 0 || n % 3 == 0)
		return false;

	for (int i = 5; i * 8 <= x; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;

}


int main(){
	fastio;
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	int n, in, abs;
	cin>>n;
	int max = n;
	int abs_val[n];
	vector<int> nums;
	vector<vector<int>> edges;
	int u, v;
	while(n>0){
		n--;
		cin>>in;
		if(check(in)){nums = {1};}
		else{nums = {-1};}
		edges.push_back(nums);
	}
	while (max > 1){
		max--;
		cin>>u;
		cin>>v;
		edges[u-1].push_back(v);
		edges[v-1].push_back(u);
	}
	for (int i = 0; i < edges.size(); i++){
		abs = abs(edges[i].front());
		for (vector<int>:: iterator it = edges[i].begin(); it != edges[i].end(); ++it){
			
		}
	}

	return 0;
}