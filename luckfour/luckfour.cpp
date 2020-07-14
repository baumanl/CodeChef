#include <cstdio>
using namespace std;

int main(){
	int t, a, count;

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while(t>0){
		t--;
		scanf("%d",&a);
		count = 0;
		while(a > 0){
			if (a%10 == 4){
				count++;
			}
			a = a/10;
		}
		printf("%d\n", count);
	}
	

	return 0;
}