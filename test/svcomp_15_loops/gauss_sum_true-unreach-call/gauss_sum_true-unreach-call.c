#include "assert.h"

void main() {
    int n, sum, i;
    n = __VERIFIER_nondet_int();
    __VERIFIER_assume(1 <= n && n <= 1000);
    sum = 0;
    for(i = 1; i <= n; i++) {
	sum = sum + i;
    }
    __VERIFIER_assert(2*sum == n*(n+1));
}
