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
		double t, pc, pr;
		cin >> t;
		while (t>0){
			t--;
			cin >> pc >> pr;
			if (ceil(pc/9) < ceil(pr/9)){
				cout << "0 " << ceil(pc/9) << "\n";
			}else{
				cout << "1 " << ceil(pr/9) << "\n";
			}
		}
	

	return 0;
}