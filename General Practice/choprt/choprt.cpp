#include <cstdio>
using namespace std;

int main(){
	int t, a, b;

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	scanf("%d",&t);
	while(t>0){
		t--;
		scanf("%d%d", &a, &b);
		if(a > b){
			printf(">\n");
		}else if(a < b){
			printf("<\n");
		}else{
			printf("=\n");
		}
	}
	

	return 0;
}