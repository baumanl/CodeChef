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
	
	int t, n;
	string in, res;
	cin >> t;
	while(t>0){
		t--;
		cin >> n;
		cin >> in;
		res = "NO";
		if (n%2 == 0){
			int alpha[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
			res = "YES";
			for (int i = 0; i < n; i++){
				alpha[in[i]%26]++;
			}
			for (int j = 0; j < 26; j++){
				if (alpha[j] % 2 != 0){
					res = "NO";
					break;
				}
			}
		}
		p(res);
	}


	return 0;
}