#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> li; //톱니바퀴의 상태를 저장하는 벡터
vector<pair<int, int>> stack; //회전해야 할 톱니바퀴 목록을 저장하는 스택
vector<int> visited; //방문 여부를 체크하는 배열

void check_rotation(int current_num, int current_dir) //재귀적으로 톱니바퀴의 회전 여부를 체크하는 함수
{
    //왼쪽 톱니바퀴를 먼저 확인하는 코드
    if (current_num - 1 >= 0 && visited[current_num - 1] == 0)
    {
        //현재 톱니바퀴의 왼쪽(6번 인덱스)과 왼쪽 톱니바퀴의 오른쪽(2번 인덱스)이 다를 경우 회전 가능
        if (li[current_num][6] != li[current_num - 1][2])
        {
            stack.push_back(make_pair(current_num - 1, current_dir * -1)); //스택에 추가 (번호와 회전 방향을 반대로 설정함함)
            visited[current_num - 1] = 1; //방문한 배열에는 1로 표시해서 체크
            check_rotation(current_num - 1, current_dir * -1); //재귀 방식으로 왼쪽 톱니바퀴 체크
        }
    }
    
    //오른쪽 톱니바퀴를 확인하는 코드
    if (current_num + 1 < li.size() && visited[current_num + 1] == 0)
    {
        //현재 톱니바퀴의 오른쪽(2번 인덱스)과 오른쪽 톱니바퀴의 왼쪽(6번 인덱스)이 다를 경우 회전 가능
        if (li[current_num][2] != li[current_num + 1][6])
        {
            stack.push_back(make_pair(current_num + 1, current_dir * -1)); //스택에 추가 (번호와 회전 방향 반대로 설정)
            visited[current_num + 1] = 1; //방문한 배열에는 1로 표시해서 체크
            check_rotation(current_num + 1, current_dir * -1); //재귀 방식으로 왼쪽 톱니바퀴 체크
        }
    }
}

int main()
{
    int t; //톱니바퀴의 개수를 입력받는 변수
    int k; //회전 횟수를 입력받는 변수수

    cin >> t; //톱니바퀴 개수 입력
    li.resize(t); //톱니바퀴 개수만큼 벡터의 크기 조절
    
    for (int i = 0; i < t; ++i)
        cin >> li[i]; //각 톱니바퀴의 상태를 입력받는 루프문

    cin >> k; //회전 횟수 입력받기
    
    for (int i = 0; i < k; ++i)
    {
        int num, direction; //회전할 톱니바퀴 번호와 회전 방향을 선언해줌
        cin >> num >> direction; //num과 direction을 입력받고, 1: 시계방향, -1: 반시계방향으로 설정함
        
        stack.clear(); //스택 초기화
        stack.push_back(make_pair(num - 1, direction)); //시작 톱니바퀴 저장
        
        visited.assign(t, 0); //방문 배열을 0으로 초기화
        visited[num - 1] = 1; //시작 톱니바퀴 방문 처리
        
        check_rotation(num - 1, direction); //연결된 톱니바퀴 회전 여부 확인

        while (!stack.empty()) //스택을 이용하여 실제 톱니바퀴 회전 수행
        {
            pair<int, int> top = stack.back(); //스택에서 요소 가져오기
            stack.pop_back(); //스택에서 제거하기
            
            int tmp_num = top.first;  //회전할 톱니바퀴 인덱스
            int tmp_dir = top.second; //회전 방향
            
            if (tmp_dir == 1) //시계방향으로 회전할 경우
            { 
                li[tmp_num] = li[tmp_num].back() + li[tmp_num].substr(0, 7); 
                //톱니바퀴 인덱스로 톱니바퀴를 가져와서 기존의 마지막 문자와 나머지 문자를 순서대로 합쳐서 마지막 문자를 앞으로 가져옴(= 시계방향으로 한번 회전)
            }
            else
            { 
                li[tmp_num] = li[tmp_num].substr(1) + li[tmp_num][0];
                //위 코드의 반대 작용(첫번째 문자를 맨 뒤로 보내는 동작)
            }
        }
    }

    int cnt = 0; //12시 방향이 '1'인 톱니바퀴의 개수를 출력하기 위한 변수
    for (int i = 0; i < t; ++i)
    {
        if (li[i][0] == '1')
        {
            cnt++; //12시 방향이 1인 톱니바퀴의 개수를 출력하는 루프문
        }
    }

    cout << cnt << endl;
    return 0;
}
