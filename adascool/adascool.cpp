#include <iostream>
using namespace std;

int main(){

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int t, n, m;
	cin >> t;
	while(t>0){
		t--;
		cin>>n;
		cin>>m;
		if((n*m)%2 == 0){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
	

	return 0;
}