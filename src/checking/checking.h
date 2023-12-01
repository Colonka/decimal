#ifndef SRC_CHECKING_CHECKING_H_
#define SRC_CHECKING_CHECKING_H_

#include "../s21_main_func.h"

/**
 * @brief Function that check number less than minimal possible number or not
 * @param val number
 * @return 1 - less, 0 - not less
 */
int is_too_small(float val);

/**
 * @brief Function that check number greater than max possible number or not
 * @param val number
 * @return 1 - greater, 0 - not greater
 */
int is_too_big(float val);

#endif
