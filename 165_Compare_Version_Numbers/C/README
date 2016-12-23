```C
/* -----------------------------------------
  方法一 : 3.85% Runtime: 0 ms
  先將兩字串以 "." 分割為陣列，在遞迴陣列互相比較數字
 
  考慮:
  1. 前面有 0   ( 001.2 )
  2. 長度不一樣 ( s1 = 1.2, s2 = 1.22.3 )
 ----------------------------------------- */
typedef char *  PChar;
typedef char ** DPChar;
DPChar JCSplit( PChar strArray, PChar delimit, int *outputSize)
{
    int     idx     = 0;
    DPChar  result  = malloc( strlen(strArray) * sizeof(char*) );
    PChar   token   = strtok(strArray, delimit);

    while( token != NULL)
    {
        result[idx++] = token;
        token = strtok(NULL, delimit);
    }
    *outputSize = idx;
    /*
    printf("idx = %d \n",idx);
    idx = 0;
    while( result[idx] != NULL){
        printf("%s \n",  result[idx++]);
    }
    */
    return result;
}

int compareVersion(char* version1, char* version2)
{
    PChar   paV1Str = (PChar) malloc( (strlen(version1)+1) );
    PChar   paV2Str = (PChar) malloc( (strlen(version2)+1) );
    strcpy( paV1Str, version1);
    strcpy( paV2Str, version2);

    int     V1ResLen    = 0;
    int     V2ResLen    = 0;
    DPChar  paV1Res     = JCSplit( paV1Str, ".", &V1ResLen);
    DPChar  paV2Res     = JCSplit( paV2Str, ".", &V2ResLen);

    int MaxLen          = V1ResLen > V2ResLen ? V1ResLen : V2ResLen ;
    int idx             = 0;
    int compare         = 0;
    for(idx = 0 ; idx < MaxLen ; idx++ )
    {
        int i1 = ((idx + 1) > V1ResLen) ? 0 : atoi ( paV1Res[idx] );
        int i2 = ((idx + 1) > V2ResLen) ? 0 : atoi ( paV2Res[idx] );
        if ( i1 > i2) {
            compare =  1;
            break;
        } else if ( i2 > i1) {
            compare = -1;
            break;
        }
    }

    free(paV1Str);
    free(paV2Str);
    free(paV1Res);
    free(paV2Res);
    return (compare == 0) ? 0 : compare ;
}

/* -----------------------------------------
  方法二 : 3.85% Runtime: 0 ms  
  法二
  每一次直接取 . 前面的數字比
 ----------------------------------------- */
int compareVersion(char* version1, char* version2)
{
    int V1Len   = strlen(version1);
    int V2Len   = strlen(version2);
    int MaxLen  = V1Len > V2Len ? V1Len : V2Len ;
    int count   = 0;
    int v1Pos   = 0, v2Pos = 0;
    int v1Num   = 0, v2Num = 0;

    while( count++ < MaxLen )
    {
        if( v1Pos >= V1Len ){
            v1Num = 0;
        }else{
            v1Num = 0;
            while( version1[v1Pos] != '\0' && version1[v1Pos] != '.' )
            {
                v1Num = ( v1Num * 10 ) + ( version1[v1Pos] - '0');
                v1Pos++;
            }
            //printf("%d v1Pos = %d\n",v1Num,v1Pos);
            v1Pos++;
        }

        if( v2Pos >= V2Len ){
            v2Num = 0;
        }else{
            v2Num = 0;
            while( version2[v2Pos] != '\0' && version2[v2Pos] != '.' )
            {
                v2Num = ( v2Num * 10 ) + ( version2[v2Pos] - '0');
                v2Pos++;
            }
            //printf("%d v2Pos = %d\n",v2Num,v2Pos);
            v2Pos++;
        }

        if ( v1Num > v2Num) {
            return  1;
        } else if ( v2Num > v1Num) {
            return -1;
        }
    }
    return 0;
}
```