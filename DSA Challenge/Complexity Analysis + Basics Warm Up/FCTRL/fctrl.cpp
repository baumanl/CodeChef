#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t,n,zeros;
	cin >> t;
	while(t>0){
		t--;
		cin >> n;
		zeros = 0;
		while (n > 0){
			zeros += n/5;
			n/=5;
		}
		cout<<zeros<<"\n";

	}

	return 0;
}