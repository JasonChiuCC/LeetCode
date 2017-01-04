```C
/* -----------------------------------------
  方法一 : 04.58% Runtime: 179 ms
 ----------------------------------------- */
char *convert(char *s, int numRows) {
    if( numRows == 1){
        return s;
    }
    int     sLen        = strlen(s);
    char*   result      = malloc( sizeof(char*) * (sLen+1) );
    int     repect      = 0;
    int     idx         = 0;
    int     resultIdx   = 0;
    int     L           = numRows - 1;
    while( repect < numRows )
    {
        idx = 0;
        while( idx < sLen )
        {
            int Row = ( L - abs( L - idx % (2*L)) );
            if( Row == repect ){
                printf("%d, %c\n", Row, s[idx] );
                result[ resultIdx++ ] = s[idx];
            }
            idx += 1;
        }
        repect += 1;
    }
    result[ resultIdx ] = '\0';
    printf("%s \n", result );
    return result;
}
int main(void)
{
    printf("%s\n",convert("PAYPALISHIRING",3));
    return 0;
}

/* -----------------------------------------
  方法二 : 53.52% Runtime: 009 ms
  用公式計算字元擺哪個位置
 ----------------------------------------- */
char *convert(char *s, int numRows) {
    if( numRows == 1){
        return s;
    }

    int     sLen    = strlen(s);
    int     step    = 2 * numRows - 2;
    char*   pA      = malloc( sizeof(char*) * (sLen+1) );
    int     i       = 0;
    int     j       = 0;
    int     idx     = 0;
    for (i = 0; i < numRows; ++i)
    {
        for ( j = i; j < sLen; j += step)
        {
            pA[idx++] = s[j];
            if (0 < i && i < numRows - 1 && j + step - 2 * i < sLen)
            {
                pA[idx++] = s[j + step - 2 * i];
            }
        }
    }
    pA[idx] = '\0';
    return pA;
}
```