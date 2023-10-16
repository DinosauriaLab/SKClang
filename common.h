#ifndef COMMON_H
#define COMMON_H

// Include any necessary libraries here

// Declare any constants or global variables here

// Declare any function prototypes here
#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif

#ifndef ABS
#define ABS(a) ((a) < 0 ? -(a) : (a))
#endif

#ifndef CLAMP
#define CLAMP(a, min, max) (MAX(MIN(a, max), min))
#endif

#define HEX2ASCII(x) ((x) < 10 ? (x) + '0' : (x)-10 + 'A')

#endif /* COMMON_H */
