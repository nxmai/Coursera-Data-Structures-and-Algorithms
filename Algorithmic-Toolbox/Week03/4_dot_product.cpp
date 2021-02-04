#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	long n, val;
	vector<long> a;
	vector<long> b;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> val;
		a.push_back(val);
	}

	for (int i = 0; i < n; i++) {
		cin >> val;
		b.push_back(val);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	long res = 0;
	for (int i = 0; i < n; i++) {
		res += a[i] * b[i];
	}

	cout << res;

	return 0;
}