// Write a function that:
//  - accepts a string as a parameter
//  - returns:
//     - the first whitespace-separated word in the string, as
//       a newly allocated string
//     - and, the size of that word

#include <stdio.h>     // needed for the declaration of NULL, printf
#include <stdlib.h>    // needed for malloc, free, EXIT_SUCCESS
#include <assert.h>    // needed for the declaration of assert()
#include <string.h>    // for strlen

// We could use isspace() from the C standard library,
// but we haven't seen that yet, so we'll write our
// own is_space.
int is_space(char c) {
  if ((c == ' ') ||   // space
      (c == '\f') ||  // form feed
      (c == '\n') ||  // newline
      (c == '\r') ||  // carriage return
      (c == '\t') ||  // horizontal tab
      (c == '\v')) {  // vertical tab
    return 1;
  }
  return 0;
}

// FirstWord scans through "string" looking for the
// first whitespace separated word in the string.
//
// If it finds one, it:
//    - malloc's space for that word
//    - copies the word into the malloc'ed space, including a NULL-term
//    - returns a pointer to the word through the "retword" return parameter
//    - returns the length of the returned word (>=0)
//
// If "string" is empty or NULL, returns -1 and doesn't malloc anything.
//
// If malloc fails, returns -2 to indicate out of memory.

int FirstWord(char *string, char **retword) {
    int len, i, retlen;

    // test the degenerate case
    if ((string == NULL) || (string[0] == '\0')) {
        return -1;
    }

    len = strlen(string);
    retlen = len;  // by default, copy the whole string
    // look for whitespace
    for (i = 0; i < len; i++) {
        if (is_space(string[i])) {
            retlen = i;
            break;
        }
    }

    // retlen tells us how many characters to copy from
    // string; we need that plus one extra byte for the
    // null terminator
    *retword = (char *) malloc(sizeof(char) * (retlen + 1));
    
    if (*retword == NULL) {
        return -2;
    }
    
    for (i = 0; i < retlen; i++) {
        (*retword)[i] = string[i];
    }
    (*retword)[retlen] = '\0';
    return retlen;
}

// Here's some code to test our function.
int main(int argc, char **argv) {
    char *string1 = "Hello world!";
    char *string2 = "Hello!";
    char *string3 = "";
    char *string4 = NULL;
    char *retstr;
    int retval;

    retval = FirstWord(string1, &retstr);
    assert(retval == 5);
    printf("Should be 'Hello':  '%s'\n", retstr);
    free(retstr);

    retval = FirstWord(string2, &retstr);
    assert(retval == 6);
    printf("Should be 'Hello!':  '%s'\n", retstr);
    free(retstr);

    retval = FirstWord(string3, &retstr);
    assert(retval == -1);

    retval = FirstWord(string4, &retstr);
    assert(retval == -1);

    return EXIT_SUCCESS;
}