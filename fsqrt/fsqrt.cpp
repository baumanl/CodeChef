#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int t, n;

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	cin >> t;
	while (t > 0){
		t--;
		cin >> n;
		cout<<floor(sqrt(n))<<"\n";
	}

	

	return 0;
}