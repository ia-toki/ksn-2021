#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

const int MAX_Nsub2 = 200;
const int MAX_Nsub3 = 2000;
const int MAX_Nsub4 = 300000;
const int MAX_Nsub5 = 2000;
const int MAX_N = 300000;

class ProblemSpec : public BaseProblemSpec {
 protected:
  int N;
  vector<int> A;

  int ans;

  void InputFormat() {
    LINE(N);
    LINE(A % SIZE(N));
  }

  void OutputFormat() {
    LINE(ans);
  }

  void GradingConfig() {
    TimeLimit(2);
    MemoryLimit(256);
  }

  void Constraints() {
    CONS(1 <= N && N <= MAX_N);
    CONS(eachElementBetween(A, 1, N));
    CONS(isDistinct(A));
  }

  void Subtask1() {
    CONS(N == 6);
    CONS(A == vector<int>({2, 5, 1, 3, 4, 6}));
    Points(0);
  }

  void Subtask2() {
    CONS(N <= MAX_Nsub2);
    Points(0);
  }

  void Subtask3() {
    CONS(N <= MAX_Nsub3);
    CONS(isSortedPerm(A));
    Points(0);
  }

  void Subtask4() {
    CONS(N <= MAX_Nsub4);
    CONS(isSortedPerm(A));
    Points(0);
  }

  void Subtask5() {
    CONS(N <= MAX_Nsub5);
    Points(0);
  }

  void Subtask6() {
    Points(0);
  }

  private:
  bool eachElementBetween(const vector<int> &A, int down, int up) {
    for (int a: A) {
      if (a < down || a > up) return false;
    }

    return true;
  }

  bool isSortedPerm(const vector<int> &A) {
    for (int i = 0; i < A.size(); i++) {
      if (A[i] != i + 1) return false;
    }
    return true;
  }

  bool isDistinct(const vector<int> &A) {
    set<int> seto;
    for (int num : A) {
      if (seto.count(num)) return false;
      seto.emplace(num);
    }
    return true;
  }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
 protected:
  void SampleTestCase1() {
    Subtasks({2, 5, 6});
    Input({
      "3",
      "2 3 1",
    });
    Output({
      "3",
    });
  }

  void SampleTestCase2() {
    Subtasks({2, 5, 6});
    Input({
      "4",
      "2 1 4 3",
    });
    Output({
      "6",
    });
  }
  
  void BeforeTestCase() {
    A.clear();
  }

  void TestGroup1() {
    Subtasks({1, 2, 5, 6});

    CASE(N = 6, A = {2, 5, 1, 3, 4, 6});
  }

  void TestGroup2() {
    Subtasks({2, 3, 4, 5, 6});

    CASE(N = 1, A = {1});
    CASE(N = 2, A = {1, 2});
    CASE(N = 3, A = {1, 2, 3});    
    CASE(N = 10, sortedPerm(A));
    CASE(N = 124, sortedPerm(A));
    CASE(N = MAX_Nsub2, sortedPerm(A));
  }

  void TestGroup3() {
    Subtasks({2, 5, 6});

    // small tc
    CASE(N = 2, A = {2, 1});
    CASE(N = 4, randomPerm(A));
    CASE(N = 10, randomPerm(A));

    CASE(N = rnd.nextInt(MAX_Nsub2-20, MAX_Nsub2), randomPerm(A));

    CASE(N = rnd.nextInt(MAX_Nsub2-10, MAX_Nsub2), sortedPerm(A, true));
    CASE(N = rnd.nextInt(MAX_Nsub2-10, MAX_Nsub2), zipPerm(A));

    CASE(N = rnd.nextInt(MAX_Nsub2-10, MAX_Nsub2), zipPerm(A), randomBySwapAdj(A, 50));
    CASE(N = rnd.nextInt(MAX_Nsub2-10, MAX_Nsub2), zipPerm(A), randomBySwap(A, 150));

    CASE(N = rnd.nextInt(MAX_Nsub2-10, MAX_Nsub2), sortedPerm(A), randomBySwapAdj(A, 200));
  }

  void TestGroup4() {
    Subtasks({3, 4, 5, 6});

    CASE(N = MAX_Nsub3, sortedPerm(A));
    CASE(N = MAX_Nsub3-1, sortedPerm(A));
    CASE(N = MAX_Nsub3-2, sortedPerm(A));
    CASE(N = rnd.nextInt(MAX_Nsub3-200, MAX_Nsub3-100), sortedPerm(A));
  }

  void TestGroup5() {
    Subtasks({4, 6});

    CASE(N = MAX_Nsub4, sortedPerm(A));
    CASE(N = MAX_Nsub4-1, sortedPerm(A));
    CASE(N = MAX_Nsub4-2, sortedPerm(A));
    CASE(N = (1 << ((int) log2(MAX_Nsub4))), sortedPerm(A));
    CASE(N = (1 << ((int) log2(MAX_Nsub4)))-1, sortedPerm(A));
  }

  void TestGroup6() {
    Subtasks({5, 6});

    CASE(N = rnd.nextInt(MAX_Nsub5-100, MAX_Nsub5), randomPerm(A));

    CASE(N = rnd.nextInt(MAX_Nsub5-50, MAX_Nsub5), sortedPerm(A, true));
    CASE(N = rnd.nextInt(MAX_Nsub5-50, MAX_Nsub5), zipPerm(A));

    CASE(N = rnd.nextInt(MAX_Nsub5-50, MAX_Nsub5), zipPerm(A), randomBySwapAdj(A, 500));
    CASE(N = rnd.nextInt(MAX_Nsub5-50, MAX_Nsub5), zipPerm(A), randomBySwap(A, 1500));

    CASE(N = rnd.nextInt(MAX_Nsub5-50, MAX_Nsub5), sortedPerm(A), randomBySwapAdj(A, 2000));
    CASE(N = rnd.nextInt(MAX_Nsub5-50, MAX_Nsub5), DAPerm(A));
    CASE(N = rnd.nextInt(MAX_Nsub5-50, MAX_Nsub5), DAPerm(A, true), randomBySwap(A, 400));
  }

  void TestGroup7() {
    Subtasks({6});

    for (int i = 1; i <= 3; i++)
      CASE(N = rnd.nextInt(MAX_N-100, MAX_N), randomPerm(A));

    CASE(N = rnd.nextInt(MAX_N-50, MAX_N), zipPerm(A));

    CASE(N = rnd.nextInt(MAX_N-50, MAX_N), zipPerm(A), randomBySwapAdj(A, 1000));
    CASE(N = rnd.nextInt(MAX_N-50, MAX_N), zipPerm(A), randomBySwap(A, 3000));

    CASE(N = rnd.nextInt(MAX_N-50, MAX_N), sortedPerm(A), randomBySwapAdj(A, 5000));
    CASE(N = rnd.nextInt(MAX_N-50, MAX_N), sortedPerm(A, true), randomBySwapAdj(A, 5000));

    CASE(N = rnd.nextInt(MAX_N-50, MAX_N), DAPerm(A));
    CASE(N = rnd.nextInt(MAX_N-50, MAX_N), DAPerm(A), randomBySwap(A, 5000));
    CASE(N = rnd.nextInt(MAX_N-50, MAX_N), DAPerm(A, true), randomBySwap(A, 5000));
  }

  private:
  void randomArray(vector<int> &A) {
    A.resize(N);
    for (int i = 0; i < N; i++) {
      A[i] = rnd.nextInt(1, N);
    }
  }

  void sortedPerm(vector<int> &A, bool rev=false) {
    A.resize(N);
    for (int i = 0; i < N; i++) {
      A[i] = i+1;
    }
    if (rev) reverse(A.begin(), A.end());
  }

  void randomPerm(vector<int> &A) {
    sortedPerm(A);
      rnd.shuffle(A.begin(), A.end());
  }

  void randomBySwapAdj(vector<int> &A, int tries) {
    assert(A.size() == N);
    int l = 0, r = N-2;
    while (tries--) {
      int pos = rnd.nextInt(l, r);
      swap(A[pos], A[pos+1]);
    }
  }

  void randomBySwap(vector<int> &A, int tries) {
    assert(A.size() == N);
    int l = 0, r = N-1;
    while (tries--) {
      int pos1 = rnd.nextInt(l, r), pos2 = rnd.nextInt(l, r);
      swap(A[pos1], A[pos2]);
    }
  }

  // pattern [1, N, 2, N-1, 3, N-2 ...]
  void zipPerm(vector<int> &A) {
    A.resize(N);
    for (int i = 0; i < N; i+=2) {
      A[i] = i/2+1;
    }

    for (int i = 1; i < N; i+=2) {
      A[i] = N-(i/2);
    }
  }

  // permutation that decreasing then ascending, preventing user to reverse permutation if their solution is more optimal if it's reversed.
  void DAPerm(vector<int> &A, bool rev=false) {
    A.resize(N);
    for (int i = 0; i <= (N-1)/2; i++) {
      A[i] = i*2 + 1;
    }
    for (int i = N-1; i > (N-1)/2; i--) {
      A[i] = (N-i)*2;
    }

    if (rev) {
      reverse(A.begin(), A.begin() + (N-1)/2 + 1);
      reverse(A.begin() + (N-1)/2 + 1, A.begin() + N);
    }
  }
};
