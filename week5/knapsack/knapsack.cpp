#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using std::vector; 

int op_weight_memoized(int W, const vector<int> &w){
  int the_weight = 0;
  std::map<int, int> weight_map = {};
  if(w.size() == 0 && W > 0){
    return the_weight;
  }
  for(int i = 0; i < w.size(); i++){
    //this should be initialized ONCE  
    weight_map[w[i]] = 0;

    vector<int> test_weight_vector = w;
    if(w[i] <= W){
      test_weight_vector.erase(test_weight_vector.begin() + i);
      int test_weight = op_weight_memoized(W-w[i], test_weight_vector) + w[i];
      if(test_weight > weight_map[w[i]]){
        weight_map[w[i]] = test_weight;
      }
    }
    if(weight_map[w[i]] > the_weight){
      the_weight = weight_map[w[i]];
    }
  }
  return the_weight;
}


  int optimal_weight(int W, const vector<int> &w) {
  //write your code here
    int current_weight = 0;
    for (size_t i = 0; i < w.size(); ++i) {
      if (current_weight + w[i] <= W) {
        current_weight += w[i];
      }
    }
    return current_weight;
  }

  int main() {
    int n, W;
    std::cin >> W >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
      std::cin >> w[i];
    }
  // std::cout << optimal_weight(W, w) << '\n';
    std::cout << op_weight_memoized(W,w);
  }
