//프로그래머스-주식가격
#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    stack<int> st;
    // vector는 후에 push_back이 아닌 인덱스로 바로 접근 하므로 이와 같이 선언해야함
    vector<int> answer(size);
    // 스택 : 인덱스 처리
    for(int i=0; i<size; i++){
        while(!st.empty() && prices[st.top()] > prices[i]){
            answer[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    // 스택에 남아있는 값 처리
    while(!st.empty()){
        answer[st.top()] = size - st.top() - 1;
        st.pop();
    }
    
    return answer;
}