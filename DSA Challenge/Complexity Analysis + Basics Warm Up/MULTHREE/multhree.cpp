#include <bits/stdc++.h>
#define ll long long int
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main(){
	fastio;
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	int t, xsum, rem;
	int d0, d1, d2, d3, d4, d5, d6;
	ll k, sum, x;
	cin >> t;
	
	while(t>0){
		t--;
		cin >> k;
		cin >> d0;
		cin >> d1;

		sum = d0 + d1;
		if (k==2){
			if (sum%3 == 0){
				cout<<"YES\n";
			}else{
				cout<<"NO\n";
			}
		}else{
			d2 = sum % 10;
			sum += d2;
			d3 = (2 * d2) % 10;
			d4 = (4 * d2) % 10;
			d5 = (8 * d2) % 10;
			d6 = (6 * d2) % 10;

			xsum = (d3 + d4 + d5 + d6);
			x = (k-3)/4;
			rem = (k-3)%4;
			sum += (x*xsum);

			if (rem == 1) {sum += d3;}
			else if (rem == 2) {sum += d3 + d4;}
			else if (rem == 3) {sum += d3 + d4 + d5;}

			if (sum%3 == 0){
				cout<<"YES\n";
			}else{
				cout<<"NO\n";
			}
		}
		
	}
	return 0;
}