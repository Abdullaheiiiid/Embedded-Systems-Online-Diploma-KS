#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

#include <stdbool.h>
#include <stdint.h>

//General
#define CPU_TYPE_8             8
#define CPU_TYPE_16            16
#define CPU_TYPE_32            32
#define CPU_TYPE_64            64
#define MSB_FIRST              0
#define LSB_FIRST              1
#define HIGH_BYTE_FIRST        0
#define LOW_BYTE_FIRST         1


//Symbols
#define CPU_TYPE               CPU_TYPE_32
#define CPU_BIT_ORDER          MSB_FIRST
#define CPU_BYTE_ORDER         HIGH_BYTE_FIRST

#ifndef _Bool
#define _Bool                  char unsigned
#endif

#ifndef FALSE 
#define FALSE                  (boolean)false
#endif

#ifndef TRUE 
#define TRUE                   (boolean)true
#endif

//Definitions
typedef _Bool                            boolean
typedef signed char                      sint8;
typedef unsigned char                    uint8;
typedef signed short int                 sint16;
typedef unsigned short int               uint16;
typedef signed int                       sint32;
typedef unsigned int                     uint32;
typedef signed long int                  sint64;
typedef unsigned long int                uint64;
typedef float                            float32;
typedef double                           float64;

typedef volatile signed char             vsint8;
typedef volatile unsigned char           vuint8;
typedef volatile signed short int        vsint16;
typedef volatile unsigned short int      vuint16;
typedef volatile signed int              vsint32;
typedef volatile unsigned int            vuint32;
typedef volatile signed long int         vsint64;
typedef volatile unsigned long int       vuint64;
typedef volatile float                   vfloat32;
typedef volatile double                  vfloat64;

#endif /* PLATFORM_TYPES_H */
