#include <iostream>
#include <string>
using namespace std;

int main(){
	int t, min_dif, max_dif;
	string s1, s2;
	

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	scanf("%d", &t);
	while(t>0){
		t--;
		cin >> s1;
		cin >> s2;
		min_dif = 0;
		max_dif = s1.length();
		for(int i = 0; i < s1.length(); i++){
			if (s1[i] == s2[i]){
				if (s1[i] != '?'){
					max_dif--;
				}
			}else if (s1[i] != s2[i]){
				if (s1[i] != '?' && s2[i] != '?'){
					min_dif++;
				}
			}
		}
		cout << min_dif << " " << max_dif << "\n";


	}
	

	return 0;
}