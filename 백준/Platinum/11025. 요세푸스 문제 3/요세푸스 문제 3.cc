#include <bits/stdc++.h>
using namespace std;

long long ans;
int n, k;

int main(void) {
  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    ans = (ans + k - 1) % i + 1; // f(1,k)는 1이므로.
  }
  cout << ans << "\n";
}