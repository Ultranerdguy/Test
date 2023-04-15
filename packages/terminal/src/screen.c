#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32)
#include "windows/screen.c"
#else if defined(__linux__)
#include "linux/screen.c"
#endif

#ifdef __cplusplus
} // extern "C"
#endif