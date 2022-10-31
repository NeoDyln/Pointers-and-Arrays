# About
- This repo simply has some of my notes and test files regarding C pointers, arrays and strings from personal studies

## Pointers
- These are variables containing a memory address
- Pointers can be defined by appending an * at the variable name eg (int *p is a pointer )
- The address in memory that they point to can be checked using the and (&) symbol like so: &variable
- Therefore, for a variable say int c = 27, we can define a pointer to its address as so: *p = &c

## Storage in memory by type
- Every data type has an allocated size of storage in memory and can be checked using the sizeof function
- It works by stating the function and the data type you want to check ie: sizeof(int)
- To print it out eg while using printf(), we make use of the %lu wildcard
- ie: printf("Size of int is %lu", sizeof(int))
- We can also check the address of a variable using the %p wildcard like so
- printf("Address of variable c is %p" &c)
- NOTE: This function is platform specific...that is the memory allocated is dependent on your os type if it's 32-bit or 64 bit
- Allocation also happens by reserving bytes (1 byte = 8 bits) (1 bit is either a 0 or 1 and values are stored in binary form)
- A sample program I have is 0-storage_test.c and it is compiled to 0-storage_test

- Note that bits work in binary notation therefore one bit can hold either 0 or 1...and 1 byte has 8 bits therefore 1 byte can hold 2^8 values this being from -128 to 127

- When storing values in a variable, the PC reserves memory based on the data type passed therefore for a char, 1 byte/ 8 bits are reserved. The reserved memory is the address and the variable essentially stores to an address

- Therefore variables -> check/ create address -> retrieve/ update data in that address
- Hence if you have : int c = 7, int *p = &c, what int c does is it checks its address and updates whatever value was there to 7
- NOTE that in the addresses, the 7 won't be stored as 7 but rather it will be stored in its ASCII form.
- NOTE also that addresses are not always empty if unassigned to a variable...For instance, the address that c above cecks may have had a value of 56 before but waas simply updated to read 7

## Storing memory addresses

- They are stored in pointers as we saw above. Pointers by default get 8 bytes in memory... They have their own addresses wich can be checked the same way we checked the address of a variable....and their value reads the address of the variable it points to

- This brings me to this point: If int c =7 and int *p = &c, what would printing p and *p read?

## Dereferencing

- Pointers are powerful in that they can edit the value of the variable they point to hence my question above in the previous section
- p would print the address of c but *p would print the value of c
- As a result if int c = 7 and int *p = &c, then *p = 8 would update c to read 8 
- Basically, c == *p == 7 while p == &c hence the difference in p and *p

- int *p is different from *p = {some_value} since the latter edits the value at the variable it's pointing to whereas the first is a pointer declaration.

## Passing parameter values
- A function that takes a parameter does not edit the original variable's value if a variable was passed in as a paramenter but instead it copies the value of the variable and assigns it to the variable x as defined in the function definition.

- For example: int n = 98, modify_m(n) && int modify_m(int m) { m = 402; return m;} 
- The above simply takes the value of n, copies it and assigns it to a variable m with its own address hence updating to 402 only affects the variable m and not n therefore n still reads 98

If however we passed in the address of n, then we can change the value of n by directly editiong the value at its address without touching the variable

- For example: int n = 98, int *x = &n, modify_m(x) && void modify_m(int *m) { *m = 402;}
- The above takes the address of n and stores it in m....since the addresses match, *m = *x = n = 98...therefore *m =402 is the same as indirectly saying n = 402;

## Arrays and accessing through pointers
- Arrays are objects that hold multiple data variables of the same type. They are not pointers.
- While they aren't pointers, you will find that an array's name acts as a pointer to the first element in the array if printed as an array
- This is due to a concept called array decay where if used in such a way, the array name is implicitly declared as a pointer to an element in this case, the first element in the array. This however is usually a temporary action
- This applies to all cases except when used in a sizeof() or a &array_name scenario as these refer to the array itself,
the first returning the size of the array in memory and the other returning the address of the array which agai matches the address of the first element as it is where the array starts

- Array elements can incidentally be accessed like so *(array_name + x) where x = the xth + 1 element in the array since array_name points to the first element which is at index 0

## Pointers to other pointers
- Pointers usually contain the addresses of a variable therefore a pointer to a pointer would also contain the address tof the variable being pointed to by pointer 1

- For instance int c = 9; int *p, **pt; p = &c; pt = &p;
