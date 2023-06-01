#include "SCRS.h"

#ifndef STATICARRAY_H
#define STATICARRAY_H

#define student_count_max 30
#define course_count_max 30
#define registration_count_max 900 // likely not needed

// student-oriented functions
int import_students(char const filename[], student_type students[], int *count );
int display_students(student_type const students[], int count );
// int examine_students(student_type const students[], int count ); // note: for illustrative purposes only
int sort_students(student_type students[], int count, student_fields_enum field, order_enum order );
int export_students(char const filename[], student_type const students[], int count );

int add_student(student_type students[], int *count, student_type student);
int remove_student(student_type students[], int *count, student_type student);
int isa_student(student_type const students[], int count, char const student_id[]);
int get_student(student_type const students[], int count, char const student_id[], student_type *student);
int compare_student(student_type first_student, student_type second_student);
int copy_student(student_type *destination, student_type const *source);
int display_student(student_type student );

// course-oriented functions
int import_courses(char const filename[], course_type courses[], int *count );
int display_courses(course_type const courses[], int count );
// int examine_courses(course_type const courses[], int count ); // note: for illustrative purposes only
int sort_courses(course_type courses[], int count, course_fields_enum field, order_enum order );
int export_courses(char const filename[], course_type const courses[], int count );

int add_course(course_type courses[], int *count, course_type course);
int remove_course(course_type courses[], int *count, course_type course);
int isa_course(course_type const courses[], int count, char const course_id[]);
int get_course(course_type const courses[], int count, char const course_id[], course_type *course);
int compare_course(course_type first_course, course_type second_course);
int copy_course(course_type *destination, course_type const *source);
int display_course(course_type course );

// registration-oriented functions
int import_registrations(char const filename[], registration_type registrations[], int *count );
int display_registrations(registration_type const registrations[], int count );
// int examine_registrations(registration_type const registrations[], int count ); // note: for illustrative purposes only
int sort_registrations(registration_type registrations[], int count, registration_fields_enum field, order_enum order );
int export_registrations(char const filename[], registration_type const registrations[], int count );

int add_registration(registration_type registrations[], int *count, registration_type registration);
int remove_registration(registration_type registrations[], int *count, registration_type registration);
int isa_registration(registration_type const registrations[], int count, char const registration_student_id[], char const registration_course_id[]);
int get_registration(registration_type const registrations[], int count, char const course_id[], char const student_id);
int compare_registration(registration_type first_registration, registration_type second_registration);
int copy_registration(registration_type *destination, registration_type const *source);
int display_registration(registration_type registration );

// bonus functions
int display_registrations_by_student_id( char const student_id[] );
int get_gpa_by_student_id( char const student_id[], double *gpa );
int display_registrations_by_course_id( char const course_id[] );
int get_mean_by_course_id( char const course_id[], double *mean );

#endif /* STATICARRAY_H */

