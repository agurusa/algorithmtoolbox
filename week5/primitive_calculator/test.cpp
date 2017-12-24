#include <iostream>

int test_recursive(int count = 0){
	std::cout << count << " this is count \n";
	if(count == 4){
		std::cout <<"i finished \n";
		return count;
	}
	else{
		count++;
		return test_recursive(count);
	}
}

int main(){
	std::cout << test_recursive() << " this is my answer ";
}