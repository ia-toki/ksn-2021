#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e3+5;

int T, N, Q;
int K, X, Y;
int A[MAXN];
int B[MAXN];
int C[MAXN];

bool ask(int x,int y) {
  if (!B[x]) return 0;
  cout<<"? "<<B[x]<<" "<<y<<endl;
  cin>>X;
  return X!=x;
}

int main () {
  cin>>T>>N>>Q;
  cout<<"? 1 "<<N<<endl;
  cin>>K;
  for (int i=1;i<K;i++) {
    C[i]=i;
  }
  
  for (int i=1;i<=N;i++) {
    Y=lower_bound(C+1,C+K,i,ask)-C;
    if (!B[Y]) {
      A[i]=Y;
    }
    else {
      A[i]=A[B[Y]];
    }
    for (int j=Y;j>1;j--) {
      B[j]=B[j-1];
    }
    B[1]=i;
  }
  
  cout<<"!";
  for (int i=1;i<=N;i++) {
    cout<<" "<<A[i];
  }
  cout<<endl;
}
