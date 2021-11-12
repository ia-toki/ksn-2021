#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e3+5;

int T, N, Q;
int K, M, X, Y;
int A[MAXN];
int B[MAXN];

int brute(int i) {
  if (M<K) {
    cout<<"? 1 "<<i<<endl;
    cin>>X;
    if (X>M) {
      return ++M;
    }
  }
  Y=1;
  for (int j=1;j<=M;j++) {
    B[j]=0;
  }
  for (int j=i-1;Y<M;j--) {
    if (!B[A[j]]++) {
      Y++;
      cout<<"? "<<j<<" "<<i<<endl;
      cin>>X;
      if (X!=Y) {
        return A[j];
      }
    }
  }
  for (int j=1;j<=M;j++) {
    if (!B[j]) {
      return j;
    }
  }
  return 0;
}

int main () {
  cin>>T>>N>>Q;
  cout<<"? 1 "<<N<<endl;
  cin>>K;
  M=1;
  
  for (int i=1;i<=N;i++) {
    A[i]=brute(i);
  }
  
  cout<<"!";
  for (int i=1;i<=N;i++) {
    cout<<" "<<A[i];
  }
  cout<<endl;
}
