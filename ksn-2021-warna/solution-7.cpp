#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e3+5;

int T, N, Q;
int X, Y;
int A[MAXN];
int B[MAXN];
int C[MAXN];

bool findAll(int x,int y) {
  cout<<"? "<<x<<" "<<y<<endl;
  cin>>X;
  return X==B[x];
}

int main () {
  cin>>T>>N>>Q;
  
  for (int i=1;i<=N;i++) {
    Y=lower_bound(C+1,C+i,i,findAll)-C-1;
    if (!Y) {
      A[0]++;
    }
    A[i]=A[Y];
    for (int j=Y+1;j<=i;j++) {
      B[j]++;
    }
    C[i]=i;
  }
  
  cout<<"!";
  for (int i=1;i<=N;i++) {
    cout<<" "<<A[i];
  }
  cout<<endl;
}
