//BOJ-17298(오큰수)
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	//인덱스를 저장할 스택
	stack<int> st;
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> answer(n);
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	for(int i=0; i<n; i++){
		while(!st.empty() && arr[i] > arr[st.top()])
		{
			answer[st.top()] = arr[i];
			st.pop();
		}
		st.push(i);
	}
	//스택에 남아있는 것은 오큰수가 없는 경우
	while(!st.empty()){
		answer[st.top()] = -1;
		st.pop();
	}
	
	for(int i=0; i<answer.size(); i++){
		cout << answer[i] << ' ';
	}
	
	return 0;
}