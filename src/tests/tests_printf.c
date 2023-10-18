/*
** EPITECH PROJECT, 2023
** printf
** File description:
** tests_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/new/assert.h>
#include "my_printf.h"

void redirect() {
    cr_redirect_stdout();
}

TestSuite(printf, .init=redirect);

Test(printf, should_write_simple_strings_on_stdout) {
    char expected[] = "Hello world\n";
    cr_assert(eq(int, my_printf("Hello world\n"), sizeof(expected) - 1));
    cr_assert_stdout_eq_str(expected);
}

Test(printf, should_return_zero_with_empty_strings) {
    char expected[] = "";
    cr_assert(eq(int, my_printf(""), sizeof(expected) - 1));
    cr_assert_stdout_eq_str(expected);
}

Test(printf, should_handle_a_simple_s_flag) {
    char expected[] = "Hello world\n";
    cr_assert(eq(int, my_printf("Hello %s\n", "world"), sizeof(expected) - 1));
    cr_assert_stdout_eq_str(expected);
}

Test(printf, should_handle_a_simple_c_flag) {
    char expected[] = "Hello world\n";
    cr_assert(eq(int, my_printf("Hello worl%c\n", 'd'), sizeof(expected) - 1));
    cr_assert_stdout_eq_str(expected);
}

Test(printf, should_handle_a_simple_d_flag) {
    char expected[] = "Hello 123 world\n";
    cr_assert(eq(int, my_printf("Hello %d world\n", 123), sizeof(expected) - 1));
    cr_assert_stdout_eq_str(expected);
}

