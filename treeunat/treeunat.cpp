#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

/*

this solution works for small datasets, but is extraordinarily inefficient. 
It does not pass the time standard.
I worked on it for two days before giving in and looking at someone else's soln
for inspiration. I am now going to try to understand C++ graphs.
Scratch that. I'm giving up for now. Guess I'll need to start with the easy problems...

*/

vector<vector<int>> maketrees(vector<int> vals){
	if(vals.size() == 2){
		return {vals, {vals.back(), vals.front()}};
	}
	else{
		vector<vector<int>> res;
		vector<int> t;
		vector<vector<int>> m;
		int size = vals.size();
		for(int i=0; i < size; i++){
			int z = vals[i];
			for(int j=0; j < size; j++){
				if(i != j){
					t.push_back(vals[j]);
				}
			}
			m = maketrees(t);
			t.clear();
			int msize = m.size();
			for(int k=0; k < msize; k++){
				m[k].push_back(z);
				res.insert(res.begin(), m[k]);
			}
			m.clear();
		}
		return res;
	}
}


int abs_val(int a, int b){

	switch(a) {
		case 0:
			switch(b) {
				case 0:
					return 0;
					break;
				case 1:
					return 1;
					break;
				case 2:
					return 2;
					break;
			}
			break;
		case 1:
			switch(b) {
				case 0:
					return 1;
					break;
				case 1:
					return 0;
					break;
				case 2:
					return 1;
					break;
			}
			break;
		case 2:
			switch(b) {
				case 0:
					return 2;
					break;
				case 1:
					return 1;
					break;
				case 2:
					return 0;
					break;
			}
			break;
	}
	return -1;

}

int max_unat(vector<int> tree, vector<vector<int>> edges){
	int max = 0;
	int av = 0;
	int esize = edges.size();
	for(int i=0; i<esize; i++){
		av = abs_val(tree[edges[i][0]-1], tree[edges[i][1]-1]);
		if (av > max){
			max = av;
		}
	}
	return max;
}


int main() {

	struct timeval start, end;
	gettimeofday(&start, NULL);

	ios_base::sync_with_stdio(false);
	
	int t;
	cin >> t;
	//std::cout<<"T: "<<t<<"\n";
	
	int n,a,b,c;
	vector<int> vals;
	vector<vector<int>> edges;
	vector<int> temp;
	vector<vector<int>> trees;
	int zero_count = 0;
	int one_count = 0;
	int two_count = 0;
	
	for (int j = 0; j < t; j++){
    	cin >> n;
    	//std::cout<<"N: "<<n<<"\n";
    	
    	for(int i=0; i < n; i++){
    	    cin >> a;
    	    //std::cout<<"a: "<<a<<"\n";
    	    vals.push_back(a);
    	    switch(a){
    	    	case 0:
    	    		zero_count++;
    	    		break;
    	    	case 1:
    	    		one_count++;
    	    		break;
    	    	case 2:
    	    		two_count++;
    	    		break;
    	    }
    	    //std::cout<<"Val"<<i<<": "<<vals.at(i)<<"\n";
    	}
    	/*std::cout<<"zero count: "<<zero_count<<"\n";
    	std::cout<<"one count: "<<one_count<<"\n";
    	std::cout<<"two count: "<<two_count<<"\n";*/

    	if ((zero_count == 0 && one_count == 0) || (zero_count == 0 && two_count == 0) || (one_count == 0 && two_count == 0)){
    		std::cout<<"0\n";
    	}else if(one_count == 0){
    		std::cout<<"2\n";
    	}else if(zero_count == 0 || two_count == 0){
    		std::cout<<"1\n";
    	}else{
    		for(int i=0; i < n-1; i++){
	    	    cin >> b;
	    	    cin >> c;
	    	    temp = {b, c};
	    	    edges.push_back(temp);
	    	    temp.clear();
	    	    //std::cout<<"Edge "<<i<<": "<<edges[i].at(0)<<" "<<edges[i].at(1)<<"\n";
	    	}
	    	
	    	int min_unat = 2; //min unattractiveness is set to 2 which is the highest possible value
	    	int test_munat = 2;
	    	trees = maketrees(vals); //generates all permutations of vals. (With repeats; not efficient)
	    	for (int i=0; i < trees.size(); i++){
	      		test_munat = max_unat(trees[i], edges);
	    		if(test_munat == 1){
	    			min_unat = 1;
	    			std::cout<<"should break now.";
	    			break;
	    		}
	    		std::cout<<".\n";
	    	}

	    	std::cout<<min_unat<<"\n";

	    	vals.clear();
	    	edges.clear();
    	}
    }
    gettimeofday(&end, NULL);
    double time_taken;
    time_taken = (end.tv_sec - start.tv_sec)*1e6;
   	time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;

    cout<< "Time taken by program is: "<< fixed << time_taken << setprecision(6);
    cout << " sec " << endl;	
	return 0;
}