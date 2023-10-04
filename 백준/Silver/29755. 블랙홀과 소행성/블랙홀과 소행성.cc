#include <bits/stdc++.h>
using namespace std;

vector<int> b;
vector<pair<int, int>> v;

int n, m;

int main(void) {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    b.push_back(tmp);
  }
  sort(b.begin(), b.end());
  for(int i = 0; i < m; i++) {
    int tmp, tmp2;
    cin >> tmp >> tmp2;
    v.push_back({tmp, tmp2});
  }
  int ans = 0;
  for(auto i : v) {
    int left = 0;
    int right = n-1;
    while (left <= right) {
      int mid = (left + right)/2;
      int target = b[mid];
      if(target == i.first) break;
      else if(target < i.first) left = mid + 1;
      else if(target > i.first) right = mid - 1;
    }
    int near = INT_MAX;
    int lastcheck = (left + right) / 2;
    for(int j = lastcheck - 1; j <= lastcheck + 1; j++) {
      if(j >= 0 and j < n) near = min(near, abs(b[j] - i.first));
    }
    ans = max(ans, near * i.second);
  }
  cout << ans << "\n";
}