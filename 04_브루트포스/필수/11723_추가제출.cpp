// 11723: 집합 (실버5/비트마스킹)
#include <iostream>
using namespace std;
/**[백준 11723] 집합
/* - vector나 map으로 각 원소의 유무를 판단할 경우 시간초과 발생!
/*   => 총 원소의 개수는 20. 32비트 크기 int의 각 bit에 원소의 유무를 저장
/* - value의 i번째 bit가 1이면: 현재 집합에 i 존재 O
/* - value의 i번째 bit가 1이면: 현재 집합에 i 존재 X
 */

void all(int &s)//s를 1~20으로 바꾸는 연산. &로 s에 write되도록 함
{
    s = (1 << 21) - 1; //하위 21비트를 모두 1로 채워 20개의 수를 나타냄
}

void empty(int &s)//s를 공집합으로 바꾸는 연산
{
    s = 0; //그냥 0으로 비움
}

void add(int &s, int n) //s에 x를 추가하는 연산산
{
    s |= (1 << n); //s와 n부분이 1인 수를 or연산, n이 있는 것으로 처리되는 연산
}

void remove(int &s, int n) //s에서 n을 제거하는 연산
{
    s &= ~(1 << n); //n번째 비트를 제외하고 모두 1인 값과 s를 and연산해서 n이 없는 것으로 처리
}

int check(int &s, int n) //n이 있는지 체크하는 연산
{
    if (s & (1 << n)) //s와 n번째 비트만 and연산한 결과가 true면(있으면) 1을 반환, 아니면 0 반환
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void toggle(int &s, int n) //s에 n이 있으면 n 제거, 없으면 추가하는 연산
{
    s ^= (1 << n); //s와 n번째 비트만 xor연산(둘 다 있으면 지우고 없으면 만들고)
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); //입출력처리

    int m, x, s = 0; //연산 횟수, 피연산자, 비트마스킹용 정수를 선언
    string op; //명령어 처리용 string변수
    cin >> m;
    while (m--) //연산 횟수만큼 반복
    {
        cin >> op;

        // x 피연산자가 입력되지 않는 연산자: all, empty
        if (op == "all") //s를 1~20으로 바꾸는 연산
        {
            all(s);
        }
        else if (op == "empty") //s를 공집합으로 만드는 연산
        {
            empty(s);
        }

        // x 피연산자가 입력되는 연산자: add, remove, check, toggle
        else
        {
            cin >> x;
            if (op == "add") //x를 s에 추가하는 연산
            {
                add(s, x);
            }
            else if (op == "remove") //x를 s에서 제거하는 연산
            {
                remove(s, x);
            }
            else if (op == "check") //x가 s에 있는지 체크하는 연산
            {
                cout << check(s, x) << "\n";
            }
            else if (op == "toggle") //x가 s에 있으면 제거하고, 없으면 추가하는 연산(XOR 이용)
            {
                toggle(s, x);
            }
        }
    }
    return 0;
}