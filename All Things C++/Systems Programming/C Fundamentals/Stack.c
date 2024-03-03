int f(int, int);
int g(int);

int main(int argc, char** argv) {
  int n1 = f(3,-5);
  n1 = g(n1);
}

int f(int p1, int p2) {
  int x;
  int a[3];
  x = g(a[2]);
  return x;
}

int g(int param) {
  return param * 2;
}