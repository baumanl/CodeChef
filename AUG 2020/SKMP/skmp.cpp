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

	int t, ins;
	cin >> t;
	string S, P;
	while (t>0){
		t--;
		cin >> S >> P;
		sort(S.begin(), S.end());
		//p(S);
		for (int i = 1; i < P.length(); i++){
			S.erase(S.find_first_of(P[i]), 1);
		}
		ins = S.find_first_of(P[0]);
		for (int i = 1; i < P.length(); i++){
			if (P[i] > P[0]){
				ins = S.find_last_of(P[0]);
				break;
			}else if(P[i] < P[0]){
				break;
			}
		}

		S.erase(ins, 1);
		S.insert(ins, P);
		p(S);

	}
	return 0;
}