#include <bits/stdc++.h>
using namespace std;

int tree[100001];
int n, m;
vector<int> v;

int find(int a) {
  if(tree[a] == a) {
    return a;
  }
  return tree[a] = find(tree[a]);
}

void Union(int a, int b) {
  int x = find(a);
  int y = find(b);
  tree[x] = y;
}


int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for(int i = 1; i <= n; i++) {
    tree[i] = i;
  }
  for(int i = 0; i < m; i++) {
    int tmp, tmp2;
    cin >> tmp >> tmp2;
    Union(tmp, tmp2);
  }
  for(int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
  }
  int cnt = 0;
  for(int i = 0; i < n-1; i++) {
    if(find(v[i]) != find(v[i+1])) cnt++;
  }
  cout << cnt << "\n";
}