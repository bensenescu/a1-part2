### Change Log
- Changed TestArray.cpp to test-array.cpp


**Description of Part 2 Code**


For the design portion of this assignment, we decided to go with an Array data structure.
Our design behaves just like the standard library's Vector class where the capacity of the data structure
is being handled automatically by the container itself as elements are added and removed.

Our Array data structure contains 3 fields: an array of pointers to Objects, the current capacity/total storage of the 
array, and the current length of the array. The default constructor initializes the fields to an initial capacity of 1
element, capacity of 1 and length to 0.

As you can see in "Array.h", the allocate() function is checking if the current length has reached the Array's capacity. 
If it has, we double the array's capacity, reinsert the old data into the new array called temp, delete the previous
array and set the array equal to the temp array. This function is then called every time 
an item is being added to the array.

Conversely, the deallocate() function does the inverse of the previous function and decreases capacity if the current
length is less than half of the capacity. This function is then called every time an item is being removed from the 
array.


Our design does accommodate Arrays of all Objects and String as well.
We also designed a basic API for our Object class, where basic equality and hashing functions are
designed and implemented as you can see in "object.h"


