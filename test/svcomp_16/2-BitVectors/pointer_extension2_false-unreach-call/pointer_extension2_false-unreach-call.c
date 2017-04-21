extern void __VERIFIER_error() __attribute__ ((__noreturn__));

#include <stdio.h>

int main() {
  char t = 50;
  char* z1 = &t;
  void* z2 = z1;
  unsigned int* pi = z2;
  printf ("pi = %u\n", *pi);
  // We could dereference anything here
  if (*pi != 50) {
    printf ("UNSAFE\n");
    goto ERROR;
  }
  printf ("SAFE\n");

  return (0);
  ERROR: __VERIFIER_error();
  return (-1);
}

