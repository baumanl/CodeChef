#include <bits/stdc++.h>
#include <list>
using namespace std;

int main(){

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	string str;
	list<char> s1;
	list<char> s2;
	bool res;
	while (t > 0){
		t--;
		cin >> str;
		for (int i = 0; i < str.length()/2; i++){
			s1.push_back(str[i]);
		}
		if (str.length()%2 == 0){
			for (int i = str.length()/2; i < str.length(); i++){
				s2.push_back(str[i]);
			}
		}else{
			for (int i = str.length()/2+1; i < str.length(); i++){
				s2.push_back(str[i]);
			}
		}
		s1.sort();
		s2.sort();
		if (s1 == s2){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
		s1.clear();
		s2.clear();

	}

	return 0;
}