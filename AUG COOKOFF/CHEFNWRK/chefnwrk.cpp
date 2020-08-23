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
	
	int t, n, k, b, load, trips;
	cin>>t;
	while (t > 0){
		t--;
		cin>>n>>k;
		load = 0;
		trips = 1;
		for (int i = 0; i < n; i++){
			cin>>b;
			if (trips > -1){
				if (b > k){
					trips = -1;
				}else{
					load += b;
					if (load > k){
						trips++;
						load = b;
					}
				}
			}
		}
		p(trips);
	}

	return 0;
}