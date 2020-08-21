#include <bits/stdc++.h>
using namespace std;

int main(){

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, e, ct=0;
	cin>>n;
	cin>>k;
	while(n > 0){
		n--;
		cin >> e;
		if (e%k == 0){
			ct++;
		}
	}
	
	cout<<ct<<"\n";

	return 0;
}