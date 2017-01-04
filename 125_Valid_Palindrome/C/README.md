```C
/* -----------------------------------------
  方法一 : 21.74% Runtime: 3 ms
  
  建立兩個指標指向字串"頭"和"尾"
  先檢查字串是否為字母或數字，如果不是往前/往後移動
  逐一比較字元是否相同
 ----------------------------------------- */
#define JC_C_isAlphabetOrDigit(ch) (JC_C_Lowercased(ch) < '0' || (JC_C_Lowercased(ch) > '9' && JC_C_Lowercased(ch) < 'a') || JC_C_Lowercased(ch) > 'z')
char JC_C_Lowercased(char ch) {
    if (ch >= 'A' && ch <= 'Z')
        ch += 0x20;
    return ch;
}

bool isPalindrome(char *s) {
    int len     = strlen(s);
    int head    = 0;
    int tail    = len - 1;

    while (head <= tail)
    {
        while( JC_C_isAlphabetOrDigit(s[head]) )
        {
            head++;
            if (head > tail) break;
        }

        while( JC_C_isAlphabetOrDigit(s[tail]) )
        {
            tail--;
            if (head > tail) break;
        }

        if (head > tail) break;

        if (JC_C_Lowercased(s[head]) != JC_C_Lowercased(s[tail])) {
                return false;
        }
        head++;
        tail--;
    }
    return true;
}

int main(void)
{
    char s1[] = "A man, a plan, a canal: Panama";
    char s2[] = "race a car";
    char s3[] = "";
    char s4[] = "a";
    char s5[] = ".,";
    char s6[] = ".";
    char s7[] = " ";

    printf("%d\n", isPalindrome(s1));
    printf("%d\n", isPalindrome(s2));
    printf("%d\n", isPalindrome(s3));
    printf("%d\n", isPalindrome(s4));
    printf("%d\n", isPalindrome(s5));
    printf("%d\n", isPalindrome(s6));
    printf("%d\n", isPalindrome(s7));
    return 0;
}
```