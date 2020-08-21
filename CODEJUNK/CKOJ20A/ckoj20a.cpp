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

	list<int> nums;
	bool tri;
	int n, in, count;
	int a, b, c;
	cin >> n;
	count = n - 3;
	while (n>0){
		n--;
		cin>>in;
		nums.push_back(in);
	}
	tri = false;
	nums.sort();

	c = nums.back();
	nums.pop_back();
	b = nums.back();
	nums.pop_back();
	a = nums.back();
	nums.pop_back();

	if (a + b > c){
		tri = true;
	}else{
		while(count > 0){
			c = b;
			b = a;
			a = nums.back();
			nums.pop_back();
			count--;
			if (a + b > c){
				tri = true;
				break;
			}
		}
	}
	if (tri){
		cout<<"YES\n";
		cout<<c<<" "<<b<<" "<<a<<"\n";
	}else{
		cout<<"NO\n";
	}
	return 0;
}