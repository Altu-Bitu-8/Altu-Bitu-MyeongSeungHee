#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int max_result = INT_MIN;
int min_result = INT_MAX;

void backtrack(int idx, int current, const vector<int>& num, vector<int>& op) {
    if (idx == num.size()) {
        max_result = max(max_result, current);
        min_result = min(min_result, current);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (op[i] > 0) {
            op[i]--;
            int next = current;
            if (i == 0) next += num[idx];
            else if (i == 1) next -= num[idx];
            else if (i == 2) next *= num[idx];
            else if (i == 3) {
                if (next < 0) next = -(-next / num[idx]);
                else next /= num[idx];
            }
            backtrack(idx + 1, next, num, op);
            op[i]++;
        }
    }
}

int findMin(vector<int>& num, vector<int> op) {
    max_result = INT_MIN;
    min_result = INT_MAX;
    backtrack(1, num[0], num, op);
    return min_result;
}

int findMax(vector<int>& num, vector<int> op) {
    max_result = INT_MIN;
    min_result = INT_MAX;
    backtrack(1, num[0], num, op);
    return max_result;
}

int main() {
    int n;
    cin >> n;

    vector<int> num(n);
    vector<int> op(4); // + - * /

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    cout << findMax(num, op) << '\n';
    cout << findMin(num, op) << '\n';

    return 0;
}