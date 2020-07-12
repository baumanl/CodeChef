#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct A {
	int array[9];
};

bool operator==(const A& lhs, const A& rhs){
	bool res = true;
	for (int i = 0; i < 9; i++){
		if (lhs.array[i] != rhs.array[i]){
			res = false;
			break;
		}
	}
	return res;
}

void print_3by3(int in[]){
	cout<<in[0]<<" "<<in[1]<<" "<<in[2]<<"\n";
	cout<<in[3]<<" "<<in[4]<<" "<<in[5]<<"\n";
	cout<<in[6]<<" "<<in[7]<<" "<<in[8]<<"\n";
}

int solve(A in){
	static int addends[9][4] = {{2, 4, 6}, {1, 3, 5, 9}, {2, 4, 8}, 
	{1, 3, 7, 9}, {2, 6, 8}, {1, 5, 7}, {4, 6}, {3, 5, 9},
	{2, 4, 8}};
	static int adjacents[9][4] = {{1, 3}, {0, 2, 4}, {1, 5}, 
	{0, 4, 6}, {1, 3, 5, 7}, {2, 4, 8}, {3, 7}, {4, 6, 8}, {5, 7}};
	static A ideal;
	for(int i = 0; i< 9; i++){
		ideal.array[i] = i;
	}

	list <A> mods;
	list <int> step_counter;
	
	int min_steps = -1;
	int steps, num;
	A grid;
	A temp;
	vector<A> tried;
	bool same, rep, loop;
	vector<int> swapped;

	mods.push_back(in);
	tried.push_back(in);
	step_counter.push_back(min_steps);

	while(mods.size() > 0){
		steps = step_counter.front();
		step_counter.pop_front();
		grid = mods.front();
		mods.pop_front();
		swapped.clear(); 
		if (min_steps == -1 || steps < min_steps-1){
			same = true;
			for(int i=0; i<9; i++){
				rep = false;
				for (auto j : swapped){
					if (i == j){
						rep = true;
					}
				}
				if (rep == false){
					num = grid.array[i];
					if (num != ideal[i]){
						same = false;
						for (int j=0; j < 4 && (j < 2 || adjacents[i][j] != 0); j++){
							int n = adjacents[i][j];
							for (int m = 0; m < 4 && (m < 2 || addends[num-1][m] > 0); m++){
								int k = addends[num-1][m];
								if(grid.array[n] == k){
									swapped.push_back(n);
									temp = grid;
									temp.array[i] = k;
									temp.array[n] = num;
									loop = false;
									for(auto z : tried){
										if (temp == z){
											loop = true;
										}
									}
									if (loop == false){
										mods.push_back(temp);
										tried.push_back(temp);
										print_3by3(temp.array);
										cout<<"swapped: "<<k<<" and "<<num<<"\n";
										if (steps == -1){
											cout<<"steps: 1\n";
											cout<<"\n";
											step_counter.push_back(1);
										}else{
											step_counter.push_back(steps + 1);
											cout<<"steps: "<<steps+1<<"\n";
											cout<<"\n";
										}
									}
									break;
								}
							}
						}
					}
				}
			}
			if(same == true){
				if (min_steps == -1 || steps < min_steps){
					min_steps = steps;
					cout<<"GOT ONE: "<<min_steps<<"\n";
				}
			}
		}
	}
	return min_steps;
}

int main(){
	int t;
	cin >> t;
	cout<<"T: "<<t<<"\n";
	cout<<"\n";

	A input;
	while(t-- > 0){
		for (int i = 0; i < 9; i++){
			cin >> input.array[i];
		}
		print_3by3(input.array);
		int steps = solve(input);
		cout<<"steps: "<<steps<<"\n";
	}

	return 0;
}