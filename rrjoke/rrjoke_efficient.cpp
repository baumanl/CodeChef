#include <iostream>
using namespace std;

int main(){

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	
	int t, n, trash, res;
	cin >> t;

	while (t > 0){
		t--;
		cin >> n; //number of points
		for(int j = 0; j < 2*n; j++){
			cin >> trash;
		}
		res = 1;
		if (n > 1){
			for(int i = 2; i <= n; i++){
				res = res^i;
			}
			cout<<res<<"\n";
		}else{
			cout<<1<<"\n";
		}
	}
	return 0;
}