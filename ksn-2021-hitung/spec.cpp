#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

const int MAX_Q = 1e4;

class ProblemSpec : public BaseProblemSpec {
protected:
  int Q;
  vector<int> A;

  void InputFormat() {
    LINE(Q);
    LINE(A % SIZE(Q));
  }

  void GradingConfig() {
    TimeLimit(2);
    MemoryLimit(256);
  }

  void StyleConfig() {
    InteractiveEvaluator();
  }

  void Constraints() {
    CONS(1 <= Q && Q <= MAX_Q);
  }

  void Subtask1() {
    Points(10);
    CONS(alwaysRight(A));
  }

  void Subtask2() {
    Points(10);
    CONS(alwaysWrong(A));
  }

  void Subtask3() {
    Points(15);
    CONS(allElementsIs(A, 1));
  }

  void Subtask4() {
    Points(65);
  }

private:
  bool alwaysRight(vector<int> &A) {
    for(int i = 0; i < (int)A.size(); i++) {
      if(A[i] != i+1) return false;
    }
    return true;
  }

  bool alwaysWrong(vector<int> &A) {
    for(int i = 0; i < (int)A.size(); i++) {
      if(A[i] == 1) return false;
    }
    return true;
  }

  bool allElementsIs(vector<int> &A, int x) {
    for(auto it : A) {
      if(it != x) return false;
    }
    return true;
  }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
  void SampleTestCase1() {
    Subtasks({4});
    Input({
      "4",
      "1 2 5 1"
    });
  }

  void TestGroup1() {
    Subtasks({1, 4});
    CASE(Q = 4, A = allRight(Q));
    CASE(Q = MAX_Q, A = allRight(Q));
    for(int i = 0; i < 3; i++) {
      CASE(Q = rnd.nextInt(1, MAX_Q), A = allRight(Q));
    }
  }

  void TestGroup2() {
    Subtasks({2, 4});
    CASE(Q = 4, A = allWrong(Q));
    CASE(Q = MAX_Q, A = allWrong(Q));
    for(int i = 0; i < 3; i++) {
      CASE(Q = rnd.nextInt(1, MAX_Q), A = allWrong(Q));
    }
  }

  void TestGroup3() {
    Subtasks({3, 4});
    CASE(Q = 4, A = allOnes(Q));
    CASE(Q = MAX_Q, A = allOnes(Q));
    for(int i = 0; i < 3; i++) {
      CASE(Q = rnd.nextInt(1, MAX_Q), A = allOnes(Q));
    }
  }

  void TestGroup4() {
    Subtasks({4});
    for(auto x : {20, 200, 2000, MAX_Q}) {
      CASE(Q = MAX_Q, A = randomArray(Q, x));
      for(int i = 0; i < 2; i++) {
        CASE(Q = rnd.nextInt(x, MAX_Q), A = randomArray(Q, x));
      }
    }
    for(auto x : {20, 200, 2000}) {
      for(int i = 0; i <= 1; i++) {
        CASE(Q = MAX_Q, A = moduloFlip(Q, rnd.nextInt(x/2, x), i));
      }
    }
  }

private:
  vector<int> allRight(int n) {
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    return a;
  }

  vector<int> allWrong(int n) {
    vector<int> a(n);
    for(int &x : a) {
      x = rnd.nextInt(2, MAX_Q);
    }
    return a;
  }

  vector<int> allOnes(int n) {
    return vector<int>(n, 1);
  }

  vector<int> randomArray(int n, int streak_limit = MAX_Q) {
    vector<int> a;
    int prv = 0;
    for(int ty = rnd.nextInt(0, 1); a.size() < n; ty ^= 1) {
      int sz = rnd.nextInt(1, min(streak_limit, n - (int)a.size()));
      if(ty == 0) { // wrong
        int x = rnd.nextInt(1, MAX_Q);
        if(!a.empty() && x == a.back()+1) x++;
        a.push_back(x);
        if(sz > 1) {
          vector<int> v = allWrong(sz-1);
          a.insert(a.end(), v.begin(), v.end());
        }
      } else { // right
        vector<int> v = allRight(sz);
        a.insert(a.end(), v.begin(), v.end());
      }
    }
    return a;
  }

  vector<int> moduloFlip(int n, int md, int st = 0) {
    vector<int> a;
    for(int ty = st; a.size() < n; ty ^= 1) {
      int sz = min(md, n - (int)a.size());
      if(ty == 0) { // wrong
        int x = rnd.nextInt(1, MAX_Q);
        if(!a.empty() && x == a.back()+1) x++;
        a.push_back(x);
        if(sz > 1) {
          vector<int> v = allWrong(sz-1);
          a.insert(a.end(), v.begin(), v.end());
        }
      } else { // right
        vector<int> v = allRight(sz);
        a.insert(a.end(), v.begin(), v.end());
      }
    }
    return a;
  }
};
