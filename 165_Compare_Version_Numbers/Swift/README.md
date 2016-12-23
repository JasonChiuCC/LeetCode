```swift
/* -----------------------------------------
  方法一 : 90%-20% Runtime:  62ms-16ms
  先將兩字串以 "." 分割為陣列，在遞迴陣列互相比較數字
 
  考慮:
  1. 前面有 0   ( 001.2 )
  2. 長度不一樣 ( s1 = 1.2, s2 = 1.22.3 )
 ----------------------------------------- */
import Foundation
class Solution {
    func compareVersion(_ version1: String, _ version2: String) -> Int {
        let V1Len   = version1.characters.count  
        let V2Len   = version2.characters.count  
        let V1Res   = version1.components(separatedBy: ".")
        let V2Res   = version2.components(separatedBy: ".")
        let MaxLen  = max( V1Len , V2Len )
        var idx     = 0
        var compare = 0
        
        let V1ResLen = V1Res.count
        let V2ResLen = V2Res.count
        
        while( idx < MaxLen )
        {
            let i1 = ((idx + 1) > V1ResLen) ? 0 : Int(V1Res[idx])!;
            let i2 = ((idx + 1) > V2ResLen) ? 0 : Int(V2Res[idx])!;  
            
            if ( i1 > i2) {
                return  1;
            } else if ( i2 > i1) {
                return -1;
            }            
            idx = idx + 1
        }
        return 0 
    }
}

/* -----------------------------------------
  方法二 : 10% Runtime:  85ms
  每一次直接取 "." 前面的數字比
 ----------------------------------------- */
private extension String {
    subscript (index: Int) -> Character {
        return self[self.index(self.startIndex, offsetBy: index)]    
    }
    var length: Int { return self.characters.count }
}

private extension Character{
    func toInt() -> Int!
    {
        return Int(String(self))
    }
}

class Solution {
    func compareVersion(_ version1: String, _ version2: String) -> Int {
        let V1Len  = version1.characters.count  
        let V2Len  = version2.characters.count  
        let MaxLen = max( V1Len, V2Len )
        var count   = 0
        var v1Pos   = 0, v2Pos = 0
        var v1Num   = 0, v2Num = 0
       
       
        while( count < MaxLen )
        {
            if( v1Pos >= V1Len ){
                v1Num = 0;
            }else{
                v1Num = 0;
                while( (v1Pos < V1Len) && version1[v1Pos] != "."  )
                {
                    v1Num = ( v1Num * 10 ) + version1[v1Pos].toInt()
                    v1Pos = v1Pos + 1
                }
                //print("\(v1Num) v1Pos = \(v1Pos) ") 
                v1Pos = v1Pos + 1
            }   
    
            if( v2Pos >= V2Len ){
                v2Num = 0;
            }else{
                v2Num = 0;
                while( (v2Pos < V2Len) && version2[v2Pos] != "." )
                {
                    v2Num = ( v2Num * 10 ) + version2[v2Pos].toInt()
                    v2Pos = v2Pos + 1
                }
                //print("\(v2Num) v2Pos = \(v2Pos) ")
                v2Pos = v2Pos + 1
            }  
    
            if ( v1Num > v2Num) {
                return  1
            } else if ( v2Num > v1Num) {
                return -1
            }
            count = count + 1
        }
        
        return 0;   
    }
}    
```