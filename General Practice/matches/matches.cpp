#include <cstdio>
using namespace std;

int main(){

	int mats[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	int t, a, b, sum, i, res;

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d",&t);
	while(t > 0){
		t--;
		res = 0;
		scanf("%d%d",&a, &b);
		sum = a+b;
		while (sum>0){
			i = sum%10;
			res = res+mats[i];
			sum = sum/10;
		}
		printf("%d\n", res);
	}
	

	return 0;
}