#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int main() {
    stack<int> st;
    char s[101];
    int temp;
 
    cin >> s;
    for(char c : s){
        if(isdigit(c)){
            temp = c - '0';
            st.push();
        } else {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
    
            switch(c){
                case '+':
                    temp = a+b;
                    st.push(temp);
                    break;
                case '-':
                    temp = a-b;
                    st.push(temp);
                    break;
                case '*':
                    temp = a*b;
                    st.push(temp);
                    break;
                case '/':
                    temp = a/b;
                    st.push(temp);
                break;
            }
        }
    }
    cout << st.top();
    return 0;
}
