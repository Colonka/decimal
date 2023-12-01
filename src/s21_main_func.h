#ifndef SRC_S21_MAIN_FUNC_H_
#define SRC_S21_MAIN_FUNC_H_

#define MINUS_SIGN 2147483648    // 32-th bit
#define TOTAL_BITS 32            // bits amount of one bits[]
#define S21_MAX_UINT 4294967295  // 2^32 (max number by one bits[])
#define DEFAULT_BASE 65536       // default base of number = 1

#define is_inf(x) __builtin_isinf(x)
#define is_nan(x) __builtin_isnan(x)

/// @brief Error and info codes
typedef enum {
  OK,                ///<
  TOO_BIG,           ///< Result is greater that max possible decimal
  TOO_SMALL,         ///< Result is less that min possible decimal
  DIVISION_BY_ZERO,  ///< Division by zero
  EXTRA_CODE  ///< Indicator that one of the decimal number transformed to
              ///< addcode
} value_type_t;

/// @brief Bits names
enum {
  low,   ///< bits[0]
  mid,   ///< bits[1]
  high,  ///< bits[2]
  scale  ///< bits[3]
};

/// @brief Convertation condition
enum Convertation { CONVERTATION_OK, CONVERTATION_ERROR };

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[7];
} s21_big_decimal;

//========Arithmetic functions========//

/**
 * @brief Function that add two decimal
 * @param [in] value_1 first decimal
 * @param [in] value_2 second decimal
 * @param [out] result result of addition
 * @return error's code
 */
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/**
 * @brief Function that subtracts second decimal from first decimal
 * @param [in] value_1 first decimal
 * @param [in] value_2 second decimal
 * @param [out] result result of subtractions
 * @return error's code
 */
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/**
 * @brief Function that multiplicate two decimal
 * @param [in] value_1 first decimal
 * @param [in] value_2 second decimal
 * @param [out] result result of multiplication
 * @return error's code
 */
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/**
 * @brief Function that divide two decimal
 * @param [in] value_1 divisible decimal
 * @param [in] value_2 divider decimal
 * @param [out] result result of division
 * @return error's code
 */
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/**
 * @brief Function that computes remainder of division two decimal
 * @param [in] value_1 divisible decimal
 * @param [in] value_2 divider decimal
 * @param [out] result remainder
 * @return error's code
 */
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

//========Comparison functions========//

/**
 * @brief Function that check two decimal is equal or not
 * @param [in] first first decimal
 * @param [in] second second decimal
 * @return 0 - first != second, 1 - first == second
 */
int s21_is_equal(s21_decimal first, s21_decimal second);

/**
 * @brief Function that check two decimal is not equal or is equal
 * @param [in] first first decimal
 * @param [in] second second decimal
 * @return 0 - first == second, 1 - first != second
 */
int s21_is_not_equal(s21_decimal first, s21_decimal second);

/**
 * @brief Function that check that first decimal is greater than second
 * @param [in] first first decimal
 * @param [in] second second decimal
 * @return 0 - second >= first, 1 - first > second
 */
int s21_is_greater(s21_decimal first, s21_decimal second);

/**
 * @brief Function that check that first decimal is greater or equal than second
 * @param [in] first first decimal
 * @param [in] second second decimal
 * @return 0 - second > first, 1 - first >= second
 */
int s21_is_greater_or_equal(s21_decimal first, s21_decimal second);

/**
 * @brief Function that check that first decimal is less than second
 * @param [in] first first decimal
 * @param [in] second second decimal
 * @return 0 - first >= second , 1 - first < second
 */
int s21_is_less(s21_decimal first, s21_decimal second);

/**
 * @brief Function that check that first decimal is less or equal than second
 * @param [in] first first decimal
 * @param [in] second second decimal
 * @return 0 - first >= second , 1 - first < second
 */
int s21_is_less_or_equal(s21_decimal first, s21_decimal second);

//========Transformation functions========//

/**
 * @brief Fuction that transform int to decimal
 * @param [in] src int number
 * @param [in] dst pointer to decimal number
 * @return 0 - CONVERTATION_OK, 1 - CONVERTATION_ERROR
 */
int s21_from_int_to_decimal(int src, s21_decimal *dst);

/**
 * @brief Fuction that transform float to decimal
 * @param [in] src float number
 * @param [in] dst pointer to decimal number
 * @return 0 - CONVERTATION_OK, 1 - CONVERTATION_ERROR
 */
int s21_from_float_to_decimal(float src, s21_decimal *dst);

/**
 * @brief Fuction that transform decimal to int
 * @param [in] src int number
 * @param [in] dst pointer to decimal number
 * @return 0 - CONVERTATION_OK, 1 - CONVERTATION_ERROR
 */
int s21_from_decimal_to_int(s21_decimal src, int *dst);

/**
 * @brief Fuction that transform decimal to float
 * @param [in] src int number
 * @param [in] dst pointer to decimal number
 * @return 0 - CONVERTATION_OK, 1 - CONVERTATION_ERROR
 */
int s21_from_decimal_to_float(s21_decimal src, float *dst);

//========Addition functions========//

/**
 * @brief Rounds a decimal value to the nearest integer.
 * @param [in] value decimal number
 * @param [in] result pointer to rounded decimal
 * @return 0 - ОК, 1 - computes error
 */
int s21_round(s21_decimal value, s21_decimal *result);

/**
 * @brief Rounds decimal number to the closest integer toward negative infinity.
 * @param [in] value decimal number
 * @param [in] result pointer to rounded decimal
 * @return 0 - ОК, 1 - computes error
 */
int s21_floor(s21_decimal value, s21_decimal *result);

/**
 * @brief Function that multiplicate Decimal and (-1).
 * @param [in] value decimal number
 * @param [in] result pointer to decimal number
 * @return 0 - ОК, 1 - computes error
 */
int s21_negate(s21_decimal value, s21_decimal *result);

/**
 * @brief Returns the integral digits of the Decimal; any fractional
 * digits are discarded, including trailing zeroes.
 * @param [in] value decimal number
 * @param [in] result pointer to decimal number that contents only integer
 * @return 0 - ОК, 1 - ошибка вычисления
 */
int s21_truncate(s21_decimal value, s21_decimal *result);

#endif
