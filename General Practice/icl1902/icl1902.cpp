#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int t, squares;
	float n, s;

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);

	while(t > 0){
		t--;
		squares = 0;
		scanf("%f", &n);
		while(n > 1){
			s = sqrt(n);
			squares++;
			n = n - (floor(s)*floor(s));
		}
		if (n==1){
			squares++;
		}
		printf("%d\n", squares);
	}
	return 0;
}