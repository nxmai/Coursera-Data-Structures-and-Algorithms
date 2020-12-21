#include <iostream>
#include <vector>

using namespace std;

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

vector<long long> pisano(long long n) {
    vector<long long>res;

    res.push_back(0);
    res.push_back(1);

    for (long long i = 2; i <= n * n; i++) {
        res.push_back((res[i - 1] + res[i - 2]) % n);

        if (res[i] == 1 && res[i - 1] == 0)
            break;
    }

    res.pop_back();
    res.pop_back();

    return res;
}

long long int get_fibonacci_huge_fast(long long n, long long m) {
    vector<long long> countPisano = pisano(m);
    long long size = countPisano.size();

    long long remainder = n % size;
    if (countPisano[remainder] == 0)
        return 10;
    return countPisano[remainder];
}


int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n) << std::endl;

    //because sum(fn) = f(n+2) - 1 => = pisano f(n+2) - 1;
    cout << get_fibonacci_huge_fast(n + 2, 10) - 1;
}
