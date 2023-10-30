#include <bits/stdc++.h>
using namespace std;

long long n;

long long solve() {
  long long ret = n;
  long long sqrtn = sqrt(n);
  for(long long i = 2; i <= sqrtn; i++) {
    if(n % i == 0) {
      ret = ret / i * (i - 1);
    }
    while (n % i == 0) {
      n /= i;
    }
  }
  if(n != 1) {
    ret = ret / n * (n - 1);
  }
  return ret;
}

int main(void) {
  cin >> n;
  long long ans = solve();
  cout << ans << "\n";
}