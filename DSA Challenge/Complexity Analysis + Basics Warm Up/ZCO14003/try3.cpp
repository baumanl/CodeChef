#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main(){

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long a, t, n;
	long long avg_budg = 0;
	long long closest_up, closest_down, profit_up = 0, profit_down = 0;
	cin >> t;
	n = t;
	long long budgets[n];
	while (n>0){
		cin >> a;
		budgets[n-1] = a;
		avg_budg += a;
		n--;
	}
	avg_budg = avg_budg/t;
	closest_up = -1;
	closest_down = -1;
	for (int i = 0; i < t; i++){
		a = budgets[i];
		if (a > avg_budg){
			if ((a-avg_budg) < (closest_up-avg_budg) || closest_up == -1){
				closest_up = a;
			}
		}else if (a < avg_budg){
			if ((avg_budg - a) < (avg_budg  - closest_down) || closest_down == -1){
				closest_down = a;
			}
		}else{
			closest_up = a;
			closest_down = a;
		}
	}

	for (int j = 0; j<t; j++){
		if(budgets[j] >= closest_up){
			profit_up += closest_up;
		}if(budgets[j] >= closest_down){
			profit_down += closest_down;
		}
	}
	if (profit_up > profit_down || profit_up == profit_down){
		int max = profit_up;
		for (int i = 0; i < t; i++){
			if (budgets[i] > max){
				max = budgets[i];
			}
		}
		cout<<max<<"\n";
	}else{
		cout<<profit_down<<"\n";
	}

	return 0;
}