#include "Student.h"

class Windows{

  public:
    Windows(int count);
    bool windowIsEmpty(int window);
    bool windowsFull();
    void addStudent(Student s);
    void removeStudents();
    int getSize();

  private:
    Student *windowArray;
    int *idleTimes;
    int size;

}
