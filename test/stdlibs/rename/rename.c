/*
 * =====================================================================================
 * /
 * |     Filename:  rename.c
 * |
 * |  Description:  
 * |
 * |      Version:  1.0
 * |      Created:  05/09/2014 11:55:49 AM
 * |     Revision:  none
 * |     Compiler:  gcc
 * `-. .--------------------
 *    Y
 *    ,,  ,---,
 *   (_,\/_\_/_\     Author:   Pablo González de Aledo (), pablo.aledo@gmail.com
 *     \.\_/_\_/>    Company:  Universidad de Cantabria
 *     '-'   '-'
 * =====================================================================================
 */

#include <stdio.h>

int main(int argc, const char *argv[])
{
	rename("hello", "bye");
	return 0;
}
