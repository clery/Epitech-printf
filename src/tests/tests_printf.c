/*
** EPITECH PROJECT, 2023
** printf
** File description:
** tests_printf
*/

#define _GNU_SOURCE
#include <stdio.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/new/assert.h>
#include "my_printf.h"

void redirect() {
    cr_redirect_stdout();
}

TestSuite(printf, .init=redirect);

Test(printf, should_write_simple_strings_on_stdout) {
    char *expected;
    char *fmt = "Hello world\n";
    cr_expect(eq(int, my_printf(fmt), asprintf(&expected, fmt)));
    cr_assert_stdout_eq_str(expected);
    free(expected);
}

Test(printf, should_return_zero_with_empty_strings) {
    char *expected;
    char *fmt = "";
    cr_expect(eq(int, my_printf(fmt), asprintf(&expected, fmt)));
    cr_assert_stdout_eq_str(expected);
    free(expected);
}

Test(printf, should_handle_a_simple_s_flag) {
    char *expected;
    char *fmt = "Hello %s\n";
    cr_expect(eq(int, my_printf(fmt, "world"), asprintf(&expected, fmt, "world")));
    cr_assert_stdout_eq_str(expected);
    free(expected);
}

Test(printf, should_handle_a_simple_c_flag) {
    char *expected;
    char *fmt = "Hello worl%c\n";
    cr_expect(eq(int, my_printf(fmt, 'd'), asprintf(&expected, fmt, 'd')));
    cr_assert_stdout_eq_str(expected);
    free(expected);
}

Test(printf, should_handle_a_modulo_flag) {
    char *expected;
    char *fmt = "Hello 100%% world\n";
    cr_expect(eq(int, my_printf(fmt), asprintf(&expected, fmt)));
    cr_assert_stdout_eq_str(expected);
    free(expected);
}

Test(printf, should_handle_a_simple_d_flag) {
    char *expected;
    char *fmt = "Hello %d world\n";
    cr_expect(eq(int, my_printf(fmt, 123), asprintf(&expected, fmt, 123)));
    cr_assert_stdout_eq_str(expected);
    free(expected);
}

Test(printf, should_handle_a_negative_d_flag) {
    
    char *expected;
    char *fmt = "Hello %d world\n";
    cr_expect(eq(int, my_printf(fmt, -123), asprintf(&expected, fmt, -123)));
    cr_assert_stdout_eq_str(expected);
    free(expected);
}

Test(printf, should_handle_a_simple_f_flag, .disabled=true) {
    char *expected;
    char *fmt = "Hello %f world\n";
    cr_expect(eq(int, my_printf(fmt, 100.612), asprintf(&expected, fmt, 100.612)));
    cr_assert_stdout_eq_str(expected);
    free(expected);
}

Test(printf, should_handle_a_negative_f_flag, .disabled=true) {
    char *expected;
    char *fmt = "Hello %f world\n";
    cr_expect(eq(int, my_printf(fmt, -123.456789123), asprintf(&expected, fmt, -123.456789123)));
    cr_assert_stdout_eq_str(expected);
    free(expected);
}

Test(printf, should_handle_a_space_after_modulo_flag, .disabled=true) {
    char *expected;
    char *fmt = "Hello % d world\n";
    cr_expect(eq(int, my_printf(fmt, 123), asprintf(&expected, fmt, 123)));
    cr_assert_stdout_eq_str(expected);
    free(expected);
}

Test(printf, should_handle_a_simple_x_flag) {
    char *expected;
    char *fmt = "Hello %x world\n";
    cr_expect(eq(int, my_printf(fmt, 3124567098), asprintf(&expected, fmt, 3124567098)));
    cr_assert_stdout_eq_str(expected);
    free(expected);
}

Test(printf, should_handle_a_simple_caps_x_flag) {
    char *expected;
    char *fmt = "Hello %X world\n";
    cr_expect(eq(int, my_printf(fmt, 3124567098), asprintf(&expected, fmt, 3124567098)));
    cr_assert_stdout_eq_str(expected);
    free(expected);
}

Test(printf, should_handle_a_simple_o_flag) {
    char *expected;
    char *fmt = "Hello %o world\n";
    cr_expect(eq(int, my_printf(fmt, 3124567098), asprintf(&expected, fmt, 3124567098)));
    cr_assert_stdout_eq_str(expected);
    free(expected);
}

Test(printf, should_handle_a_simple_u_flag) {
    char *expected;
    char *fmt = "Hello %u world\n";
    cr_expect(eq(int, my_printf(fmt, 3124567098), asprintf(&expected, fmt, 3124567098)));
    cr_assert_stdout_eq_str(expected);
    free(expected);
}