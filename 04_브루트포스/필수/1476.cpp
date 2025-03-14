#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int E = 1, S = 1, M = 1, cnt = 1;
    
    int i_E, i_S, i_M;
    cin >> i_E >> i_S >> i_M;

    while (true) {
        if (i_E == E && i_S == S && i_M == M) {
            break;
        }
        
        E += 1;
        S += 1;
        M += 1;
        cnt += 1;

        if (E >= 16) E -= 15;
        if (S >= 29) S -= 28;
        if (M >= 20) M -= 19;
    }

    cout << cnt << endl;
    return 0;
}
