#include <iostream>
#include <vector>

using namespace std;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
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

long long get_fibonacci_huge_fast(long long n, long long m) {
    vector<long long> countPisano = pisano(m);
    long long size = countPisano.size();
   
    long long remainder = n % size;
    return countPisano[remainder];
}

int main() {
    long long n, m;
    std::cin >> n >> m;

    cout << get_fibonacci_huge_fast(n, m);
    
    return 0;
}
