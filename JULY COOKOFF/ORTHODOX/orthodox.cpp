#include <bits/stdc++.h>
#define ll long long int
#define f(n) for(int i=0;i<n;i++)
#define p(x) cout<<x<<endl;
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const unsigned int M = 1000000007;
//inspired by https://www.codechef.com/viewsolution/35792416

int main(){
	fastio;
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	int t;
	cin >> t;
	while (t--){
		int n; cin >> n;
		ll x, acc;
		n--;
		bool dist = true;
		cin >> acc;
		while(n--){
			cin >> x;
			if (((x | acc) == x) || ((x | acc) == acc)){dist = false;}
			acc |= x;
		}
		if (dist) {p("YES");}
		else {p("NO");}
	}
	return 0;
}