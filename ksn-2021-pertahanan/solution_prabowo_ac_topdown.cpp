// O(KN)

#include <cstdio>
#include <cstring>

const int kMaxN = 3005;
const int kMod = 1000000007;

inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }

int N, M, K;
char S[kMaxN];

int f(int k, int n, int bit);
int hori(int k, int n, int bit);
int diag(int k, int n, int bit);

int memoHori[kMaxN][kMaxN][2];
int hori(int k, int n, int bit) {
  if (n < 0 || k < 0) return 0;
  int &ret = memoHori[k][n][bit];
  if (~ret) return ret;
  return ret = (f(k, n, bit) + hori(k, n - 1, bit)) % kMod;
}

int memoDiag[kMaxN][kMaxN][2];
int diag(int k, int n, int bit) {
  if (n < 0 || k < 0) return 0;
  int &ret = memoDiag[k][n][bit];
  if (~ret) return ret;
  return ret = (f(k, n, bit) + diag(k - 1, n - 1, bit)) % kMod;
}

int memoLst[kMaxN][2];
int lst(int n, int bit) {
  if (n <= 0) return 0;
  int &ret = memoLst[n][bit];
  if (~ret) return ret;
  if (bit == 0 && S[n] == 'A' || bit == 1 && S[n] == 'B') return ret = n;
  return ret = lst(n - 1, bit);
}

int dp[kMaxN][kMaxN][2];
int f(int k, int n, int bit) {
  if (n == 0 && k == 0) return 1;
  if (n <= 0 || k < 0) return 0;
  int &ret = dp[k][n][bit];
  if (~ret) return ret;

  int bound = lst(n, 1 ^ bit) - 1;
  ret = (hori(k, n - 1, 1 ^ bit) - hori(k, max(n - M, bound), 1 ^ bit) + kMod) % kMod;

  if (bound <= n - M) {
    int add = (diag(k - 1, n - M, 1 ^ bit) - diag(k - (n - bound - M + 1), bound, 1 ^ bit) + kMod) % kMod;
    ret = (ret + add) % kMod;
  }
  return ret;
}

int main() {
  scanf("%d %d %d", &N, &M, &K);
  scanf("%s", S + 1);

  memset(dp, -1, sizeof dp);
  memset(memoLst, -1, sizeof memoLst);
  memset(memoDiag, -1, sizeof memoDiag);
  memset(memoHori, -1, sizeof memoHori);

  int ans = (f(K, N, 0) + f(K, N, 1)) % kMod;
  printf("%d\n", ans);
  return 0;
}
