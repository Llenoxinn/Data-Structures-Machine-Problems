/* Force-included (gcc -include) before every program of the book.
   The listings themselves start at their first type or function. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __cplusplus
#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;
#endif

#ifdef COUNT_BLOCKS
/* Test builds only: count live heap blocks so that leaks are detected. */
long g_live_blocks = 0;
void *dbg_malloc(size_t n) { void *p = malloc(n); if (p) g_live_blocks++; return p; }
void dbg_free(void *p) { if (p) g_live_blocks--; free(p); }
#define malloc(n) dbg_malloc(n)
#define free(p) dbg_free(p)
#endif

int g_fail = 0;
int g_checks = 0;
#define CHECK(cond) do { g_checks++; if (!(cond)) { \
    printf("FAIL %s:%d: %s\n", __FILE__, __LINE__, #cond); g_fail++; } } while (0)
#define DONE() do { printf("%s: %d checks, %d failures\n", \
    g_fail ? "FAILED" : "ok", g_checks, g_fail); return g_fail != 0; } while (0)
