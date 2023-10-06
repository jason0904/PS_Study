#include <bits/stdc++.h>
using namespace std;

int n;
int board[20][20];
int vis[20][20];

int dy[] = {-1, 0, 1 ,0};
int dx[] = {0, -1, 0, 1};

int shark = 2;
int cnt = 0;
int now_x, now_y;
int min_dist, min_x, min_y, result;

void init() {
  for(int i = 0; i < n; i++) fill(vis[i], vis[i] + n, -1);
  min_dist = 401;
  min_x = 21;
  min_y = 21;
}

void bfs(int x, int y) {
  queue<pair<int,int>> q;
  vis[x][y] = 0;
  q.push({x,y});
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    for(int i = 0; i < 4; i++) {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];
      if(nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
      if(vis[nx][ny] >= 0) continue;
      if(board[nx][ny] > shark) continue;
      vis[nx][ny] = vis[cur.first][cur.second] + 1;
      if(board[nx][ny] < shark and board[nx][ny] != 0) {
        if(min_dist > vis[nx][ny]) {
          min_x = nx;
          min_y = ny;
          min_dist = vis[nx][ny];
        }
        else if(min_dist == vis[nx][ny]) {
          if(min_x == nx) {
            if(min_y > ny) {
              min_x = nx;
              min_y = ny;
            }
          }
          else if(min_x > nx) {
            min_x = nx;
            min_y = ny;
          }
        }
      }
      q.push({nx,ny});
    }
  }
}

int main(void) {
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> board[i][j];
      if(board[i][j] == 9) {
        now_x = i;
        now_y = j;
        board[i][j] = 0;
      }
    }
  }
  while (true) {
    init();
    bfs(now_x, now_y);
    if(min_x != 21 and min_y != 21) {
      result += vis[min_x][min_y];
      cnt++;
      if(cnt == shark) {
        shark++;
        cnt = 0;
      }
      board[min_x][min_y] = 0;
      now_x = min_x;
      now_y = min_y;
    }
    else break;
  }
  cout << result << "\n";
}