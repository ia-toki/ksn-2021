// O(KN^2)

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <cstdio>

const int kMaxN = 3005;
const int kMod = 1000000007;

int N, M, K;
char S[kMaxN];

int dp[kMaxN][kMaxN][2];

int main() {
  scanf("%d %d %d", &N, &M, &K);
  scanf("%s", S + 1);

  dp[0][0][0] = dp[0][0][1] = 1;
  for (int i = 0; i <= K; ++i) {
    for (int j = 1; j <= N; ++j) {
      int bound = j - M + 1;
      if (bound < 0) bound = 0;

      bool hasA = S[j] == 'A', hasB = S[j] == 'B';
      for (int k = j - 1; k >= bound; --k) {
        if (hasB) break;
        dp[i][j][0] = (dp[i][j][0] + dp[i][k][1]) % kMod;
        hasB |= S[k] == 'B';
      }
      for (int k = j - 1; k >= bound; --k) {
        if (hasA) break;
        dp[i][j][1] = (dp[i][j][1] + dp[i][k][0]) % kMod;
        hasA |= S[k] == 'A';
      }

      bound = j - M + 1 - i;
      if (bound < 0) bound = 0;

      for (int k = j - M; k >= bound; --k) {
        if (hasB) break;
        dp[i][j][0] = (dp[i][j][0] + dp[i - (j - k - M + 1)][k][1]) % kMod;
        hasB |= S[k] == 'B';
      }
      for (int k = j - M; k >= bound; --k) {
        if (hasA) break;
        dp[i][j][1] = (dp[i][j][1] + dp[i - (j - k - M + 1)][k][0]) % kMod;
        hasA |= S[k] == 'A';
      }
    }
  }

  int ans = (dp[K][N][0] + dp[K][N][1]) % kMod;
  printf("%d\n", ans);
  return 0;
}
