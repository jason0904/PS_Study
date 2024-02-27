#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> s[101][101]; // [x][y]은 시작, 값의 pair는 도착
vector<pair<int,int>> v; //소 위치저장.
int visited[101][101];
int ans = 0;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, k, r;

void dfs(int x, int y) {
    if(x < 1 or x > n or y < 1 or y > n) return;
    visited[x][y] = 1;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(visited[nx][ny] == 1 or s[x][y].count({nx,ny})) continue; //return 박으면 for문쪽 다 실행안됨.
        dfs(nx, ny);
    }

}

void reset() {
    for(auto & i : visited) fill(i, i + 101, 0);
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> k >> r;
    for(int i = 0; i < r; i++) {
        int sx,sy,destx,desty;
        cin >> sx >> sy >> destx >> desty;
        s[sx][sy].insert({destx, desty});
        s[destx][desty].insert({sx,sy});
    }
    for(int i = 0; i < k; i++) {
        int tmpx, tmpy;
        cin >> tmpx >> tmpy;
        v.push_back({tmpx, tmpy});
    }
    for(int i = 0; i < v.size(); i++) {
        reset();
        dfs(v[i].first, v[i].second);
        for(int j = i + 1; j < v.size(); j++) {
            if(!visited[v[j].first][v[j].second]) ans++;
        }
    }
    cout << ans << "\n";
}