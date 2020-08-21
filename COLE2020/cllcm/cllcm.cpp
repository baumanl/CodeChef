#include <bits/stdc++.h>
using namespace std;

int main(){

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, a, n;
	bool res;
	cin >> t;
	while(t>0){
		t--;
		cin >> n;
		res = true;
		for (int i = 0; i < n; i++){
			cin >> a;
			if (a % 2 == 0){
				res = false;	
			}
		}
		if (res == false){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}

	}

	return 0;
}