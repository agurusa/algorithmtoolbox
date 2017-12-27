#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

// what is the minimum number of coins needed to change x cents fo denominations of coins?
// x starts at 0 and moves up until we get to the actual coin we're looking for.
int change(int money){
  std::vector<int> coins = {1, 5, 6};
  std::map<int, int> minNumCoins = {
    {0 , 0}
  };

  for(int m = 1; m <= money; m++){
    minNumCoins[m] = m;
    for(int i = 0; i < coins.size(); i++){
      int coin = coins[i];
      if(m >= coin){
        int num_coins = minNumCoins[m-coin]+1;
        if(num_coins < minNumCoins[m]){
          minNumCoins[m] = num_coins;
        }
      }
    }
  }
  return minNumCoins[money];
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> num_of_coins_vector;
  std::cout << change(n);
}