#include <bits/stdc++.h>
#define ll long long int
#define f(n) for(int i=0;i<n;i++)
#define p(x) cout<<x<<endl;
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;



int main(){
	fastio;
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	int t, n, k, f, ie;
	cin >> t;
	while(t>0){
		t--;
		cin >> n >> k;
		vector<int> families (101, 0);
		ie = 1;
		while(n>0){
			n--;
			cin >> f;
			families[f]++;
			if (families[f] == 2){
				ie += 1;
				families.assign(101, 0);
				families[f]++;
			}

		}
		p(ie);
		families.clear();
	}
	

	return 0;
}