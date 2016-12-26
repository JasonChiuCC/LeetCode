/* -----------------------------------------
 字串分割
 ----------------------------------------- */
 strtok 第一次要先傳字串 s 進去，之後只要用 NULL 就可以
 注意 strtok 第一個參數要使用 char array，不能用 char pointer
 
// Type 1
char s[]    = "1.1.5.3";
char *delim = ".";
char *p;
printf("%s ", strtok(s,    delim));  // 1
printf("%s ", strtok(NULL, delim));  // 1
printf("%s ", strtok(NULL, delim));  // 5
printf("%s ", strtok(NULL, delim));  // 3

// Type 2
char s[]    = "1.1.5.3";
char *delim = ".";
char *p;
while( (p = strtok(NULL, delim)) && p!= NULL )
    printf("%s ", p);
    
    
/* -----------------------------------------
 字串複製
 ----------------------------------------- */    
char* inStr = "123456"
char *aStr  = malloc( strlen(inStr)*sizeof(char));
strcpy(aStr, inStr);
free(aStr);

/* ----------------------------------
 字串長度
 ---------------------------------- */
char *p     = "hello";
char q[]    = "hello"; // no need to count this
printf("%zu\n", sizeof(p)); // => size of pointer to char -- 4 on x86, 8 on x86-64
printf("%zu\n", sizeof(q)); // => size of char array in memory -- 6 on both
printf("%zu\n", strlen(p)); // => 5
printf("%zu\n", strlen(q)); // => 5

/* ----------------------------------
 取字元
 ---------------------------------- */
char* testStr = "Hello";
printf("%c\n",testStr[2]);

/* ----------------------------------
 字串複製
 ---------------------------------- */
strncpy(dest, src + beginIndex, endIndex - beginIndex);
Validated that dest is large enough.
endIndex is greater than beginIndex
beginIndex is less than strlen(src)
endIndex is less than strlen(src)

/*
 0 1 2 3 4  5
 H e l l o \n
   1 2 3
*/
char*   t1      = "Hello";
char    t2[255] = {0};
strncpy(t2, t1 + 1, 3); //From 1 and Num = 3
// t2 = ell



/* ----------------------------------
 String Pointer and Array
 ---------------------------------- */
Use command below to dump object file.
gcc -c main.c -o main.o
objdump -Sr main.o

// Point store .rodata section, not in .text
char *s  = "abc";
6:   c7 45 fc 00 00 00 00    movl   $0x0,-0x4(%ebp)
     9: R_386_32     .rodata

// Array store stack
char s[] = "abc";
15:   c7 44 24 08 61 62 63    movl   $0x636261,0x8(%esp)
1c:   00
