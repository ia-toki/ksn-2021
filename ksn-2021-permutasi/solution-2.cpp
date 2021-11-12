#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 3e5 + 5;
const int MOD = 1e9 + 7;

int N;
int A[MAX_N];
long long dp[MAX_N];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }

  int smallest = A[N];
  A[N+1] = N+1;
  dp[N+1] = 1;
  for (int i = N; i > 0; i--) {
    smallest = min(smallest, A[i]);
    dp[i] = 1;

    for (int j = i; j <= N; j++) {
      int smallest = min(A[j], A[j+1]);

      for (int k = j+2; k <= N+1; k++) {
        smallest = min(smallest, A[k]);
        if (A[j] <= smallest || A[k] <= smallest) {
          dp[i] = (dp[i] + dp[k]) % MOD;
        }
      }
    }
  }

  long long ans = 0;
  smallest = A[1];
  for (int i = 1; i <= N; i++) {
    smallest = min(smallest, A[i]);
    if (A[i] <= smallest) {
      ans = (ans + dp[i]) % MOD;
    }
  }
  cout << ans << "\n";
}
