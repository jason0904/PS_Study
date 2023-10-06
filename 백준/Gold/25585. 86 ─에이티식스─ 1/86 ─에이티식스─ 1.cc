#include <bits/stdc++.h>
using namespace std;

int n;
int arr[201][201];
pair<int, int> jug;
vector<pair<int, int>> reg;
int ans = 2e9;


void dfs() {
    if(reg.empty()) {
        ans = 0;
        return;
    }
    sort(reg.begin(), reg.end()); //거리순으로 정렬
    do {
        int y = jug.first;
        int x = jug.second;
        bool finish = true;
        int time = 0;
        for(auto i : reg) {
            int dy = abs(y - i.first);
            int dx = abs(x - i.second);
            if(dy % 2 == 0 and dx % 2 == 0) { //바둑판의 색이 같으면
                time += dx + dy;
                y = i.first;
                x = i.second;
            }
            else {
                finish = false;
                break;
            }
        }
        if(finish) {
            ans = min(ans , time/2);
        }
    } while(next_permutation(reg.begin(), reg.end()));
}


int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i+j][n-1-i+j];
            if(arr[i+j][n-1-i+j] == 1) reg.push_back({i+j,n-1-i+j});
            else if(arr[i+j][n-1-i+j] == 2) jug = {i+j, n-1-i+j};
        }
    }
    dfs();
    if(ans == 2e9) {
        cout << "Shorei" << "\n";
    }
    else cout << "Undertaker" << "\n" << ans << "\n";
    return 0;
}