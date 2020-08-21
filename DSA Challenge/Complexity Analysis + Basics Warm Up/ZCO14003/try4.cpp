#include <bits/stdc++.h>
#define ll long long
using namespace std;

//referenced: https://www.codechef.com/viewsolution/35715413

int main(){

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i=0; i<n; i++)
		cin>>v[i];
	sort(v.begin(),v.end());
	ll m=0;
	for (int i=0; i<n; i++)
		m = max(m, (n-i)*1ll*v[i]);
	cout<<m<<"\n";

	return 0;
}