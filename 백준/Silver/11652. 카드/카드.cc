#include <bits/stdc++.h>
using namespace std;

int n;
long long answer;
int maximum = 0;
map<long long, int> m;

int main(void) {
    cin >> n;

    for(int i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        m[tmp]++;
    }
    for(auto i : m) {
        if(i.second > maximum) {
            answer = i.first;
            maximum = i.second;
        }
    }

    cout << answer << "\n";
}