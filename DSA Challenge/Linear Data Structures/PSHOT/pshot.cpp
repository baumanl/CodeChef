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

	ll t, n, steps, diff, rem_1, rem_2, rem, p1_score, p2_score, p1_max, p2_max;
	string s;
	cin >> t;
	while(t>0){
		t--;
		cin>>n>>s;
		p1_score = p2_score = 0;
		steps = 0;
		rem_1 = rem_2 = n;
		for (int i = 0; i < (2*n); i++){
			if (i%2==0){
				p1_score += (s[i] - '0');
				rem_1--;
			}
			else {
				p2_score += s[i] - '0';
				rem_2--;
			}
			steps++;

			p1_max = p1_score + rem_1;
			p2_max = p2_score + rem_2;

			if (p1_score > p2_max || p2_score > p1_max){break;}

		}
		cout<<steps<<"\n";
	}
	

	return 0;
}