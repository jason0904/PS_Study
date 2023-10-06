#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<long long> v;
long long ans = 0;


int main(void) {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    long long tmp;
    cin >> tmp;
    v.push_back(tmp);
  }
  for(int i = 0; i < m; i++) {
    sort(v.begin(), v.end());
    long long tmp = v[0] + v[1];
    v[0] = tmp;
    v[1] = tmp;
  }
  for(int i = 0; i < n; i++) {
    ans += v[i];
  }
  cout << ans << "\n";
}