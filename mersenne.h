#ifndef MERSENNE_H_INCLUDED
#define MERSENNE_H_INCLUDED

////
//// Includes
////

#include "types.h"


////
//// Prototypes
////

extern uint32_t genrand_int32(void);
extern uint64_t genrand_int64(void);
extern void init_mersenne(void);


#endif // !defined(MERSENNE_H_INCLUDED)
