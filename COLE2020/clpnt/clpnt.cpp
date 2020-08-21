#include <bits/stdc++.h>
using namespace std;

//too slow

int main(){

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n, q, x, y;
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
			if (x < a[0] && y < a[0] - x){
				cout<<0<<"\n";
			}else if(x > a[n-1] || y > a[n-1] - x){
				cout<<n<<"\n";
			}else{
				int i = n/2;
				while(i >= 0 && i < n){
					if (y == a[i] - x){
						cout<<-1<<"\n";
						break;
					}else if (y < a[i] - x){
						if (y > a[i-1] - x){
							cout<<i<<"\n";
							break;
						}else{
							i = i/2;
						}
					}else{
						i = (3*i)/2;
					}
				}
			}
		}
	}

	return 0;
}