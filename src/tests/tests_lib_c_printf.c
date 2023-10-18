/*
** EPITECH PROJECT, 2023
** printf
** File description:
** tests_printf
*/


#include <stdio.h>
#include <errno.h>

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/alloc.h>
#include <criterion/redirect.h>
#include <string.h>

#include "my_printf.h"

void redirect(void);

static const char * OUTPUT_FILE = "./.out.txt";

static void remove_output_file(void)
{
    remove(OUTPUT_FILE);
}

TestSuite(lib_c_printf, .init=redirect, .fini=remove_output_file);

Test(lib_c_printf, basic_test)
{
    FILE *reference_file = fopen(OUTPUT_FILE, "wr+");
    const char expected[] = "PLOP\n";

    cr_assert(not(eq(ptr, reference_file, NULL)));
    fprintf(reference_file, expected);
    fflush(reference_file);
    cr_expect(eq(int, my_printf(expected), sizeof(expected) - 1));
    fflush(stdout);
    cr_expect_stdout_eq(reference_file);
    fclose(reference_file);
}
