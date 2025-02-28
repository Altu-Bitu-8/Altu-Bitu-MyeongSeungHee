#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string A, B;
    cin >> A >> B;

    while(A.length() < B.length()){
        A = "0" + A;
    }
    while (B.length() < A.length()) {
        B = "0" + B;  // B가 더 짧으면 앞에 0을 추가
    }

    stack<char> result;
    int carry = 0;

    for(int i = A.length() - 1; i >= 0; i--){
        int sum = (A[i] - '0') + (B[i] - '0') + carry;
        carry = sum / 10;
        result.push((sum % 10) + '0');
    }

    if(carry > 0){
        result.push(carry + '0');
    }

    while(result.empty() == false){
        cout << result.top();
        result.pop();
    }

    cout << endl;
    return 0;
}