#include <iostream>
#include <algorithm>
using namespace std;

int majority(const int* A, int N){
	std::cout<< A[0] << " A \n";
	std::cout<< N << " N \n";
	// std::cout<< A+N << "A + N \n";
	if(N == 1) return A[0];
	int mid = N/2;
	int majority_left = majority (A, mid);
	int majority_right = majority(A+mid, N-mid);
	if(majority_left == majority_right){
		return majority_left;
	}
	if(count(A, A+N, majority_left) > N/2){
		std::cout<< majority_left << "\n";
		std::cout<< count(A, A+N, majority_left) << " count left \n";
		return majority_left;
	}
	if(count(A, A+N, majority_right) > N/2){
		std::cout<< majority_right << "\n";
		std::cout<< count(A, A+N, majority_right) << " count right \n";
		return majority_right;
	}
	return -1; //no majority
}

int main(){
	int array[] = {0,1,0,1,0,2,5,0,0};
	std::cout<< sizeof(array) << "size of array \n";
	std::cout<< sizeof(*array) << "size of *array \n";
	enum {N = sizeof(array)/sizeof(*array)};
	int x = majority(array,N);
	if(x == -1) cout << "there is no majority element \n";
	else cout << "majority element is: " << x << "\n";
}