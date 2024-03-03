#include <iostream>



/// <summary>
/// In the previous example, we already done the dynamic array but fixed type to int
/// now we need to implement generic so we dont have to create the same class
/// for each different type for creating dynamic array
/// </summary>
template <typename T>
class DynamicArray
{
	size_t m_size;
	// declare array that store address
	T * m_arr;

public:
	DynamicArray(size_t size)
		: m_size(size)
		// storing array in heap using keyword new
		// also new keyword will set default value to 0. so it will not giving a garbage
		, m_arr(new T[size])
	{


		std::cout << "array constructed\n";
	}

	// Destructor with cleanup, bcs we use pointer
	~DynamicArray()
	{
		delete [] m_arr; 
		std::cout << "Array deconstructed \n";
	}

	// setter and getter
	T get(size_t index) const
	{
		// we need to handle out of bound error handling 
		if (index >= m_size)
		{
			std::out_of_range("Index out of bounds");
		}
		return m_arr[index];
	}

	void set(size_t index, T val)
	{
		// we need to handle out of bound error handling 
		if (index >= m_size)
		{
			std::out_of_range("Index out of bounds");
		}
		m_arr[index] = val;
	}

	void print() const
	{
		for (size_t i = 0; i <m_size; i++)
		{
			std::cout << i << " " << m_arr[i] << "\n";
		}
	}

};



int main()
{
	// define the size of 5
	// implementing the generic type

	DynamicArray<int> myArr(10);

	myArr.set(4, 7);

	myArr.print();

	std::cout << "string array:\n";
	
	DynamicArray<std::string> names(2);

	names.set(0, "fdsfsddfs");

	auto n = names.get(0);
	std::cout << "\n\n" << n << "\n";
	
	names.print();
	
	return 0;

}

