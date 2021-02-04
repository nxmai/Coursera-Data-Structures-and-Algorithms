#include <iostream>
using namespace std;

int moneyChange(int n) {
	int res = n / 10;
	n %= 10;
	res += n / 5;
	n %= 5;
	res += n;
	 
	return res;
}

int main() {
	int n;
	cin >> n;
	cout << moneyChange(n);
}