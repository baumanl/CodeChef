#include <cstdio>
using namespace std;

int main(){
	int t, b, temp, res;

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while(t > 0){
		t--;
		res = 0;
		temp = 0;
		scanf("%d", &b);
		if (b < 4){
			printf("0\n");
		}else{
			temp = b/2 -1;
			for (int i=temp; i>0; i--){
				res = res + i;
			}
			printf("%d\n",res);
		}
	}
	

	return 0;
}