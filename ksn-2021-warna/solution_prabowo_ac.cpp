#include <cstdio>
#include <vector>

int ask(int L, int R) {
  printf("? %d %d\n", L + 1, R + 1);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret;
}

std::vector<int> solveSorted(int N) {
  std::vector<int> ans(N);
  for (int i = 1; i < N; ++i) {
    ans[i] = ans[i - 1] + (ask(i - 1, i) == 1 ? 0 : 1);
  }
  return ans;
}

std::vector<int> solveAllButOneDistincts(int N) {
  std::vector<int> ans(N);
  for (int i = 1; i < N; ++i) {
    ans[i] = i;
    if (ask(0, i) == i) {
      for (int j = i - 1; j >= 0; --j) {
        if (ask(j, N - 1) == N - j - 1) {
          ans[i] = ans[j];
          break;
        }
      }
      for (int j = i + 1; j < N; ++j) {
        ans[j] = j - 1;
      }
      return ans;
    }
  }
  return ans;
}

std::vector<int> solve(int N, int maxDistinct=-1) {
  std::vector<int> ans(N);
  for (int i = 1; i < N; ++i) {
    std::vector<bool> flag(i, false);
    std::vector<int> distincts;
    for (int j = i - 1; j >= 0; --j) {
      if (!flag[ans[j]]) {
        flag[ans[j]] = true;
        distincts.push_back(j);
      }
    }

    int colour = -1;
    int l = 0, r = static_cast<int>(distincts.size()) - 1;
    if (static_cast<int>(distincts.size()) == maxDistinct) {
      colour = r--;
    }
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (ask(distincts[mid], i) == mid + 1) {
        colour = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    if (colour == -1) ans[i] = static_cast<int>(distincts.size());
    else ans[i] = ans[distincts[colour]];
  }

  return ans;
}

int main() {
  int T;
  int N, Q;

  scanf("%d", &T);
  scanf("%d %d", &N, &Q);

  std::vector<int> ans;
  if (T == 1 || T == 2) ans = solveSorted(N);
  else if (T == 4) ans = solve(N, 4);
  else if (T == 5) ans = solveAllButOneDistincts(N);
  else if (T == 3 || T == 6 || T == 7) ans = solve(N);

  printf("!");
  for (int c : ans) printf(" %d", c + 1);
  printf("\n");  
  return 0;
}
