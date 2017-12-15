#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right){
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
}
