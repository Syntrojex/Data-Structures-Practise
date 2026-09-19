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

<details>
<summary><b>shiftRight(int fromIndex)</b> — Shift elements right</summary>

### Purpose

Moves elements one position to the right to create an empty position for insertion.

### Code

```cpp
void shiftRight(int fromIndex)
{
    for (int i = size - 1; i >= fromIndex; i--)
    {
        arr[i + 1] = arr[i];
    }
}
```

### Complexity

- Time: `O(n)`
- Space: `O(1)`

</details>

---

<details>
<summary><b>shiftLeft(int fromIndex)</b> — Shift elements left</summary>

### Purpose

Moves elements one position to the left after deletion.

### Code

```cpp
void shiftLeft(int fromIndex)
{
    for (int i = fromIndex; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}
```

### Complexity

- Time: `O(n)`
- Space: `O(1)`

</details>

---
