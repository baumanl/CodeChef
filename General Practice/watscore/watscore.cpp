#include <iostream>
using namespace std;

int main(){

/*11 problems
1 to 8 are scorable. 9, 10, 11 are not scoreable
Total score = sum of best scores for first 8*/


#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int t, n, p, s, total;
	cin >> t;
	while(t>0){
		t--;
		cin >> n;
		total = 0;
		int probs[8] = {0, 0, 0, 0, 0, 0, 0, 0};
		for (int i = 0; i < n; i++){
			cin>>p;
			cin>>s;
			if (p < 9){
				if (probs[p-1] < s){
					probs[p-1] = s;
				}
			}
		}
		for (int i = 0; i < 8; i++){
			total = total + probs[i];
		}
		cout<<total<<"\n";



	}
	

	return 0;
}