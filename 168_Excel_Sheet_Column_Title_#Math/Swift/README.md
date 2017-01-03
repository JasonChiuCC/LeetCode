```C
/* -----------------------------------------
  方法一 : 75.00% Runtime: 26 ms  
 ----------------------------------------- */
class Solution {
    func convertToTitle(_ n: Int) -> String {
        let dict = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
                    "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"]
        var num = n
        var ans = ""
        while num != 0
        {
            num -= 1
            ans = dict[num % 26] + ans
            num = num / 26
        }
        return ans   
    }
}
```