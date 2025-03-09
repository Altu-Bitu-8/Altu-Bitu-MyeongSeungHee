#include <iostream>
#include <vector>

using namespace std;

int getGcdIter(int a, int b){
    while(b != 0){
        a %= b;
        swap(a, b);
    }
    return a;
}

vector<int> changeNum(int s, vector<int> &kids){
    vector<int> result(kids.size());

    for(int i = 0; i < kids.size(); i++){
        result[i] = abs(kids[i] - s);
    }
    return result;
}

int main(){
    int n, s;
    cin >> n >> s;
    vector<int> kids(n), dist(n);

    for (int i = 0; i < n; i++)
	    cin >> kids[i];

    dist = changeNum(s, kids); // 수빈이와 동생들 사이의 거리

    int g = dist[0];
    for(int i = 1; i < n; i++){
        g = getGcdIter(g, dist[i]);
    }
    cout << g << endl;
}