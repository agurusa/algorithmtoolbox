#include <iostream>
#include <cassert>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int fib_fast(int n) {
    int fib_array [n];
    if (n <= 1){
        return n;
    }
    else{
        for(int i = 0; i <2; i++){
            fib_array[i] = i;
        }
        for(int i = 2; i <= n; i++){
            int result = 0;
            result = (fib_array[i-2] + fib_array[i-1])%10;
            fib_array[i] = result;
            // std::cout << fib_array[i]<<'\n';
        }
    }
    return fib_array[n];
}

void test_solution(){
    assert(fib_fast(3) == 2);
    assert(fib_fast(10) == 5);
    for (int n = 0; n < 200; ++n){
        std::cout<< "this is the n it failed on";
        std::cout<< n << '\n';
        assert(get_fibonacci_last_digit_naive(n) == fib_fast(n));
    }
}

int main() {
    int n;
    std::cin >> n;
    // int c = get_fibonacci_last_digit_naive(n);
    // std::cout << c << '\n';
    // test_solution();
    std::cout << fib_fast(n);
    }
