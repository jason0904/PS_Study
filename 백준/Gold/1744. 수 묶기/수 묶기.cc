#include <bits/stdc++.h>
using namespace std;

vector<int> v; //양수
vector<int> v2; //음수
long long ans = 0;
int n;

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    if(tmp > 0) v.push_back(tmp);
    else v2.push_back(tmp);
  }
  sort(v.begin(), v.end(), greater<>());
  sort(v2.begin(), v2.end());
  if(v.size() % 2 != 0) ans += v[v.size() - 1];
  if(!v.empty()) {
    for (int i = 0; i < v.size() - 1; i += 2) {
      if (v[i] == 1 or v[i + 1] == 1) {
        ans += (v[i] + v[i + 1]);
      } else if (v[i + 1] > 0) ans += v[i] * v[i + 1];
    }
  }
  if(v2.size() % 2 != 0) ans += v2[v2.size() - 1];
  if(!v2.empty()) {
    for (int i = 0; i < v2.size() - 1; i += 2) {
      ans += (v2[i] * v2[i + 1]);
    }
  }
  cout << ans << "\n";
}