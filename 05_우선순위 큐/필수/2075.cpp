#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n;

    //최소 힙으로 바꿔서 입력받기
    priority_queue<int, vector<int>, greater<int>> min_heap; // 최소 힙 사용

    // n줄에 걸쳐 n개의 정수 입력 (총 n*n개의 수 입력)
    for(int i = 0; i < n * n; i++){
        cin >> x;
        min_heap.push(x);
        
        // 힙 크기가 n을 초과하면 가장 작은 원소 제거
        if(min_heap.size() > n){
            min_heap.pop();
        }
    }
    
    // n번째로 큰 수 출력
    cout << min_heap.top() << "\n";
    
    return 0;
}