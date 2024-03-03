#include <iostream>
#include <vector>
// working with files
#include <fstream>

class Human
{

	std::string m_name = "john doe";
	std::string m_hairColor = "black";
	int yearBorn = 0000;
public:

	Human(std::string name, std::string hairColor, int yearBorn)
		:m_name(name), m_hairColor(hairColor), yearBorn(yearBorn)
	{};

	void greetSelf()
	{
		std::cout << "Hello There! my name is " << m_name << "\n";
		std::cout << "My Age is " << 2023 - yearBorn << "\n";
	}
};


class Student
{
	std::string m_first = "john";
	std::string m_last = "doe";
	int			m_id = 0;
	float		m_gpa = 0.0f;

public:
	// default constructor
	Student() {};

	Student(std::string first, std::string last, int id, float gpa)
		:m_first(first),
		m_last(last),
		m_id(id),
		m_gpa(gpa)
	{}

	// now we get all the property encapsulated, that's where getter and setter become handy


	/// <summary>
	///	we need to make sure that the getter will not changing the class it self
	/// by using CONST CORRECTNESS it is considered as good practice 
	///  
	/// check line 100 -> for implementation
	/// </summary>

	float getGpa() const
	{
		return m_gpa;
	}

	int getID() const
	{
		return m_id;
	}

	std::string getFirstName() const
	{
		return m_first;
	}

	std::string getLastName() const
	{
		return m_last;
	}

	std::string getFullName() const
	{
		return m_first + " " + m_last;
	}

	void print() const
	{
		std::cout << m_first << "\t";
		std::cout << m_last << "\t";
		std::cout << m_id << "\t";
		std::cout << m_gpa << "\n";
	
	}
};



/// <summary>
///		SEE THE IMPLEMENTATION OF THIS CLASS ON LINE : 183
/// </summary>

class Course
{
	std::string m_name = "untitled course";
	std::vector<Student> students;

public:
	Course() {};
	

	/// <summary>
	/// 
	///  because default behaviour of cpp when giving an object as a parameter
	/// in this case are std::string. it will creates a copy to the original object
	/// 
	/// hence, all we want is to construct original data first then seal it so it cannot be changed
	/// by using combination of constant and reference
	///  
	/// P.S -> let's see more example on next method which are adding student
	/// </summary>

	Course(const std::string& name)
		: m_name(name)
	{}

	/// <summary>
	///  This is where passing reference become handy. i want to store a student that 
	///  really a studdent object, not just the copy of it. so if there any change via course object
	/// it will affect the original student object.
	/// 
	/// hence, we use const and reference on this function by value.
	/// 
	/// however this function need to change something, then it will NOT having const function
	/// 
	/// P.S -> next method are going to implement const function
	/// </summary>

	void addStudent(const Student& student)
	{
		students.push_back(student);
	}

	/// <summary>
	///  now this is it, where we dont want to change the original object. 
	///  we need to use cosnt on the function so it will not modify anything..
	/// 
	///	however if we want to get the students vector, as always we want to use the original data right?
	/// that's where reference and const become handy. 
	/// 
	/// on the return type: we need to use reference and const. const preventing user be able to change the data
	/// and reference: will prevent copying the real object
	/// </summary>

	const std::vector<Student>& getStudents() const
	{
		return students;
	};

	void loadFromFiles(const std::string& filename)
	{
		std::ifstream fileInput(filename);
		std::string first, last;
		int id;
		float gpa;

		while (fileInput >> first)
		{
			fileInput >> last >> id >> gpa;
			
			addStudent(Student(first, last, id, gpa));
		}

	};

	void printAllStudents() const
	{
		// we need to be able to traverse through the students stack
		// and we call the print fucntion.
		for (const auto& student : students)
		{
			student.print();
		}
	}

};

int main()
{
	std::vector<int> m_vec;

	m_vec.push_back(1);
	m_vec.push_back(2);
	m_vec.push_back(24);

	Human human1 = Human("afif", "black", 2001);

	human1.greetSelf();

	Student afif("afif", "fadillah", 2010290291, 3.05f);
	afif.print();

	// this is implementation of const 
	const Student afif2;
	afif2.print();

	Student dave("dave", "whitaker", 201999029, 3.75f);
	
	Course compSci("Computer Science");

	compSci.addStudent(dave);
	compSci.addStudent(afif);

	// we can also add the student along with addStudent method
	compSci.addStudent(Student("james", "gray", 1023929, 3.75f));

	std::cout << "getting all the student in Computer Science course" << "\n";

	compSci.printAllStudents();

	std::cout << "\n\n";

	std::cout << "Reading from the files" << "\n";

	Course cpp("c++ course");

	cpp.loadFromFiles("students.txt");

	cpp.printAllStudents();


	std::cout << "\n\n";
	


	// first method to loop the collection

	/// <summary>
	///  We use size_t becaus the collection size is unint means it has value of unasigned
	/// however size_t will ensure compatible to convert based on how many bits does current system
	/// had
	/// </summary>
	for (size_t i = 0; i < m_vec.size(); i++)
	{
		std::cout << m_vec[i] << "\n";
	}

	// second similar to foreach 
	for (int a : m_vec)
	{
		std::cout << a << "\n";
	}

	/// <summary>
	/// We can also use auto keyword to make the type dynamic
	/// </summary>

	std::vector<float> m_vecf;

	m_vecf.push_back(123.2f);
	m_vecf.push_back(12233.221f);
	m_vecf.push_back(12312.22312f);
	m_vecf.push_back(1233223.22f);

	// this where auto used

	/// <summary>
	/// this method will copy from corresponding array
	/// but for float and integer this keyword willl not affecting that much
	/// 
	/// but if this long string or big data structure this will copying the object
	/// but the solution to this are using pointer 
	/// it will not copying to it but less copy
	/// 
	/// keyword:
	///				 auto&
	/// </summary>

	for (auto a : m_vecf)
	{
		std::cout << a << "\n";
	}

	return 0;

}

