#include<iostream>
#include <vector>

using namespace std;

int countBlock(int n) {
    //블록배치의 종류를 저장할 배열 선언
    vector<int> dp(n + 1, 0);
    
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= n; i++) {
        // 맨 끝이 세로인 경우(dp[i-1])와 맨 끝이 가로인 경우(dp[i-2])를 더해주기
        dp[i] = dp[i - 1]+dp[i - 2];
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    
    int ans = countBlock(n);
    ans %= 10007;
    
    cout << ans;
    return 0;
}