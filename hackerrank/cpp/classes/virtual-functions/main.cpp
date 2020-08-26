#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{
    public:
        virtual void getdata(){
            cin >> name >> age;
        }

        virtual void putdata(){
            cout << name << " " << age << " ";
        }

    private:
        string name;
        int age;
};

// The class Professor should have two integer members: publications and cur_id. 
// There will be two member functions: getdata and putdata. 
// The function getdata should get the input from the user: the name, age and publications of the professor. 
// The function putdata should print the name, age, publications and the cur_id of the professor.
class Professor : public Person{
    public:
        Professor(){
            id=++cur_id;
        }   
       void getdata(){
            Person::getdata();
            cin >> publications;
        }

        void putdata(){
            Person::putdata();
            cout << publications << " " << id << "\n";
        }

    private:
        static int cur_id;
        int publications, id;
};

int Professor::cur_id=0;

// The class Student should have two data members: marks, which is an array of size 6 and cur_id. 
// It has two member functions: getdata and putdata. 
// The function getdata should get the input from the user: the name, age, and the marks of the student in 6 subjects. 
// The function putdata should print the name, age, sum of the marks and the cur_id of the student.
class Student : public Person{
    public:
        Student(){
            id=++cur_id;
        }
        void getdata(){
            Person::getdata();
            int s;
            for(int i=0;i<6;i++) {
                cin >> s;
                marks.push_back(s);
            }
        }

        void putdata(){
            int sum=0;
            Person::putdata();
            for(int i=0;i<6;i++){
                sum+=marks[i];
            }
            cout << sum << " " << id << "\n";
        }
    private:   
        vector<int> marks;
        static int cur_id;
        int id;
};

int Student::cur_id=0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
