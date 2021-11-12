#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int N, A[MAXN], nextSmaller[MAXN];
long long sum = 1;
long long start_dp[MAXN];

namespace fastio {

inline bool ok(char c) {
  return '0' <= c && c <= '9';
}

inline int scanint() {
  int c = 0, rs = 0;
  while(!ok(c)) {
    c = getchar_unlocked();
  }
  while(ok(c)) {
    rs = 10 * rs + (c - '0');
    c = getchar_unlocked();
  }
  return rs;
}

int out[35];

inline void printint(int val) {
  int sz = 0;
  while(val) {
    out[sz++] = (val % 10) + '0';
    val /= 10;
  }
  if(!sz) out[sz++] = '0';
  for(int i = sz - 1; i >= 0; i--) {
    putchar_unlocked(out[i]);
  }
}

}

void input() {
  N = fastio::scanint();
  for (int i = 1; i <= N; i++) {
    A[i] = fastio::scanint();
  }
}

void findNextSmaller() {
  vector<pair<int, int>> stac;
  nextSmaller[N] = N + 1;
  stac.emplace_back(A[N], N);
  for (int i = N - 1; i >= 1; i--) {
    while (!stac.empty() && stac.back().first > A[i]) {
      stac.pop_back();
    }
    nextSmaller[i] = (stac.empty() ? N + 1 : stac.back().second);
    stac.emplace_back(A[i], i);
  }

  int smallest = A[1];
  for (int i = 1; i <= N; i++) {
    if (A[i] <= smallest) start_dp[i]++;
    smallest = min(smallest, A[i]);
  }
}

long long prefix_diff[MAXN];

void solve() {
  long long ans = 0, endSum = 0;
  long long diffSum = 0;
  for (int i = 1; i <= N; i++) {
    diffSum += prefix_diff[i];
    endSum = (endSum + start_dp[i] + diffSum) % MOD;

    prefix_diff[i+2] += endSum;
    prefix_diff[nextSmaller[i]] -= endSum;

    for (int j = nextSmaller[i]; j <= N; j = nextSmaller[j]) {
      start_dp[j] += endSum;
    }

    if (nextSmaller[i] == N + 1) {
      ans += endSum;
    }
  }
  fastio::printint(ans % MOD);
  putchar('\n');
}

int main() {
  input();
  findNextSmaller();
  solve();
}