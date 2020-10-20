//BOJ-12605
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    int x = 0;
    string line;
    string temp = "";
    stack<string> st;
    
    cin >> n;
    cin.ignore();
    while(n--){
        getline(cin, line);
        line += '\n';
        for(auto ch:line){
            if(ch == ' ' || ch == '\n'){
                st.push(temp);
                temp = "";
            } else {
                temp += ch;
            }
        }
        x++;
        cout << "Case #" << x << ": ";
        while(!st.empty()){
            cout << st.top() << ' ';
            st.pop();
        }
        cout << '\n';
    }

    return 0;
}