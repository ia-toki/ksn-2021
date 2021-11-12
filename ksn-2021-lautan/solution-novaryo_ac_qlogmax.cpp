#include <bits/stdc++.h>
using namespace std;

int N, M, Q;

namespace dp {
  int current_C, disabled_mask;
  int memo[30][3];

  bool isActive(int idx, int mask) {
    return (1 << idx) & mask;
  }

  bool isDisabledBit(int idx) {
    return isActive(idx, disabled_mask);
  }

  bool isMoreThanC(int idx, int is_same) {
    if (is_same == false) return false;
    return !isActive(idx, current_C);
  }

  int dp(int idx, int is_same) {
    if (idx < 0) return 1;
    if (memo[idx][is_same] != -1) return memo[idx][is_same];
    int res = 0;
    // we choose 1
    if (!isDisabledBit(idx) && !isMoreThanC(idx, is_same)) res += dp(idx - 1, is_same);
    // we choose 0
    if (is_same) {
      // if the current bit in C is  1: is_same = 0
      res += dp(idx - 1, !isActive(idx, current_C));
    }else {
      res += dp(idx - 1, 0);
    }

    return memo[idx][is_same] = res;
  }
}

int calcLand(int b, int r) {
  if (r < 0) return 0;
  dp::current_C = r;
  dp::disabled_mask = b;
  memset(dp::memo, -1, sizeof(dp::memo));
  int res = dp::dp(29, 1);
  return res;
}

int calcCCRow(int b, int l, int r) {
  if (b == 0) return 1;
  int cc_size = b & -b;
  int cnt_l = l > 0 ? calcLand(b, l-1) : 0, cnt_r = calcLand(b, r);
  int cc_l = (cnt_l / cc_size), cc_r = (cnt_r / cc_size) + (cnt_r % cc_size > 0);
  return cc_r - cc_l;
}

int calcCCMatric(int a, int b, int c, int d) {
  int cc_row = calcCCRow(b, a, c);
  int cc_col = calcCCRow(a, b, d);
  return cc_row + cc_col - !(a & b);
}

int main() {
  scanf("%d %d %d", &N, &M, &Q);
  int A, B, C, D;
  for (int i = 1; i <= Q; i++) {
    scanf("%d %d %d %d", &A, &B, &C, &D);
    printf("%d\n", calcCCMatric(A, B, C, D));
  }
}
