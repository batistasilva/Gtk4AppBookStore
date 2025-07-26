#include <stdio.h>
#include <util.h>

/**
 * Function to check if a const char* is effectively empty
 * (null or points to an empty string)
 * @brief is_effectively_empty
 * @param s
 * @return true or false
 */
bool is_effectively_empty(const char* s) {
    return (s == NULL || s[0] == '\0');
}
