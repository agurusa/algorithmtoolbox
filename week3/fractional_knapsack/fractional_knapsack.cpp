#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

double get_optimal_value(long long capacity, vector<long long> weights, vector<long long> values) {
  double value = 0.0;
  vector<vector<float>>value_per_weight_vector;
  if(capacity == 0){
    return 0;
  }
  else{
    for(int i = 0; i < weights.size(); i++){
        float val_per_weight = float(values[i])/float(weights[i]);
        vector<float> temp_vector = {static_cast<float>(val_per_weight), static_cast<float>(i)};
        value_per_weight_vector.push_back(temp_vector);
    }
    std::sort(value_per_weight_vector.begin(), value_per_weight_vector.end(), [](
      const vector<float> &a, const vector<float> &b){
      return a[0] > b[0];
    });
    for(int i = 0; i < value_per_weight_vector.size(); i++){
      int temp_capacity = capacity;
      int index = value_per_weight_vector[i][1];
      if(temp_capacity == 0){
        break;
      }
      else if(weights[index] == 0){
        value += values[index];
        capacity -= weights[index];
      }
      else{
        float amount_of_item = float(temp_capacity)/float(weights[index]);
        if(amount_of_item >= 1){
          value+= values[index];
          capacity -= weights[index];
        }
        else{
          value+= values[index]*amount_of_item;
          capacity -= weights[index]*amount_of_item;
        }
      }
    }
  }
  return value;
}

int main() {
  long long n;
  long long capacity;
  std::cin >> n >> capacity;
  vector<long long> values(n);
  vector<long long> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
