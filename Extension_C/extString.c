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
char* strA = "123456"
char* strB  = malloc( strlen(strA)*sizeof(char));
strcpy(strB, strA);
free(strB);

/* ----------------------------------
 字串長度
 ---------------------------------- */
char *strA     = "hello";
char strB[]    = "hello"; // no need to count this
printf("%zu\n", sizeof(strA)); // => size of pointer to char -- 4 on x86, 8 on x86-64
printf("%zu\n", sizeof(strB)); // => size of char array in memory -- 6 on both
printf("%zu\n", strlen(strA)); // => 5
printf("%zu\n", strlen(strB)); // => 5

/* ----------------------------------
 取字元
 ---------------------------------- */
char* strA = "Hello";
printf("%c\n",strA[2]);

/* ----------------------------------
 字串複製
 ---------------------------------- */
strncpy(dest, src + beginIndex, endIndex - beginIndex);
/*
 0  1  2  3  4  5
 H  e  l  l  o  \n
    1  2  3
*/
char*   strA      = "Hello";
char    strB[255] = {0};
strncpy(strB, strA + 1, 3); //From 1 and Num = 3
// strB = ell


