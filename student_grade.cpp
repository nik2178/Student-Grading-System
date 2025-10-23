#include <iostream>
#include <iomanip>
using namespace std;

struct Subject {
	string subjectName;
	float mark;
	string grade;
	float point;
};

struct Student{
	string name;
	int age;
	Subject subjects[5];
	float cpa;
	int countSub=0;
};

Student studentInput();
Subject subjectInput();
void displayOutput(Student stu);

int main(){
	Student students[10];
	int countStudent=0;
	
	do {
    	cout << "\nEnter number of students: ";
    	cin >> countStudent;
	} while (countStudent>10);
	
	for (int i = 0; i < countStudent; i++) {
		cout << "Enter details for Student " << (i + 1) ;
		students[i]=studentInput();
	}
	
	cout << "----Student Details----";
    for (int i = 0; i < countStudent; i++) {
        displayOutput(students[i]);
    }
	
	return 0;
}

Student studentInput(){
	Student stu;
	int countSub=0;
	float totalPoints = 0;
	
	cout << "\nEnter name: ";
    cin >> stu.name;
    cout << "\nEnter age: ";
    cin >> stu.age;
    
    do {
    	cout << "\nEnter number of subjects: ";
    	cin >> countSub;
	} while (countSub>5);
	
	for (int j = 0; j < countSub; j++) {
		cout << "\nEnter details for Subject " << (j + 1) ;
		stu.subjects[j]=subjectInput();
		totalPoints += stu.subjects[j].point;
	}
	
	stu.cpa = totalPoints / countSub;
	stu.countSub = countSub;
	
	return stu;
}

Subject subjectInput(){
	Subject sub;
	
	cout << "\nEnter subject: ";
    cin >> sub.subjectName;
    
    do {
    	cout << "\nEnter mark: ";
    	cin >> sub.mark;
    	if (sub.mark<0||sub.mark>100){
    		cout << "\nInvalid output! Please enter mark in range of 0-100 only.";
		}
	} while (sub.mark<0||sub.mark>100);
	
	if (sub.mark >= 90){
		sub.grade = "A+";
		sub.point = 4.00;
	}
	else if (sub.mark >= 80){
		sub.grade = "A";
		sub.point = 4.00;
	}
	else if (sub.mark >= 75){
		sub.grade = "A-";
		sub.point = 3.67;
	}
	else if (sub.mark >= 70){
		sub.grade = "B+";
		sub.point = 3.33;
	}
	else if (sub.mark >= 65){
		sub.grade = "B";
		sub.point = 3.00;
	}
	else if (sub.mark >= 60){
		sub.grade = "B-";
		sub.point = 2.67;
	}
	else if (sub.mark >= 55){
		sub.grade = "C+";
		sub.point = 2.33;
	}
	else if (sub.mark >= 50){
		sub.grade = "C";
		sub.point = 2.00;
	}
	else if (sub.mark >= 45){
		sub.grade = "C-";
		sub.point = 1.67;
	}
	else if (sub.mark >= 40){
		sub.grade = "D+";
		sub.point = 1.33;
	}
	else if (sub.mark >= 35){
		sub.grade = "D";
		sub.point = 1.00;
	}
	else if (sub.mark >= 30){
		sub.grade = "D-";
		sub.point = 0.67;
	}
	else{
		sub.grade = "E";
		sub.point = 0.00;
	}
	
	return sub;

}

void displayOutput(Student stu){
	cout << "\nName: " << stu.name;
    cout << "\nAge: " << stu.age;
    
    for (int j = 0; j < stu.countSub; j++) {
        cout << "\nSubject " << (j + 1) << ": "<< stu.subjects[j].subjectName;
        cout << "\nMark: " << stu.subjects[j].mark;
        cout << "\nGrade: " << stu.subjects[j].grade;
        cout << "\nPoint: " << stu.subjects[j].point;
    }
    
    cout << fixed << setprecision(2);
    cout << "\nCPA: " << stu.cpa << endl;
    cout << "\n--------------------------";
    
}