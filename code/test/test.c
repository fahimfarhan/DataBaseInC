#include <stdio.h>
#include <stdlib.h>

int main() {

  char* a = "abcde";
  char b[50] = "abcde";

  int sizeOfA = sizeof(a);  // 6, cz last e terminating character \0 soho se calculate kore
  int sizeOfB = sizeof(b);  // 50

  int strLenA = strlen(a);  // 5
  int strLenB = strlen(b);  // 5
  return 0;
}