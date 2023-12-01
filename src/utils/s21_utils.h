#ifndef SRC_UTILS_S21_UTILS_H_
#define SRC_UTILS_S21_UTILS_H_

#include "../s21_main_func.h"

/**
 * @brief Function that translate decimal to addcode
 * @param val_1 pointer to decimal
 */
void convert_to_addcode(s21_decimal *val_1);

/**
 * @brief Function that translate bigdecimal to addcode
 * @param val_1 pointer to bigdecimal
 */
void big_convert_to_addcode(s21_big_decimal *val_1);

/**
 * @brief Decimal number ititialization
 * @param val pointer to decimal number
 */
void init_decimal(s21_decimal *val);

/**
 * @brief big_decimal number ititialization
 * @param val pointer to big_decimal number
 */
void init_big_decimal(s21_big_decimal *val);

/**
 * @brief Decimal number ititialization
 * @return decimal number
 */
s21_decimal create_decimal(unsigned int low_num, unsigned int mid_num,
                           unsigned int high_num, unsigned int scale_info);

/**
 * @brief Function that transform number of mantissa from decimal to float
 * @param val decimal number
 * @return float number of mantissa
 */
float get_full_bits(s21_decimal val);

/**
 * @brief Function that returns value of i-th bit for decimal
 * @param val decimal number
 * @param i bit number
 * @return value specified bit (0 - bit off, 1 - bit on)
 */
int get_bit(s21_decimal val, int i);

/**
 * @brief Function that returns value of i-th bit for big_decimal
 * @param val big_decimal number
 * @param i bit number
 * @return value specified bit (0 - bit off, 1 - bit on)
 */
int big_get_bit(s21_big_decimal val, int i);

/**
 * @brief Function that set i-th bit for decimal
 * @param val pointer to decimal number
 * @param i bit number
 * @param value setting bit value (0 or 1)
 */
void set_bit(s21_decimal *val, int i, int value);

/**
 * @brief Function that set i-th bit for big_decimal
 * @param val pointer to big_decimal number
 * @param i bit number
 * @param value setting bit value (0 or 1)
 */
void big_set_bit(s21_big_decimal *val, int i, int value);

/**
 * @brief Function that find first bit that on in decimal number
 * @param val decimal number
 * @return 0-95 - bit's number that first on, -1 - if all bits are off
 */
int last_bit(s21_decimal val);

/**
 * @brief Function that gets decimal number's scale
 * @param val decimal number
 * @return value of scale
 */
int get_scale(s21_decimal val);

/**
 * @brief Function that gets big_decimal number's scale
 * @param val decimal number
 * @return value of scale
 */
int big_get_scale(s21_big_decimal val);

/**
 * @brief Function that sets decimal number's scale
 * @param val pointer to decimal number
 * @return value of scale
 */
void set_scale(s21_decimal *val, int scale);

/**
 * @brief Function that sets big_decimal number's scale
 * @param val pointer to decimal number
 * @return value of scale
 */
void big_set_scale(s21_big_decimal *val, int scale);

/**
 * @brief Function that equalize scales of two decimal numbers
 * @param val_1 pointer to decimal number
 * @param val_2 pointer to decimal number
 * @return code error
 */
int scale_eq(s21_decimal *val_1, s21_decimal *val_2);

/**
 * @brief Function that equalizes scales of two big_decimal numbers
 * @param val_1 pointer to decimal number
 * @param val_2 pointer to decimal number
 * @return code error
 */
int big_scale_eq(s21_big_decimal *val_1, s21_big_decimal *val_2);

/**
 * @brief Function that gets decimal number sign
 * @param val decimal number
 * @return sign value of number (0 - positive, 1 - negative)
 */
int get_sign(s21_decimal val);

/**
 * @brief Function that gets big_decimal number sign
 * @param val decimal number
 * @return sign value of number (0 - positive, 1 - negative)
 */
int big_get_sign(s21_big_decimal val);

/**
 * @brief Function that sets decimal number sign
 * @param val decimal number
 * @param sign sign value of number (0 - positive, 1 - negative)
 */
void set_sign(s21_decimal *val, int sign);

/**
 * @brief Function that sets big_decimal number sign
 * @param val decimal number
 * @param sign sign value of number (0 - positive, 1 - negative)
 */
void big_set_sign(s21_big_decimal *val, int sign);

/**
 * @brief bitwise left shift
 * @param val decimal number
 * @param move_value bits amount to shift
 * @return code error
 */
int move_left(s21_decimal *val, int move_value);

/**
 * @brief bitwise left shift
 * @param val big_decimal number
 * @param move_value bits amount to shift
 * @return code error
 */
int big_move_left(s21_big_decimal *val, int move_value);

/**
 * @brief Add bits that content mantissa of two decimals
 * @param val_1 first decimal number
 * @param val_2 second decimal number
 * @param result pointer to decimal number result
 * @param code ок - add, extra - addcode
 * @return code error
 */
int bit_addition(s21_decimal *val_1, s21_decimal *val_2, s21_decimal *result,
                 int code);

/**
 * @brief Add bits that content mantissa of two big_decimals
 * @param val_1 first decimal number
 * @param val_2 second decimal number
 * @param result pointer to decimal number result
 * @param code ок - add, extra - addcode
 * @return code error
 */
int big_bit_addition(s21_big_decimal *val_1, s21_big_decimal *val_2,
                     s21_big_decimal *result, int code);

/**
 * @brief Function that check decimal numbers is zero or not
 * @param val_1 first decimal number
 * @param val_2 second decimal number
 * @return 0 - both of them is zero,
 * 1 - isn't zero (at least one of them)
 */
int zero_check(s21_decimal val_1, s21_decimal val_2);

/**
 * @brief Function that check big_decimal numbers is zero or not
 * @param val_1 first decimal number
 * @param val_2 second decimal number
 * @return 0 - both of them is zero,
 * 1 - isn't zero (at least one of them)
 */
int big_zero_check(s21_big_decimal val_1, s21_big_decimal val_2);

/**
 * @brief Check value sign of decimal numbers
 * @param val_1 first decimal number
 * @param val_2 second decimal number
 * @return 0 - both same value sign, 1 - first decimal number is positive, -1 -
 * second decimal number is positive
 */
int is_negative(s21_decimal *val_1, s21_decimal *val_2);

/**
 * @brief Copy from src to dest only mantissa of decimal number
 * @param src decimal number from copy
 * @param dest decimal number to copy
 */
void copy_bits(s21_decimal src, s21_decimal *dest);

/**
 * @brief Copy from src to dest only mantissa of big_decimal number
 * @param src decimal number from copy
 * @param dest decimal number to copy
 */
void big_copy_bits(s21_decimal src, s21_big_decimal *dest);

/**
 * @brief Division only mantissa of two decimal numbers
 * @param value_1 divisible decimal
 * @param value_2 divider decimal
 * @param div_remainder pointer to decimal number that content division
 * remainder
 * @param result pointer to decimal number that content integer part of number
 */
void div_only_bits(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *div_remainder, s21_decimal *result);

/**
 * @brief Division only mantissa of two big_decimal numbers
 * @param value_1 divisible decimal
 * @param value_2 divider decimal
 * @param div_remainder pointer to big_decimal number that content division
 * remainder
 * @param result pointer to big_decimal number that content integer part of
 * number
 */
void big_div_only_bits(s21_big_decimal value_1, s21_big_decimal value_2,
                       s21_big_decimal *div_remainder, s21_big_decimal *result);

/**
 * @brief Function that transform nunber from float to decimal
 * @param num float number
 * @param result decimal number
 */
void float_to_bin(float num, s21_decimal *result);

/**
 * @brief Function that check two big_decimal is equal or not
 * @param first first decimal
 * @param second second decimal
 * @return 0 - first != second, 1 - first == second
 */
int big_s21_is_equal(s21_big_decimal first, s21_big_decimal second);

/**
 * @brief Function that check that first big_decimal is greater than second
 * @param first first decimal
 * @param second second decimal
 * @return 0 - second >= first, 1 - first > second
 */
int big_s21_is_greater(s21_big_decimal first, s21_big_decimal second);

/**
 * @brief Function that check that first big_decimal is greater or equal than
 * second
 * @param first first decimal
 * @param second second decimal
 * @return 0 - second > first, 1 - first >= second
 */
int big_s21_is_greater_or_equal(s21_big_decimal first, s21_big_decimal second);

#endif
