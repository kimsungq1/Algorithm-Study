#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, sum = 0, temp;
	vector<int> first;
	vector<int> second;
	//�Է�
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		first.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		cin >> temp;
		second.push_back(temp);
	}
	//����
	sort(first.begin(), first.end());
	sort(second.begin(), second.end(), greater<>());
	//���
	for (int i = 0; i < n; i++) {
		sum += first[i] * second[i];
	}
	//���
	cout << sum;
}