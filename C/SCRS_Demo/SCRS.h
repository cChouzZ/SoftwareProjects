#ifndef SCRSLIB_H
#define SCRSLIB_H

typedef enum {
    unknown, active, inactive
} status_enum;

// note: 
//  used to specify which field_name instead of using a char[]. (Ex. sort)
typedef enum {
    student_id, last_name, student_status
} student_fields_enum;

typedef enum {
    course_id, course_department, course_status 
} course_fields_enum;

typedef enum {
    registration_status 
} registration_fields_enum;

typedef struct {
    status_enum student_status;
    char student_id[10]; // consider length
    char student_first_name[20]; // consider length
    char student_middle_initial[2]; // intentionally a string
    char student_last_name[20]; // consider length
} student_type;

typedef struct { 
    status_enum course_status;
    char course_id[10]; // ex: crn
    char course_semester[10]; // a char code that can be sorted like 202110, 202120,...
    char course_department[4]; // 3 usable char + '\0'    
    unsigned int course_number;
    char course_title[30];
    unsigned int course_hours;        
} course_type;

typedef struct { 
    status_enum registration_status; // active with _grade --> completed, inactive --> incomplete or w
    char registration_student_id[10]; // same as student_type.student_id
    char registration_course_id[10]; // same as course_type.course_id
    unsigned int registration_grade; // 0 to 4;
} registration_type;


#endif	// SCRSLIB_H

