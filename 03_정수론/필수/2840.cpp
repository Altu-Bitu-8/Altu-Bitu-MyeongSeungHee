#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<char> wheel(n, '?');
    int tmp_loc = n - 1;
    string result;

    for(int i = 0; i < k; i++){
        char letter;
        int s;
        cin >> s >> letter;

        tmp_loc -= s;
        if(tmp_loc < 0){
            tmp_loc += n;
        } 
        if(tmp_loc >= n){
            tmp_loc -= n;
        }

        if(wheel[tmp_loc] == '?'){
            if (find(wheel.begin(), wheel.end(), letter) != wheel.end()) {
                result = "!";
                continue;
            }
            wheel[tmp_loc] = letter;
        } else if(wheel[tmp_loc] != letter){
            result = "!";
            continue;
        } else if (wheel[tmp_loc] == letter){
            continue;
        }
    }

    for(int i = 0; i < n; i++){
        if(result != "!"){
            result += wheel[(tmp_loc + i) % n];
        } else{
            break;
        }
    }
    cout << result << endl;

    return 0;
}