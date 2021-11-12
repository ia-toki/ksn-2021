#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N;
  cin >> S;

  string T;
  vector<int> cnt(26);
  for (char c : S) {
    ++cnt[c - 'A'];
  }

  int lst = -1;
  for (int i = 0; i < N; ++i) {
    for (int c = 0; c < 26; ++c) {
      if (cnt[c] == 0) continue;
      if (c == lst) continue;
      --cnt[c];
      if (*max_element(cnt.begin(), cnt.end()) * 2 - 1 > N - i - 1) {
        ++cnt[c];
        continue;
      }

      T += c + 'A';
      lst = c;
      break;
    }
  }

  cout << T << endl;
  return 0;
}
