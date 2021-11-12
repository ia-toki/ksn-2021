#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

const int MAXQ=100000, SMALLQ=1000;
const int BIG=1<<30, MEDIUM=1<<20, SMALL=1<<10;

class ProblemSpec : public BaseProblemSpec {
protected:
  int Q, K;
  vector <int> C, P;
  
  void InputFormat() {
    LINE(Q,K);
    LINES(C) % SIZE(Q);
  }
  
  void OutputFormat() {
    LINES(P) % SIZE(Q);
  }
  
  void GradingConfig() {
    TimeLimit(1);
    MemoryLimit(256);
  }
  
  void StyleConfig() {
    CustomScorer();
  }
  
  void Constraints() {
    CONS(1<=Q&&Q<=MAXQ);
    CONS(0<=K&&K<BIG);
    CONS(eachElementsBetween(C,0,BIG-1));
  }
  
  void Subtask1() {
    Points(9);
    CONS(Q==5);
    CONS(K==2);
    CONS(C==vector<int>({1,2,3,4,5}));
  }
  
  void Subtask2() {
    Points(11);
    CONS(K==0);
  }
  
  void Subtask3() {
    Points(12);
    CONS(eachElementsBetween(C,0,K-1));
  }
  
  void Subtask4() {
    Points(21);
    CONS(Q<=SMALLQ);
    CONS(K<SMALL);
    CONS(eachElementsBetween(C,0,SMALL-1));
  }
  
  void Subtask5() {
    Points(19);
    CONS(K<MEDIUM);
    CONS(eachElementsBetween(C,0,MEDIUM-1));
  }
  
  void Subtask6() {
    Points(28);
  }
  
private:
  bool eachElementsBetween(vector <int> V,int L,int R) {
    for (int x:V) {
      if (x<L||x>R) {
        return false;
      }
    }
    return true;
  }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
  void SampleTestCase1() {
    Subtasks({4,5,6});
    Input({
      "3 5",
      "7",
      "9",
      "13"
    });
  }
  
  void TestGroup1() {
    Subtasks({1,4,5,6});
    CASE(Q=5,K=2,C={1,2,3,4,5});
  }
  
  void TestGroup2() {
    Subtasks({2,4,5,6});
    CASE(Q=2,K=0,C={0,1});
  }
  
  void TestGroup3() {
    Subtasks({2,6});
    CASE(Q=MAXQ,K=0,C=randomBetween(Q,BIG-1,BIG-1));
    CASE(Q=MAXQ,K=0,C=randomBetween(Q,0,BIG-1));
    for (int i=1;i<=3;i++)
      CASE(Q=rnd.nextInt(1,MAXQ),K=0,C=randomBetween(Q,0,BIG-1));
  }
  
  void TestGroup4() {
    Subtasks({3,6});
    CASE(Q=MAXQ,K=BIG-1,C=randomBetween(Q,0,0));
    CASE(Q=MAXQ,K=BIG-1,C=randomBetween(Q,0,BIG-2));
    for (int i=1;i<=3;i++)
      CASE(Q=rnd.nextInt(1,MAXQ),K=rnd.nextInt(1,BIG-1),C=randomBetween(Q,0,K-1));
  }
  
  void TestGroup5() {
    Subtasks({4,5,6});
    CASE(Q=SMALLQ,K=1,C=randomBetween(Q,0,SMALL-1));
    CASE(Q=SMALLQ,K=SMALL-1,C=randomBetween(Q,SMALL-1,SMALL-1));
    for (int i=1;i<=3;i++)
      CASE(Q=rnd.nextInt(1,SMALLQ),K=rnd.nextInt(1,SMALL-1),C=randomOr(randomBetween(Q,0,SMALL-1),K));
  }
  
  void TestGroup6() {
    Subtasks({5,6});
    CASE(Q=MAXQ,K=1,C=randomBetween(Q,0,MEDIUM-1));
    CASE(Q=MAXQ,K=MEDIUM-1,C=randomBetween(Q,MEDIUM-1,MEDIUM-1));
    for (int i=1;i<=3;i++)
      CASE(Q=rnd.nextInt(1,MAXQ),K=rnd.nextInt(1,MEDIUM-1),C=randomOr(randomBetween(Q,0,MEDIUM-1),K));
  }
  
  void TestGroup7() {
    Subtasks({6});
    CASE(Q=MAXQ,K=1,C=randomBetween(Q,0,BIG-1));
    CASE(Q=MAXQ,K=BIG-1,C=randomBetween(Q,BIG-1,BIG-1));
    for (int i=1;i<=3;i++)
      CASE(Q=rnd.nextInt(1,MAXQ),K=rnd.nextInt(1,BIG-1),C=randomOr(randomBetween(Q,0,BIG-1),K));
  }
  
private:
  vector <int> randomBetween(int N,int L,int R) {
    vector <int> V(N);
    for (int i=0;i<N;i++) {
      V[i]=rnd.nextInt(L,R);
    }
    return V;
  }
  
  vector <int> randomOr(vector<int>V,int K) {
    int N=V.size();
    for (int i=0;i<N;i++) {
      if (rnd.nextInt(0,99)) {
        V[i]=V[i]|K;
      }
    }
    return V;
  }
};
