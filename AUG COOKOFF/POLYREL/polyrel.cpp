#include <bits/stdc++.h>
#define ll long long int
#define f(n) for(int i=0;i<n;i++)
#define p(x) cout<<x<<endl;
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int child_sides(int psides){
	if (psides < 6){
		return 0;
	}else{
		return (psides/2);
	}
}

int main(){
	fastio;
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	int t, n, res, s, c;
	cin >> t;
	while (t > 0){
		t--;
		cin>>n;
		s = child_sides(n);
		res = n+s;
		while (s > 0){
			s = child_sides(s);
			res += s;
		}
		p(res);
		for (int i = 0; i < 2*n; i++){
			cin>>c;
		}
	}

	return 0;
}