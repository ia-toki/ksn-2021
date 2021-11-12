// O(KN)

#include <cstdio>
#include <vector>

const int kMod = 1000000007;

inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }

void solve() {
  int N, M, K;
  scanf("%d %d %d", &N, &M, &K);
  char S[N + 5];
  scanf("%s", S + 1);

  std::vector dp(K + 1, std::vector(N + 1, std::vector(2, 0)));
  dp[0][0][0] = dp[0][0][1] = 1;
  auto preHori = dp, preDiag = dp;
  preHori[0] = std::vector(N + 1, std::vector(2, 1));

  std::vector lst(N + 1, std::vector(2, 0));
  for (int i = 1; i <= N; ++i) {
    if (S[i] == 'A') lst[i][0] = i;
    else lst[i][0] = lst[i - 1][0];

    if (S[i] == 'B') lst[i][1] = i;
    else lst[i][1] = lst[i - 1][1];
  }

  for (int i = 0; i <= K; ++i) {
    for (int j = 1; j <= N; ++j) {
      for (int bit = 0; bit < 2; ++bit) {
        int bound = max(j - M, lst[j][1 ^ bit] - 1);
        dp[i][j][bit] = preHori[i][j - 1][1 ^ bit] - (bound >= 0 ? preHori[i][bound][1 ^ bit] : 0);

        bound = max(j - M - i, min(j - M, lst[j][1 ^ bit] - 1));
        dp[i][j][bit] += (i - 1 >= 0 && j >= M ? preDiag[i - 1][j - M][1 ^ bit] : 0)
            - (i - (j - bound - M + 1) >= 0 && bound >= 0 ? preDiag[i - (j - bound - M + 1)][bound][1 ^ bit] : 0);
        
        dp[i][j][bit] %= kMod;
        if (dp[i][j][bit] < 0) dp[i][j][bit] += kMod;

        preHori[i][j][bit] = (preHori[i][j - 1][bit] + dp[i][j][bit]) % kMod;
        preDiag[i][j][bit] = dp[i][j][bit];
        if (i > 0) preDiag[i][j][bit] = (preDiag[i][j][bit] + preDiag[i - 1][j - 1][bit]) % kMod;
      }
    }
  }

  int ans = (dp[K][N][0] + dp[K][N][1]) % kMod;
  printf("%d\n", ans);
}

int main() {
  solve();
  return 0;
}
