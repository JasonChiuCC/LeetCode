```C
/* -----------------------------------------
  方法一 : 23.66% Runtime: 9 ms
  直接算出新位置即可 (i+k)%numsSize
 ----------------------------------------- */
typedef int *   PInt;
#define JC_MALLOC( type, size)          (type *) malloc ( sizeof(type)*size )
void rotate(int* nums, int numsSize, int k)
{
    // 等於沒轉
    if( k%numsSize == 0) return;
    
    int* result = JC_MALLOC( int, numsSize );
    if( result == NULL ) return;

    int i = 0;
    for( i=0; i < numsSize; ++i)
    {
        int newPos      = (i+k)%numsSize;
        result[newPos]  = nums[i];
    }

    for( i=0; i < numsSize; ++i)
    {
        nums[i] = result[i];
    }
    free(result);
}

/* -----------------------------------------
  方法二 : 51.15% Runtime: 6 ms
  使用 reverse 
  Ex: 1 2 3 4 5 6 7 (k=3) => 5 6 7 1 2 3 4
  1. 1 2 3 4 5 6 7   => [7] 2 3 4 5 6 [1]
  2. 7 2 3 4 5 6 1   => 7 [6] 3 4 5 [2] 1
  3. 7 6 3 4 5 2 1   => 7 6 [5] 4 [3] 2 1 
  4. 7 6 5 | 4 3 2 1 => 2 區塊再分別 reverse
  
  1. 7 6 5 => 5 6 7
  
  1. 4 3 2 1 => 1 3 2 4 
  2. 1 3 2 4 => 1 2 3 4
  
  最後合併 = 5 6 7 | 1 2 3 4  
 ----------------------------------------- */
void rotate(int* nums, int numsSize, int k)
{
    int i = (k % numsSize);
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, i - 1);
    reverse(nums, i, numsSize - 1);
}

void reverse(int* nums, int begin, int end) {
    if (begin >= end) return;
    while (begin < end) {
        nums[begin] ^= nums[end] ^= nums[begin] ^= nums[end];
        begin++;
        end--;
    }
}
```