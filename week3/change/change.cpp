#include <iostream>
#include <vector>

int get_change(int m) {
	int amount = m;
	int coins = 0;
	std::vector<int> coin_vector = {10, 5, 1};
	for(int i = 0; i < coin_vector.size(); i++){
		int temp_amount = amount;
		amount = amount%coin_vector[i];
		coins+= temp_amount/coin_vector[i];
	}
  return coins;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
