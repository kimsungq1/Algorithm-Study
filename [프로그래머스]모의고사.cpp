#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int cnt_a = 0, cnt_b = 0, cnt_c = 0;
	int a[] = { 1,2,3,4,5 };
	int b[] = { 2,1,2,3,2,4,2,5 };
	int c[] = { 3,3,1,1,2,2,4,4,5,5 };
	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == a[i % 5]) {
			cnt_a += 1;
		}
		if (answers[i] == b[i % 8]) {
			cnt_b += 1;
		}
		if (answers[i] == c[i % 10]) {
			cnt_c += 1;
		}
	}

	int max_cnt = max(cnt_a, max(cnt_b, cnt_c));
	if (max_cnt == cnt_a) answer.push_back(1);
	if (max_cnt == cnt_b) answer.push_back(2);
	if (max_cnt == cnt_c) answer.push_back(3);

	return answer;
}