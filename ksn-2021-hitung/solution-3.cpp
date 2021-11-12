#include <iostream>
using namespace std;

int n, x;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> x;
    cout << ((i % 2 == 0) ? "BENAR" : "SALAH") << endl;
  }
  return 0;
}
