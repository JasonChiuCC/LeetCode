/*
 M = Memory
 A = Array
*/


/* Memory */
#define JC_M_MALLOC( type, size)        (type *) malloc ( sizeof(type)*size )

/* Array */
#define JC_A_LEN( array, typeOfArray)   (sizeof(array) / sizeof(typeOfArray))