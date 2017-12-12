#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

bool odd_size(int size){
  if(size%2!=0){
    return true;
  }
  else{
    return false;
  }
}


bool first_time_calculating_index(int item, int x, int index){
    // if the index is defaulted at 0, that means we're at the first time we're calculating this. Unless the first value is where x is.
  if(index == 0 && item!= x){
    return true;
  }
  // otherwise, that means we passed in a value of index to the function.
  else{
    return false;
  }
}

int get_index(const vector<int> &a, int x, int index){
  if(first_time_calculating_index(a[0], x, index)){
    std::cout << (int)a.size()/2 << " this is the first time index is calculated and here it is \n";
    return (int)a.size()/2;
  }
  else{
    std::cout << index << " this is the index passed into get_index and that's what it returns \n";
    return index;
  }
}

int binary_search(const vector<int> &a, int x, int index = 0){
  int temp_index = index;
  int left = 0, right = (int)a.size();
  // bool odd_sized = odd_size(right);
  int half = right/2;
  int item_at_half = a[half];
  index = get_index(a, x, index);
  vector<int>b;
  std::cout << item_at_half << " This is the item at half \n";
  //if the size of the vector is equal to 1 and the item_at_half is still not equal to x, the element
  // does not exist in the vector.
  if(item_at_half!=x && right == 1){
    return -1;
  }
  // if the item_at_half is greater than x, then x must exist in the first half of the vector
  else if(item_at_half > x){
    if(first_time_calculating_index(a[0], x, temp_index)== false){
      index = right - half;
    }
    for(int i = 0; i < half; i++){
      b.push_back(a[i]);
    }
    binary_search(b, x, index);
  }
  // otherwise, if the item_at_half is less than x, then x must exist in the second half of the vector
  else if(item_at_half < x){
    if(first_time_calculating_index(a[0], x, temp_index)== false){
      index += half;
    }
    for(int i = half; i < right; i++){
      b.push_back(a[i]);
    }
    binary_search(b, x, index);
  }
  // otherwise, if the item_at_half is equal to x, we have to calculate its position in the original vector.
  else if(item_at_half == x){
    return index;
  }
}


// int binary_search_wrapper(const vector<int> &a, int x){
//   int halved_count = 0;
//   int original_size = (int)a.size();
  // for every time that binary_search is run, we have to add one to the halved_count. This is because we need to
  //keep track of what index number we're on. When we find the number in the vector, we use halved_count
  //to calculate where we are in the vector. If x is in the second half of the vector, we use 
  //half of the original_size. Then the second time it is halved, if it is in the first part of the vector
  //we use half the original size + half that amount. If it is in the second part of the vector, we use 
  // half the original size + the size of the vector. In other words, if vector_at_half < x, index += vector_size.
  // if vector_at_half > x, index-=
// }

// int binary_search(const vector<int> &a, int x) {
//   int left = 0, right = (int)a.size(); 
//   //this will always round down
//   int half = right/2;
//   int vector_at_half = a[half];
//   //if the vector is an odd number of elements, the size of the derivative vectors will be
//   //vector.size()/2 AND vector.size()/2 + 1. The one with the smaller elements will the shorter
//   //and the one with the larger elements will be the +1.
//   // vector<int> b(half);
//   //if the size of the vector that we're searching is 1, that means that we went through the whole thing and either this is the number, or it doesn't exist.
//   if((int)a.size() == 1 && vector_at_half != x){
//     std::cout << "here \n";
//     return -1;  
//   }
//   //if x is larger than the midpoint, we have to search the second half of the vector.
//   else if(vector_at_half < x){
//     if((int)a.size()%2 != 0){
//       vector<int> b(half + 1);
//       int j=0;
//       for(int i = half; i < right; i++){
//         b[j] = a[i];
//         j++;
//       }
//       binary_search(b, x);
//     }
//     else{
//       vector<int> b(half);
//       int j=0;
//       for(int i = half; i < right; i++){
//         b[j] = a[i];
//         j++;
//       }
//       binary_search(b, x);
//     }
//   }
//   //if x is smaller than the midpoint, we have to search the first half.
//   else if(vector_at_half > x){
//     vector<int> b(half);
//     for(int i = 0; i < half; i++){
//       b[i] = a[i];
//     }
//     binary_search(b, x);
//   }
//   else if(vector_at_half == x){
//     //this won't work because half is dependent on the size of the vector you're searching, 
//     //which is not the same as the size of the original vector.
//     return half;
//   }
//   else{
//     std::cout << "hitting here \n";
//     return -1;
//   }
// }

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
    std::cout << binary_search(a, b[i]) << " this is the answer \n";
    // binary_search(a, b[i]);
  }
}
