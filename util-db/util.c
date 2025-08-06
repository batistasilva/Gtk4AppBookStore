// This is the header file that declares malloc()
#include <util.h>

/**
 * Function to check if a const char* is effectively empty
 * (null or points to an empty string)
 * @brief is_effectively_empty
 * @param s
 * @return true or false
 */
bool is_effectively_empty(const char *s) { return (s == NULL || s[0] == '\0'); }

/**
 * @brief safe_strcpy
 * @param dest
 * @param size
 * @param src
 * @return  src copy
 */
char *safe_strcpy(char *dest, const char *src, size_t size) {
  size_t len_dest = sizeof(dest);
  size_t len_src = strlen(src);

  if (size > 0) {
    size_t i;
    for (i = 0; i < size - 1 && src[i]; i++) {
      dest[i] = src[i];
    }
    dest[i] = '\0';
  }
  return dest;
}

// A helper function to safely allocate and copy a string.
// This function ensures the destination string is always null-terminated.
char *safe_strdup(const char *source) {
  if (source == NULL) {
    return NULL;
  }

  size_t len = strlen(source) + 1;

  // printf("\n\n Size: %d:\n ", len);

  char *destination = (char *)malloc(sizeof(char) * len);

  if (destination != NULL) {
    // Use strncpy to copy the string, specifying the maximum number of
    // characters.

    // strncpy(destination, source, len);
    safe_strcpy(destination, source, len);

    //       printf("\n\nValue dest: %d - Source: %d \n\n", strlen(destination),
    //       strlen(source));

    // This is the CRITICAL step to ensure safety and fix the warning:
    // Manually place a null terminator at the end of the string.
    destination[len] = '\0';
  }

  return destination;
}

void print_date_time() {
  time_t current_time;
  struct tm *local_time_info;
  char time_string[100]; // Buffer to hold the formatted time string

  // Step 1: Get the current time as a numerical value (seconds since epoch).
  current_time = time(NULL);

  if (current_time == -1) {
    perror("Failed to get current time");
    exit(EXIT_FAILURE);
  }

  // Step 2: Convert the numerical time value to a local time structure.
  // The struct tm contains broken-down time components (day, month, year,
  // etc.).
  local_time_info = localtime(&current_time);

  if (local_time_info == NULL) {
    perror("Failed to convert time to local time");
    exit(EXIT_FAILURE);
  }

  // Step 3: Format the time structure into a human-readable string.
  // The strftime() function is safe and highly flexible.
  // The first argument is the destination buffer.
  // The second is the size of the buffer.
  // The third is the format string (see comments below for examples).
  // The fourth is the time structure to format.

  // Format specifiers examples:
  // %Y: Year with century (e.g., 2024)
  // %m: Month as a decimal number (01-12)
  // %d: Day of the month (01-31)
  // %H: Hour in 24-hour format (00-23)
  // %M: Minute (00-59)
  // %S: Second (00-60)
  // %A: Full weekday name (e.g., Sunday)
  // %B: Full month name (e.g., August)

  // Example format: "Friday, August 02, 2024 - 15:30:45"
  size_t format_result = strftime(time_string, sizeof(time_string),
                                  "%A, %B %d, %Y - %H:%M:%S", local_time_info);

  if (format_result == 0) {
    fprintf(stderr, "strftime failed to format the time string.\n");
    exit(EXIT_FAILURE);
  }

  // Print the formatted string.
  printf("The current date and time is: %s\n", time_string);
}

/**
 * @brief write_to_file
 */
void write_to_file() {
  FILE *file_ptr;
  const char *filename = "file.txt";

  // 1. Open the file in "write" mode ("w").
  // If the file exists, its contents will be overwritten.
  // If it doesn't exist, a new file will be created.
  file_ptr = fopen(filename, "w");

  // 2. Check for an error.
  if (file_ptr == NULL) {
    // If fopen() returns NULL, it failed to open the file.
    // perror() prints a descriptive error message based on errno.
    perror("Error opening file");
    // Exit the program with a failure status.
    //        return 1;
  }

  // 3. Write to the file.
  // fprintf() is like printf(), but the first argument is the file handle.
  fprintf(file_ptr, "This is the first line of the file.\n");
  fprintf(file_ptr, "Hello, file writing in C!\n");
  fprintf(file_ptr, "The number is: %d\n", 42);

  // 4. Close the file.
  // This is essential to ensure the data is saved and resources are freed.
  fclose(file_ptr);

  printf("Successfully wrote to the file: %s\n", filename);
}

/**
 * @brief getTimeFormat
 * @param buf_to_hold_date
 * @param buf_len_to_hold_date
 * @param format "%Y-%m-%d %H:%M:%S"
 */
void getTimeFormat(char *buf_to_hold_date, size_t buf_len_to_hold_date,
                   const char *format) {
  time_t now;
  struct tm *ts;
  char buf[80]; // Use of 80 to ensure long date formats

  // Get the current time
  time(&now);

  // Format and print the time, "ddd yyyy-mm-dd hh:mm:ss zzz"
  ts = localtime(&now); //"%Y-%m-%d %H:%M:%S"
  strftime(buf, sizeof(buf), format, ts);

  size_t len_buf = sizeof(buf);

  int written;
  if (buf_len_to_hold_date >= len_buf) {
    written = snprintf(buf_to_hold_date, buf_len_to_hold_date, buf);
  } else { // Not enough space or error
    written = snprintf(buf_to_hold_date, buf_len_to_hold_date, buf);
    fprintf(stderr, "Warning: output truncated or failed\n");
  }
}

/**
 * @brief mWriteToFile
 * @param m_file
 * @param message
 * @return true of false
 */
bool mWriteToFile(const char *m_file, const char *message) {
  bool result = true;
  FILE *file_ptr;
  char file_name[100];
  getFileNameWithDate(file_name, sizeof(file_name), m_file);

  // const char * msg =   ;

  // 1. Open the file in "write" mode ("w").
  // If the file exists, its contents will be overwritten.
  // If it doesn't exist, a new file will be created.
  file_ptr = fopen(file_name, "w");

  // 2. Check for an error.
  if (file_ptr == NULL) {
    // If fopen() returns NULL, it failed to open the file.
    // perror() prints a descriptive error message based on errno.
    perror("Error opening file");
    // Exit the program with a failure status.
    //        return 1;
  }
  // cout << colors[second_color] << "[" << __FILE__ << ":" << __LINE__ << "] "
  // << colors[first_color] << endl;

  // 3. Write to the file.
  fprintf(file_ptr, "\n**************************************************\n");
  fprintf(file_ptr, "%s\n", __FILE__);
  fprintf(file_ptr, "%d\n", __LINE__);
  fprintf(file_ptr, "%s.\n", message);
  fprintf(file_ptr, "****************************************************\n");

  // 4. Close the file.
  fclose(file_ptr);

  printf("Successfully wrote to the file: %s\n", file_name);
  return result;
}

/**
 * @brief getFileNameWithDate
 * @param buf_to_hold_file_name
 * @param buffer_len
 * @param name_file
 */
void getFileNameWithDate(char *buf_to_hold_file_name, size_t buffer_len,
                         char *name_file) {
  //
  const char *date_time_format = "%Y-%m-%d.%H:%M:%S";
  //
  char date_time[80];
  // Get date to add in file name
  getTimeFormat(date_time, sizeof(date_time), date_time_format);
  // Extension to file
  char *file_ext = ".log";
  // Path to file in sistem
  char *path_file = DEFAULT_LOG_PATH;
  //
  int result = snprintf(buf_to_hold_file_name, buffer_len, "%s%s-%s%s",
                        path_file, name_file, date_time, file_ext);
  //
  if (result >= sizeof(date_time))
    printf("Warning: String was truncated. Output is: \"%s\"\n",
           buf_to_hold_file_name);
}

/***
 * @brief creat_result_msg
 * @param buffer_to_msg
 * @param buffer_msg_len
 * @param msg
 * @param param1
 * @param param2
 **/
void create_result_msg(char *buffer_to_msg, size_t buffer_msg_len, char *msg,
                      char *param1, char *param2) {
  int msg_len = strlen(msg);
  int param1_len = strlen(param1);
  int param2_len = strlen(param2);
  int written;

  if (buffer_msg_len > 0 &&
             msg != NULL &&
          param1 != NULL &&
          param2 != NULL)
  {
    // printf("\nSize of buffer: %d\n  "
    //                     "Msg: %d\n "
    //                  "Param1: %d\n "
    //                  "Param2: %d\n",
    //        (int)buffer_msg_len,
    //                    msg_len,
    //                 param1_len,
    //                param2_len); // 25
    int total_len_msg = msg_len + param1_len + param2_len + 1;
    //
    if (buffer_msg_len > total_len_msg) {
      written = snprintf(buffer_to_msg, buffer_msg_len, "\n\t Message: %s\n\t Book_ID: %s\n\t Author: %s\n", msg, param1, param2);
    } else { // Not enough space or error
      written = snprintf(buffer_to_msg, buffer_msg_len, "\n\t Message: %s\n\t Book_ID: %s\n\t Author: %s\n", msg, param1, param2);
      fprintf(stderr, "Warning: output truncated or failed\n");
    }
    // printf("\nSize of writter: %d - buffer to receipt %d \n", written,  (int)buffer_msg_len); // 25
  }
}
