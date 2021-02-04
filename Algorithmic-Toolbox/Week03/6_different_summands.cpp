#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

//
vector<int> maximum_number_of_prices(int n)
{
	double delta = 0.25 + 2 * n;
	int size = (int)(-0.5 + sqrt(delta));

	vector<int>res;
	for (int i = 1; i < size; i++) {
		res.push_back(i);
	}

	res.push_back(n - (size - 1) * size / 2);
	return res;
}

int main() {
	int n;
	cin >> n;
	vector<int> res = maximum_number_of_prices(n);

	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}

	return 0;
}