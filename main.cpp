// Grade Analysis program in modern C++.


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>


using namespace std;


class Course
{
private:
	
	//Dept,Number,Title,A,B,C,D,F,I,NR,S,U,W,Instructor
	
	string dept;
	int number;
	string title;
	int a;
	int b;
	int c;
	int d;
	int f;
	int i;
	int nr;
	int s;
	int u;
	int w;
	string instructor;

public:

	//constructor
	Course(string dept1,
	int number1,
	string title1,
	int a1,
	int b1,
	int c1,
	int d1,
	int f1,
	int i1,
	int nr1,
	int s1,
	int u1,
	int w1,
	string instructor1)
	{
		dept = dept1;
		number = number1;
		a = a1;
		b = b1;
		c = c1;
		d = d1;
		f = f1;
		i = i1;
		nr = nr1;
		s = s1;
		u = u1;
		w = w1;
		instructor = instructor1;
	}

	int getNumStudents() {
		int total = a + b + c + d + f;
		return total;
	}

	int getAllStudents() {
		return a + b + c + d + f + i + nr + s + u + w;
	}

	double getPercentDFW() {
		double totalDFW = d + f + w;
		double total = a + b + c + d + f + w;
		if (total == 0) {
			return 100;
		}
		return (totalDFW / total) * 100;
	}

	int numberOfS() { return s; }
	
	int numberOfA() {return a;}

	int numberOfB() {return b;}

	int numberOfC() {return c;}

	int numberOfD() {return d;}

	int numberOfF() {return f;}

	int numberOfW() {return w;}

	string getDepartment() { return dept; }

	int getNumber() { return number; }

	string getInstructor() { return instructor; }


};

//builds the course objects and does most of the file stuff
vector<Course> buildCourses(ifstream& file) {
	
	string line;
	string dept;
	string number;
	string title;
	string a;
	string b;
	string c;
	string d;
	string f;
	string i;
	string nr;
	string s;
	string u;
	string w;
	string instructor;
	vector<Course> courses;

	getline(file, line);


	while (getline(file, line)) {
		stringstream ss(line);
		getline(ss, dept, ',');
		getline(ss, number, ',');
		getline(ss, title, ',');
		getline(ss, a, ',');
		getline(ss, b, ',');
		getline(ss, c, ',');
		getline(ss, d, ',');
		getline(ss, f, ',');
		getline(ss, i, ',');
		getline(ss, nr, ',');
		getline(ss, s, ',');
		getline(ss, u, ',');
		getline(ss, w, ',');
		getline(ss, instructor, ',');

		Course co(dept, stoi(number), title, stoi(a), stoi(b), stoi(c), stoi(d),
			stoi(f), stoi(i), stoi(nr), stoi(s), stoi(u), stoi(w), instructor);

		courses.push_back(co);

	}

	return courses;
}

//does part 1 (analysis for entire COE)
void doPart1(vector<Course> courses, string title) {
	double totalCourses = 0;
	double totalGrades = 0;
	double totalA = 0;
	double totalB = 0;
	double totalC = 0;
	double totalD = 0;
	double totalF = 0;

	for (Course& c : courses) {
		totalCourses++;
		totalGrades += c.getNumStudents();
		totalA += c.numberOfA();
		totalB += c.numberOfB();
		totalC += c.numberOfC();
		totalD += c.numberOfD();
		totalF += c.numberOfF();
	}

	double percentA = (totalA / totalGrades) * 100;
	double percentB = (totalB / totalGrades) * 100;
	double percentC = (totalC / totalGrades) * 100;
	double percentD = (totalD / totalGrades) * 100;
	double percentF = (totalF / totalGrades) * 100;

	cout << std::fixed;
	
	//no decimal points
	cout << std::setprecision(0);
	cout << title << endl;
	cout << "  Num courses:  " << totalCourses << endl;
	cout << "  Num grades:   " << totalGrades << endl;
	//2 decimal places
	cout << std::setprecision(2);
	cout << "  Distribution: " << percentA << "%, " << percentB << "%, " << percentC << "%, " << percentD << "%, " << percentF << "%" << endl;
}

//does part 2 (analysis by department)
void doPart2(vector<Course> courses) {
	double depCourses = 0;
	double depGrades = 0;
	double depA = 0;
	double depB = 0;
	double depC = 0;
	double depD = 0;
	double depF = 0;

	vector<string> departments;

	//get departments
	for (Course& c : courses) {
		if (!(find(departments.begin(), departments.end(), c.getDepartment()) != departments.end())) {
			departments.push_back(c.getDepartment());

		}
	}

	cout << endl;

	for (string& dep: departments) {
		vector<Course> matchingDep;
		vector<Course>::iterator iter = courses.begin();
		while ((iter = find_if(iter,courses.end(), [=](Course& c) {
			if (c.getDepartment() == dep) {
				return true;
			}
			else {
				return false;
			}
		}))!= courses.end()) {

			matchingDep.push_back(*iter);
			iter++;
		}
		string title = dep + ":";
		doPart1(matchingDep, title);
		
}
	
}

//does part 3 (analysis by professor)
void part3Calculator(vector<Course> courses) {
	
	

	for (Course& c : courses) {
		
		double percentA = 0;
		double percentB = 0;
		double percentC = 0;
		double percentD = 0;
		double percentF = 0;

		double totalStudents = c.getNumStudents();
		if (totalStudents > 0) {
			percentA = (c.numberOfA() / totalStudents) * 100;
			percentB = (c.numberOfB() / totalStudents) * 100;
			percentC = (c.numberOfC() / totalStudents) * 100;
			percentD = (c.numberOfD() / totalStudents) * 100;
			percentF = (c.numberOfF() / totalStudents) * 100;

		}

			cout << std::fixed;

			//no decimal points
			cout << std::setprecision(0);
			cout << c.getDepartment()<< " " << c.getNumber() << " (" << c.getInstructor() << "):" << endl;
			cout << "  Num students: " << c.getAllStudents() << endl;
			//2 decimal places
			cout << std::setprecision(2);
			
			if (totalStudents > 0) {
				cout << "  Distribution: " << percentA << "%, " << percentB << "%, " << percentC << "%, " << percentD << "%, " << percentF << "%" << endl;
				cout << "  DFW rate: " << c.getPercentDFW() << "%"<< endl;
			}
			else {
				cout << "  Distribution: no report" << endl;
				if ((c.numberOfS()) > 0) {
					cout << "  DFW rate: 0.00%" << endl;
				}
				else {
					cout << "  DFW rate: 100.00%" << endl;
				}
			}


			
		
	}
}

void doPart3(vector<Course> courses) {

	string name;
	while (name != "#") {
		cout << endl;
		cout << "Please enter instructor's name (or prefix or #)> ";
		cin >> name;
		if (name == "#") {
			break;
		}
		cout << endl;

		vector<string> professor;

		vector<Course> matchingProf;

		vector<Course>::iterator iter = courses.begin();
		while ((iter = find_if(iter, courses.end(), [=](Course& c) {
			string instructor = c.getInstructor();
			auto res = mismatch(name.begin(), name.end(), instructor.begin());
			if(res.first == name.end()){
				return true;
			}
			else {
				return false;
			}
		})) != courses.end()) {

			matchingProf.push_back(*iter);
			iter++;
		}
		part3Calculator(matchingProf);

	}
}





int main()
{
	
	string filename;

  cin >> filename;
  //cout << filename << endl;
  

  //ifstream file("C:/Users/uzair/source/repos/cs341Proj1/Debug/fall-2017.csv");
  ifstream file(filename);

  if (!file.good()) {
	  cout << "cannot  open  file!" << endl;
	 return  -1;
  }

  vector<Course> courses = buildCourses(file);

  cout << filename <<endl;
  cout << endl;
  doPart1(courses, "College of Engineering:");
  doPart2(courses);
  doPart3(courses);
  

  //
  // done:
  //
  cout << endl;
  return 0;
}


