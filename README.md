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
The `DEQUE` data type has been implemented. The following functionality exists:

* creation
* deletion
* lookup
  * arbitrary
  * front
  * back
* check capacity
* clearing (remove everything from deque)
* check if empty
* erasing (specified index)
* iterate and apply function
  * accepts a function pointer and calls it on each value
* insert a value (specified index)
* pop value from end
* pop value from front
* push value to end
* push value to front
* resizing
* check size

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
* check size

### LIST
The `LIST` data type has been implemented. The following functionality exists:

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
* pop value from back
* pop value from front
* push value to back
* push value to front
* remove value from list
* check size

### STACK
The `STACK` data type has been implemented. The following functionality exists:

* creation
* deletion
* check if empty
* push value onto stack
* pop value from stack
* check size
* get value on top of stack

### QUEUE
The `QUEUE` data type has been implemented. The following functionality exists:

* creation
* deletion
* lookup
  * front
  * back
* check if empty
* pop value from front
* push value to back
* check size

### PRIORITY_QUEUE
The `PRIORITY_QUEUE` data type has been implemented. The following functionality exists:

* creation
  * custom comparators possible
* deletion
* check if empty
* pop value from front
* push value into queue
* check size
* get value at front of queue

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

