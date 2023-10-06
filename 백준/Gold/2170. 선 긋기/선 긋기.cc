#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v;

int n;

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    int tmp, tmp2;
    cin >> tmp >> tmp2;
    v.push_back({tmp, tmp2});
  }
  sort(v.begin(), v.end());
  int l = v[0].first;
  int r = v[0].second;
  int ans = 0;
  for(int i = 1; i < n; i++) {
    int a = v[i].first;
    int b = v[i].second;
    if(a <= r and b >= r) r = b;
    else if (a > r) {
      ans += r - l;
      l = a;
      r = b;
    }
  }
  cout << ans + r - l << "\n";
}