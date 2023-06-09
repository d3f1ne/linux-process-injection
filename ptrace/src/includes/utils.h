#ifndef __UTILS_DEF1NE__
#define __UTILS_DEF1NE__

#include <stdint.h>
#include <limits.h>
#include <errno.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#define log_plain(fmt, ...) fprintf(stderr, fmt "", ##__VA_ARGS__)
#define error(fmt, ...) log_plain("\x1b[0;31m[fail] " fmt "\x1b[0m", ##__VA_ARGS__)
#define warn(fmt, ...) log_plain("\x1b[0;33m[warn] " fmt "\x1b[0m", ##__VA_ARGS__)
#define info(fmt, ...) log_plain("\x1b[0;36m[info] " fmt "\x1b[0m", ##__VA_ARGS__)

#define CHECK_MEMORY_ALLOC(ptr) \
    if (!ptr) { \
        error("Failed to allocate memory\n"); \
        exit(EXIT_FAILURE); \
    }

size_t _strlen(const char *str);
int _atoi(const char *s);

void freestr_( char **p );
void printShellcode(const unsigned char* shellcode, size_t size);
char *asprintfEx( const char *fmt, ... );
char *vasprintfEx( const char *fmt, va_list args );
void _memcpy(void *destaddr, const void *srcaddr, int len);

/* auxiliar functions */
int u_isspace(char c);
int u_isdigit(char c);
int u_isupper(char c);
int u_isalpha(char c);

#endif
