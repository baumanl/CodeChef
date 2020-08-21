#include <bits/stdc++.h>
using namespace std;

int main(){

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n, q, x, y, sum, mid, val;
	int res;
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
				res = n;
			}else if(sum < a[0]){
				res = 0;
			}else{
				mid = n/2;
				while (mid >=0 && mid < n-1){
					val = a[mid];
					if (sum == val){
						res = -1;
						break;
					}else if (sum < val){
						mid = mid/2;
					}else{
						if (sum < a[mid + 1]){
							res = mid;
							break;
						}else{
							mid = 3*mid/2;
						}
						
					}
				}
			}
			cout<<res<<"\n";
		}
	}

	return 0;
}