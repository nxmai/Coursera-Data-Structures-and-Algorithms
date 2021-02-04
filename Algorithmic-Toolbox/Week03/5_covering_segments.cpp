#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sortbysec(const pair<int, int>& a, const pair<int, int>& b)
{
	return (a.second < b.second);
}

vector<int> covering_segments(vector<pair<int, int>>segments) {
	sort(segments.begin(), segments.end(), sortbysec);

	vector<int>points;
	int point = segments[0].second;
	points.push_back(point);

	for (int i = 1; i < segments.size(); i++) {
		if (point < segments[i].first || point > segments[i].second) {
			point = segments[i].second;
			points.push_back(point);
		}
	}

	return points;
}

int main()
{
	int n, tmp1, tmp2;
	cin >> n;
	vector<pair<int, int>>segments;

	for (int i = 0; i < n; i++) {
		cin >> tmp1 >> tmp2;
		segments.push_back({ tmp1, tmp2 });
	}

	vector<int> res = covering_segments(segments);

	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}

	return 0;
}