#include <bits/stdc++.h>
using namespace std;

int main(){

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long t, n, price_1, price_2, profit_1, profit_2, max_profit = 0;
	cin >> t;
	n = t;
	int budgets[n];
	while (n>0){
		cin >> budgets[n-1];
		n--;
	}
	if (t==1){
		cout << budgets[0]<<"\n";
	}else{
		for (int i = 0; i < t-1; i+=2){
			price_1 = budgets[i];
			price_2 = budgets[i+1];
			profit_1 = profit_2 = 0;
			for (int j = 0; j < t; j++){
				long long a = budgets[j];
				if (a >= price_1){
					profit_1 += price_1;
				}
				if (a >= price_2){
					profit_2 += price_2;
				}
			}
			if (profit_1 > max_profit){
				max_profit = profit_1;
			}
			if (profit_2 > max_profit){
				max_profit = profit_2;
			}
		}

		cout<<max_profit<<"\n";
	}
	

	return 0;
}