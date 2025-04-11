#include<iostream>
#include<cstring> // for memset

using namespace std;

int n; // 컴퓨터 수
int m; // 연결된 쌍의 수
int graph[101][101] = {0,}; //그래프 배열
bool visited[101] = {false,}; // 방문 배열
int infected = 0; // 감염된 컴퓨터 수 (1번 제외하고 셈)

void dfs(int from) {
	for (int i = 1; i <= n; ++i) {
		if (graph[from][i] == 1 && !visited[i]) {
			visited[i] = true;
			infected++; // 방문(감염)한 컴퓨터 수 증가
			dfs(i);
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = graph[b][a] = 1; // 양방향 연결
	}

	visited[1] = true; // 1번 컴퓨터에서 시작 (이미 감염)
	dfs(1);

	cout << infected << '\n';
	return 0;
}