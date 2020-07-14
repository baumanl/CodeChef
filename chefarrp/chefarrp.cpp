#include <iostream>
using namespace std;

int main(){

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	
	int t, n, total, sum, prod;
	cin >> t;
	while(t>0){
		t--;
		cin >> n;
		total = n;
		int a[n];
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int j = 2; j <= n; j++){ //sizes of subarrays are 2 to the full array
			for (int k = 0; k <= n-j; k++){ //different starting points (0 to j less than n)
				sum = 0;
				prod = 1;
				for (int l = k; l < k+j; l++){
					sum = sum + a[l];
					prod = prod * a[l];
				}
				if (sum == prod){
					total++;
				}
			}
		}
		cout<<total<<"\n";

	}

	return 0;
}