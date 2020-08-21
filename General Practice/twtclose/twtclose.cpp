#include <bits/stdc++.h>
using namespace std;

int main(){

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, x, open=0;
	cin >> n;
	cin >> k;
	int tweets[n];
	for (int i = 0; i < n; i++){
		tweets[i] = 0;
	}
	string instr;
	while(k>0){
		k--;
		cin >> instr;
		open = 0;
		if (instr == "CLICK"){
			cin >> x;
			if (tweets[x-1] == 0){
				tweets[x-1] = 1;
			}else{
				tweets[x-1] = 0;
			}
			//tweets[x-1] = tweets[x-1]^1;
			for (int j = 0; j < n; j++){
				open = open + tweets[j];
			}
		}else{
			for (int i = 0; i < n; i++){
				tweets[i] = 0;
			}
		}
		cout << open << "\n";


	}

	return 0;
}