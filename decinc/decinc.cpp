#include <cstdio>
using namespace std;

int main(){
	int x;

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	scanf("%d",&x);
	if(x%4 == 0){
		printf("%d", ++x);
	}else{
		printf("%d", --x);
	}
	return 0;
}