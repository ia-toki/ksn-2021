#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

const int MAXN = 3000, MAXN_sub2 = 20, MAXN_sub3 = 200;

class ProblemSpec : public BaseProblemSpec {
 protected:
  int N, M, K;
  string S;
  int ANS;

  void InputFormat() {
    LINE(N, M, K);
    LINE(S);
  }

  void OutputFormat() {
    LINE(ANS);
  }

  void Constraints() {
    CONS(1 <= N && N <= MAXN);
    CONS(1 <= M && M <= N);
    CONS(0 <= K && K <= N);
    CONS(S.size() == N);
    CONS(stringOnlyContains(S, {'A', 'B', '?'}));
  }

  void Subtask1() {
    Points(5);
    CONS(N == 10);
    CONS(M == 3);
    CONS(K == 5);
    CONS(S == "????A???B?");
  }

  void Subtask2() {
    Points(9);
    CONS(N <= MAXN_sub2);
  }

  void Subtask3() {
    Points(11);
    CONS(N <= MAXN_sub3);
  }

  void Subtask4() {
    Points(6);
    CONS(K == 0);
    CONS(M == 2);
  }

  void Subtask5() {
    Points(9);
    CONS(K == 0);
  }

  void Subtask6() {
    Points(8);
    CONS(K <= 1);
  }

  void Subtask7() {
    Points(27);
    CONS(stringOnlyContains(S, {'?'}));
  }

  void Subtask8() {
    Points(25);
  }

  void GradingConfig() {
    TimeLimit(1);
    MemoryLimit(256);
  }

private:
  bool stringOnlyContains(string s, vector<char> const &chars) {
    for(auto &c : s) {
      bool ok = 0;
      for(auto &x : chars) {
        if(c == x) {
          ok = 1;
        }
      }
      if(!ok) {
        return false;
      }
    }
    return true;
  }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
  void SampleTestCase1() {
    Subtasks({2, 3, 6, 7, 8});
    Input({
      "5 4 1",
      "?????",
    });
    Output({
      "4",
    });
  }

  void SampleTestCase2() {
    Subtasks({2, 3, 8});
    Input({
      "5 2 2",
      "A????",
    });
    Output({
      "6",
    });
  }

  void SampleTestCase3() {
    Subtasks({2, 3, 8});
    Input({
      "5 3 4",
      "AAAAA",
    });
    Output({
      "0",
    });
  }

  void TestGroup1() {
    Subtasks({1, 2, 3, 8});
    CASE(
      N = 10, M = 3, K = 5, S = "????A???B?"
    );
  }

  void TestGroup2() { // N <= MAXN_sub2, M any, K >= 2, all '?'
    Subtasks({2, 3, 7, 8});
    CASE(
      N = 20;
      M = 3;
      K = 3;
      S = string(N, '?');
    );
    CASE(
      N = 20;
      M = 10;
      K = 2;
      S =string(N, '?');
    );
  }

  void TestGroup3() { // N <= MAXN_sub2, M any, K >= 2, no all '?'
    Subtasks({2, 3, 8});
    CASE(
      N = MAXN_sub2;
      M = rnd.nextInt(3, 5);
      tie(S, K) = validRandomString(N, M);
    );
    CASE(
      N = MAXN_sub2;
      M = rnd.nextInt(3, 5);
      tie(S, K) = validRandomString(N, M);
      // make invalid K
      if(K > 0) K--;
      else K++;
    );
    CASE(
      N = 8;
      M = 2;
      K = 2;
      S = "AABA?AAB";
    );
    CASE(
      N = MAXN_sub2;
      K = N/2;
      M = 2;
      S = moduloFixedCharString(N, 3, 'A');
    );
    CASE(
      N = rnd.nextInt(MAXN_sub2/2+1, MAXN_sub2);
      K = rnd.nextInt(2, N/2);
      M = rnd.nextInt(2, min(9, N-K+1));
      S = moduloFixedCharString(N, rnd.nextInt(1, N/2), 'A');
    );
    CASE(
      N = rnd.nextInt(MAXN_sub2/2+1, MAXN_sub2);
      K = rnd.nextInt(2, N/2);
      M = rnd.nextInt(2, min(9, N-K+1));
      S = moduloRandomCharString(N, rnd.nextInt(1, N/2));
    );
    CASE(
      N = rnd.nextInt(MAXN_sub2/2+1, MAXN_sub2);
      K = rnd.nextInt(2, N/2);
      M = rnd.nextInt(2, min(9, N-K+1));
      S = moduloAlternatingCharString(N, rnd.nextInt(1, N/2), 'A');
    );
    CASE(
      N = rnd.nextInt(MAXN_sub2/2+1, MAXN_sub2);
      K = rnd.nextInt(2, N/2);
      M = rnd.nextInt(2, min(9, N-K+1));
      S = randomRevealString(N, rnd.nextInt(1, N/2));
    );
  }

  void TestGroup4() { // N <= MAXN_sub3, M any, K >= 2, no all '?'
    Subtasks({3, 8});
    CASE(
      N = MAXN_sub3;
      M = rnd.nextInt(10, 20);
      tie(S, K) = validRandomString(N, M);
    );
    CASE(
      N = MAXN_sub3;
      M = rnd.nextInt(10, 20);
      tie(S, K) = validRandomString(N, M);
      // make invalid K
      if(K > 0) K--;
      else K++;
    );
    CASE(
      N = MAXN_sub3;
      K = N/3;
      M = 3;
      S = randomRevealString(N, rnd.nextInt(1, N/3));
    );
    CASE(
      N = MAXN_sub3;
      K = N/2;
      M = 13;
      S = moduloFixedCharString(N, 14, 'A');
    );
    CASE(
      N = rnd.nextInt(MAXN_sub3/2+1, MAXN_sub3);
      K = rnd.nextInt(4, N/2);
      M = rnd.nextInt(2, (N-K+1)/2);
      S = moduloFixedCharString(N, rnd.nextInt(1, N/2), 'A');
    );
    CASE(
      N = rnd.nextInt(MAXN_sub3/2+1, MAXN_sub3);
      K = rnd.nextInt(4, N/2);
      M = rnd.nextInt(2, (N-K+1)/2);
      S = moduloRandomCharString(N, rnd.nextInt(1, N/2));
    );
    CASE(
      N = rnd.nextInt(MAXN_sub3/2+1, MAXN_sub3);
      K = rnd.nextInt(4, N/2);
      M = rnd.nextInt(2, (N-K+1)/2);
      S = moduloAlternatingCharString(N, rnd.nextInt(1, N/2), 'A');
    );
    CASE( // will most likely output zero
      N = rnd.nextInt(MAXN_sub3/2+1, MAXN_sub3);
      K = rnd.nextInt(4, N/2);
      M = rnd.nextInt(2, (N-K+1)/2);
      S = randomRevealString(N, N/2);
    );
  }

  void TestGroup5() { // N <= MAXN, alternating (M = 2, K = 0), all '?'
    // ans will be 2
    Subtasks({4, 5, 6, 7, 8});
    CASE(
      N = MAXN;
      M = 2;
      K = 0;
      S = string(N, '?');
    );
    CASE(
      N = MAXN-1;
      M = 2;
      K = 0;
      S = string(N, '?');
    );
  }

  void TestGroup6() { // N <= MAXN, alternating (M = 2, K = 0), no all '?'
    // ans will be either 0/1
    Subtasks({4, 5, 6, 8});
    CASE(
      N = MAXN;
      M = 2;
      K = 0;
      S = validAlternatingString(N, rnd.nextInt(1, (int)sqrt(MAXN)));
    );
    CASE(
      N = MAXN-1;
      M = 2;
      K = 0;
      S = validAlternatingString(N, rnd.nextInt(1, (int)sqrt(MAXN)));
    );
    CASE(
      N = MAXN;
      M = 2;
      K = 0;
      S = falseAlternatingString(N, rnd.nextInt(1, (int)sqrt(MAXN)));
    );
  }

  void TestGroup7() { // N <= MAXN, M != 2, K = 0, no all '?'
    Subtasks({5, 6, 8});
    CASE( // always 0
      N = MAXN;
      M = 1;
      K = 0;
      S = randomRevealString(N, 2);
    );
    CASE(
      N = MAXN;
      M = MAXN;
      K = 0;
      S = string(N, '?');
      S[0] = 'A';
    );
    CASE(
      N = MAXN;
      M = MAXN/2;
      K = 0;
      S = randomRevealString(N, 2);
    );
    CASE(
      N = rnd.nextInt(MAXN/2, MAXN);
      M = rnd.nextInt(1, MAXN/2-1);
      if(M >= 2) M++;
      K = 0;
      S = moduloFixedCharString(N, rnd.nextInt(2, MAXN/3), 'A');
    );
    CASE(
      N = rnd.nextInt(MAXN/2, MAXN);
      M = rnd.nextInt(1, MAXN/2-1);
      if(M >= 2) M++;
      K = 0;
      S = moduloAlternatingCharString(N, rnd.nextInt(2, MAXN/3), 'A');
    );
    CASE(
      N = rnd.nextInt(MAXN/2, MAXN);
      M = rnd.nextInt(1, MAXN/2-1);
      if(M >= 2) M++;
      K = 0;
      S = moduloRandomCharString(N, rnd.nextInt(2, MAXN/3));
    );
  }

  void TestGroup8() { // N <= MAXN, M any, K = 1, no all '?'
    Subtasks({6, 8});
    CASE(
      N = MAXN;
      M = MAXN/2;
      K = 1;
      S = randomRevealString(N, 2);
    );
    CASE(
      N = rnd.nextInt(MAXN/2, MAXN);
      M = rnd.nextInt(1, MAXN/2);
      K = 1;
      S = moduloFixedCharString(N, rnd.nextInt(2, MAXN/3), 'A');
    );
    CASE(
      N = rnd.nextInt(MAXN/2, MAXN);
      M = rnd.nextInt(1, MAXN/2);
      K = 1;
      S = moduloAlternatingCharString(N, rnd.nextInt(2, MAXN/3), 'A');
    );
    CASE(
      N = rnd.nextInt(MAXN/2, MAXN);
      M = rnd.nextInt(1, MAXN/2);
      K = 1;
      S = moduloRandomCharString(N, rnd.nextInt(2, MAXN/3));
    );
  }

  void TestGroup9() { // N <= MAXN, M != 2, K = 0, all '?'
    Subtasks({5, 6, 7, 8});
    CASE(
      N = MAXN;
      K = 0;
      M = MAXN;
      S = string(N, '?');
    );
    CASE(
      N = MAXN;
      K = 0;
      M = MAXN/2;
      S = string(N, '?');
    );
  }

  void TestGroup10() { // N <= MAXN, M any, K >= 2, all '?'
    Subtasks({7, 8});
    CASE(
      N = MAXN;
      M = 2;
      K = MAXN;
      S = string(N, '?');
    );
    CASE(
      N = MAXN;
      K = MAXN/2;
      M = N-K+1;
      S = string(N, '?');
    );
    CASE(
      N = rnd.nextInt(MAXN/2, MAXN);
      K = rnd.nextInt(MAXN/2, N);
      M = N-K+1;
      S = string(N, '?');
    );
    for(int i = 0; i < 2; i++) {
      CASE(
        N = rnd.nextInt(400, MAXN/3);
        K = rnd.nextInt(3*MAXN_sub2, N-3*MAXN_sub2);
        M = rnd.nextInt(3*MAXN_sub2, N-K+1);
        S = string(N, '?');
      );
      CASE(
        N = rnd.nextInt(MAXN/2, MAXN);
        K = rnd.nextInt(MAXN/3, N);
        M = rnd.nextInt(1, N-K+1);
        S = string(N, '?');
      );
    }
  }

  void TestGroup11() { // N <= MAXN, M any, K >= 2, no all '?'
    Subtasks({8});
    CASE(
      N = MAXN;
      M = rnd.nextInt(400, 500);
      tie(S, K) = validRandomString(N, M);
    );
    CASE(
      N = MAXN;
      M = rnd.nextInt(400, 500);
      tie(S, K) = validRandomString(N, M);
      // make invalid K
      if(K > 0) K--;
      else K++;
    );
    CASE(
      N = MAXN;
      M = rnd.nextInt(400, 500);
      tie(S, K) = validRandomHiddenString(N, M, rnd.nextInt(300, M));
    );
    CASE(
      N = MAXN;
      K = 5;
      M = rnd.nextInt(100, 300);
      S = randomRevealString(N, rnd.nextInt(3, 7));
    );
    CASE(
      N = MAXN;
      K = 2;
      M = rnd.nextInt(1000, 2000);
      S = randomRevealString(N, rnd.nextInt(3, 7));
    );
    CASE(
      N = MAXN;
      K = MAXN/2;
      M = N-K+1;
      S = string(N, '?');
      S[0] = 'B';
    );
    CASE(
      N = MAXN;
      K = N/2;
      M = rnd.nextInt(2, 20);
      S = randomRevealString(N, rnd.nextInt(N/3, N/2));
    );
    CASE(
      N = MAXN;
      M = rnd.nextInt(400, 1000);
      K = rnd.nextInt(400, 1000);
      S = randomRevealString(N, rnd.nextInt(1, 2));
    );
    CASE(
      N = MAXN;
      M = rnd.nextInt(400, 1000);
      K = rnd.nextInt(400, 1000);
      S = randomRevealString(N, rnd.nextInt(1, N/6));
    );
  }

private:
  string generateAlternatingString(int n) {
    string s;
    char c = rnd.nextInt(0, 1) ? 'A' : 'B';
    for(int i = 0; i < n; i++) {
      s += c;
      if(c == 'A') c = 'B';
      else c = 'A';
    }
    return s;
  }

  string validAlternatingString(int n, int c) {
    string s = generateAlternatingString(n);
    vector<int> pick(n);
    iota(pick.begin(), pick.end(), 0);
    rnd.shuffle(pick.begin(), pick.end());
    pick.erase(pick.end()-c, pick.end());
    for(int &i : pick) {
      s[i] = '?';
    }
    return s;
  }

  string falseAlternatingString(int n, int c) {
    string s = generateAlternatingString(n);
    vector<int> pick(n);
    iota(pick.begin(), pick.end(), 0);
    rnd.shuffle(pick.begin(), pick.end());
    int idx_flip = *(pick.end() - rnd.nextInt(1, c));
    s[idx_flip] = (s[idx_flip] == 'A' ? 'B' : 'A');
    pick.erase(pick.end()-c, pick.end());
    for(int &i : pick) {
      s[i] = '?';
    }
    return s;
  }

  string moduloFixedCharString(int n, int md, char c) {
    string s = string(n, '?');
    for(int i = md-1; i < n; i+=md)
      s[i] = c;
    return s;
  }

  string moduloAlternatingCharString(int n, int md, char start) {
    string s = string(n, '?');
    char c = start;
    for(int i = md-1; i < n; i+=md) {
      s[i] = c;
      c = (c == 'A' ? 'B' : 'A');
    }
    return s;
  }

  string moduloRandomCharString(int n, int md) {
    string s = string(n, '?');
    for(int i = md-1; i < n; i+=md)
      s[i] = rnd.nextInt(0, 1) ? 'A' : 'B';
    return s;
  }

  string randomRevealString(int n, int cnt_reveal) {
    string s = string(n, '?');
    vector<int> pick(n);
    iota(pick.begin(), pick.end(), 0);
    rnd.shuffle(pick.begin(), pick.end());
    for(int i = 0; i < cnt_reveal; i++) {
      s[pick[i]] = rnd.nextInt(0, 1) ? 'A' : 'B';
    }
    return s;
  }

  pair<string, int> validRandomString(int n, int m) {
    //returns {string S, count K}
    string res;
    char c = 'A';
    int i = 0;
    int k = 0;
    while(i < n) {
      int cnt = rnd.nextInt(1, min(3*m/2, n-i));
      k += max(0, cnt - m + 1);
      for(int j = 0; j < cnt; j++)
        res += c;
      i += cnt;
      c = c == 'A' ? 'B' : 'A';
    }
    return {res, k};
  }

  pair<string, int> validRandomHiddenString(int n, int m, int cnt_hidden) {
    //return {string S, count K}
    string s; int k;
    tie(s, k) = validRandomString(n, m);
    vector<int> pick(n);
    iota(pick.begin(), pick.end(), 0);
    rnd.shuffle(pick.begin(), pick.end());
    for(int i = 0; i < cnt_hidden; i++) {
      s[pick[i]] = '?';
    }
    return {s, k};
  }
};

