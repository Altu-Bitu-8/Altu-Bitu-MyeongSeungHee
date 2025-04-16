#include<iostream>

using namespace std;

int graph[101][101] = {0,}; // 그래프
int visited[101] = {false, }; // 방문 여부
int p1, p2; // 촌수를 계산해야하는 서로 다른 두 사람의 번호

int n; //전체 사람의 수
int m; // 부모 자식들 간의 관계의 개수

int dfs(int from) { //dfs로 해결

	int ret = -1; //리턴할 두 사람의 촌수(관계가 없으면 -1을 출력해야 하므로 디폴트는 -1)

	if (graph[from][p2] == 1) { //p1과 p2가 부모자식 관계라면 이미 그래프의 값이 1
		return 1; //그대로 리턴해 줌
	}

	else {
		for (int i = 1; i <= n; ++i) { //1부터 n까지 루프를 돌며 검사
			if (i == from) {
				continue; // 자기를 참조할 때는 건너뜀
			}
			if (graph[from][i] == 1 && !visited[i]) { // 사람이 연결 되어있고, 참조하지 않은 사람이라면 dfs 함수 호출
				visited[i] = true; //참조하지 않았으므로 방문여부를 true로 표시
				ret = max(ret, dfs(i)); //i를 시작점으로 다시 dfs를 탐색하고, 이 값이 기존 ret보다 크다면 업데이트
			}
		}
	}
	if (ret != -1) {
		ret += 1; //dfs(i)로 결정된 경우 지금의 ret값은 i->p2이므로 from->i->p2를 계산하기 위해 +1해줌
	}
	return ret; //촌수값 리턴

}

int main() {
	cin >> n; //전체 사람 수 입력받기
	cin >> p1 >> p2; //촌수관계를 계산해야 하는 p1과 p2 입력받기
	cin >> m; //부모자식 관계의 개수인 m을 입력받기

	for (int i = 0; i < m; ++i) { // 부모 자식간의 관계의 개수 m 개 입력
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		graph[tmp1][tmp2] = graph[tmp2][tmp1] = 1; //이중배열에서 입력받은 관계를 1로 바꿈
	}

	int ans = dfs(p1); // dfs 함수 호출
	cout << ans;
}