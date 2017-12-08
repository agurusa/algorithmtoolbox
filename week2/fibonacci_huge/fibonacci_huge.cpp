#include <iostream> 
#include <vector>
#include <array>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

bool is_prime(int a){
    for(int i = 2; i < a; i++){
        if (a % i == 0){
            return false;
        }
    }
    return true;
}


long long gcd_fast(int a, int b) {
    if(b == 0){
        return a;
    }
    else{
        return gcd_fast(b, a%b);
    }
}

long long lcm_fast(long long int a, long long int b) {  
    long long product = a * b;
    long long gcd = gcd_fast(a , b);
    long long lcm = product/gcd;
    return lcm;
}


bool is_start_of_period(long long period_snippet[3]){
    long long period_start[3] = {0, 1, 1};
    if(period_snippet == period_start){
        return true;
    }
    else{
        return false;
    }
}

long long period_length_func(long long index){
    if(index == 0){
        return 0;
    }
    else if (index == 1 || index == 2){
        return 1;
    }
    else if (index == 3){
        return 3;
    }
    // //this is true if m is already a number in the fib series. 
    // else if (index%2 == 0){
    //     return 2*index;
    // }
    // //this is true if m is already a number in the fib series. 
    // else if (index%2 != 0 && index > 5){
    //     return 4*index;
    // }
    else{
        return index*index + 1;
    }
}
long long fib_mod_fast(long long n,long long m){
    std::vector<long long> fib_vector;
    std::vector<long long> fib_mod_vector;
    fib_vector.push_back(0);
    fib_vector.push_back(1);
    fib_mod_vector.push_back(0);
    fib_mod_vector.push_back(1);
    long long period_length = std::min(n + 1, period_length_func(n));
    for(int i = 2; i <= period_length; i++){
        std::cout << i << "this is i \n";
        long long fib_number = fib_vector.at(i-2) + fib_vector.at(i-1);
        fib_vector.push_back(fib_number);
        std::cout << fib_number;
        std::cout << "fib number" << '\n';
        long long fib_mod_number = fib_number%m;
        std::cout << fib_mod_number<< '\n';
        fib_mod_vector.push_back(fib_mod_number);
        if(fib_mod_number == 1 && fib_mod_vector.at(i-1) == 0){
            period_length = fib_mod_vector.size();
            break;
        }
    }
    long long remainder = n%period_length;
    return fib_vector.at(remainder) % m;
}


int main() {
    long long n, m;
    std::cin >> n >> m;
    // std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << fib_mod_fast(n,m);
}
