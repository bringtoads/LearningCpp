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
int main(int arg, char* argv[])
{
	//int a = 42;
	//int b = 10;
	//int x;
	//string name = "Ajaya";
	//std::cout << "Hello, World!" << std::endl;
	//cout << (a + b) << endl;
	//cout << name << endl;
	/*cout << "Give an int input";
	cin >> x;
	cout << "your number is " << x;*/
	/*vector<int> vec;
	vec.push_back(42);
	vec.push_back(10);*/

	/*for (size_t  i = 0; i < vec.size(); i++)
	{
		cout << vec[i] <<  "\n";
	}*/

	//for (int a : vec)
	//{
	//	cout << a << "\n";
	//}

	//// auto will look for the type and infer it 
	//// will copy the thing in the vector 
	//// for floating point or int this doesn't matter because you are just copying an int
	//// but if it was a big data structure it would copy it
	//for (auto b : vec)
	//{
	//	cout << b << "\n";
	//}

	//Student s1;
	//Student s2("Ajaya", "Deep", "Sherestha", 1, 100);

	//// i want a const student 
	//const Student s3("Jane", "", "Doe", 123456, 99.99);

	//s2.print();
	//s3.getLast();

	Course comp400("COMP 4300",1); 
	comp400.loadFromFile("students.txt");
	/*comp400.addStudents(s1);
	comp400.addStudents(s2);
	comp400.addStudents(s3);
	comp400.addStudents(Student("Test","test","test",4,11));*/
	comp400.print();
	// s3 in this case is const so you can only call const functions of s3

	return 0;
}
