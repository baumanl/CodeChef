#include <iostream>
using namespace std;

void isPrime(int n){
	if (n <= 1){
		cout<<"no\n";
		return;
	}
	for (int i = 2; i < n; i++){
		if (n%i == 0){
			cout<<"no\n";
			return;
		}
	}
	cout<<"yes\n";
	return;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int t, n;
	cin >> t;
	while (t>0){
		t--;
		cin >> n;
		isPrime(n);
	}
	

	return 0;
}