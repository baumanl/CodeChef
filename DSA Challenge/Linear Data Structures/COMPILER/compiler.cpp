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

	int t;
	ll lcount, rcount, prefix;
	string exp;
	cin >> t;
	while (t > 0){
		t--;
		lcount = rcount = 0;
		cin >> exp;
		prefix = 0;
		if (exp[0] == '>'){
			cout<<0<<"\n";
		}
		else{
			for (int i = 0; i < exp.size(); i++){
				if (exp[i] == '>'){rcount++;}
				else{lcount++;}
				if (rcount == lcount){prefix = i+1;}
				if (rcount > lcount){
					prefix = i;
					break;
				}

			}
			cout<<prefix<<"\n";
		}
	}
	

	return 0;
}