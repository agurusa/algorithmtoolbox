#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using std::vector;

vector<int> min_operations(int n, vector<int>numbas = {}){
  numbas.push_back(n);
  if(n == 1){
    reverse(numbas.begin(), numbas.end());
    return numbas;
  }
  else{
    vector<int> options = {3,2,1};
    int n_over_three, n_over_two, n_minus_1;
    for(int i = 0; i < options.size(); i++){
      int option = options[i];
      if(option == 1){
        n_minus_1 = n - option;
      }
      else{
        if(n%option == 0){
          if(option == 2){
            n_over_two = n/option;
          }
          else{
            n_over_three = n/option;
          }
        }
        else{
          if(option == 2){
            n_over_two = n;
          }
          else{
            n_over_three = n;
          }
        }
      }
    }
    int result = std::min(std::min(n_minus_1, n_over_two), n_over_three);
    return(min_operations(result, numbas));
  }
}
int min_test(int n, int count = 1){
  if(n == 1){
    return 0;
  }
  else{
    int a_count = count;
    vector<int> options = {3,2,1};
    int n_over_three;
    int n_over_two;
    int n_minus_1;
    for(int i = 0; i < options.size(); i++){
      int option = options[i];
      if(option == 1){
        n_minus_1 = n - option;
      }
      else{
        if(n%option == 0){
          if(option == 2){
            n_over_two = n/option;
          }
          else{
            n_over_three = n/option;
          }
        }
        else{
          if(option == 2){
            n_over_two = n;
          }
          else{
            n_over_three = n;
          }
        }
      }
    }
    int result = std::min(std::min(n_minus_1, n_over_two), n_over_three);
    if(result == 1){
      return a_count;
    }
    else{
      a_count = a_count+1;
      return min_test(result, a_count);
    }
  }
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
  vector<int> seq = min_operations(n);
  // std::cout << sequence.size() - 1 << std::endl;
  // for (size_t i = 0; i < sequence.size(); ++i) {
  //   std::cout << sequence[i] << " ";
  // }
  std::cout << seq.size() - 1 << std::endl;
  for(size_t i = 0; i < seq.size(); i++){
    std::cout << seq[i] << " ";
  }
}
