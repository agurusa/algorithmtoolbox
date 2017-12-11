#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size(); 
  //this will always round down
  int half = right/2;
  int vector_at_half = a[half];
  //if the vector is an odd number of elements, the size of the derivative vectors will be
  //vector.size()/2 AND vector.size()/2 + 1. The one with the smaller elements will the shorter
  //and the one with the larger elements will be the +1.
  // vector<int> b(half);
  //if the size of the vector that we're searching is 1, that means that we went through the whole thing and either this is the number, or it doesn't exist.
  if((int)a.size() == 1 && vector_at_half != x){
    std::cout << "here \n";
    return -1;  
  }
  //if x is larger than the midpoint, we have to search the second half of the vector.
  else if(vector_at_half < x){
    if((int)a.size()%2 != 0){
      vector<int> b(half + 1);
      int j=0;
      for(int i = half; i < right; i++){
        b[j] = a[i];
        j++;
      }
      binary_search(b, x);
    }
    else{
      vector<int> b(half);
      int j=0;
      for(int i = half; i < right; i++){
        b[j] = a[i];
        j++;
      }
      binary_search(b, x);
    }
  }
  //if x is smaller than the midpoint, we have to search the first half.
  else if(vector_at_half > x){
    vector<int> b(half);
    for(int i = 0; i < half; i++){
      b[i] = a[i];
    }
    binary_search(b, x);
  }
  else if(vector_at_half == x){
    //this won't work because half is dependent on the size of the vector you're searching, 
    //which is not the same as the size of the original vector.
    return half;
  }
  else{
    std::cout << "hitting here \n";
    return -1;
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
    binary_search(a, b[i]);
  }
}
