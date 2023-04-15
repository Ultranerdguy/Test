#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32)
#include "windows/io.c"
#else if defined(__linux__)
#include "linux/io.c"
#endif

#ifdef __cplusplus
} // extern "C"
#endif