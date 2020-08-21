#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dist(int x[], int y[], int p1, int p2){
	return min(abs(x[p2]-x[p1]), abs(y[p2]-y[p1]));
}

int fact(int x){
	int res = 1;
	for (int i=x; i > 1; i--){
		res = res*i;
	}
	return res;
}

int cost(vector<int> path, int x[], int y[]){
	int total = 0;
	if (path.size() > 1){
		for(int i = 0; i < path.size()-2; i++){
			total = total + dist(x, y, path[i], path[i+1]);
		}
	}
	return total;

}

int xor_vec(vector<int> v){
	int l = v.size();
	int res = v[0];
	for (int i = 1; i < l; i++){
		res = res^v[i];
	}
	return res;
}

void print_vector(vector<int> v){
	for (int i=0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
	cout<<"\n";
	return;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	
	int t, n, p;
	cin >> t;

	vector<int> pts, min_path;
	int length, min_length;

	while (t > 0){
		t--;
		cin >> n; //number of points
		min_path.clear();
		pts.clear();
		min_length = -1;
		if (n > 1){
			int x_vals[n+1], y_vals[n+1];
			x_vals[0] = y_vals[0] = 0;
			for(int i = 1; i <= n; i++){
				cin >> x_vals[i];
				cin >> y_vals[i];
				pts.push_back(i);
			}
			int p = fact(n);
			//cout<<"p: "<<p<<"\n";
			//print_vector(pts);

			for(int j = 0; j < p/2 + 1; j++){
				print_vector(pts);
				length = cost(pts, x_vals, y_vals);
				cout<<"length: "<<length<<"\n";
				cout<<"\n";
				if (min_length == -1 || length < min_length){
					min_length = length;
					min_path = pts;
				}
				next_permutation(pts.begin(), pts.end());
			}

			print_vector(min_path);
			cout<<"min_length: "<<min_length<<"\n";

			int res = min_path[0];
			for (int i = 1; i < n; i++){
				res = res^min_path[i];
			}
			cout<<res<<"\n";
		}else{
			cout<<0<<"\n";
		}
		
	}

	return 0;
}