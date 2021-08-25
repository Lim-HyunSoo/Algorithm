#include <iostream>

using namespace std;

int factorial(int n) {
  if(n > 1) {
    return n * factorial(n-1);
  }
  else {
    return 1;
  }
}
void main() {
  cout << factorial(5) << endl;
}
