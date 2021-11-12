#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e3+5;

int T, N, Q;
int X, Y;
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
  
  for (int i=1;i<=3;i++) {
    C[i]=i;
  }
  for (int i=1;i<=N;i++) {
    Y=lower_bound(C+1,C+4,i,ask)-C;
    if (!B[Y]) {
      if (Y==4) {
        A[i]=10-A[B[1]]-A[B[2]]-A[B[3]];
      }
      else {
        A[i]=Y;
      }
    }
    else {
      A[i]=A[B[Y]];
    }
    for (int j=Y;j;j--) {
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
