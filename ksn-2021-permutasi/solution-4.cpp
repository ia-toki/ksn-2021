#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 3e5 + 5;
const int MOD = 1e9 + 7;

int N;

long long POW(long long X, long long Y) {
  long long res = 1;
  while(Y > 0) {
    if (Y & 1) res = res * X % MOD;
    X = X * X % MOD;
    Y >>= 1;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> N;
  cout << POW(2, N-1) << "\n";
}
