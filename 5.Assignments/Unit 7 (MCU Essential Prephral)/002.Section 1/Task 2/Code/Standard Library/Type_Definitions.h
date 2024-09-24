#ifndef TYPE_DEFINITIONS_H
#define TYPE_DEFINITIONS_H

#include <stdbool.h>
#include <stdint.h>
 
#ifndef BOOL
#define BOOL                             char unsigned
#endif

#define FALSE                            0
#define TRUE                             1

typedef BOOL                             boolean;
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

typedef char*                            String;

#endif
