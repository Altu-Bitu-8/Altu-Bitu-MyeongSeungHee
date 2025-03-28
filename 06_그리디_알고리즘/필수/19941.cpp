#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K; //개수와 손의 범위위
    cin >> N >> K;
    int count = 0, p = 0, b = 0; //정답 변수와 인덱스로 사용할 변수들들
    
    string table;
    cin >> table;
    
    vector<int> people, burgers;

    // 사람 배열과 햄버거 배열에 위치(인덱스) 저장
    for (int i = 0; i < N; i++) {
        if (table[i] == 'P') {
            people.push_back(i);
        } else if (table[i] == 'H') {
            burgers.push_back(i);
        }
    }

    while (p < people.size() && b < burgers.size()) {
        if (abs(people[p] - burgers[b]) <= K) { // 사람이 햄버거를 먹을 수 있는 거리라면
            count++;
            p++;
            b++;
        } else if (people[p] > burgers[b]) { // 햄버거가 사람이 있는 곳보다 왼쪽이면
            b++; // 다음 햄버거로 이동
        } else { // 사람이 햄버거보다 왼쪽이면
            p++; // 다음 사람으로 이동
        }
    }

    cout << count << endl;
    return 0;
}
