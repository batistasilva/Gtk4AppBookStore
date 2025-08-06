#ifndef ERROR_LOG_H
#define ERROR_LOG_H
#include "util-dbg/show-msg.h"

#define ERROR_LOG(fmt, ...) \
fprintf(stderr, "ERROR: %s:%d: " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define DBG(x, ...) fprintf( stdout, "%s: " x "\n", "DBG", ##__VA_ARGS__)

#endif // ERROR_LOG_H
