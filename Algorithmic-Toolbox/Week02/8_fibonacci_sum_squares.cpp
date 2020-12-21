#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

vector<long long> pisanoarr(long long n) {
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

    for (int i = 0; i < res.size(); i++) {
        res[i] = ((res[i] * res[i])) % n;
    }

    return res;
}

int get_fibonacci_sum_square(long long n, long long m) {
    vector<long long> countPisano = pisanoarr(m);
    long long size = countPisano.size();

    long long numberofset = n / size;
    int countnumberofpisano = 0;
    for (int i = 0; i < countPisano.size(); i++) {
        countnumberofpisano += countPisano[i];
        countnumberofpisano %= 10;
    }

    int countoddset = 0;
    for (int i = 0; i <= n % size; i++) {
        countoddset += countPisano[i];
        countoddset %= 10;
    }

    return (countnumberofpisano * numberofset + countoddset) % m;
}

int main() {
    long long n = 0;
    std::cin >> n;
    cout << get_fibonacci_sum_square(n, 10);
}
