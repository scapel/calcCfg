/*
 * common.h
 *
 *  Created on: 13 déc. 2016
 *      Author: scapel
 */

#ifndef COMMON_COMMON_H_
#define COMMON_COMMON_H_


typedef enum {
   DIR_IN = 0,
   DIR_OUT = 1,
   DIR_IN_OUT = 2
}t_direction;

typedef enum {
   UNKNOWN = 0,
   TYPE_INT = 1,
   TYPE_FLOAT = 2,
   TYPE_BOOL = 3
}t_type;


#endif /* COMMON_COMMON_H_ */
