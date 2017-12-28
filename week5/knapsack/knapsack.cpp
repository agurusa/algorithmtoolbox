#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using std::vector;

int op_weight_memoized(int W, const vector<int> &w){
  // std::cout << W << " W \n";
  vector<int> weight_v = {};
  std::map<int, int> weight_map = {};
  for(int i = 0; i < w.size(); i++){  
    weight_map[w[i]] = 0;
    // std::cout << weight_map[w[i]] << " weight map at i " << i << "\n";
    vector<int> a_test_v = w;
    if(w[i] < W){
      a_test_v.erase(a_test_v.begin() + i);
      int test_weight = op_weight_memoized(W-w[i], a_test_v) + w[i];
      // std::cout << test_weight << " test weight \n";
      if(test_weight > weight_map[w[i]]){
        weight_map[w[i]] = test_weight;
      }
    }
    weight_v.push_back(weight_map[w[i]]);
    // return weight_map[w[i]];
  }
  std::sort(weight_v.begin(), weight_v.end());
  return weight_v[weight_v.size()-1];
}

int op_weight(int W, const vector<int> &w){
  vector<int> item_vector = {};
  for(int i = 0; i < w.size(); i++){
    vector<int> copy_weight_vector = w;
    if(w[i] <= W){
      item_vector.push_back(w[i]);
      copy_weight_vector.erase(copy_weight_vector.begin() + i);
      for(int y = 0; y < copy_weight_vector.size(); y ++){
        int weight_left = W - item_vector[i];
        if(copy_weight_vector[y] <= weight_left){
          item_vector[i] += copy_weight_vector[y];
        }
      }
      std::cout << item_vector[i] << " weight at i ";
    }
    else{
      item_vector.push_back(0);
    }
    std::sort(item_vector.begin(), item_vector.end());  }
  return item_vector[item_vector.size() - 1];
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
  // std::cout << op_weight(W,w) << '\n';
  std::cout << op_weight_memoized(W,w);
}
