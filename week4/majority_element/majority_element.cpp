#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right){
  std::cout << left << " left " << right << " right \n";
  if (left == right){
    return -1;
  } 
  else if (left + 1 == right){
    return a[left];
  } 
  else{
    int mid = (right - left)/2;
    int ml = get_majority_element(a, left, left + mid);
    int mr = get_majority_element(a, left + mid + 1, right);
    std::cout << ml << " ml " << mr << " mr \n";
    // std::cout << a.begin() << " begin + left " << a.begin() << " begin + right " 
    std::cout<< count(a.begin() + left, a.begin() + right, ml) << " count left \n";
    std::cout<< count(a.begin() + left, a.begin() + right, mr) << " count right \n";
    if (ml == mr) return ml; 
    else if(count(a.begin() + left, a.begin() + right, ml) > mid) return ml;
    else if(count(a.begin() + left, a.begin() + right, mr) > mid) return mr;
    else {
      return -1;
    }
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
  std::cout << (get_majority_element(a, 0, a.size())) << '\n';
}
