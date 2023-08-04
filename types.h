#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

#if !defined(_MSC_VER)

#include <inttypes.h>

#else

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed long int32_t;
typedef unsigned long uint32_t;
typedef signed long long int64_t;
typedef unsigned long long uint64_t;

#endif // !defined(_MSC_VER)

// Hash keys:
typedef uint64_t Key;

#endif // !defined(TYPES_H_INCLUDED)
