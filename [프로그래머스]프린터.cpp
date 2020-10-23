//프로그래머스-프린터
#include <string>
#include <vector>
#include <deque>
#include <utility>

using namespace std;

int solution(vector<int> priorities, int location) {
    deque<pair<int, int>> dq;
    vector<int> v;
    int answer;
    for (int i = 0; i < priorities.size(); i++) {
        dq.push_back(make_pair(i, priorities[i]));
    }
    while(!dq.empty()) {
        pair<int, int> temp = dq.front();
        dq.pop_front();
        bool flag = true;
        for(int i = 0; i < dq.size(); i++){
            if(temp.second < dq[i].second){
                flag = false;
                break;
            }
        }
        if(flag){
            v.push_back(temp.first);
        } else {
            dq.push_back(temp);
        }
    }
    for (int i = 0; i < v.size(); i++) {
        if(v[i] == location){
            answer = i+1;
        }
    }

    return answer;
}