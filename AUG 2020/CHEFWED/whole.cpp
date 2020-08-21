#include <bits/stdc++.h>
#define ll long long int
#define f(n) for(int i=0;i<n;i++)
#define p(x) cout<<x<<endl;
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int find_val(vector<vector<int>>::iterator record, int rtab){
	int val = 0;
	vector<int> left = record[rtab-1];
	vector<int> right = record[rtab];
	if (rtab >= 2){
		vector<int> prev = record[rtab-2];
		for (int i = 1; i < 101; i++){
			if (right[i] == 1 && left[i] != 0){
				if (prev[i] != 0 || left[i] >=2){
					val++;
				}else{
					val += 2;
				}
			}else if(left[i] == 1 && (right[i] > 1 && prev[i] == 0)){
				val++;
			}
		}
	}else{
		for (int i = 1; i < 101; i++){
			if (right[i] == 1 && left[i] != 0){
				if (left[i] >= 2){
					val++;
				}else{
					val += 2;
				}
			}else if(left[i] == 1 && right[i] > 1){
				val++;
			}
		}
	}
	return val;
}

int cost(vector<vector<int>>::iterator it, int table){
	int total = 0;
	vector<int> t = it[table];
	for (int i = 0; i < t.size(); i++){
		if (t[i] > 1){
			total += t[i];
		}
	}
	return total;
}

void vec_print(vector<int> a, int size){
	for (int i = 0; i < size; i++){
		cout << a[i] << " ";
	}
	cout << "\n";
}

int main(){
	fastio;
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	vector<vector<int>> fam_records;
	vector<int> families;
	vector<int> split_vals;
	int t, n, k, f, ie, val, table, min;

	cin >> t;
	while(t>0){
		t--;
		cin >> n >> k;

		families.assign(101, 0);
		fam_records.clear();
		split_vals.clear();
		fam_records.push_back(families);
		val = 0;
		ie = k;
		table = 1;

		while(n>0){
			n--;
			cin >> f;
			families[f]++;

			if (families[f] == 2){
				ie += k;
				families[f]--;
				fam_records.push_back(families);
				families.assign(101, 0);
				families[f]++;
				val = find_val(fam_records.begin(), table);
				split_vals.push_back(val);
				table++;
			}
			if (n == 0){
				fam_records.push_back(families);
				val = find_val(fam_records.begin(), table);
				split_vals.push_back(val);
			}
		}
		min = ie;
		for (int i = 1; i < split_vals.size(); i++){
			if (split_vals[i] < k){
				ie -= k;
				ie -= cost(fam_records.begin(), i);
				ie -= cost(fam_records.begin(), i+1);
				transform(fam_records[i].begin(), fam_records[i].end(), fam_records[i+1].begin(), fam_records[i].begin(), plus<int>());
				fam_records.erase(fam_records.begin()+i+1);
				split_vals.erase(split_vals.begin()+i);
				if (i < split_vals.size()){
					split_vals[i] = find_val(fam_records.begin(), i+1);
				}
				split_vals[i-1] = find_val(fam_records.begin(), i);

				ie += cost(fam_records.begin(), i);

				i--;
			}
		}

		if (ie < min){
			min = ie;
		}
		if (k != 1){
			for (int i = 1; i < split_vals.size(); i++){
				if (split_vals[i] <= k){
					ie -= k;
					ie -= cost(fam_records.begin(), i);
					ie -= cost(fam_records.begin(), i+1);
					transform(fam_records[i].begin(), fam_records[i].end(), fam_records[i+1].begin(), fam_records[i].begin(), plus<int>());
					fam_records.erase(fam_records.begin()+i+1);
					split_vals.erase(split_vals.begin()+i);
					if (i < split_vals.size()){
						split_vals[i] = find_val(fam_records.begin(), i+1);
					}
					split_vals[i-1] = find_val(fam_records.begin(), i);

					ie += cost(fam_records.begin(), i);

					i--;
				}
			}
		}
		if (ie < min){
			min = ie;
		}
		
		p(min);
		
	}
	return 0;
}