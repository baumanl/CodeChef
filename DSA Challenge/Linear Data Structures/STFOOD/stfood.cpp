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

	int t, n, s, p, v;
	ll max_p, prof;
	cin >> t;
	while(t>0){
		t--;
		cin>>n;
		max_p = 0;
		while (n>0){
			n--;
			cin>>s>>p>>v;
			prof = v * floor(p/(s+1));
			if (prof > max_p) {max_p = prof;}
		}
		cout<<max_p<<"\n";
	}
	

	return 0;
}