#include<iostream>
using namespace std;

class Array
{
private:
	int* arr;
	int size;
	int capacity;

	bool isFull()
	{
		if (size == capacity)
		{
			return true;
		}

		return false;
	}

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

	// Shifting
	void shiftRight(int fromIndex)
	{
		for (int i = size - 1; i >= fromIndex; i--)
		{
			arr[i + 1] = arr[i];
		}
	}

	void shiftLeft(int fromIndex)
	{
		for (int i = fromIndex; i < size - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
	}

public:

	// Default Constructor
	Array()
	{
		capacity = 2;
		arr = new int[capacity];
		size = 0;
	}

	// Parameterized Constructor
	Array(int capacity)
	{
		this->capacity = capacity;
		arr = new int[capacity];
		size = 0;
	}

	// Insertion at Start
	void insertAtStart(int value)
	{
		if (isFull())
		{
			regrow();
		}

		if (size > 0)
		{
			shiftRight(0);
		}

		arr[0] = value;
		size++;
	}

	// Insertion at Index
	void insertAtIndex(int value, int index)
	{
		if (index < 0 || index > size)
		{
			cout << "Invalid Index!" << endl;
			return;
		}

		if (isFull())
		{
			regrow();
		}

		if (index < size)
		{
			shiftRight(index);
		}

		arr[index] = value;
		size++;
	}

	// Insertion at End
	void insertAtEnd(int value)
	{
		if (isFull())
		{
			regrow();
		}

		arr[size] = value;
		size++;
	}

	// Deletion from Start
	void deleteFromStart()
	{
		if (size == 0)
		{
			cout << "Array is Empty!" << endl;
			return;
		}

		shiftLeft(0);
		size--;
	}

	// Deletion from Index
	void deleteFromIndex(int index)
	{
		if (index < 0 || index >= size)
		{
			cout << "Invalid Index!" << endl;
			return;
		}

		shiftLeft(index);
		size--;
	}

	// Deletion from End
	void deleteFromEnd()
	{
		if (size == 0)
		{
			cout << "Array is Empty!" << endl;
			return;
		}

		size--;
	}

	// Update at Start
	void updateAtStart(int value)
	{
		if (size == 0)
		{
			cout << "Array is Empty!" << endl;
			return;
		}

		arr[0] = value;
	}

	// Update at Index
	void updateAtIndex(int index, int value)
	{
		if (index < 0 || index >= size)
		{
			cout << "Invalid Index!" << endl;
			return;
		}

		arr[index] = value;
	}

	// Update at End
	void updateAtEnd(int value)
	{
		if (size == 0)
		{
			cout << "Array is Empty!" << endl;
			return;
		}

		arr[size - 1] = value;
	}

	// Reverse Array
	void reverse(int start, int end)
	{
		while (start < end)
		{
			int temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;

			start++;
			end--;
		}
	}

	// Rotate Right
	void rotateRight(int k)
	{
		if (size <= 1)
		{
			return;
		}

		k = k % size;

		reverse(0, size - 1);
		reverse(0, k - 1);
		reverse(k, size - 1);
	}

	// Rotate Left
	void rotateLeft(int k)
	{
		if (size <= 1)
		{
			return;
		}

		k = k % size;

		reverse(0, k - 1);
		reverse(k, size - 1);
		reverse(0, size - 1);
	}

	// Display
	void display()
	{
		if (size > 0)
		{
			cout << "\nArray is: [";

			for (int i = 0; i < size; i++)
			{
				cout << arr[i];

				if (i != size - 1)
				{
					cout << ",";
				}
			}

			cout << "]" << endl;
		}
		else
		{
			cout << "Array is Empty!!" << endl;
		}
	}

	// Destructor
	~Array()
	{
		delete[] arr;
		arr = nullptr;
	}
};
