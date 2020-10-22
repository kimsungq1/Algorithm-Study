//���α׷��ӽ� - ���� ū��
/*
	������ ���� ���� ���Ϸ� ������ 3, 30 ���� ��� �ָ���
	���� ������ ��ó�� �� �����ϴ� ������ ��ħ
	���� ���� �� ���� �ذ����� ���� ������ ���� ��
*/
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) {
		return a.first > b.first;
	}
	else
		return a.second > b.second;

}

string solution(vector<int> numbers) {
	string answer = "";
	int size = numbers.size();
	//pair<���� ��, ��ó���� ��>
	vector<pair<int, int>> copy(size);
	//��ó��(ex. 3->3333, 30->3030, 300->3003, 3000->3000)
	for (int i = 0; i < size; i++) {
		copy[i].first = numbers[i];
		if (numbers[i] < 10) {
			copy[i].second = numbers[i] * 1000 + numbers[i] * 100 + numbers[i] * 10 + numbers[i];
		}
		else if (numbers[i] < 100) {
			copy[i].second = numbers[i] * 100 + numbers[i];
		}
		else if (numbers[i] < 1000) {
			copy[i].second = numbers[i] * 10 + numbers[i] / 100;
		}
	}
	sort(copy.begin(), copy.end(), cmp);

	for (int i = 0; i < size; i++) {
		answer += to_string(copy[i].first);
	}
	// 0 ����ó��
	if (answer[0] == '0') {
		answer = "0";
	}

	return answer;
}