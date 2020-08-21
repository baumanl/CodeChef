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
	
	int t, n, k, p, min, jmp, res;
	cin >> t;
	while (t>0){
		t--;
		cin >> n >> k;
		min = 0;
		res = -1;
		while (n > 0){
			n--;
			cin >> p;

			if (min != 1){
				jmp = p;

				while (p < k){
					p += jmp;
				}

				if (p == k && (((p/jmp) - 1 < min )|| min == 0)){
					min = p/jmp - 1;
					res = jmp;
				}
			}
		}
		cout << res << "\n";
	}
	return 0;
}