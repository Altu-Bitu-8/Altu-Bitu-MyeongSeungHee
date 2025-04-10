#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef vector<deque<int>> cards;  // 0: 도도, 1: 수연
const int DO = 0, SU = 1;

/** 승리 판단하기 */
string judge(cards& deck) { //덱을 주소째로 받아서 누가 이겼는지 판명하는 함수
	int do_deck = deck[DO].size(), su_deck = deck[SU].size(); // 도도의 덱 크기와 수연이의 덱 크기를 각각 int 변수로 선언
	if (do_deck > su_deck) { //도도 덱의 크기가 더 크면 도도의 승리
		return "do";
	}
	else if (do_deck < su_deck) { //수연이 덱의 크기가 더 크면 수연이의 승리
		return "su";
	}
	return "dosu"; //둘 다 해당되지 않는 경우(무승부) dosu를 리턴하기
}

/** 그라운드에서 덱으로 카드 옮기기 */
void groundToDeck(deque<int>& deck, deque<int>& ground) {
	while (!ground.empty()) { // 그라운드에 남겨진 카드가 없을 때까지 반복함
		deck.push_back(ground.back()); //deck의 맨 뒤에 ground의 맨 끝 원소 집어넣기(카드를 뒤집어서 덱에 넣기 때문에)
		ground.pop_back(); // 그라운드에서 덱으로 넣은 카드를 그라운드에서 삭제
	}
}

/** 종을 쳤을 때 */
void ringTheBell(int player, cards& deck, cards& ground) {
	groundToDeck(deck[player], ground[!player]);// 카드 가져가기 (상대 그라운드 -> 본인 덱)
	groundToDeck(deck[player], ground[player]); // 카드 가져가기 (본인 그라운드 -> 본인 덱)
}


/** 종을 울릴 수 있는 사람 판단 */
int whoCanRingTheBell(cards& deck, cards& ground) { //덱 벡터와 그라운드 벡터를 주소째로 받음
	if (!ground[DO].empty() && ground[DO].front() == 5) { // 도도가 종을 칠 수 있는 경우
		return DO; //DO를 리턴함( = 0 리턴)
	}
	else if (!ground[SU].empty() && ground[SU].front() == 5) { // 수연이 쪽에 5가 있어서 도도가 종을 치는 경우
		return DO;//DO를 리턴함( = 0 리턴)
	}
	else if (!ground[DO].empty() && !ground[SU].empty() && (ground[DO].front() + ground[SU].front() == 5)) { // 수연이가 종을 칠 수 있는 경우
        //둘 다의 그라운드가 비어있지 않고 합해서 5가 되는 경우
		return SU; ////SU를 리턴함( = 1 리턴)
	}
	return -1; // 종을 울릴 수 없음
}

/** 게임 진행 */
string game(int m, cards& deck, cards& ground) {
	bool turn = DO; // 도도 먼저
	while (m--) { //게임은 m번 진행함
		ground[turn].push_front(deck[turn].front()); // 카드 내려놓기(덱 -> 그라운드)
		deck[turn].pop_front(); //deck에서 ground로 내려진 카드를 deck에서 삭제
		if (deck[turn].empty()) { //지금 턴인 사람의 deck이 비어있다면 -> 패배
			break; //바로 게임이 종료됨
		}

		int bell = whoCanRingTheBell(deck, ground); // 종을 울릴 수 있는 사람이 누구인지 판명하는 코드
		if (bell != -1) { // 종을 울린 경우
			ringTheBell(bell, deck, ground); //상대 그라운드의 카드를 자기 덱에 넣고, 자기 그라운드의 카드를 자기 덱에 넣는 코드
		}
		turn = !turn; // 차례 바꾸기
	}
	return judge(deck); //덱 vector로 누가 이겼는지 판명하는 함수
}

/**
 * 도도, 수연이 각각 덱과 그라운드를 가짐
 * 도도->수연->도도->수연... 순으로 차례를 바꿔가며 게임 진행 (game 함수)
 * 1. 카드를 덱에서 한 장 내려놓음
 * 2. 어떤 플레이어가 종을 칠 수 있는지 판단 (whoCanRingTheBell 함수)
 * 3. 종을 친 경우 그라운드의 카드를 덱으로 이동(ringTheBell, groundToDeck 함수)
 * 종료 조건 만족 시 승리한 사람 리턴(judge 함수)
 */

int main() {
	int n, m, card1, card2;
	cards deck(2), ground(2); // 0: 도도, 1: 수연

	// 입력
	cin >> n >> m;
	while (n--) {
		cin >> card1 >> card2; //도도의 카드와 수연의 카드를 입력받음음
		deck[DO].push_front(card1); //deque<int> 벡터인 deck를 도도의 것과 수연이의 것을 각각 선언해둠
		deck[SU].push_front(card2); //cards1과 cards2를 각각의 카드덱에 집어넣기
	}

	// 출력 & 연산
	cout << game(m, deck, ground); //승리의 판단 결과를 출력하기

	return 0;
}