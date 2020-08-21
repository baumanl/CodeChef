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

	double t, p, h, total;
	cin >> t;
	while (t > 0){
		t--;
		total = 0;
		cin >> h >> p;
		while (p > 0){
			total += p;
			p = floor(p/2); 
		}

		if (total >= h){
			p(1);
		}else{
			p(0);
		}
	}
	

	return 0;
}