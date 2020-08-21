#include <bits/stdc++.h>
#define ll long long int
#define f(n) for(int i=0;i<n;i++)
#define p(x) cout<<x<<endl;
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;



int main(){
	fastio;
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	int t, act_num, laddus;
	cin >> t;
	string origin, act;
	int rank, severity;

	while (t > 0){
		t--;
		cin >> act_num;
		cin >> origin;
		laddus = 0;
		while (act_num > 0){
			act_num --; 
			cin >> act;
			if (act == "CONTEST_WON"){
				cin >> rank;
				if (rank > 20){
					laddus += 300;
				}else{
					laddus += 300 + 20 - rank;
				}
			}else if (act == "TOP_CONTRIBUTOR"){
				laddus += 300;
			}else if (act == "BUG_FOUND"){
				cin >> severity;
				laddus += severity;
			}else{
				laddus += 50;
			}
		}
		if (origin == "INDIAN"){
			p(laddus/200);
		}else{
			p(laddus/400);
		}
	}
	

	return 0;
}