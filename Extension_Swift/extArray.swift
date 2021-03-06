# 初始化陣列
let array           = Array(repeating: 0, count: 100)
let array           = [String]()
let array:[Int]     = [1, 2, 3]
let array:[Int]     = []
let array:[Int]     = [1, 2]

# 初始化 Optional 陣列
let array: Int?[]       = [1, 2, nil, 4, 5]
let array: [Int?]       = [1, 2, nil, 4, 5]
let array: Array<Int?>  = [1, 2, nil, 4, 5]
let array               = [String?](count:64, repeatedValue: nil)

# 陣列長度
array.count

# 將字串轉為字串陣列
e.g. Hello -> ["H","e","l","l","o"]
// 轉陣列但元素為 Character
let array = Array(aStr.characters)
let array = Array(aStr.utf16)
let array = Array(aStr.unicodeScalars)

// 轉陣列且元素為 String
aStr.characters.map { String($0) }

# 將字串轉為字元陣列
let myString    = "Hello"
let characters  = [Character](myString.characters)
let characters  = Array(myString.characters)

# 將字串陣列轉字串
let strTest = array.joinWithSeparator("")

# 排序
Array.sort(<)

# 陣列加入元素
array.append("$")
array.insert(val!,at:0) // 插入到指定位置，後面元素往後移

# 陣列移除元素
array.removeAtIndex(0) 
array.popLast() // 移除最後一個，會回傳最後一個值

// 過濾元素
let even = chars.filter { 
    $0 >= "a" && $0 <= "z"
}
