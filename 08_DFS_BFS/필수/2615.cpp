#include <iostream>
using namespace std;

int board[19][19];
int dx[4] = {0, 1, 1, -1}; // → ↓ ↘ ↙
int dy[4] = {1, 0, 1, 1};
int x, y;

bool isInRange(int nx, int ny) {
    return nx >= 0 && nx < 19 && ny >= 0 && ny < 19;
}

int dfs(int r, int c, int color, int dir) {
    int cnt = 1;
    int nx = r + dx[dir];
    int ny = c + dy[dir];

    while (isInRange(nx, ny) && board[nx][ny] == color) {
        cnt++;
        nx += dx[dir];
        ny += dy[dir];
    }

    // 6목 체크: 앞뒤 모두 봐야 함
    int prevX = r - dx[dir];
    int prevY = c - dy[dir];
    if (isInRange(prevX, prevY) && board[prevX][prevY] == color) return 0;
    if (isInRange(nx, ny) && board[nx][ny] == color) return 0;

    if (cnt == 5) {
        x = r + 1;
        y = c + 1;
        return color;
    }
    return 0;
}

int main() {
    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 19; j++)
            cin >> board[i][j];

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (board[i][j] != 0) {
                for (int dir = 0; dir < 4; dir++) {
                    int result = dfs(i, j, board[i][j], dir);
                    if (result != 0) {
                        cout << result << '\n' << x << ' ' << y << '\n';
                        return 0;
                    }
                }
            }
        }
    }
    cout << 0 << '\n';
    return 0;
}

