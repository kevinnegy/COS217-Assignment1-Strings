#include "str.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void test_get_length(){
    const char * word = "hello";
    assert(str_get_length(word) == 5);

    const char* empty_word = "";
    assert(str_get_length(empty_word) == 0);

    const char * word2 = "he\nllo";
    assert(str_get_length(word2) == 6);
}

void test_str_copy(){
    const char * word = "hello";
    char * dest = (char*) malloc (sizeof(char) * 6);
    str_copy(dest, word);
    assert(str_get_length(dest) == 5);
    free(dest);

    const char* word2 = "tester";
    dest = (char*) malloc (sizeof(char) * 25);
    str_copy(dest, word2);
    assert(str_get_length(dest) == 6);
    free(dest);
}

void test_str_compare(){
    const char * w1 = "hello";
    const char * w2 = "none";
    int ret = str_compare(w1, w2);
    assert(ret == -1);
    
    ret = str_compare(w1, w1);
    assert(ret == 0);

    ret = str_compare(w2, w1);
    assert(ret == 1);

    const char * w3 = "hell";
    ret = str_compare(w3, w1);
    assert(ret == -1);

    ret = str_compare(w1, w3);
    assert(ret == 1);
}

void test_str_concat(){
    const char * word = "hello";
    char * dest = (char*) malloc (sizeof(char) * 15);
    str_copy(dest, word);

    str_concat(dest, word);
    assert(str_get_length(dest) == 10);
    assert(str_compare(dest, "hellohello") == 0);
    free(dest);
}

void test_str_search(){
    const char * word = "hello";
    char * location = str_search(word, "hell");
    assert(word == location);

    location = str_search(word, "ll");
    assert((word+2) == location);

    location = str_search(word, "la");
    assert(location == NULL);

    location = str_search(word, "");
    assert(location == word);
}

int main(){
    test_get_length();
    test_str_copy();
    test_str_compare();
    test_str_concat();
    test_str_search();
    printf("Passed all tests\n");
    
}
