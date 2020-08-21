#include <iostream>
#include <list>
#include <vector>
using namespace std;

//this code answers all the test cases I can think of, but it is too slow to pass the online test. 

//used instead of a plain array because arrays can't be copied easily
struct A {
	int array[9];
};

//implement equality operater for struct A
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
	cout<<"\n";
}

int solve(A in){

	//arrays of all numbers that can be added to 1, 2, 3,...to form prime number sums
	static int addends[9][4] = {{2, 4, 6}, {1, 3, 5, 9}, {2, 4, 8}, 
	{1, 3, 7, 9}, {2, 6, 8}, {1, 5, 7}, {4, 6}, {3, 5, 9},
	{2, 4, 8}};

	//arrays of all indeces adjacent to indeces 0, 1, 2, ...
	static int adjacents[9][4] = {{1, 3}, {0, 2, 4}, {1, 5}, 
	{0, 4, 6}, {1, 3, 5, 7}, {2, 4, 8}, {3, 7}, {4, 6, 8}, {5, 7}};

	//the end result grid
	static A ideal;
	for(int i = 0; i< 9; i++){
		ideal.array[i] = i+1;
	}

	list <A> mods; //all variations of the grid that have to be altered
	list <int> step_counter; //corresponding step counts to mods
	
	int min_steps = -1; //default number of steps and # returned if the grid is impossible
	int steps, num;
	A grid, temp;
	vector<A> tried;
	bool rep, loop;
	vector<int> swapped;
	bool solved = false;

	mods.push_back(in);
	tried.push_back(in);
	step_counter.push_back(min_steps);

	while(mods.size() > 0){ //goes through all 
		//initializes steps, grid, and alters lists to reflect they are being processed
		steps = step_counter.front();
		step_counter.pop_front();
		grid = mods.front();
		mods.pop_front();
		swapped.clear(); 
		//cout<<"steps: "<<steps<<"\n";
		if (steps > 25){
			break;
		}

		for(int i=0; i<9; i++){//goes through each position of a grid to make all possible swaps and add them to mods list
			rep = false; //keeps track of if a swap has already been performed on a grid (1, 2) and (2, 1) shouldn't be repeated
			for (auto j : swapped){
				if (i == j){
					rep = true;
				}
			}
			if (rep == false){
				num = grid.array[i];
				if (num != ideal.array[i]){
					for (int j=0; j < 4 && (j < 2 || adjacents[i][j] != 0); j++){
						int n = adjacents[i][j];
						for (int m = 0; m < 4 && (m < 2 || addends[num-1][m] > 0); m++){
							int k = addends[num-1][m];
							if(grid.array[n] == k){
								swapped.push_back(n);
								temp = grid;
								temp.array[i] = k;
								temp.array[n] = num;
								//print_3by3(temp.array);
								if (temp == ideal){
									//cout<<"Temp: "<<temp.array[0]<<temp.array[1]<<temp.array[2]<<temp.array[3]<<temp.array[4]<<temp.array[5]<<temp.array[6]<<temp.array[7]<<temp.array[8]<<"\n";
									//cout<<"Temp: "<<ideal.array[0]<<ideal.array[1]<<ideal.array[2]<<ideal.array[3]<<ideal.array[4]<<ideal.array[5]<<ideal.array[6]<<ideal.array[7]<<ideal.array[8]<<"\n";
									if (steps == -1){
										return 1;
									}else{
										return steps+1;
									}
								}else{
									loop = false;
									for(auto z : tried){
										if (temp == z){
											loop = true;
										}
									}
									if (loop == false){
										mods.push_back(temp);
										tried.push_back(temp);
										if (steps == -1){
											step_counter.push_back(1);
										}else{
											step_counter.push_back(steps + 1);
										}
									}
									
									break;
								}
							}
						}
					}
				}
			}
		}
	}
	return min_steps;
}

int main(){
	int t;
	cin >> t;

	A input;
	while(t-- > 0){
		for (int i = 0; i < 9; i++){
			cin >> input.array[i];
		}
		//print_3by3(input.array);
		int steps = solve(input);
		cout<<steps<<"\n";
	}

	return 0;
}