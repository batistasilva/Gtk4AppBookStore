#ifndef UTIL_H
#define UTIL_H
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <time.h>   // This is the header file for all time-related functions
#include <stdlib.h> // For exit() in case of memory allocation failure
#define DEFAULT_LOG_PATH "../../logs/" // for app folder
#define DATE_FORMAT "%Y-%m-%d %H:%M:%S"

bool is_effectively_empty(const char* s);
char* safe_strdup(const char* source);
char *safe_strcpy(char *dest, const char *src, size_t size);
void print_date_time();
void write_to_file();
bool mWriteToFile(const char * m_file, const char * message);
void getTimeFormat(char *buf_to_hold_date, size_t buf_len_to_hold_date, const char * format);
void getFileNameWithDate(char *buf_to_hold_file_name, size_t buffer_len, char * name_file);
void create_result_msg(char *buffer_to_msg,
                      size_t buffer_msg_len,
                      char *msg,
                      char * param1,
                      char * param2);

#endif // UTIL_H
