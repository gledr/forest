/********Software Analysis - FY2013*************/
/*
* File Name: conflicting_cond.c
* Defect Classification
* ---------------------
* Defect Type: Inappropriate code
* Defect Sub-type: Contradict conditions
* Description: Defect Free Code to identify false positives occurring in contradicting conditions
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
int rand (void);

/*
 * Types of defects: contradict condition
 * Complexity: the if statement	(a==0&&a==1)
 */
void conflicting_cond_001 ()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	if ((a == 0) || (a == 1)) /*Tool should Not detect this line as error*/ /*No ERROR:contradict condition*/
	{
		b += a;
	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: contradict condition
 * Complexity: the if statement	(a<5&&10<a)
 */
void conflicting_cond_002 ()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	if (! ((a < 5) || (10 < a))) /*Tool should Not detect this line as error*/ /*No ERROR:contradict condition*/
	{
		b += a;
	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: contradict condition
 * Complexity: the if statement	((0<a&&a<2)&&(8<a&&a<10))
 */
void conflicting_cond_003 ()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	if (((0 < a) && (a < 2)) || ((8 < a) && (a < 10)))/*Tool should Not detect this line as error*/ /*No ERROR:contradict condition*/
	{
		b += a;
	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: contradict condition
 * Complexity: the if statement	nested if statement if (a < 5) if(10<a)�j
 */
void conflicting_cond_004 ()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	if (a < 5)
	{
		a += 10;
		if (10 < a)/*Tool should Not detect this line as error*/ /*No ERROR:contradict condition*/
		{
			b += a;
		}
	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: contradict condition
 * Complexity: conditional operator	(a==0&&a==1)
 */
void conflicting_cond_005 ()
{
	int a;
	int b;
	int ret;

	a = rand();
	b = ((a == 0) || (a == 1)) ? 0 : 1;/*Tool should Not detect this line as error*/ /*No ERROR:contradict condition*/
	ret = b;
        sink = ret;
}

/*
 * Types of defects: contradict condition
 * Complexity: the for statement	(a==0&&a==1)
 */
void conflicting_cond_006 ()
{
	int a;
	int b = 0;
	int ret;

	for (a = 0; (a == 0) || (a == 1); a ++)/*Tool should Not detect this line as error*/ /*No ERROR:contradict condition*/
	{
		b += a;
	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: contradict condition
 * Complexity: while statement	(a==0&&a==1)
 */
void conflicting_cond_007 ()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	while ((a == 0) || (a == 1))/*Tool should Not detect this line as error*/ /*No ERROR:contradict condition*/
	{
		b += a;
		a ++;
	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: contradict condition
 * Complexity: while statement	(a<5&&10<a)
 */
void conflicting_cond_008 ()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	while (! ((a < 5) || (10 < a)))/*Tool should Not detect this line as error*/ /*No ERROR:contradict condition*/
	{
		b += a;
		a ++;
	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: contradict condition
 * Complexity: while statement	((0<a&&a<2)&&(8<a&&a<10))
 */
void conflicting_cond_009 ()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	while (((0 < a) && (a < 2)) || ((8 < a) && (a < 10)))/*Tool should Not detect this line as error*/ /*No ERROR:contradict condition*/
	{
		b += a;
		a ++;
	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: contradict condition
 * Complexity: do-while statement	(a==0&&a==1)
 */
void conflicting_cond_010 ()
{
	int a;
	int ret;

	do
	{
		a = rand();
	}
	while ((a == 0) || (a == 1));/*Tool should Not detect this line as error*/ /*No ERROR:contradict condition*/
	ret = a;
        sink = ret;
}

/*
 * Types of defects: contradict condition
 * contradict condition - main function
 */
extern volatile int vflag;
void conflicting_cond_main ()
{
	if (vflag ==1 || vflag ==888)
	{
		conflicting_cond_001();
	}

	if (vflag ==2 || vflag ==888)
	{
		conflicting_cond_002();
	}

	if (vflag ==3 || vflag ==888)
	{
		conflicting_cond_003();
	}

	if (vflag ==4 || vflag ==888)
	{
		conflicting_cond_004();
	}

	if (vflag ==5 || vflag ==888)
	{
		conflicting_cond_005();
	}

	if (vflag ==6 || vflag ==888)
	{
		conflicting_cond_006();
	}

	if (vflag ==7 || vflag ==888)
	{
		conflicting_cond_007();
	}

	if (vflag ==8 || vflag ==888)
	{
		conflicting_cond_008();
	}

	if (vflag ==9 || vflag ==888)
	{
		conflicting_cond_009();
	}

	if (vflag ==10 || vflag ==888)
	{
		conflicting_cond_010();
	}
}
