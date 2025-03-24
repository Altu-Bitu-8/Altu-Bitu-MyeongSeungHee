#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
 * [HINT]
 * 우선 m개의 줄을 만들고, 각 줄의 선두끼리 우선순위를 따져야겠네요!
 * 데카가 언제 화장실을 쓰는지 알기 위해서는 화장실에 온 순서도 기록해야 해요!
 */

struct info {
    int idx;        // 처음 줄에 선 번호
    int line_num;   // m개의 줄 중 속한 줄의 번호
    int work_days;  // 근무 일수
    int urgency;    // 급한 정도
};

struct cmp {
    bool operator()(const info &child, const info &parent) {
        if (parent.work_days != child.work_days) {
            return parent.work_days > child.work_days; //cmp 비교의 최우선순위는 work_days
        }
        if (parent.urgency != child.urgency) {
            return parent.urgency > child.urgency; //work_days가 똑같으면 urgency
        }
        return parent.line_num < child.line_num; //urgency가 똑같으면 line_num으로 비교
    }
};

int simulation(int m, int k, vector<queue<info>> &lines) { //줄 개수와 데카의 순서, lines 벡터를 입력받아 계산하는 함수
    // 각 줄의 선두들이 저장되는 우선순위 큐
    priority_queue<info, vector<info>, cmp> pq;

    // 우선순위 큐 초기화
    for (int i = 0; i < m; i++) {
        if (!lines[i].empty()) { //줄이 비어있지 않은 경우 if가 실행됨(pop이 끝나면 자동 종료)
            pq.push(lines[i].front()); //우선순위 큐에 줄의 맨 앞 직원을 넣음(맨 앞 줄 직원들을 근속일수, 긴급도, 줄번호로 비교하는 과정)
            lines[i].pop(); //lines의 i번째 멤버를 pop함
        }
    }

    // k 차례가 오기 전 화장실을 사용한 사람의 수(출력해야하는 정보)
    int count = 0;

    while (!pq.empty() && pq.top().idx != k) {  // k의 차례가 되기 전까지
        int line_num = pq.top().line_num; //우선순위 큐의 최상위(줄의 맨앞 직원들 중에서도 가장 우선순위가 높은 직원)
        pq.pop(); //최상위 직원이 화장실을 가는 것

        if (!lines[line_num].empty()) { //방금 화장실을 간 최상위 직원이 그 줄의 마지막 멤버가 아닐 경우(남은 사람이 있으면)
            pq.push(lines[line_num].front()); //우선순위 큐에 그 줄의 맨 앞 직원이 들어옴
            lines[line_num].pop(); //그 직원을 줄 벡터에서는 제거함
        }

        count++; //k 앞의 직원이 화장실을 갔으니 count를 하나 늘려줌
    }

    return count; //결과 리턴
}

/**
 * [화장실의 규칙] - 우선순위 큐 & 시뮬레이션 문제
 *
 * 1. 각 사람은 (온 순서 % m) 번째 줄의 뒤에 서게 된다.
 * 2. 매 순간, 모든 줄의 앞 사람 중에 우선 순위가 가장 높은 사람부터 화장실을 이용한다.
 *
 * <우선순위>
 * 1. 근무 일자가 많은 사람(D)
 * 2. 더 급한 사람(H)
 * 3. 줄 번호가 앞선 사람(N % M)
 *
 * ---
 * 1. 각 줄은 먼저 온 사람이 먼저 나가기 때문에, 큐를 이용해 저장한다.
 * 2. 모든 줄의 선두를 우선순위 큐에 넣고, 우선순위가 가장 앞선 사람부터 삭제한다.
 * 3. 어떤 줄의 선두가 화장실을 이용했으면, 그 줄의 선두를 우선 순위 큐에 넣는다.
 *
 * 이때, 0번부터 표기하므로 데카의 idx는 k가 된다.
 *
 * !주의! 큐에서 사람을 빼서 우선 순위 큐에 넣을 때, 항상 큐가 비어있지 않은지 확인
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); //입출력 최적화 함수

    int n, m, k, d, h; //전체 인원, 줄 개수, 데카의 순서, 근속일수, 화장실 가고싶은 정도를 각각 변수로 선언
    cin >> n >> m >> k; //전체 인원, 줄 개수, 데카의 순서를 입력받음

    vector<queue<info>> lines(m, queue<info>()); //info 우선순위 큐의 벡터인 lines를 선언함(크기를 m으로 지정함)

    // 입력
    for (int i = 0; i < n; i++) {
        cin >> d >> h; //각 직원마다 근속일수와 화장실 가고싶은 정도를 입력받음
        lines[i % m].push({i, i % m, d, h}); //i를 줄의 수로 나눈 나머지 번째의 줄에 이 직원을 넣음
        //(idx = i, line_num = i % m, work_days = d, urgency = h)
    }

    // 연산 & 출력
    cout << simulation(m, k, lines); //m과 k, lines로 simulation한 결과(데카의 차례)

    return 0;
}
