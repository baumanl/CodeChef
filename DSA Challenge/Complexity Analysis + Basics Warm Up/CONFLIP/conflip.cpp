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

	int t, g, n, i, q;
	cin >> t;
	while(t > 0){
		t--;
		cin >> g;
		while(g > 0){
			g--;
			cin >> i; //1=heads, 2=tails @ start
			cin >> n; //num coins/rounds
			cin >> q; //1 = guess # of heads, 2 = guess # of tails

			if (n%2==0){
				p(n/2);
			}else if (i == q){
				p(n/2);
			}else{
				p(n-n/2);
			}


		}
	}
	

	return 0;
}