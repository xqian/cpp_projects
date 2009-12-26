/*
 * xinqian.h
 *
 *  Created on: Dec 13, 2009
 *      Author: Qian Xin
 */

#ifndef XINQIAN_H_
#define XINQIAN_H_

#include "iostream"

extern int debug_level;
#define debug_print(statement) if (debug_level) std::cerr<<statement;

#endif /* XINQIAN_H_ */
