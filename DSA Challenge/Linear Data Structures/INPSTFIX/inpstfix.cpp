#include <bits/stdc++.h>
#define ll long long int
#define f(n) for(int i=0;i<n;i++)
#define p(x) cout<<x<<endl;
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void swap(string in, int len){
	int st = 0, end = len-1, max_depth = 0, depth = 0;
	bool exp_flag = false, mult_div_flag = false, add_sub_flag = false;
	string res;
	for (int i = 0; i < len; i++){
		if (in[i] == '(') {depth++;}
		else if (in[i] == ')') {depth--;}
		else if (in[i] == '^'){
			exp_flag = true;
		}
		else if (in[i] == '*' || in[i] == '/'){
			mult_div_flag = true;
		}
		else if (in[i] == '+' || in[i] == '-'){
			add_sub_flag = true;
		}
		else {
			res.push_back(in[i]);
		}
		
	}





	for (int i = 0; i < len; i++){
		if (in[i] == '(') {depth++;}
		else if (in[i] == ')') {
			if (depth == max_depth){
				end = i;
			}
			depth--;
		}
		if (depth > max_depth){
			max_depth = depth;
			st = i;
		}
	}
	//cout<<"Max Depth: "<<max_depth<<"\n";
	//cout<<"start: "<<st<<" end: "<<end<<"\n";

	return;

}

	

int main(){
	fastio;
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	
	int t, n, depth;
	string infix, ans;
	cin >> t;
	while (t>0){
		t--;
		cin>>n>>infix;
		swap(infix, n);
	}

	return 0;
}