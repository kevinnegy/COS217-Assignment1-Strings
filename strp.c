#include "str.h"
#include <assert.h>


// Returns number of characters that precede terminating NULL character
size_t str_get_length(const char *s){
    assert(s != NULL);
    size_t length = 0;
    char* ptr = s;
    while (*ptr != '\0'){
        length++;
        ptr++;
    }
    return length;
}

// Copy src to destination including terminating \0 character 
// Returns dest
// TODO: assumes there is enough space?
char* str_copy(char* dst, const char* src){
    assert(dst != NULL && src != NULL);
    char* src_tmp = src;
    char* dst_tmp = dst;  

    // TODO: should this also look to see if dst is at the end of its string length?
    while(*src_tmp != '\0'){
        *dst_tmp = *src_tmp;
        dst_tmp++;
        src_tmp++;
    }
    return dst;
}

// Append a copy of null terminated s2 to the end of null terminated s1 
// s1 must have sufficient space to hold the result
char* str_concat(char* s1, const char* s2){
    assert(s1 != NULL && s2 != NULL);
    char* s1_ptr = s1;
    char* s2_ptr = s2;
    while (*s1_ptr != '\0')
        s1_ptr++;

    while (*s2_ptr != '\0'){
        *s1_ptr = *s2_ptr;
        s1_ptr++;
        s2_ptr++;
    }

    // Copy final null character
    *s1_ptr = *s2_ptr;
    
    return s1;
}

// Lexicographically compare two strings
// Negative means s1 comes first, zero equal, and positive is s2 comes first (TODO: verify) 
size_t str_compare(const char * s1, const char * s2){
    assert(s1 != NULL && s2 != NULL);
    char* s1_tmp = s1;
    char* s2_tmp = s2;

    while(*s1_tmp != '\0' && *s2_tmp != '\0'){
        if (*s1_tmp < *s2_tmp)
            return -1;
    
        if (*s1_tmp > *s2_tmp)
            return 1;
        
        s1_tmp++;
        s2_tmp++;
    }

    if (*s1_tmp == *s2_tmp)
        return 0;

    if (*s1_tmp == '\0')
        return -1;

    if (*s2_tmp == '\0')
        return 1;
}

static char * find_null(const char *word){
    assert(word != NULL);
    char * ptr = word;
    while (*ptr != '\0'){
        ptr++;
    }
    return ptr;
}

// Locates first occurrence of null-terminated string needle
// Returns haystack if needle is empty, NULL if not found, and otherwise pointer to first character in haystack that matches needle.
char* str_search(const char* haystack, const char *needle){
    assert(haystack != NULL && needle != NULL);
    size_t haystack_len = str_get_length(haystack);
    size_t needle_len = str_get_length(needle);

    if (needle_len == 0)
        return haystack;

    char* haystack_tmp = haystack;
    char* needle_tmp = needle;

    int i, j;
    // Search for letters that match first letter of needle
    for(i = 0; i < haystack_len; i++){
        
        // Found first letter that matched, check if substring matches
        if (*haystack_tmp == *needle_tmp){
            char * haystack_substring = haystack_tmp;
            int found = 1;

            for(j = i; j < i + needle_len; j++){

                if (*haystack_substring != *needle_tmp){
                    found = -1;
                    break;
                }
                haystack_substring++;
                needle_tmp++;
            }

            if (found == 1)
                return haystack_tmp;
        }

        // No substring match, Move haystack pointer forward in search
        haystack_tmp++;
        // Reset needle tmp
        needle_tmp = needle;
    }

    // Substring not found 
    return NULL;
}
