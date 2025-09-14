#include "str.h"
#include <assert.h>


// Returns number of characters that precede terminating NULL character
size_t str_get_length(const char s[]){
    assert(s != NULL);
    size_t length = 0;
    int index = 0;
    while (s[index] != '\0'){
        length++;
        index++;
    }
    return length;
}

// Copy src to destination including terminating \0 character 
// Returns dest
// TODO: assumes there is enough space?
char* str_copy(char dst[], const char src[]){
    assert(dst != NULL && src != NULL);

    // TODO: should this also look to see if dst is at the end of its string length?
    int i = 0;
    while(src[i] != '\0'){
        dst[i] = src[i];
        i++;
    }
    return dst;
}

// Append a copy of null terminated s2 to the end of null terminated s1 
// s1 must have sufficient space to hold the result
char* str_concat(char s1[], const char s2[]){
    assert(s1 != NULL && s2 != NULL);
    int s1_index = 0;
    int s2_index = 0;

    while (s1[s1_index] != '\0')
        s1_index++;

    while (s2[s2_index] != '\0'){
        s1[s1_index] = s2[s2_index];
        s1_index++;
        s2_index++;
    }

    // Copy final null character
    s1[s1_index] = s2[s2_index];
    
    return s1;
}

// Lexicographically compare two strings
// Negative means s1 comes first, zero equal, and positive is s2 comes first (TODO: verify) 
size_t str_compare(const char s1[], const char s2[]){
    assert(s1 != NULL && s2 != NULL);
    char* s1_tmp = s1;
    char* s2_tmp = s2;
    int index = 0;

    while(s1_tmp[index] != '\0' && s2_tmp[index] != '\0'){
        if (s1_tmp[index] < s2_tmp[index])
            return -1;
    
        if (s1_tmp[index] > s2_tmp[index])
            return 1;
        
        index++;
    }

    if (s1_tmp[index] == s2_tmp[index])
        return 0;

    if (s1_tmp[index] == '\0')
        return -1;

    if (s2_tmp[index] == '\0')
        return 1;
}

// Locates first occurrence of null-terminated string needle
// Returns haystack if needle is empty, NULL if not found, and otherwise pointer to first character in haystack that matches needle.
char* str_search(const char haystack[], const char needle[]){
    assert(haystack != NULL && needle != NULL);
    size_t haystack_len = str_get_length(haystack);
    size_t needle_len = str_get_length(needle);

    if (needle_len == 0)
        return haystack;

    int i, j;
    // Search for letters that match first letter of needle
    for(i = 0; i < haystack_len; i++){
        int needle_index = 0; 
        // Found first letter that matched, check if substring matches
        if (haystack[i] == needle[needle_index]){
            int found = 1;
            for(j = i; j < i + needle_len; j++){

                if (haystack[j] != needle[needle_index]){
                    found = -1;
                    break;
                }
                needle_index++;
            }

            if (found == 1)
                return &haystack[i];
        }
    }

    // Substring not found 
    return NULL;
}
