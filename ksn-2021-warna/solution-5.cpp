#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e3+5;

int T, N, Q;
int X, Y;
int A[MAXN];

bool findRight(int x,int y) {
  cout<<"? 1 "<<x<<endl;
  cin>>X;
  return X==x;
}

bool findLeft(int x,int y) {
  cout<<"? "<<x<<" "<<y<<endl;
  cin>>X;
  return X==y-x;
}

int main () {
  cin>>T>>N>>Q;
  
  for (int i=1;i<=N;i++) {
    A[i]=i;
  }
  Y=lower_bound(A+1,A+N+1,0,findRight)-A;
  if (Y<=N) {
    A[Y]=lower_bound(A+1,A+Y,Y,findLeft)-A;
    for (int i=Y;i<=N;i++) {
      A[i]--;
    }
  }
  
  cout<<"!";
  for (int i=1;i<=N;i++) {
    cout<<" "<<A[i];
  }
  cout<<endl;
}
