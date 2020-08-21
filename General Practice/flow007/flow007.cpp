#include <bits/stdc++.h>
using namespace std;

int main(){

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, in, out;
	cin >> t;
	while(t>0){
		t--;
		cin >> in;
		out = 0;
		while(in > 0){
			out = (10*out) + (in % 10);
			in = in/10;
		}
		cout<<out<<"\n";
	}

	return 0;
}