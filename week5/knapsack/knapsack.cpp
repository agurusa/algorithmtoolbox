#include <iostream>
#include <vector>
#include <map>

using std::vector;

int op_weight(int W, const vector<int> &w){
  vector<int> item_vector = {};
  for(int i = 0; i < w.size(); i++){
    vector<int> copy_weight_vector = w;
    if(w[i] < W){
      item_vector.push_back(w[i]);
      copy_weight_vector.erase(copy_weight_vector.begin() + i);
      for(int y = 0; y < copy_weight_vector.size(); y ++){
        if(copy_weight_vector[y] < W - item_vector[i]){
          item_vector[i] += copy_weight_vector[y];
        }
        else{
        }
      }
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
  std::cout << op_weight(W,w) << '\n';
}
