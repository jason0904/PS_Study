#include <bits/stdc++.h>
using namespace std;

char board[11][11];
int n,m;
pair<int, int> blue;
pair<int, int> red;

int dist[11][11][11][11];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0}; //상우하좌




int main(void) {

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'B') {
                blue = {i, j};
                board[i][j] = '.';
            }
            else if(board[i][j] == 'R') {
                red = {i, j};
                board[i][j] = '.';
            }
        }
    }

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 10; k++) {
                fill(dist[i][j][k], dist[i][j][k] + 10, -1);
            }
        }
    }

    queue<tuple<int, int, int, int>> q;
    q.push({blue.first, blue.second, red.first, red.second});
    dist[blue.first][blue.second][red.first][red.second] = 0;

    while(!q.empty()) {
        int bx,by,rx,ry;
        tie(bx,by,rx,ry) = q.front();
        q.pop();
        if(dist[bx][by][rx][ry] >= 10) {
            cout << -1 << "\n";
            return 0;
        }
        for(int i = 0; i < 4; i++) {
            int d_rx = rx, d_ry = ry, d_bx = bx, d_by = by;
            while(board[d_bx + dx[i]][d_by + dy[i]] == '.') {
                d_bx += dx[i];
                d_by += dy[i];
            }
            if(board[d_bx + dx[i]][d_by + dy[i]] == 'O') continue;

            while(board[d_rx + dx[i]][d_ry + dy[i]] == '.') {
                d_rx += dx[i];
                d_ry += dy[i];
            }

            if(board[d_rx + dx[i]][d_ry + dy[i]] == 'O') {
                cout << dist[bx][by][rx][ry] + 1 << "\n";
                return 0;
            }

            if(d_rx == d_bx and d_ry == d_by) {
                if(i == 0) {
                    if(ry < by) d_ry--;
                    else d_by--;
                }
                else if(i == 1) {
                    if(rx < bx) d_rx--;
                    else d_bx--;
                }
                else if(i == 2) {
                    if(ry > by) d_ry++;
                    else d_by++;
                }
                else if(i == 3) {
                    if(rx > bx) d_rx++;
                    else d_bx++;
                }
            }

            if(dist[d_bx][d_by][d_rx][d_ry] != -1) continue;
            dist[d_bx][d_by][d_rx][d_ry] = dist[bx][by][rx][ry] + 1;
            q.push({d_bx, d_by, d_rx, d_ry});
        }
    }
    cout << -1 << "\n";
    return 0;
}