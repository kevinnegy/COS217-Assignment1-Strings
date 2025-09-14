#ifndef STR_INCLUDED
#define STR_INCLUDED
#include <stddef.h>
/* Returns number of characters that precede terminating NULL character */
size_t str_get_length(const char *s);

/* Copy src to destination including terminating \0 character  */
/* Returns dest */
char* str_copy(char* dst, const char* src);

/* Append a copy of null terminated s2 to the end of null terminated s1  */
/* s1 must have sufficient space to hold the result */
char* str_concat(char* s1, const char* s2);

/* Lexicographically compare two strings */
/* Negative means s1 comes first, zero equal, and positive is s2 comes first (TODO: verify)  */
size_t str_compare(const char * s1, const char * s2);

/* Locates first occurrence of null-terminated string needle */
/* Returns haystack if needle is empty, NULL if not found, and otherwise pointer to first character in haystack that matches needle. */
char* str_search(const char* haystack, const char *needle);
#endif
