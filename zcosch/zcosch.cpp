#include <cstdio>
using namespace std;

int main(){
	int r;

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	scanf("%d", &r);
	if (r < 51){
		printf("100");
	}else if(r < 101){
		printf("50");
	}else{
		printf("0");
	}
	

	return 0;
}