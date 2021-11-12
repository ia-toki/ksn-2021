// O(KN)

#include <cstdio>
#include <vector>

const int kMaxN = 3005;
const int kMod = 1000000007;

inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }

int N, M, K;

char S[kMaxN];
int dp[kMaxN][kMaxN][2];
int preHori[kMaxN][kMaxN][2];
int preDiag[kMaxN][kMaxN][2];

void solve() {
  scanf("%d %d %d", &N, &M, &K);
  scanf("%s", S + 1);

  dp[0][0][0] = dp[0][0][1] = 1;
  preDiag[0][0][0] = preDiag[0][0][1] = 1;
  for (int i = 0; i <= N; ++i) preHori[0][i][0] = preHori[0][i][1] = 1;

  for (int i = 0; i <= K; ++i) {
    for (int j = 1; j <= N; ++j) {
      for (int bit = 0; bit < 2; ++bit) {
        dp[i][j][bit] = preHori[i][j - 1][1 ^ bit] - (j - M >= 0 ? preHori[i][j - M][1 ^ bit] : 0);

        dp[i][j][bit] += (i - 1 >= 0 && j >= M ? preDiag[i - 1][j - M][1 ^ bit] : 0);
        
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
