#include <cstdio>
using namespace std;

int main(){
	int t, a, b;

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	scanf("%d",&t);
	while(--t > -1){
		scanf("%d%d",&a,&b);
		printf("%d\n", (a-1)*(b-1));
	}

	return 0;
}