#ifndef DEBUG_H
#define DEBUG_H

#ifdef DEBUG
#define DBGprint(...) printf(__VA_ARGS__); printf("\n")
#else
#define DBGprint(...)
#endif

#endif
