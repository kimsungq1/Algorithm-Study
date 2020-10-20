//BOJ-10773
#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n, temp;
    int sum = 0;
    stack<int> st;

    cin >> n;
    while(n--){
        cin >> temp;
        if(temp == 0 && !st.empty()){
            st.pop();
        } else {
            st.push(temp);
        }
    }
    while(!st.empty()){
        sum += st.top();
        st.pop();
    }

    cout << sum;
    return 0;
}