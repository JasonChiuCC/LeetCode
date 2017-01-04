```Swift
/* -----------------------------------------
  方法一 : 71.88% Runtime: 222 ms
 ----------------------------------------- */
class Solution {
    func isPalindrome(_ s: String) -> Bool {
        let len     = s.characters.count
        var head    = 0
        var tail    = len - 1
        let chars   = Array(s.lowercased().characters)
        
        while ( head <= tail )
        {
            while(  chars[head] < "0" || chars[head] > "9" && 
                    chars[head] < "a" || chars[head] > "z")
            {
                head += 1
                if( head > tail ){
                    print("1")
                    break 
                }
            }
            
            
            while(  chars[tail] < "0" || chars[tail] > "9" && 
                    chars[tail] < "a" || chars[tail] > "z")
            {
                tail -= 1
                if( head > tail ){ 
                    print("2")
                    break 
                }
            } 
            if (head > tail){ break }
            if( chars[head] != chars[tail] ){
                 return false
            }
            head += 1
            tail -= 1
        }
        return true
    }
}
```