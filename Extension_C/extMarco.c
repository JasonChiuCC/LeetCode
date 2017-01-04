/*
 M = Memory
 A = Array
 C = Char
*/


/* 記憶體配置 */
#define JC_M_MALLOC( type, size)        (type *) malloc ( sizeof(type)*size )

/* 陣列長度 */
#define JC_A_LEN( array, typeOfArray)   (sizeof(array) / sizeof(typeOfArray))

/* 檢查 CHAR 是否為字母或數字 */
#define JC_C_isAlphabetOrDigit(ch)      (JC_C_Lowercased(ch) < '0' || (JC_C_Lowercased(ch) > '9' && JC_C_Lowercased(ch) < 'a') || JC_C_Lowercased(ch) > 'z')