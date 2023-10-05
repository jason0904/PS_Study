#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int n;
bool vis[100001];
int order[100001];
vector<int> ans;
vector<int> chk;

int cmp(int a, int b) {
  return order[a] < order[b];
}

void dfs(int cur) {
  chk.push_back(cur);
  vis[cur] = true;
  for(int next : adj[cur]) {
    if(vis[next]) continue;
    dfs(next);
  }
}

int main(void) {
  cin >> n;
  for(int i = 0; i < n-1; i++) {
    int tmp, tmp2;
    cin >> tmp >> tmp2;
    adj[tmp].push_back(tmp2);
    adj[tmp2].push_back(tmp);
  }
  for(int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    ans.push_back(tmp);
    order[tmp] = i+1;
  }
  for(int i = 1; i <= n; i++) {
    sort(adj[i].begin(), adj[i].end(), cmp);
  }
  dfs(1);
  for(int i = 0; i < n; i++) {
    if(ans[i] != chk[i]) {
      cout << 0 << "\n";
      return 0;
    }
  }
  cout << 1 << "\n";
}