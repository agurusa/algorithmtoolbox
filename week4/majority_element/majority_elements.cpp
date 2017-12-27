#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right){
	std::cout<< left <<  " left \n";
	std::cout<< right << " right \n";
	if(left == right) return -1;
	// if(left + 1 == right) return a[left];
	if(right - left == 1) return a[left];
	int mid = (right-left)/2;
	std::cout << mid << " mid \n";
	int ml = get_majority_element(a, left, mid);
		std::cout<< ml << " ml \n";
	int mr = get_majority_element(a, mid, right-mid);
		std::cout<< mr << " mr \n";
	if(ml == mr)return ml;
	if(count(a.begin(), a.end(), ml) > mid){
		return ml;
	}
	if(count(a.begin(), a.end(), mr) > mid){
		return mr;
	}
	return -1;
}
int main(){
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); i++){
		std::cin >> a[i];
	}
	std::cout << (get_majority_element(a, 0, a.size())) << " majority element \n";
	std::cout << (get_majority_element(a, 0, a.size()) != -1) << " this is the majority element? \n";
}