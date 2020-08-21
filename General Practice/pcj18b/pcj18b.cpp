#include <cstdio>
using namespace std;

int main(){
	int t, a, res = 0;

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	scanf("%d", &t);
	while(t > 0){
		scanf("%d", &a);
		while(a > 0){
			res = res + a*a;
			a = a-2;
		}
		printf("%d\n", res);
		res = 0;
		--t;
	}
	return 0;
}