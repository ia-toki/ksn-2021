// O(N^2)

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <cstdio>

const int kMaxN = 300005;
const int kMod = 1000000007;

int N;
int P[kMaxN], iP[kMaxN];

int stack[kMaxN];
bool hasLeft[kMaxN], hasRight[kMaxN];

int lft[kMaxN], rgt[kMaxN];
int dp[kMaxN];

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &P[i]);
    iP[--P[i]] = i;
  }

  int tail = 0;
  for (int i = 0; i < N; ++i) {
    while (tail > 0 && stack[tail - 1] > P[i]) --tail;
    hasLeft[i] = tail > 0;
    stack[tail++] = P[i];
  }

  tail = 0;
  for (int i = N - 1; i >= 0; --i) {
    while (tail > 0 && stack[tail - 1] > P[i]) --tail;
    hasRight[i] = tail > 0;
    stack[tail++] = P[i];
  }

  P[N] = N;
  for (int i = 0; i < N; ++i) {
    lft[i] = rgt[i] = N;
    for (int j = i - 1; j >= 0; --j) {
      if (P[j] < P[i]) break;
      if (P[j] < P[lft[i]]) lft[i] = j;
    }
    for (int j = i + 1; j < N; ++j) {
      if (P[j] < P[i]) break;
      if (P[j] < P[rgt[i]]) rgt[i] = j;
    }
  }
  dp[N] = 1;

  for (int val = N - 1; val >= 0; --val) {
    int i = iP[val];
    dp[i] = 1LL * (dp[lft[i]] + hasLeft[i]) * (dp[rgt[i]] + hasRight[i]) % kMod;
    if (hasLeft[i] && hasRight[i]) dp[i] = (dp[i] + kMod - 2) % kMod;
  }

  printf("%d\n", dp[iP[0]]);
  return 0;
}
