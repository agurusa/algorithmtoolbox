#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

bool first_time_calculating_right(int index){
  if(index == 0){
    return true;
  }
  else{
    return false;
  }
}

int get_right_index(const vector<int> &a, int index){
  if(first_time_calculating_right(index)){
    return a.size();
  }
  else{
    return index;
  }
}

int binary_search(const vector<int> &a, int x, int left = 0, int right = 0){
  right = get_right_index(a, right);
  int midpoint_size = (right - left)/2;
  int item_to_compare = a[left + midpoint_size];
  if(item_to_compare == x){
    return left + midpoint_size;
  }
  else if(midpoint_size == 0 && item_to_compare != x){
    return -1;
  }
  else if(item_to_compare > x){
    right = right - midpoint_size;
    binary_search(a, x, left, right);
  }
  else if(item_to_compare < x){
    left = left + midpoint_size;
    binary_search(a, x, left, right);
  }
  else{
    std::cout << "unknown condition";
  }
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    // std::cout << linear_search(a, b[i]) << ' ';
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
