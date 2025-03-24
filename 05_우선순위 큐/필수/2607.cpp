#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, count = 0;
    string word;
    vector<int> spelling(26, 0);

    //입력
    cin >> N;
    cin >> word;
    for (char c : word) {
        spelling[c - 'A']++;
    } //알파벳 각 글자가 몇번 나왔는지 26 크기의 배열에 저장해주기

    //입력 겸 연산(근데 이렇게 입력이랑 연산을 같이 받아도 되나요? 따로 받는게 낫나요?)
    N -= 1; //첫 단어는 비교용으로 word로 입력받으니 하나 빼주기
    while(N--){
        string cmd;
        int plus = 0, minus = 0; //두 단어의 차이를 양, 음으로 비교

        cin >> cmd;
        vector<int> new_spelling(26, 0); //새로 들어오는 단어도 글자별 빈도수를 저장해줌
        for (char c : cmd) {
            new_spelling[c - 'A']++;
        }
        // 두 단어의 알파벳 빈도수 차이 계산
        for (int i = 0; i < 26; ++i) {
            if (spelling[i] > new_spelling[i]) {
                minus = minus + spelling[i] - new_spelling[i]; // 원래 단어에 더 많은 경우 (삭제해야 함)
            } else if (spelling[i] < new_spelling[i]) {
                plus = plus + new_spelling[i] - spelling[i]; // 새로운 단어에 더 많은 경우 (추가해야 함)
            }
        }

        // 한 글자를 추가/삭제/변경하여 같아질 수 있는 경우
        if ((plus == 1 && minus == 0) || (plus == 0 && minus == 1) || (plus == 1 && minus == 1) || (plus == 0 && minus == 0)) {
            count++;
        }
    }

    //출력
    cout << count;

    return 0;
}