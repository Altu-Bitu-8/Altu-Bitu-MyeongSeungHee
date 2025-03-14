#include <iostream>
#include <string.h>
#include <utility>

using namespace std;

void calculateLoc(string cmd, pair<string, int> &K_loc, pair<string, int> &S_loc){
    char k_col = K_loc.first[0]; // 킹의 현재 가로 위치(A부터 H 사이에만 있게)
    int k_row = K_loc.second;    // 킹의 현재 세로 위치(1부터 8 사이에만 있게)
    char s_col = S_loc.first[0]; // 돌의 현재 가로 위치
    int s_row = S_loc.second;    // 돌의 현재 세로 위치

    if (cmd == "R") { // 오른쪽
        if (k_col + 1 > 'H') return; //체스판을 벗어나면 그냥 함수가 끝나버리게
        if (k_col + 1 == s_col && k_row == s_row) {
            if (s_col + 1 > 'H') return;
            S_loc.first[0] += 1;
        }
        K_loc.first[0] += 1;
    }
    else if (cmd == "L") { // 왼쪽
        if (k_col - 1 < 'A') return;
        if (k_col - 1 == s_col && k_row == s_row) {
            if (s_col - 1 < 'A') return;
            S_loc.first[0] -= 1;
        }
        K_loc.first[0] -= 1;
    }
    else if (cmd == "B") { // 한 칸 아래
        if (k_row - 1 < 1) return;
        if (k_row - 1 == s_row && k_col == s_col) {
            if (s_row - 1 < 1) return;
            S_loc.second -= 1;
        }
        K_loc.second -= 1;
    }
    else if (cmd == "T") { // 한 칸 위
        if (k_row + 1 > 8) return;
        if (k_row + 1 == s_row && k_col == s_col) {
            if (s_row + 1 > 8) return;
            S_loc.second += 1;
        }
        K_loc.second += 1;
    }
    else if (cmd == "RT") { // 오른쪽 위 대각선
        if (k_col + 1 > 'H' || k_row + 1 > 8) return;
        if (k_col + 1 == s_col && k_row + 1 == s_row) {
            if (s_col + 1 > 'H' || s_row + 1 > 8) return;
            S_loc.first[0] += 1;
            S_loc.second += 1;
        }
        K_loc.first[0] += 1;
        K_loc.second += 1;
    }
    else if (cmd == "LT") { // 왼쪽 위 대각선
        if (k_col - 1 < 'A' || k_row + 1 > 8) return;
        if (k_col - 1 == s_col && k_row + 1 == s_row) {
            if (s_col - 1 < 'A' || s_row + 1 > 8) return;
            S_loc.first[0] -= 1;
            S_loc.second += 1;
        }
        K_loc.first[0] -= 1;
        K_loc.second += 1;
    }
    else if (cmd == "RB") { // 오른쪽 아래 대각선
        if (k_col + 1 > 'H' || k_row - 1 < 1) return;
        if (k_col + 1 == s_col && k_row - 1 == s_row) {
            if (s_col + 1 > 'H' || s_row - 1 < 1) return;
            S_loc.first[0] += 1;
            S_loc.second -= 1;
        }
        K_loc.first[0] += 1;
        K_loc.second -= 1;
    }
    else if (cmd == "LB") { // 왼쪽 아래 대각선
        if (k_col - 1 < 'A' || k_row - 1 < 1) return;
        if (k_col - 1 == s_col && k_row - 1 == s_row) {
            if (s_col - 1 < 'A' || s_row - 1 < 1) return;
            S_loc.first[0] -= 1;
            S_loc.second -= 1;
        }
        K_loc.first[0] -= 1;
        K_loc.second -= 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string K, S;
    int N;
    cin >> K >> S >> N;

    pair<string, int> K_loc = {string(1, K[0]), K[1] - '0'};
    pair<string, int> S_loc = {string(1, S[0]), S[1] - '0'};

    //연산
    while(N--){
        string cmd;
        cin >> cmd;
        calculateLoc(cmd, K_loc, S_loc);
    }

    //출력
    cout << K_loc.first << K_loc.second << "\n";
    cout << S_loc.first << S_loc.second << "\n";

    return 0;
}