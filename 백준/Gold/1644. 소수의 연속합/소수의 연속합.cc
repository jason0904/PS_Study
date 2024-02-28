#include <bits/stdc++.h>
using namespace std;

int prime[4000002] = {0, };
vector<int> v;
int n;

int st = 0, en = 1, sum, ans = 0;

void init() {
    for(int i = 2; i*i < 4000002; i++) {
        if(prime[i] == 1) continue;
        for(int j = i + i; j < 4000002; j += i) {
            prime[j] = 1;
        }
    }
    for(int i = 2; i < 4000002; i++) {
        if(!prime[i]) v.push_back(i);
    }
    v.push_back(0);
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    init();
    sum = v[0];
    while(true) {
        if(sum == n) ans++;
        if(sum <= n) sum += v[en++];
        if(sum > n) sum -= v[st++];
        if(en == v.size()) break;
    }
    cout << ans << "\n";
}