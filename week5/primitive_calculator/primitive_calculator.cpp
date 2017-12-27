#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using std::vector;

int set_x(int n, int op){
  if(op == 1){
    return n - 1;
  }
  else{
    if(n%op == 0){
      return n / op;
    }
    else{ 
      return n;
    }
  }
}

vector<int> min_ops(int n){
  vector<int> min_op = {0};
  std::map<int, vector<int>> number_map = {};

  for(int i = 1; i <= n; i++){
    int theoretical_min_op;
    min_op.push_back(i - 1);
    number_map[i].push_back(1);  
    for(int y = 1; y <= 3; y++){
      int x = set_x(i, y);
      if(x == i){
      }
      else{
        theoretical_min_op = min_op[x] + 1;
        if(theoretical_min_op < min_op[i]){ 
          min_op[i] = theoretical_min_op;
          number_map[i] = number_map[x];
          number_map[i].push_back(i);
        }
      }
    }
  }
  if(n == 2){
    number_map[n].push_back(n);
  }
  return number_map[n];
}

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;  
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}


int main() {
  int n;
  std::cin >> n;
  // vector<int> sequence = optimal_sequence(n);
  vector<int> seq = min_ops(n);
  // std::cout << sequence.size() - 1 << std::endl;
  // for (size_t i = 0; i < sequence.size(); ++i) {
  //   std::cout << sequence[i] << " ";
  // }
  std::cout << seq.size() - 1 << std::endl;
  for(size_t i = 0; i < seq.size(); i++){
    std::cout << seq[i] << " ";
  }
}
