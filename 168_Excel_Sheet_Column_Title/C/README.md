```C
/* -----------------------------------------
  方法一 : 0.00% Runtime: 0 ms
  轉為 26 進至
 ----------------------------------------- */
#define JC_M_MALLOC( type, size)        (type *) malloc ( sizeof(type)*size )
#define DIGIT   26
void JC_A_Reverse(char* nums, int begin, int end) {
    if (begin >= end) return;
    while (begin < end) {
        nums[begin] ^= nums[end] ^= nums[begin] ^= nums[end];
        begin++;
        end--;
    }
}

char* convertToTitle(int n) {
    char    strA[1000]  = {0};
    int     i           = 0;
    while (n>0) {
        n--;
        char ch = (char) (n % DIGIT + 'A');
        strA[i++] = ch;
        n /= DIGIT;
    }
    JC_A_Reverse(strA,0,strlen(strA)-1);
    char* strB = JC_M_MALLOC(char*,1000);
    strncpy(strB, strA + 0, 1000-1);
    return strB;
}
```