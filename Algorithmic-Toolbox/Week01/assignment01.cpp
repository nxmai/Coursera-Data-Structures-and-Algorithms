#include <iostream>
#include <vector>

using namespace std;

long long MaxPairWiseProductFast(const vector<int>numbers) {
	int n = numbers.size();

	int maxIndex1 = -1;
	for (int i = 0; i < n; i++) {
		if ((maxIndex1 == -1) || (numbers[i] > numbers[maxIndex1]))
			maxIndex1 = i;
	}

	int maxIndex2 = -1;
	for (int i = 0; i < n; i++) {
		if ((i != maxIndex1) && ((maxIndex2 == -1) || (numbers[i] > numbers[maxIndex2])))
			maxIndex2 = i;
	}

	return ((long long)(numbers[maxIndex1])) * numbers[maxIndex2];
}

int main() {
	int n, x;
	cin >> n;

	vector<int>numbers;
	for (int i = 0; i < n; i++) {
		cin >> x;
		numbers.push_back(x);
	}

	cout << MaxPairWiseProductFast(numbers);
}