#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using std::vector;


vector<int> op_sequence(int n, vector<int> results = {}, std::map<int, vector<int>> calculated_options = {1,{0}}){
	if(n == 1){
		results.push_back(n);
		return results;
	}
	else{
		vector<int> options = {3,2,1};
		calculated_options[n] = {n-1};
		int x;
		for(int i = 0; i < options.size(); i++){
			int option = options[i];
			if(option == 1){
				x = n - option;
				op_sequence(x, results, calculated_options);
			}
			else{
				if(n%option != 0){
					//we shouldn't store this
				}
				else{
					x = n/option;
					vector hash_vector = calculated_options[n];
					hash_vector.push_back(x);
					op_sequence(x,results,calculated_options);
				}
			}
		}
	}
}

//first figure out how many steps it would take to get to 
//a number. 
//then figure out how many steps it would take to get from that number
// to the next number?