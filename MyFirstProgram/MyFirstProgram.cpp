#include <iostream>

// dynamic array with heap allocation
class IntArr
{
	size_t m_size;
	// declare array that store address
	int * m_arr;

public:
	IntArr(size_t size)
		: m_size(size)
		// storing array in heap using keyword new
		// also new keyword will set default value to 0. so it will not giving a garbage
		, m_arr(new int[size])
	{
		// however to guarantee the default initialization to 0 we need to use standard library
		// which handle efficient initialization

		// std::fill_n(<arr>, <size>, <value>)
		std::fill_n(m_arr, size, 0);

		std::cout << "array constructed\n";
	}

	// Destructor with cleanup, bcs we use pointer
	~IntArr() 
	{
		delete [] m_arr; 
		std::cout << "Array deconstructed \n";
	}

	// setter and getter
	int get(size_t index) const
	{
		return m_arr[index];
	}

	void set(size_t index, int val)
	{
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
	IntArr myArr(10);

	myArr.set(4, 7);

	myArr.print();
	
	return 0;

}

