/**
 * Title: hw3_2.cpp
 * Auther: William Svea-Lochert
 * Abstract: This program is a Course maker wich takes in five students, course title, number, amount of enrolled
 *           students. 
 * ID: 1112
 * Date: 09.19.2018
 * */
#include <iostream>
#include <string>
using namespace std;

struct Student 
{
  string name;
  int ID;
};

class Course
{
    
public:
    Course();
    Course(string titleValue, string instructorNameValue, int courseNumberValue);
    void setTitle(string titleValue);
    void setCourseNumber(int courseNumberValue);
    void setInstructor(string instructorNameValue); 
    string getTitle();
    bool addStudent(string name, int id);
    bool dropStudent(int id);
    void printAll();
    
private:
    string title;
    int courseNumber;
    string instructorName;
    int enrollment;
    string studentName;
    int studentId;
   // bool dup = false;
    Student students[5];
};


int main( )
{
    Course cst238;
    cst238.setTitle("Data Structures");
    cst238.setCourseNumber(238);
    cst238.setInstructor("Dr. Byun");

    cst238.addStudent("Tom",   1000);
	cst238.addStudent("Brian", 2000);
	cst238.addStudent("Alex",  3000);
	cst238.dropStudent(2000);

    cout << "===== Course Report =====" << endl;
	cst238.printAll();

	return 0;
}


Course::Course(): title("UNKNOWN"), instructorName("UNKNOWN"), courseNumber(0), enrollment(0){}


Course::Course(string titleValue, string instructorNameValue, int courseNumberValue)
: title(titleValue), courseNumber(courseNumberValue), instructorName(instructorNameValue), enrollment(0){}

void Course::setTitle(string titleValue)
{
    title = titleValue;
}

void Course::setCourseNumber(int courseNumberValue)
{
    courseNumber = courseNumberValue;
}

void Course::setInstructor(string instructorNameValue)
{
    instructorName = instructorNameValue;
}

string Course::getTitle()
{
    return title;
}

bool Course::addStudent(string name, int id)
{
    for(int i = 0; i < enrollment; i++)
    {
        if (students[i].ID == id)
        {
            cerr << "**student with this ID is alrdy in the course**" << endl << endl;
            return false;
        }
    }
    
    if(id == 0)
    {
        cerr << "ID cant be 0" << endl;
        return false;
    }
    
    else if(enrollment >= 5)
    {
        cout << "course is full" << endl;
        return false;
    }
    
    else
    {
        students[enrollment].name = name;
        students[enrollment].ID = id;
        enrollment++;
        return true;
    }
}




bool Course::dropStudent(int id)
{
    int index = 0;
    if(enrollment == 0)
    {
        cout << "****List is empty****" << endl;
        return false;
    }
    
    
    for(int i = 0; i < enrollment; i++)
    {
        if(students[i].ID == id)
        {
            index = i;
            
        }
    }
        
        if(students[index].ID == id) 
        {
            for(int x = index; x < enrollment+1; x++)
            {
                students[x] = students[x + 1];
            }
            enrollment--;
            return true;
        } 
        cout << endl << "ID:" << id << " is not in the course" << endl << endl;
        return false;
    }
    


void Course::printAll()
{
    cout << "Course Title: " << title << endl << "Course Number: " << courseNumber << endl 
         << "Instructor: " << instructorName << endl << "Enrollment: " << enrollment << endl;
         
    for(int i = 0; i < enrollment; i++)
    {
        if(students[i].ID > 0)
        {
            cout << students[i].name << ": " << students[i].ID << endl;
        }    
    }
}
