#include <iostream>
using namespace std;

int main(){
	int t, a, b;

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	
	cin >> t;
	while (t > 0){
		t--;
		cin >> a;
		cin >> b;
		cout << (a % b) << "\n";
	}


	return 0;
}