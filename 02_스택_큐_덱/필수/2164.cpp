#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; //카드의 수
    cin >> n;

    queue<int> q;

    int count = 1;

    while(count <= n){
        q.push(count);
        count++;
    }

    int count2 = 1;

    while(q.size() > 1){
        if(count2 % 2 == 1){
            q.pop();
        } else if(count2 % 2 == 0){
            q.push(q.front());
            q.pop();
        }
        count2++;
    }

    cout << q.front() << "\n";

    return 0;
}