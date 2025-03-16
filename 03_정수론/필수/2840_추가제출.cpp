#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, char> ic; //바퀴 돌릴 때 쓸 바퀴 칸의 글자가 바뀌는 횟수와 그 안의 글자를 저장할 pair타입 변수 선언언
const int ALPHA = 26; //중복 검사를 위한 알파벳 26개 변수 설정정

//index부터 시계방향으로 바퀴에 적어놓은 알파벳 출력
string printWheel(int n, int index, vector<char>& wheel) {
    string ans = ""; // 바퀴 칸별 문자를 축적할 변수수
    //바퀴를 돌릴 때와 반대방향으로 출력
    for (int i = index + n; i > index; i--) {
        ans += wheel[i % n]; //n으로 한번 모듈러 연산 - n 안의 값으로 만들어 ans에 축적적
    }
    return ans; //ans 반환
}

//행운의 바퀴 반환
string makeWheel(int n, int k, vector<ic>& record) {
    vector<char> wheel(n, '?'); //바퀴의 모든 알파벳을 ?로 초기화
    vector<bool> is_available(ALPHA, false); // 알파벳 중복 체크

    int index = 0; //화살표가 가리키는 인덱스

    for (int i = 0; i < k; i++) {
        int s = record[i].first; //화살표가 가리키는 글자가 변하는 횟수
        char ch = record[i].second; //회전을 멈추었을 때 가리키던 글자

        index = (index + s) % n; //회전한 후 화살표가 가리키는 인덱스

        //해당 칸이 ch로 이미 채워져 있는 경우 넘어감
        if (wheel[index] == ch) {
            continue;
        }

        //다른 글자로 채워져있거나 해당 글자가 이미 사용된 알파벳인 경우 ! 반환
        if (wheel[index] != '?' || is_available[ch - 'A']) {
            return "!";
        }

        wheel[index] = ch; //해당 칸에 글자 적기
        is_available[ch - 'A'] = true; //해당 알파벳이 사용되었으므로 true로 변경
    }
    return printWheel(n, index, wheel); //돌리는 횟수, 인덱스, 바퀴 변수 반환환
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); // 입출력 최적화

    //입력
    int n, k;
    cin >> n >> k;

    vector<ic> record(k); //ic 변수를 k 길이로 선언(얼마나 돌릴지)
    for (int i = 0; i < k; i++) {
        cin >> record[i].first >> record[i].second; // record[i].first에는 돌리는 횟수, record[i].second에는 돌아간 후 가리킬 문자
    }

    //연산 & 출력
    cout << makeWheel(n, k, record);

    return 0;
}