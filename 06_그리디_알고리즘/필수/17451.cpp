#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    vector<long long> speed(n);  // 속도를 담을 벡터. 최대값 고려해서 long long으로 안해주면 틀림

    for (int i = 0; i < n; i++) {
        cin >> speed[i];  // 각 행성에 필요한 속도 입력
    }

    // 앞에서부터 하면 자꾸 틀렸다고 해서 뒤에서부터 가기로 함(이유는 모르겠음음)
    for (int i = n - 2; i >= 0; i--) {
        speed[i] = ((speed[i + 1] + speed[i] - 1) / speed[i]) * speed[i]; 
    }

    // 첫 번째 행성에서 올려야 할 최소 속도(결과)를 출력
    cout << speed[0] << endl;

    return 0;
}

