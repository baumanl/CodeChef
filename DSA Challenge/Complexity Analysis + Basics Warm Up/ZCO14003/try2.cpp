#include <bits/stdc++.h>
#include <list>
using namespace std;

int main(){

	//DOESN'T WORK: CAN'T ACCESS INDECES OF A LIST

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long t, n, b, i, price, price_up, price_down, profit, profit_up, profit_down, max_profit = 0;
	cin>>t;
	n = t;
	list<int> budgets;
	while (n>0){
		n--;
		cin>>b;
		budgets.push_back(b);
	}
	if (t == 1){
		cout << budgets[0];
	}else{
		budgets.sort();
		i = t/2;
		while (i > 0 && i < t-1){
			price = budgets[i];
			price_down = budgets[i-1];
			price_up = budgets[i+1];
			profit = profit_down = profit_up = 0;
			for (int j = 0; j < t; j++){
				int a = budgets[j];
				if (a >= price){
					profit += price;
				}
				if (a >= price_down){
					profit_down += price_down;
				}
				if (a >= price_up){
					profit_up += price_up;
				}
			}
			if (profit > max_profit){
				max_profit = profit;
			}
			if (profit_up > max_profit){
				max_profit = profit_up;
				i += 3;
			}else if (profit_down > max_profit){
				max_profit = profit_down;
				i -= 3;
			}else{
				break;
			}
		}
		cout<<max_profit<<"\n";
	}
	return 0;
}