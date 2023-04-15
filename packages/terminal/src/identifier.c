#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32)
#include "windows/identifier.c"
#else if defined(__linux__)
#include "linux/identifier.c"
#endif

#ifdef __cplusplus
} // extern "C"
#endif