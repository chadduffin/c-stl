# C Standard Template Library

The C STL contains interface and implementation files that mimic the C++ STL.

## Generic Data Type

The basic data unit used for the containers can be found in `generics.h`. This type is a basic `union` that can be used to represent any desired data type.

```c
typedef union DATA {
  // int my_int;
  // float my_float;
  // char *my_string;
};
```

## Containers

### ARRAY
The `ARRAY` data type has been implemented. The following functionality has been implemented:

* creation
* deletion
* lookup
  * arbitrary
  * front
  * back
* clearing (set to 0)
* check if empty
* filling (custom value)
* iterate and apply function
  * accepts a function pointer and calls it on each value
* check the size

### VECTOR
*Not yet implemented.*

### DEQUE
*Not yet implemented.*

### FORWARD_LIST
*Not yet implemented.*

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

