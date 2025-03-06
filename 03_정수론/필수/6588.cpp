#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;

vector<int> getPrimes(){
    vector<int> primes(MAX + 1, 0);

    for(int i = 2; i * i < MAX; i++){
        if(primes[i] != 0){
            continue;
        }
        for(int j = i * i; j <= MAX; j +=i){
            if(primes[j] == 0){
                primes[j] = i;
            }
        }
    }

    return primes;
}

void isItGoldBach(int n, vector<int> &primes){
    for(int i = 3; i < n; i += 2){
        if(primes[i] == 0 && primes[n - i] == 0){
            cout << n << " = " << i << " + " << n - i << "\n";
            return;
        }
    }
    cout << "Goldbach's conjecture is wrong.\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<int> primes = getPrimes();

    while(true){
        int n;
        cin >> n;
        if(n == 0){
            break;
        }
        isItGoldBach(n, primes);
    }
    return 0;
}