#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using std::vector; 


int op(int W, const vector<int> &w){
  vector<vector<int>>weight_map;
  for(int j = 0; j <= W; j++){
    vector<int> a_vector = {};
    weight_map.push_back(a_vector);
    for(int k = 0; k <= w.size(); k++){
      if(j == 0 || k == 0){
        weight_map[j].push_back(0);
      }
      else{
        weight_map[j].push_back(0);
      }
    }
  }
  for(int a = 1; a <= W; a++){
    for(int i = 1; i <= w.size(); i++){
        weight_map[a][i] = weight_map[a][i-1];
      if(w[i-1] <= a){
        int test_val = weight_map[a-w[i-1]][i-1] + w[i-1];
        if(test_val > weight_map[a][i] ){
          weight_map[a][i] = test_val;
        }
      }
    }
  }
  return weight_map[W][w.size()];
}

int op_weight_memoized(int W, const vector<int> &w, std::map<int,int> weight_map = {}){
  int the_weight = 0;
  if(w.size() == 0 && W > 0){
    return the_weight;
  }
  for(int i = 0; i < w.size(); i++){
    weight_map[w[i]] = 0;
    vector<int> test_weight_vector = w;
    if(w[i] <= W){
      test_weight_vector.erase(test_weight_vector.begin() + i);
      int test_weight = op_weight_memoized(W-w[i], test_weight_vector, weight_map) + w[i];
      if(test_weight > weight_map[w[i]]){
        weight_map[w[i]] = test_weight;
      }
    }
    if(weight_map[w[i]] > the_weight){
      the_weight = weight_map[w[i]];
    }
    std::cout << weight_map[w[i]] << " at w[i] "<< w[i] << "\n";
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
    // std::cout << op_weight_memoized(W,w);
  std::cout<< op(W,w);
}
