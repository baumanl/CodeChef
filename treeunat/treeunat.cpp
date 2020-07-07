#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;

int fact(int n){
    int res = 1;
    for (int i = 1; i <= n; i++){
        res = res * i;
    }
    return res;
}

vector<vector<int>> maketrees(vector<int> vals){
	if(vals.size() == 2){
		vector<vector<int>> x = {vals, {vals.back(), vals.front()}};
		std::cout<<"x: {{"<<x[0][0]<<","<<x[0][1]<<"}, {"<<x[1][0]<<","<<x[1][1]<<"}}\n";
		return x;
	}
	else{
		vector<vector<int>> res;
		vector<int> t;
		vector<vector<int>> m;
		for(int i=0; i < vals.size(); i++){
			int z = vals[i];
			for(int j=0; j < vals.size(); j++){
				if(i != j){
					int a = vals[j];
					t.push_back(vals[j]);
				}
			}
			m = maketrees(t);
			t.clear();
			t.resize(0);
			for(int k=0; k < m.size(); k++){
				m[k].push_back(z);
				res.insert(res.begin(), m[k]);
			}
			m.clear();
			m.resize(0);
		}
		std::cout<<"Res preview: {{"<<res[0][0]<<","<<res[0][1]<<","<<res[0][2]<<"}, {"<<res[1][0]<<","<<res[1][1]<<","<<res[1][2]<<"}...}\n";
		return res;
	}
}


int main() {
	
	int t;
	cin >> t;
	std::cout<<"T: "<<t<<"\n";
	
	int n,a,b,c;
	vector<int> vals;
	vector<vector<int>> edges;
	vector<int> temp;
	vector<vector<int>> trees;
	
	for (int j = 0; j < t; j++){
    	cin >> n;
    	std::cout<<"N: "<<n<<"\n";
    	
    	for(int i=0; i < n; i++){
    	    cin >> a;
    	    vals.push_back(a);
    	    std::cout<<"Val"<<i<<": "<<vals.at(i)<<"\n";
    	}
    	
    	for(int i=0; i < n-1; i++){
    	    cin >> b;
    	    cin >> c;
    	    temp = {b, c};
    	    edges.push_back(temp);
    	    temp.clear();
    	    std::cout<<"Edge "<<i<<": "<<edges[i].at(0)<<" "<<edges[i].at(1)<<"\n";
    	}
    	
    	trees = maketrees(vals);
    	for (int i=0; i < trees.size(); i++){
    		std::cout<<i<<" Tree: "<<trees[i][0]<<trees[i][1]<<trees[i][2]<<"\n";
    	}

    	
    	vals.clear();
    	edges.clear();
    	
    }
    	

	return 0;
}