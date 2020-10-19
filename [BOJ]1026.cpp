#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, sum = 0, temp;
	vector<int> first;
	vector<int> second;
	//입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		first.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		cin >> temp;
		second.push_back(temp);
	}
	//정렬
	sort(first.begin(), first.end());
	sort(second.begin(), second.end(), greater<>());
	//계산
	for (int i = 0; i < n; i++) {
		sum += first[i] * second[i];
	}
	//출력
	cout << sum;
}