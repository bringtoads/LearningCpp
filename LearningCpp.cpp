#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Student
{
	// private fields
	std::string m_firstName = "FirstName"; // giving default value to field
	std::string m_middleName;
	string m_lastName = "LastName";
	int m_id = 0;
	float m_avg = 0;


public:
	// default constructor 
	Student() {} 
	
	//constructor will first assign empty value and then assign value
	/*Student(string firstName, string middleName, string lastName, int id, float avg)
	{
		m_firstName = firstName;
		m_middleName = middleName;
		m_lastName = lastName;
		m_id = id;
		m_avg = avg;
	}*/

	// this constructor will directly assign value to the field without setting it to 0 or ""
	// it is faster and more efficient memory wise
	Student(string firstName, string middleName, string lastName, int id, float avg)
		: m_firstName(firstName) // should be passing by references
		, m_middleName(middleName)
		, m_lastName(lastName)
		, m_id(id)
		, m_avg(avg)
	{
	}
	
	//public function to return private fields
	// class method/function
	// ReturnType MethodName (parameters){}
	int getAvg()
	{
		return m_avg;
	}
	
	int getId()
	{
		return m_id;
	}

	std::string getFirst()
	{
		return m_firstName;
	}

	std::string getMiddle()
	{
		return m_middleName;
	}
	// we need to return a reference in const functions
	std::string getLast() const
	{
		return m_lastName;
	}

	
	void print() const // const keyword won't let you change the object within the const function
	{
		cout << m_firstName << " " << m_middleName << " "  << m_lastName << " "  << m_id << " " << m_avg << "\n";
	}
};

class Course 
{
	string m_name;
	int m_id;
	vector<Student> m_students;
public: 
	Course(const string& name,int id)
		: m_name(name) // should be passing by references
		, m_id(id)
	{
	}

	void addStudents(const Student& s)
	{
		//adding student to student vector
		m_students.push_back(s);
	}
	
	// the const in the first means whatever we are returning can't be changed
	// the const in the end means the function will not change the class
	const std::vector<Student>& getStuents() const
	{
		return m_students;
	}

	void print() const
	{
		for (const auto& s : m_students)
		{
			s.print();
		}
	}

	void loadFromFile(const string& fileName)
	{
		std::ifstream fin(fileName);
		std::string firstName,middleName,lastName;
		int id;
		float avg;

		
		while (fin >> firstName)
		{ 
			// both are same 
		/*	fin >> middleName;
			fin >> lastName;
			fin >> id; 
			fin >> avg;*/
			
			fin >> middleName >> lastName >> id >> avg;
			addStudents(Student(firstName, middleName, lastName, id, avg));
		}
	}
};
class IntArray
{
	size_t m_size;
	int* m_arr;

public:
	IntArray(size_t size)
		: m_size(size)
		, m_arr(new int[size])
	{	
		cout << "Array Constructor \n";
	}

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
		for (size_t i = 0; i < m_size; i++)
		{
			cout << i << " " << m_arr[i] << "\n";
		}
	}
};
void pp(int & i)
{   // & address will tell where it is stored in ram
	std::cout << &i << " " << i << " " << sizeof(i) << "\n";
}
int main(int arg, char* argv[])
{
	//int a = 10;
	//int b = 25; //stack allocated variable
	/*int arr[10] = {};
	int* harr = new int[10];

	for (size_t i = 0; i < 10; i++)
	{
		pp(arr[i]);
	}
	 
	for (size_t i = 0; i < 10; i++)
	{
		pp(harr[i]);
	}*/

	//pp(a);
	//pp(b);

	//int a = 10;
	//int b = 25;
	//int c = 35;
	//int* pa = &a;//point pa ma a ko address raw pointer
	//int* pb = &b; 
	//int* pc = &c;

	// *pa ra *(&a) is same
	//*pa = 11; // Sets the value at the address stored in pa to 11
	//*(&a) = 12; // Sets the value at the address of a to 12 

	//stack buffer overrun 
	//changing value of a through b 
	//*(pb - 1) = 17;
	//int* temp = pb;  // Create a temporary pointer that points to b
	//temp--;          // Decrement the temporary pointer to access the memory before the address of b, which is the address of a.
	//*temp = 17;

	//pp(a);
	//pp(b);
	//pp(c);
	
	IntArray myArrry(10);
	myArrry.set(4, 7);
	myArrry.set(2, 712321);
	myArrry.print();
	return 0;
}
