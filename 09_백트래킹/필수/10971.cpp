#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 100000000;
int N;
vector<vector<int>> W;
vector<bool> visited;
int minCost = INF;

void tsp(int start, int cur, int cost, int count) {
    if (count == N) {
        if (W[cur][start] != 0) { // 시작 도시로 돌아가는 경로 존재 시
            minCost = min(minCost, cost + W[cur][start]);
        }
        return;
    }

    for (int next = 0; next < N; next++) {
        if (!visited[next] && W[cur][next] != 0) {
            visited[next] = true;
            tsp(start, next, cost + W[cur][next], count + 1);
            visited[next] = false;
        }
    }
}

int main() {
    cin >> N;
    W.assign(N, vector<int>(N));
    visited.assign(N, false);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> W[i][j];

    visited[0] = true; // 시작 도시는 방문 처리
    tsp(0, 0, 0, 1);

    cout << minCost << endl;
    return 0;
}