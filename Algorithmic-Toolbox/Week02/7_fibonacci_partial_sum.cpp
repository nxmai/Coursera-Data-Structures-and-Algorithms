#include <iostream>
#include <vector>
using std::vector;
using namespace std;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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

    return res;
}

long long get_fibonacci_partial_sum(long long from, long long to) {
    //ý tưởng của mình là đếm số bộ từ from tới to (số bộ pisano của 10), rồi đếm tổng các phần tử của 1 bộ
    //còn phần dư ra là từ cộng từ first tới last, nếu first lớn hơn last thì cộng từ first tới hết và từ 0 tới last
    // kết quả lấy số bộ * tổng bộ và tổng từ first tới last 

    vector<long long> pisano = pisanoarr(10);
    int numberofpisano = pisano.size();

    long long countNumber = to - from + 1;
    long long numberOfSet = countNumber / numberofpisano;

    long long first = from % numberofpisano;
    long long last = to % numberofpisano;

    int count1set = 0;
    for (int i = 0; i < pisano.size(); i++) {
        count1set += pisano[i];
        count1set %= 10;
    }

    int countfirsttolast = 0;
    if (first > last) {
        for (int i = first; i < numberofpisano; i++) {
            countfirsttolast += pisano[i];
            countfirsttolast %= 10;
        }
        for (int i = 0; i <= last; i++) {
            countfirsttolast += pisano[i];
            countfirsttolast %= 10;
        }

    }
    else {
        for (int i = first; i <= last; i++) {
            countfirsttolast += pisano[i];
            countfirsttolast %= 10;
        }
    }

    long long res = (count1set * numberOfSet + countfirsttolast);
    return res % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;

    cout << get_fibonacci_partial_sum(from, to);
}
