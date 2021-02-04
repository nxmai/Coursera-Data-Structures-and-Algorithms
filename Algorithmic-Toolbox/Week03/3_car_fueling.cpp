#include <iostream>
#include <vector>
using namespace std;

int main() {
	int dis, miles, n, val;
	vector<int> stops;

	cin >> dis >> miles >> n;
	for (int i = 0; i < n; i++) {
		cin >> val;
		stops.push_back(val);
	}
	stops.push_back(dis);

	int res = 0;
	int tmp = 0;
	int discango = miles;	//distance the driver can go with full tank from the lastest stop

	for (int i = 0; i < n + 1; i++) {
		if (stops[i] <= discango) {
			tmp = i;
		}
		else {
			if (tmp == -1) {
				res = -1;
				break;
			}
			discango = stops[tmp] + miles;
			res++;
			i--;
			tmp = -1;
		}
	}

	cout << res;

	return 0;
}