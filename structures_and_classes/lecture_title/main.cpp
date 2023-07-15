#include <string>
using namespace std;

struct Specialization{
    explicit Specialization(string new_value){
        value = new_value;
    }
    string value;
};

struct Course{
    explicit Course(string new_value){
        value = new_value;
    }
    string value;
};

struct Week{
    explicit Week(string new_value){
        value = new_value;
    }
    string value;
};

struct LectureTitle {
  string specialization;
  string course;
  string week;

  LectureTitle(Specialization new_specialization, Course new_course, Week new_week){
    specialization = new_specialization.value;
    course = new_course.value;
    week = new_week.value;
  }
};


int main(){
    LectureTitle title(
        Specialization("C++"),
        Course("White belt"),
        Week("4th")
    );

    return 0;
}