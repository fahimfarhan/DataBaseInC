# Review some C codes

For debugging C/C++ codes, we can use

1. [gdb](https://sourceware.org/gdb/)

2. [valgring](https://valgrind.org/)

Gdb is used to debug code, and valgrind is used to detect memory leaks.

For gdb, the vs code debug extension is good enough. First time there will be a popup, and you should select `something with g++` to debug both c and c++. If you only use c, you may use `gcc`

Valgrind example: [stackOverflow](https://stackoverflow.com/a/29354227/9053942)

```bash
gcc -g example1.c -o example1
valgrind --tool=memcheck --leak-check=yes ./example1
```

I wrote this:

```c++

int main() {
 // ...
  int *p;
  p = new int[10];  // line number 16
 // ...
}

```

Then I invoked:

```bash
g++ -g democlass1.cpp
valgrind --tool=memcheck --leak-check=yes ./a.out
```

And on the terminal, the output was:

```bash

(base) soumic@Zephyrus-G14:~/Codes/poridhi_io/database_in_c/class_1/cpp_version$ valgrind --tool=memcheck --leak-check=yes ./a.out 
==19547== Memcheck, a memory error detector
==19547== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==19547== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==19547== Command: ./a.out
==19547== 
16
==19547== 
==19547== HEAP SUMMARY:
==19547==     in use at exit: 40 bytes in 1 blocks
==19547==   total heap usage: 3 allocs, 2 frees, 73,768 bytes allocated
==19547== 
==19547== 40 bytes in 1 blocks are definitely lost in loss record 1 of 1
==19547==    at 0x483C583: operator new[](unsigned long) (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==19547==    by 0x1091FE: main (democlass1.cpp:16)   //<------------ This tell me to look at line number 16
==19547== 
==19547== LEAK SUMMARY:
==19547==    definitely lost: 40 bytes in 1 blocks
==19547==    indirectly lost: 0 bytes in 0 blocks
==19547==      possibly lost: 0 bytes in 0 blocks
==19547==    still reachable: 0 bytes in 0 blocks
==19547==         suppressed: 0 bytes in 0 blocks
==19547== 
==19547== For lists of detected and suppressed errors, rerun with: -s
==19547== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

## Further read

Maybe google how to use both valgrind, and gdb together.

## Pointers

```c

void pointerDemo() {
  int *pA;
  char *pB;

  int a[5];
  a[0] = 10; a[1] = 11; a[2] = 12;

  pA = &a[0];
  pB = a;  // warning in c, error in c++. hmm...

  printf("value of pA = %d\n", *pA);  // 10
  printf("value of pB = %d\n", *pB);  // 10
  
  pA++;
  pB++;
  
  printf("value of pA = %d\n", *pA);  // 11
  printf("value of pB = %d\n", *pB);  // 0   
}

```

pB is zero, why?
Let, int is 16 bit, and char is 8 bit.

```tex
0000 0000 0000 0110 // a[0]  <-- pA, pB
0000 0000 0000 0111 // a[1]
```

Initially, both pA, pB points to a[0].
When I do pA++, the pointer actually shifts 16 bits (since we assumed the size of int is 16). In the new address, pA got the next value.

When I do a pB++, pB shifts only 8 bits.

```tex
0000 0000 0000 0110 // a[0]
       pB
```

That's why we got 0.

## malloc()

malloc == memory alloc.
malloc() returns a void pointer. Why void pointer? cz it doesnot know if we want int, or char, etc.

## pass by value vs pass by reference

```c
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

```

## A question: why e use malloc?

```c

int* makeInt() {
  int a = 10;   // &a = xxxx xxxx, this address holds a.
  int* n = NULL;
  n = &a;
  printf("percent_x = %x\n", n);
  return n;
}

int main() {

  int* p = makeInt();  // xxxx xxxx held 10
                       // now makeInt() exited it's scope. so the address xxxx xxxx is no longer valid. if the program reuses this location, I won't get 10. ejonno malloc korte hoy!
  printf("percent_x = %x\n", p);
  int q = *p;

  printf("p has = %d\n", *p);
  printf("q = %d\n", q);
  return 0;
}
```

now makeInt() exited it's scope. so the address xxxx xxxx is no longer valid. if the program reuses this location, I won't get 10. ejonno malloc korte hoy!

## Build 2D array using malloc

```c
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
```

# structure and enum

