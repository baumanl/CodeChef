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
	
	int t, n, k, boxes;
	char c;
	int ztot, onetot;
	cin>>t;
	while(t>0){
		t--;
		cin>>n>>k;
		ztot = onetot = 0;
		boxes = n/k;
		for (int i = 0; i < n; i++){
			cin>>c;
			if (c == '1'){
				onetot++;
			}else{
				ztot++;
			}
		}

		if (onetot%boxes != 0 || ztot%boxes != 0){
			p("IMPOSSIBLE");
		}else{
			string res;
			res.clear();
			string zs (ztot/boxes, '0');
			string ones (onetot/boxes, '1');
			string pat1 (zs);
			string pat2 (ones);
			pat1.append(ones);
			pat2.append(zs);
			for (int i = 0; i < boxes; i++){
				if (i%2 == 0){
					res.append(pat1);
				}else{
					res.append(pat2);
				}
			}
			p(res);
		}


	}

	return 0;
}