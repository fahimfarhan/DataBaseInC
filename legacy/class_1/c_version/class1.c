#include <stdio.h>
#include <stdlib.h>
// #include <bits/stdc++.h>
// using namespace std;

// gdb
// valgrind

void foo() {
  int a = 0;
  LEVEL1:

    a++;
    printf("%d\n", a);
    if(a < 10) {
      goto LEVEL1;
    }
}

void pointerDemo() {
  int *pA = NULL;  // nummptr error dey. maybe c++ specific...
  char *pB = NULL;
  void *pC = NULL;
  int a[5];
  a[0] = 10; a[1] = 11; a[2] = 12;

  pA = &a[0];
  pB = a;  // warning in c, error in c++. hmm...
  pC = a;

  printf("value of pA = %d\n", *pA);  // 10
  printf("value of pB = %d\n", *pB);  // 10
  // printf("value of pC = %d\n", *pC);  // invalid use of void expression
  
  pA++;
  pB++;
  // pC++;
  
  printf("value of pA = %d\n", *pA);  // 11
  printf("value of pB = %d\n", *pB);  // 0   
  // printf("value of pC = %d\n", *pC);  // invalid use of void expression

}

void mallocDemo() {
  int *p = NULL;
  p = (int*)malloc(sizeof(int));
  *p = 47;
  printf("p = %d\n", *p);
}

void passByValue(int n) {
  n+=10;
  printf("passByValue er vitore n = %d\n", n);
}

// void passByRef() {
//   n+=10;
//   printf("passByRef er vitore n = %d\n");
// }

void passByPointer(int *n) {
  (*n) += 10;
  printf("passByPointer er vitore n = %d\n", *n);
}

void passByValueDemo() {
  int a = 10;
  passByValue(a);   // 20
  printf("passByValue er baire n = %d\n", a);  // 10
  passByPointer(&a);      // 10
  printf("passByPointer er baire n = %d\n", a);  // 10
}


int* makeInt() {
  int a = 10;   // &a = xxxx xxxx, this address holds a.
  int* n = NULL;
  n = &a;
  printf("percent_x = %x\n", n);
  return n;
}

int* makeIntCorrectWay() {

  int a = 11;   // &a = xxxx xxxx, this address holds a.
  int* n = malloc(sizeof(int));
  n = &a;
  printf("percent_x = %x\n", n);
  return n;
}

void mallocDemo2() {
  int* p = makeIntCorrectWay();  // xxxx xxxx held 10
                       // now makeInt() exited it's scope. so the address xxxx xxxx is no longer valid. if the program reuses this location, I won't get 10. ejonno malloc korte hoy!
  printf("percent_x = %x\n", p);
  int q = *p;

  printf("p has = %d\n", *p);
  printf("q = %d\n", q);

}

void buildA2DArrayUsingMalloc() {
  int *a[10];

  int i=0, j = 0;
  for(i=0; i<10; i++) {
    a[i] = (int *)malloc(sizeof(int) * 10);
  }

  int k = 0;
  for(i = 0; i<10; i++) {
    for(j = 0; j<10; j++) {
      a[i][j] = k;
      k++;
    }
  }


  for(i = 0; i<10; i++) {
    for(j = 0; j<10; j++) {
      // a[i][j] = k;
      // k++;
      printf("%d\n", a[i][j]);
  
    }
  }

  int **p = NULL;
}


typedef struct node
{
  /* data */
  int a;
  struct node *pNode; 
}node;


enum {
  SUCCESS = 15, FAIL = 16
};

void enumAndStructDemo() {
  printf("success = %d\n", SUCCESS);
}

int main() {

  int a, b, sum = 0;
  a = 10;
  b = 6;

  sum = a + b;


  printf("%d\r\n", sum);
 // foo();

  // pointerDemo();
  // mallocDemo();
  // passByValueDemo();
  // mallocDemo2();
  // buildA2DArrayUsingMalloc();
  enumAndStructDemo();
  return 0;
}