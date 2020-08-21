#include <iostream>
using namespace std;

int main(){

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	
	int t, n, def, freq;
	int counts[100];
	cin >> t;
	while(t>0){
		t--;
		for (int l = 0; l<100; l++){
			counts[l] = 0;
		}

		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++){
			cin >> a[i];
			counts[a[i]]++;
		}

		def = 0;
		freq = 0;
		for (int k = 0; k < 100; k++){
			if (counts[k] > freq){
				freq = counts[k];
				def = k;
			}
		}
		cout<<n-freq<<"\n";

		
	}

	return 0;
}