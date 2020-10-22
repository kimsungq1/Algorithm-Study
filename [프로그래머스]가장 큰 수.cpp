//프로그래머스 - 가장 큰수
/*
	정렬을 통해 값을 비교하려 했지만 3, 30 같은 경우 애매함
	따라서 데이터 전처리 후 정렬하는 과정을 거침
	정렬 문제 중 같은 해결방법을 가진 문제가 많을 듯
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
	//pair<원래 값, 전처리한 값>
	vector<pair<int, int>> copy(size);
	//전처리(ex. 3->3333, 30->3030, 300->3003, 3000->3000)
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
	// 0 예외처리
	if (answer[0] == '0') {
		answer = "0";
	}

	return answer;
}