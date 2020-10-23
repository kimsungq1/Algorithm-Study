//[프로그래머스]기능개발
#include <cmath>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;

    for (int i = 0; i < progresses.size(); i++) {
        //완료에 걸리는 일수 계산
        progresses[i] = ceil((100 - progresses[i]) / (double)speeds[i]);
        if(q.empty()){
            q.push(progresses[i]);
            continue;
        }
        else {
            //더 긴 작업 등장 시 큐 비우기
            if(q.front() < progresses[i]){
                answer.push_back(q.size());
                while(!q.empty()){
                    q.pop();
                }
            }
            q.push(progresses[i]);
        }
    }

    if(!q.empty())
        answer.push_back(q.size());
    
    return answer;
}