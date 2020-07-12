#include <cstdio>
using namespace std;

int main(){
	int t,yr;
	int hosted[2022];
	hosted[2010] = hosted[2015] = hosted[2016] = hosted[2017] = hosted[2019] = 1;

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	
	scanf("%d", &t);
	while(t > 0){
		t--;
		scanf("%d", &yr);
		if(hosted[yr] == 1){
			printf("HOSTED\n");
		}else{
			printf("NOT HOSTED\n");
		}
	}


	return 0;
}