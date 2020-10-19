#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	vector<int> sub;
	int size = commands.size();
	for (int i = 0; i < size; i++) {
		sub = array;
		sort(sub.begin() + commands[i][0] - 1, sub.begin() + commands[i][1]);
		answer.push_back(sub[commands[i][0] + commands[i][2] - 2]);
	}
	return answer;
}