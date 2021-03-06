/*
* File Name: cmp_funcadr.c
* Defect Classification
* ---------------------
* Defect Type: Pointer related defects
* Defect Sub-type: Comparison NULL with function pointer
* Description: Defect Free Code to identify false positives while comparison of NULL with function pointers
*/

/*
 * HeaderFile.h
 *
 */

#ifndef HEADERFILE_H_
#define HEADERFILE_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>
#include <unistd.h>
#include <limits.h>

extern int idx, sink;
extern double dsink;
extern void *psink;

void bit_shift_main (void);
void dynamic_buffer_overrun_main (void);
void dynamic_buffer_underrun_main (void);
void cmp_funcadr_main (void);
void conflicting_cond_main (void);
void data_lost_main (void);
void data_overflow_main (void);
void data_underflow_main (void);
void dead_code_main (void);
void dead_lock_main (void);
void deletion_of_data_structure_sentinel_main (void);
void double_free_main (void);
void double_lock_main (void);
void double_release_main (void);
void endless_loop_main (void);
void free_nondynamic_allocated_memory_main (void);
void free_null_pointer_main (void);
void func_pointer_main (void);
void function_return_value_unchecked_main (void);
void improper_termination_of_block_main (void);
void insign_code_main (void);
void invalid_extern_main (void);
void invalid_memory_access_main (void);
void littlemem_st_main (void);
void livelock_main (void);
void lock_never_unlock_main  (void);
void memory_allocation_failure_main(void);
void memory_leak_main (void);
void not_return_main (void);
void null_pointer_main (void);
void overrun_st_main (void);
void ow_memcpy_main (void);
void pow_related_errors_main (void);
void ptr_subtraction_main (void);
void race_condition_main (void);
void redundant_cond_main (void);
void return_local_main (void);
void sign_conv_main (void);
void sleep_lock_main (void);
void st_cross_thread_access_main (void);
void st_overflow_main (void);
void st_underrun_main (void);
void underrun_st_main (void);
void uninit_memory_access_main (void);
void uninit_pointer_main (void);
void uninit_var_main (void);
void unlock_without_lock_main (void);
void unused_var_main (void);
void wrong_arguments_func_pointer_main (void);
void zero_division_main (void);

/*
# define PRINT_DEBUG 0
*/

#endif /* HEADERFILE_H_ */

/*
 * Types of defects: comparing function addresses with NULL
 * Complexity: constant (NULL)
 */
int cmp_funcadr_001_glb_a;
int* cmp_funcadr_001_func_001 ()
{
	return &cmp_funcadr_001_glb_a;
}

void cmp_funcadr_001 ()
{
	int ret = 0;
	if (cmp_funcadr_001_func_001() == NULL) /*Tool should Not detect this line as error*/ /*No ERROR:compare function address with NULL*/
	{
		ret = 1;
	}
        sink = ret;
}

/*
 * Types of defects: comparing function addresses with NULL
 * Complexity: constant (numeric)
 * Note: the PolySpace compilation error handling
 *       (operands of == have incompatible types)
 */
int cmp_funcadr_002_func_001 ()
{
	return 10;
}

void cmp_funcadr_002 ()
{
	int ret = 0;
	if (cmp_funcadr_002_func_001() == 10) /*Tool should Not detect this line as error*/ /*No ERROR:compare function address with NULL*/
	{
		ret = 1;
	}
        sink = ret;
}

/*
 * Types of defects: comparing function addresses with NULL
 * comparing function addresses main function
 */
extern volatile int vflag;
void cmp_funcadr_main ()
{
	if (vflag ==1 || vflag == 888)
	{
		cmp_funcadr_001();
	}

	if (vflag ==2 || vflag == 888)
	{
		cmp_funcadr_002();
	}
}
