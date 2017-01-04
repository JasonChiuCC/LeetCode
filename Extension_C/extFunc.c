/* -----------------------------------------
 傳入字串和分割條件，回傳陣列
 注意: 傳入 strArray 要為字串陣列，例如
 char str[] = "Hello";
 
 回傳值為 char **，且記得要 free
          outputSize 為總共分割幾個
          
  舉例 : 1.2.33.4.555 ( 以 "." 分割 )
  ArrayRes[0] = 1;
  ArrayRes[1] = 2;
  ArrayRes[2] = 33;
  ArrayRes[3] = 4;
  ArrayRes[4] = 555;
  outputSize =  5        
  
  
  *ArrayRes -> *[0] -> "AAA"
               *[1] -> "BBB"
               *[2] -> "CCC"
  => ArrayRes = **
 ----------------------------------------- */
typedef char *  PChar;
typedef char ** DPChar;
DPChar JC_A_Split( PChar strArray, PChar delimit, int *outputSize)
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

int main()
{
    PChar   SourceStr   = "1.1.3.52";
    PChar   ArrayStr    = malloc( (strlen(SourceStr)+1) * sizeof(char) );
    strcpy( ArrayStr, SourceStr);

    int     V1ResLen    = 0;
    DPChar  ArrayRes    = JCSplit(ArrayStr,".",&V1ResLen);
    int idx = 0;
    while( ArrayRes[idx] != NULL )
    {
        printf("%s \n", ArrayRes[idx++] );
    }

    free(ArrayStr);
    free(ArrayRes);
    return 0;
}

/* -----------------------------------------
 Array = 1 2 3 4 5 6 7, numsSize = 5, k = 3
 -> 5 6 7 1 2 3 4 
 JCRotate  = 傳入陣列往右移 3 位
 JCReverse = 反轉 Ex: 1 2 3 4 5 => 5 4 3 2 1
 ----------------------------------------- */
void JC_A_Reverse(int* nums, int begin, int end) {
    if (begin >= end) return;
    while (begin < end) {
        nums[begin] ^= nums[end] ^= nums[begin] ^= nums[end];
        begin++;
        end--;
    }
}
 
void JC_A_Rotate(int* nums, int numsSize, int k)
{
    int i = (k % numsSize);
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, i - 1);
    reverse(nums, i, numsSize - 1);
}

/* -----------------------------------------
 Array = 1 2 3 4 5 6 7, numsSize = 5, k = 3
 -> 5 6 7 1 2 3 4 
 JCRotate  = 傳入陣列往右移 3 位
 JCReverse = 反轉 Ex: 1 2 3 4 5 => 5 4 3 2 1
 ----------------------------------------- */
int JC_Algo_BinarySearch(int data[], int search, int len)
{
    int low     = 0;
    int high    = len - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (data[mid] == search)
        {
            return mid;
        }
        else if (data[mid] > search)
        {
            high = mid - 1;
        }
        else if (data[mid] < search)
        {
            low = mid + 1;
        }
    }
    return -1;
}

/* -----------------------------------------
 char 轉小寫
 ----------------------------------------- */
char JC_C_Lowercased(char ch) {
    if (ch >= 'A' && ch <= 'Z')
        ch += 0x20;
    return ch;
}