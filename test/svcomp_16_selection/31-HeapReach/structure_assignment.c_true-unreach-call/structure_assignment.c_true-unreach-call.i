extern void __VERIFIER_error() __attribute__ ((__noreturn__));

# 1 "files/structure_assignment.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "files/structure_assignment.c"



# 1 "./assert.h" 1

void __blast_assert()
{
 ERROR: __VERIFIER_error();
}
# 5 "files/structure_assignment.c" 2



typedef struct Stuff {
 int a;
 int b;
} Stuff;

int main()
{
 Stuff good = {1,2};
 Stuff bad;
 bad = good;
 ((bad.b == 2) ? (0) : __blast_assert ());
 return 0;
}
