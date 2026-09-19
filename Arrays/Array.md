# Dynamic Array — Complete C++ DSA Function Reference

> A practical, copy-ready reference for a custom Dynamic Array in C++.
>
> Includes **Insertion, Deletion, Update, Searching, Duplicate Removal, Reverse, Rotation, and Sorting Algorithms**.

---

# 1. Class Structure

```cpp
class Array
{
private:
    int* arr;
    int size;
    int capacity;
};
```

- `arr` → dynamically allocated array
- `size` → number of currently stored elements
- `capacity` → total allocated space

---

# 2. Helper Functions

<details>
<summary><b>isFull()</b> — Check whether the array is full</summary>

### Purpose

Checks whether the current number of elements has reached the allocated capacity.

### Code

```cpp
bool isFull()
{
    if (size == capacity)
    {
        return true;
    }

    return false;
}
```

### Complexity

- Time: `O(1)`
- Space: `O(1)`

</details>

---

<details>
<summary><b>regrow()</b> — Double the array capacity</summary>

### Purpose

Creates a larger array, copies the existing elements, deletes the old array, and updates the capacity.

### Code

```cpp
void regrow()
{
    int* newArr = new int[capacity * 2];

    for (int i = 0; i < size; i++)
    {
        newArr[i] = arr[i];
    }

    delete[] arr;

    arr = newArr;
    capacity = capacity * 2;
}
```

### Complexity

- Time: `O(n)`
- Space: `O(n)`

</details>

---
