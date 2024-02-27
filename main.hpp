#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

const int N = 5;
struct Student
{
    int id;
    char name[20];
    char major[20];
    Student *next;
};

Student *makeStudent();
void printStudent(Student *head);

Student *makeStudent()
{
  Student *head, *tmp, *prev;
  char tstr[10];
  ifstream ifs;
  ifs.open("students.txt");
  if (!ifs)
  {
    cerr << "Error: file open error" << endl;
    exit(0);
  }
  for(int i=0;i<N;i++)
    {
      tmp = (Student *)malloc(sizeof(Student)); 
      ifs.getline(tstr, 20, ' ');
      tmp->id = atoi(tstr);
      ifs >> tmp->name;
      ifs >> tmp->major;
      tmp->next = NULL;
      if (i==0)
        head = tmp;  
      else
        prev->next = tmp; 
      prev = tmp;
    }
  return head;
}
void printStudent(Student *head)
{
  Student *tmp;
  tmp = head;
  while(tmp != NULL)
    {
        cout << tmp->id << "\t";
        cout << tmp->name << "\t";
        cout << tmp->major << "\n";
        tmp = tmp->next;
    }
}