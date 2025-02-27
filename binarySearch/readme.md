# Compilation Errors and Solutions in C++

## Error 1: Undefined Reference to Functions

### **Error Message:**

```
/usr/bin/ld: /tmp/ccznk8q2.o: in function `countNoOfOccuranceOfaElement(std::vector<int, std::allocator<int> >&, int)':
countNoOfOccuranceOfaElement.cpp:(.text+0x20): undefined reference to `findFisrtOccurence(std::vector<int, std::allocator<int> >&, int)'
/usr/bin/ld: countNoOfOccuranceOfaElement.cpp:(.text+0x34): undefined reference to `findLastOccurence(std::vector<int, std::allocator<int> >&, int)'
collect2: error: ld returned 1 exit status
```

### **Cause:**

- The linker cannot find the definitions of `findFisrtOccurence` and `findLastOccurence`.
- This happens because the function declarations exist in `functions.h`, but their definitions are in `firstAndLastPositionsInSortedArray.cpp`, which is not being linked correctly.

### **Solution:**

Compile both files together:

```sh
g++ countNoOfOccuranceOfaElement.cpp firstAndLastPositionsInSortedArray.cpp -o output
```

Alternatively, compile separately and then link:

```sh
g++ -c countNoOfOccuranceOfaElement.cpp -o countNoOfOccuranceOfaElement.o
g++ -c firstAndLastPositionsInSortedArray.cpp -o firstAndLastPositionsInSortedArray.o
g++ countNoOfOccuranceOfaElement.o firstAndLastPositionsInSortedArray.o -o output
```

---

## Error 2: Multiple Definition of `main`

### **Error Message:**

```
/usr/bin/ld: firstAndLastPositionsInSortedArray.o: in function `main':
firstAndLastPositionsInSortedArray.cpp:(.text+0x3b2): multiple definition of `main'; countNoOfOccuranceOfaElement.o:countNoOfOccuranceOfaElement.cpp:(.text+0x53): first defined here
collect2: error: ld returned 1 exit status
```

### **Cause:**

- Both `countNoOfOccuranceOfaElement.cpp` and `firstAndLastPositionsInSortedArray.cpp` contain a `main()` function.
- The linker does not know which `main()` function to use.

### **Solution 1: Remove `main()` from One File**

If you want a single executable, remove `main()` from `firstAndLastPositionsInSortedArray.cpp`:

```cpp
// Comment out or remove the main function
// int main() {
//     vector<int> arr = {5, 7, 7, 8, 8, 10};
//     int target = 8;
//     vector<int> result = firstAndLastPosition(arr, target);
//     cout << "first occurrence " << result[0] << endl;
//     cout << "last occurrence " << result[1] << endl;
//     return 0;
// }
```

Then, recompile:

```sh
g++ countNoOfOccuranceOfaElement.cpp firstAndLastPositionsInSortedArray.cpp -o output
```

Run:

```sh
./output
```

### **Solution 2: Compile and Run Separately**

If both `main()` functions are needed, compile and execute them separately:

```sh
g++ countNoOfOccuranceOfaElement.cpp -o output1
g++ firstAndLastPositionsInSortedArray.cpp -o output2
```

Run separately:

```sh
./output1
./output2
```

---

### **Final Notes:**

- Use **Solution 1** if you need a single executable.
- Use **Solution 2** if you want to test both files independently.

---

### **Additional Best Practices:**

- Keep reusable functions in separate `.cpp` files without `main()` and include them where necessary.
- Always compile `.cpp` files together if they depend on each other.
- Use `#ifndef HEADER_H` in header files to prevent multiple inclusions.

### **Conclusion:**

The primary mistakes made were not linking all required `.cpp` files properly, leading to undefined references, and having multiple `main()` functions in separate files, causing linker errors. To avoid these errors in the future, ensure that function implementations are properly included in the compilation process and that only one `main()` function exists in a project if a single executable is required. Proper use of header files and modular code structure can help streamline compilation and execution processes. Debugging compilation errors systematically by understanding linker messages will also make troubleshooting easier. **By following best practices in file organization, compilation, and linking, these issues can be prevented effectively.**

**Hope this helps! 🚀**
