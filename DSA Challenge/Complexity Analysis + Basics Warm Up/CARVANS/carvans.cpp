#include <bits/stdc++.h>
using namespace std;

int main(){

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n, prior_speed, speed, tot;
	cin >> t;
	while(t>0){
		t--;
		cin >> n;
		prior_speed = -1;
		tot = 0;
		for (int i = 0; i < n; i++){
			cin >> speed;
			if (speed < prior_speed || prior_speed == -1){
				tot++;
				prior_speed = speed;
			}
		}
		cout<<tot<<"\n";
	}

	return 0;
}