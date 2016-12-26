```swift
/* -----------------------------------------
  方法一 : 00.00% Runtime: 1882 ms
  取出最後一個元素，並放到陣列第一個位置，非常慢
 ----------------------------------------- */
class Solution {
    func rotate(_ nums: inout [Int], _ k: Int) {
        let i = (k % nums.count)
        for _ in 0..<i {
            let lastVal = nums.popLast()
            nums.insert(lastVal!,at:0)  
        } 
    }
}

/* -----------------------------------------
  方法二 : 42.86% Runtime: 55 ms
 ----------------------------------------- */
class Solution {
    func rotate(_ nums: inout [Int], _ k: Int) {
        let numsSize        = nums.count
        var result          = Array(repeating: 0, count: numsSize)        
        for i in 0..<numsSize {
            let newPos      = (i+k)%numsSize
            result[newPos]  = nums[i]
        }
        for i in 0..<numsSize {
            nums[i] = result[i]
        }        
    }
}

/* -----------------------------------------
  方法三 : 39.29% Runtime: 59 ms
 ----------------------------------------- */
func reverse(_ nums: inout [Int], _ begin: Int, _ end: Int) {
    if (begin >= end){
      return  
    } 
    var iBegin = begin
    var iEnd   = end
    while (iBegin < iEnd) {
        nums[iBegin] = nums[iBegin] ^ nums[iEnd]
        nums[iEnd]   = nums[iEnd]   ^ nums[iBegin]
        nums[iBegin] = nums[iBegin] ^ nums[iEnd]
        iBegin = iBegin + 1
        iEnd   = iEnd - 1
    }
}

class Solution {
    func rotate(_ nums: inout [Int], _ k: Int) {
        let numsSize = nums.count
        let i = (k % numsSize)
        reverse(&nums, 0, numsSize - 1);
        reverse(&nums, 0, i - 1);
        reverse(&nums, i, numsSize - 1);      
    }
}
```