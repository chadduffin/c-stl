# C Standard Template Library

The C STL contains interface and implementation files that mimic the C++ STL.

## Generic Data Type

The basic data unit used for the containers can be found in `generics.h`. This type is a basic `union` that can be used to represent any desired data type.

```c
union DATA {
  // int my_int;
  // float my_float;
  // char *my_string;
};
```

## Containers

### ARRAY
The `ARRAY` data type has been implemented. The following functionality exists:

* creation
* deletion
* lookup
  * arbitrary
  * front
  * back
* clearing (set all values to 0)
* check if empty
* filling (set all values to custom value)
* iterate and apply function
  * accepts a function pointer and calls it on each value
* check the size

### VECTOR
The `VECTOR` data type has been implemented. The following functionality exists:

* creation
* deletion
* lookup
  * arbitrary
  * front
  * back
* check capacity
* clearing (remove everything from vector)
* check if empty
* erasing (specified index)
* iterate and apply function
  * accepts a function pointer and calls it on each value
* insert a value (specified index)
* pop value from end
* push value to end
* resizing
* check size

### DEQUE
*Not yet implemented.*

### FORWARD_LIST
The `FORWARD_LIST` data type has been implemented. The following functionality exists:

* creation
* deletion
* lookup
  * front
  * back
* clearing (remove everything from list)
* check if empty
* iterate and apply function
  * accepts a function pointer and calls it on each value
* merging of two lists
* pop value from front
* push value to front
* remove value from list

### LIST
*Not yet implemented.*

### STACK
*Not yet implemented.*

### QUEUE
*Not yet implemented.*

### PRIORITY_QUEUE
*Not yet implemented.*

### SET
*Not yet implemented.*

### MULTISET
*Not yet implemented.*

### MAP
*Not yet implemented.*

### MULTIMAP
*Not yet implemented.*

### UNORDERED_SET
*Not yet implemented.*

### UNORDERED_MULTISET
*Not yet implemented.*

### UNORDERER_MAP
*Not yet implemented.*

### UNORDERED_MULTIMAP
*Not yet implemented.*

