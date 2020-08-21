#include <cstdio>
using namespace std;

int main(){
	int a, b;

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d%d",&a, &b);
	if (a > b){
		printf("%d",a-b);
	}else{
		printf("%d", a+b);
	}
	return 0;
}