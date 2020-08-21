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

	int x;
	ll n;
	cin>>n;

	int nesting_depth, nd_pos, max_sym, ms_pos, num_open, num_closing, depth, length;
	nesting_depth = nd_pos = max_sym = ms_pos = num_open = num_closing = depth = length = 0;

	for (int i = 0; i < n; i++){
		cin>>x;
		length++;
		if (x == 1){
			num_open++;
			depth++;
		}
		else {
			num_closing++;
			depth--;
		}
		if (depth > nesting_depth){
			nesting_depth = depth;
			nd_pos = i+1;
		}
		if (length > max_sym){
			max_sym = length;
			ms_pos = i-length+2;
		}
		if (depth == 0){
			length = 0;
		}
	}

	cout<<nesting_depth<<" "<<nd_pos<<" "<<max_sym<<" "<<ms_pos<<"\n";
	

	return 0;
}