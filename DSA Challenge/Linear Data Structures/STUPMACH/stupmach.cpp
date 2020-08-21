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

	ll t, n, tokens, smallest, temp;
	cin >> t;
	while(t>0){
		t--;
		cin>>n;
		int boxes[n];
		tokens = 0;
		smallest = -1;
		for (int i = 0; i < n; i++){
			cin>>boxes[i];
			if (smallest == -1 || boxes[i] < smallest){
				smallest = boxes[i];
			}
		}
		while(boxes[0] > 0){
			tokens += smallest*n;
			temp = -1;
			for (int i = 0; i < n; i++){
				boxes[i] -= smallest;
				if (boxes[i] == 0){
					n = i;
					break;
				}
				else if (temp == -1 || boxes[i] < temp){
					temp = boxes[i];
				}
			}
			smallest = temp;
		}
		cout<<tokens<<"\n";

	}
	

	return 0;
}