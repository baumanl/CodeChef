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


int main() {
	
	int t;
	cin >> t;
	std::cout<<"T: "<<t<<"\n";
	
	int n,a,b,c;
	vector<int> vals;
	vector<vector<int>> edges;
	vector<int> temp;
	
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
    	
    	int numtrees = fact(n);
    	std::cout<<"numtree of n = "<<n<<": "<<numtrees<<"\n";
    	int trees[numtrees][n];
    	
    	vals.clear();
    	edges.clear();
    	
    }
    	

	return 0;
}