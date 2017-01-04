```C
/* -----------------------------------------
  方法一 : 00.00% Runtime: 0 ms
  isBadVersion 不用實作，當作 API 呼叫
  假設 N = 6，表示版本為 1,2,3,4,5,6
  要找出第一個錯誤的版本
 ----------------------------------------- */
bool isBadVersion(int version);
int firstBadVersion(int n) {
    int low     = 1;
    int high    = n;
    int mid     = 0;
    
    while (low < high)
    {
        mid = (low + (high - low) / 2);
        if ( isBadVersion(mid) ){
            high = mid - 1;
        } else  { 
            low = mid + 1;
        }
    }

    return isBadVersion(low) ? low : high+1 ;
}
```