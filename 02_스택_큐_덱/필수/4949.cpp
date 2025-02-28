#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string cmd = "";
    
    while(true){
        getline(cin, cmd);
        if (cmd == ".") break;

        stack<char> s;

        bool isBalanced = true;
        for (char ch : cmd) {
            if (ch == '(' || ch == '[') {
                s.push(ch);
            } 
            else if (ch == ')' || ch == ']') {
                if (s.empty()){
                    isBalanced = false;
                }
                
                char top = s.top();
                if ((ch == ')' && top == '(') || (ch == ']' && top == '[')) {
                    s.pop();
                } else {
                    isBalanced = false;
                }
            }
        }
        if(isBalanced && s.empty()){
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}