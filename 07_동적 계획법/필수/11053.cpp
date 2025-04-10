#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, a[1001], dp[1001];
    cin >> n;

    int max_len = 0; //최장 LIS 길이

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i] = 1;

        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1); //해당 위치의 LIS 길이
            }
        }

        max_len = max(max_len, dp[i]); //전체 수열에서의 LIS 길이 업데이트
    }

    cout << max_len << "\n";
    return 0;
}
