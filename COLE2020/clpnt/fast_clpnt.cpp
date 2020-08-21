#include <bits/stdc++.h>
using namespace std;

//still too slow

int main(){

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n, q, x, y, sum;
	cin >> t;
	while(t > 0){
		t--;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		cin >> q;
		for (int j = 0; j < q; j++){
			cin >> x;
			cin >> y;
			sum = x+y;
			if (sum > a[n-1]){
				cout<<n<<"\n";
			}else if(sum < a[0]){
				cout<<0<<"\n";
			}else if(sum > a[n/2]){
				for (int i = (n/2 + 1); i < n; i++){
					if (sum == a[i]){
						cout<<-1<<"\n";
						break;
					}else if (sum < a[i]){
						cout<<i<<"\n";
						break;
					}
				}
			}else{
				for (int i = 0; i < (n/2 + 1); i++){
					if (sum == a[i]){
						cout<<-1<<"\n";
						break;
					}else if (sum < a[i]){
						cout<<i<<"\n";
						break;
					}
				}
			}
		}
	}

	return 0;
}