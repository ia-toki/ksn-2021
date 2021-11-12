#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 3e5 + 5;
const int MOD = 1e9 + 7;

int N;
long long dp[MAX_N];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> N;
  for (int i = N; i > 0; i--) {
    dp[i] = 1;
    for (int j = i+1; j <= N; j++) {
      dp[i] = (dp[i] + dp[j]) % MOD;
    }
  }
  cout << dp[1] << "\n";
}
