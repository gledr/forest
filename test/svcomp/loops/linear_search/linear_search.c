#define SIZE 10

int linear_search(int *a, int n, int q) {
  unsigned int j=0;
  while (j<n && a[j]!=q) {
  j++;
  }
  if (j<SIZE) return 1;
  else return 0;
}

int main() {
  int a[SIZE];
  a[SIZE/2]=3;
  if(linear_search(a,SIZE,3)) return 1;
  else return 0;
}
