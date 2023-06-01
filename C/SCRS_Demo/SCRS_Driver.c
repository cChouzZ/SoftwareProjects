#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SCRS.h"
#include "Core.h"
// will need to choose what type of data structure to use (Static Array) 
#include "StaticArray.h"
//#include "SingleList.h"
//#include "DoubleList.h"


void help(void);

/* 
 * File: SCRS_Driver.c
 * Copy: Copyright (c) 2021 Gregory C. Myers
 * BlazerID: gmyers
 * Vers: 1.0.0 04/19/2021 GCM - Original Coding
 * Desc: Driver for testing concepts 
 */
int main(int argc, char** argv) {
    student_type students[ student_count_max ];
    course_type courses[ course_count_max ];
    registration_type registrations[ registration_count_max];
    student_fields_enum field; 
    char student_id[ 10 ];
    char student_first_name[ 20 ];
    char student_middle_initial[ 2 ];
    char student_last_name[ 20 ];
    student_type student_temp;
    int results_students; 
    int results_courses; 
    char registration_course_id[ 10 ]; 
    course_fields_enum course_field; 
    int index = 0;
    int count = 0;
    int results = 0;
    char course_id[ 10 ];
    char course_semester[ 10 ];
    char course_department[ 4 ];
    unsigned int course_number;
    char course_title[ 30 ];
    unsigned int course_hours;
    course_type course_temp;
    registration_fields_enum registration_field;
    char registration_student_id[ 10 ];
    unsigned int registration_grade[ 3 ];
    registration_type registration_temp;
    order_enum order;

    //argc - count of arguments
    // argv - array of arguments from the command line 
    // indexing is 0-based 

    printf("argc: %d \n", argc);
    for (index = 0; index < argc; index++) {
        printf("argv[ %d ] has the value %s.\n", index, argv[ index ]);
    }

    if (argc == 1) {
        help(); // implicit call for help
    } else if ((strcmpi(argv[ 1 ], "/h") == 0) || (strcmpi(argv[ 1 ], "/?") == 0)) {
        help(); // explicit call for help 
    } else if ((argc >= 3) && (strcmpi(argv[ 1 ], "/student") == 0)) {
        // focus on the student switches...
        if ((argc == 3) && (strcmpi(argv[ 2 ], "/display_all") == 0)) {
            printf("Note: Display all of the students!\n");
            // import the students 
            results = import_students("Students.csv", students, &count);
            printf("results: %d\n", results);
            // display the students
            results = display_students(students, count);
            printf("results: %d\n", results);
            results = export_students(" Students_New.csv", students, count);
        } else if ((argc == 3) && (strcmpi(argv[ 2 ], "/examine_all") == 0)) {
            printf("Note: Display all of the students!\n");
            // import the students 
            results = import_students("Students.csv", students, &count);
            printf("results: %d\n", results);
            // display the students
            results = examine_students(students, count);
            printf("results: %d\n", results);
        } else if ((argc == 4) && (strcmpi(argv[ 2 ], "/display") == 0)) {
            printf("Note: Display information for %s\n", argv[ 3 ]);
            strcpy(student_id, argv[ 3 ]); 
            //import the students 
            results = import_students("Students.csv", students, &count);
            printf("results: %d\n", results);
            // search for the given student --> success 
            results = get_student(students, count, student_id, &student_temp ); 
            
            if ( results == 1 ) { 
                //display that student
                results = display_student(student_temp); 
            }
        } else if ((argc == 4) && (strcmpi(argv[ 2 ], "/isa") == 0)) {
            printf("Note: Verify that the information exists %s\n", argv[ 3 ]);
            results = import_students("Students.csv", students, &count); 
            
            results = isa_student(students, count, argv[ 3 ]); 
            printf("results: %d\n", results ); 
            if ( results == 1 ) { 
                printf("Student found: True\n"); 
            } else { 
                printf("Student found: False\n"); 
            }
        } else if ((argc == 7) && (strcmpi(argv[ 2 ], "/add") == 0)) {
            printf("Note: Adding a student with id %s\n", argv[ 3 ]);
            strcpy(student_id, argv[ 3 ]);
            strcpy(student_first_name, argv[ 4 ]);
            student_middle_initial[ 0 ] = argv[ 5 ][ 0 ];
            student_middle_initial[ 1 ] = '\0'; // EOS 
            strcpy(student_last_name, argv[ 6 ]);

            // import the existing students
            results = import_students("Students.csv", students, &count);
            printf("results: %d\n", results);
            // attempt to add the student --> temp_student. 
            student_temp.student_status = active;
            strcpy(student_temp.student_id, student_id);
            strcpy(student_temp.student_first_name, student_first_name);
            strcpy(student_temp.student_middle_initial, student_middle_initial);
            strcpy(student_temp.student_last_name, student_last_name);
            results = add_student(students, &count, student_temp);
            printf("results: %d\n", results);

            // export out array 
            //results = export_students("Students_New.csv", students, count);
            results = export_students("Students.csv", students, count);
            printf("results: %d\n", results);




        } else if ((argc == 4) && (strcmpi(argv[ 2 ], "/remove") == 0)) {
            printf("Note: Remove a student with id %s\n", argv[ 3 ]);
            strcpy(student_id, argv[ 3 ]);
            // import all of out students
            results = import_students(" Students.csv", students, &count);
            printf("results: %d\n", results);
           
            // find a match for out student_id
            results = get_student(students, count, student_id, &student_temp);
            printf("results: %d\n", results);
            if (results == 1) {
                // attempt to remove that student (after retrieving the student using the student_id) 
                results = remove_student(students, &count, student_temp);
                printf("results: %d\n", results);

                // export students Student_New.csv --> students.csv 
                results = export_students("Students_New.csv", students, count);
                printf("results: %d\n", results);

            }





        } else if ((argc == 5) && (strcmpi(argv[ 2 ], "/sort") == 0)) {
            printf("Note: Sort the students with %s %s\n", argv[ 3 ], argv[ 4 ]);
            if ( 0 == strcmpi("student_id", argv[ 3 ])) { 
               printf("student_id: %s\n", student_id);    
            } else if ( 0 == strcmpi("last_name", argv[ 3 ])) { 
                 printf("last_name: %d\n", last_name); 
            } else if ( 0 == strcmpi("student_status", argv[ 3 ])) { 
                field = student_status; 
            }
            if ( 0 == strcmpi("ascending", argv[ 4 ])) { 
                order = ascending; 
            } else if ( 0 == strcmpi("descending", argv[ 4 ])) { 
                order = descending; 
            }
            results = import_students("Students.csv", students, &count ); 
            sort_students(students, count, field, order ); 
            export_students ("Students.csv", students, count); 
        } else {
            help(); // implicit call for help
        }
    } else if ((argc >= 3) && (strcmpi(argv[ 1 ], "/course") == 0)) {
        // focus on the course switches...
        if ((argc == 3) && (strcmpi(argv[ 2 ], "/display_all") == 0)) {
            printf("Note: Display all of the courses!\n");
            // import the courses    
            results = import_courses("Courses.csv", courses, &count);
            printf("results: %d\n", results);
            // display the courses
            results = display_courses(courses, count);
            printf("results: %d\n", results);
            results = export_courses(" Courses_New.csv", courses, count);
        } else if ((argc == 3) && (strcmpi(argv[ 2 ], "/examine_all") == 0)) {
            printf("Note: Display all of the courses!\n");
            // import the courses
            results = import_courses("Courses.csv", courses, &count);
            printf("results: %d\n", results);
            // display the courses
            results = examine_courses(courses, count);
            printf("results: %d\n", results);
        } else if ((argc == 4) && (strcmpi(argv[ 2 ], "/display") == 0)) {
            printf("Note: Display information for %s\n", argv[ 3 ]);
            strcpy(course_id, argv[ 3 ]); 
            results = import_courses("Courses.csv", courses, &count); 
            printf("results: %d\n", results); 
            results = get_course(courses, count, course_id, &course_temp); 
            printf("results: %d\n", results); 
            if ( results == 1 ) { 
                results = display_course(course_temp); 
            }
        } else if ((argc == 4) && (strcmpi(argv[ 2 ], "/isa") == 0)) {
            printf("Note: Verify that the information exists %s\n", argv[ 3 ]);
            strcpy(course_id, argv[ 3 ]); 
            results = import_courses("Courses.csv", courses, &count); 
            results = isa_course(courses, count, course_id); 
            if (results == 1 ) { 
                printf("true, course exist\n"); 
            } else { 
                printf("false, course does not exist\n"); 
            }
        } else if ((argc == 9) && (strcmpi(argv[ 2 ], "/add") == 0)) {
            printf("Note: Adding a course with id %s\n", argv[ 3 ]);
            strcpy(course_id, argv[ 3 ]);
            strcpy(course_semester, argv[ 4 ]);
            strcpy(course_department, argv[ 5 ]);
            course_number = atoi(argv[ 6 ]); 
            strcpy(course_title, argv[ 7 ]);
            course_hours = atoi(argv[ 8 ]); 

            // import the existing courses
            import_courses("Courses.csv", courses, &count);
            printf("results: %d\n", results);
            // attempt to add the course --> temp_course. 
            course_temp.course_status = active;
            strcpy(course_temp.course_id, course_id);
            strcpy(course_temp.course_department, course_department);
            course_temp.course_number = course_number; 
            strcpy(course_temp.course_title, course_title);
            course_temp.course_hours = course_hours;
            results = add_course(courses, &count, course_temp);
            printf("results: %d\n", results);

            // export out array 
            results = export_courses("Courses_New.csv", courses, count);
            // results = export_students("Courses.csv", courses, count);
            printf("results: %d\n", results);
        } else if ((argc == 4) && (strcmpi(argv[ 2 ], "/remove") == 0)) {
            printf("Note: Remove a course with id %s\n", argv[ 3 ]);
            strcpy(course_id, argv[ 3 ]);
            // import all of out students
            results = import_courses(" Courses.csv", courses, &count);
            printf("results: %d\n", results);

            // find a match for out course_id
            results = get_course(courses, count, course_id, &course_temp);
            printf("results: %d\n", results);
            if (results == 1) {
                // attempt to remove that course (after retrieving the course using the course_id) 
                results = remove_course(courses, &count, course_temp);
                printf("results: %d\n", results);

                // export courses Course_New.csv --> courses.csv 
                results = export_courses("Course_New.csv", courses, count);
                printf("results: %d\n", results);
            }
        } else if ((argc == 5) && (strcmpi(argv[ 2 ], "/sort") == 0)) {
            printf("Note: Sort the course swith %s %s\n", argv[ 3 ], argv[ 4 ]);
            if ( 0 == strcmpi("course_id", argv [ 3 ])) { 
                printf("course_id: %s\n", course_id);    
            } else if ( 0 == strcmpi("course_department", argv [ 3 ])) { 
                printf("course_department: %s\n", course_department);  
            } else if ( 0 == strcmpi("course_status", argv[ 3 ])) { 
                course_field = course_status; 
            }
            if ( 0 == strcmpi("ascending", argv[ 4 ])) { 
                order = ascending; 
            } else if ( 0 == strcmpi("descending", argv[ 4 ])) { 
                order = descending; 
            }
            results = import_courses("Courses.csv", courses, &count); 
            sort_courses(courses, count, course_field, order); 
            export_courses("Courses_New.csv", courses, &count); 
        } else {
            help(); // implicit call for help
        }
    } else if ((argc >= 3) && (strcmpi(argv[ 1 ], "/registration") == 0)) {
        // focus on the registration switches... 
        if ((argc == 3) && (strcmpi(argv[ 2 ], "/display_all") == 0)) {
            printf("Note: Display all of the registrations!\n");
            // import the registrations
            results = import_registrations("Registrations.csv", registrations, &count);
            printf("results: %d\n", results);
            // display the registrations
            results = display_registrations(registrations, count);
            printf("results: %d\n", results);
            results = export_registrations(" Registration_New.csv", registrations, count);
        } else if ((argc == 3) && (strcmpi(argv[ 2 ], "/examine_all") == 0)) {
            printf("Note: Display all of the registrations!\n");
            // import the registrations
            results = import_registrations("Registrations.csv", registrations, &count);
            printf("results: %d\n", results);
            // display the registrations
            results = examine_registrations(registrations, count);
            printf("results: %d\n", results);
        } else if ((argc == 5) && (strcmpi(argv[ 2 ], "/display") == 0)) {
            printf("Note: Display information for %s %s\n", argv[ 3 ], argv[ 4 ]);
            //strcpy(registration_student_id, argv [ 3 ]); 
            //strcpy(registration_course_id, argv [ 4 ]); 
            results = import_registrations("Registrations.csv", registrations, &count); 
            printf("results: %d\n", results); 
            results = get_registration(registrations, count, course_id, student_id); 
            printf("results: %d\n", results); 
            
            if ( results == 1 ) { 
                display_registration(registration_temp); 
                printf("results: %d\n", results); 
            }
            
        } else if ((argc == 5) && (strcmpi(argv[ 2 ], "/isa") == 0)) {
            printf("Note: Verify that the information exists %s %s\n", argv[ 3 ], argv[ 4 ]);
            results = import_registrations("Registrations.csv", registrations, &count); 
            printf("result: %d\n", results); 
            results = isa_registration( registrations, count, argv[ 3 ], argv[ 4 ]); 
            printf("results: %d\n", results); 
            if ( results == 1 ) { 
                printf("registrations found: True\n"); 
            } else { 
                printf("registration found: False\n"); 
            }
        } else if ((argc == 6) && (strcmpi(argv[ 2 ], "/add") == 0)) {
            printf("Note: Adding a registration with id %s %s\n", argv[ 3 ], argv[ 4 ]);
            strcpy(registration_temp.registration_student_id, argv[ 3 ]);
            strcpy(registration_temp.registration_course_id, argv[ 4 ]);
            registration_temp.registration_grade = atoi( argv[ 5 ] ); 


            // import the existing registrations
            import_registrations("Registration.csv", registrations, &count);
            printf("results: %d\n", results);
            // attempt to add the registration --> temp_registration. 
            registration_temp.registration_status = active;
            strcpy(registration_temp.registration_student_id, registration_student_id);
            strcpy(registration_temp.registration_course_id, registration_course_id);
            strcpy(registration_temp.registration_grade, registration_grade);

            results = add_registration(registrations, &count, registration_temp);
            printf("results: %d\n", results);

            // export out array 
            results = export_registrations("Registration_New.csv", registrations, count);
            // results = export_registrations("Registrations.csv", registrations, count);
            printf("results: %d\n", results);
        } else if ((argc == 6) && (strcmpi(argv[ 2 ], "/change_grade") == 0)) {
                printf("Note: Change the student grade using registration %s %s %s\n", argv[ 3 ], argv[ 4 ], argv[ 5 ]);
        } else if ((argc == 5) && (strcmpi(argv[ 2 ], "/remove") == 0)) {
            printf("Note: Remove a registration with id %s %s\n", argv[ 3 ], argv[ 4 ]); 
            strcpy(registration_student_id, argv[ 3 ]);
            strcpy(registration_course_id, argv [ 4 ]); 
            // import all of out registration
            results = import_registrations(" Registrations.csv", registrations, &count);
            printf("results: %d\n", results);

            // find a match for out registration_student_id
            results = get_registration(registrations, count, registration_student_id, &registration_temp);
            printf("results: %d\n", results);
            if (results == 1) {
                // attempt to remove that registration (after retrieving the course using the registration_student_id) 
                results = remove_registration(registrations, &count, registration_temp);
                printf("results: %d\n", results);
            }

                // export students Registration_New.csv --> registrations.csv 
                results = export_registrations("Registration_New.csv", registrations, count);
             printf("results: %d\n", results);

        } else if ((argc == 5) && (strcmpi(argv[ 2 ], "/sort") == 0)) {
            printf("Note: Sort the registrations with %s %s\n", argv[ 3 ], argv[ 4 ]);
            if ( 0 == strcmpi("registration_status", argv [ 3 ])) { 
                registration_field = registration_status; 
                
                if ( 0 == strcmpi("ascending", argv[ 4 ])) { 
                    order = ascending; 
                } else if ( 0 == strcmpi("descending", argv[ 4 ])) { 
                    order = descending; 
                }
            }
            results = import_registrations("Registrations.csv", registrations, &count); 
            sort_registrations(registrations, count, registration_field, order);
            export_registrations("Registrations_New.csv", registrations, count); 
        } else {
            help(); // implicit call for help
        }


    } else {
        help(); // implicit call for help 
    }




    return (EXIT_SUCCESS);
}

    void help(void) {
        printf("Usage:\n");
        printf("            scrs_demo.exe   /h                                                                             ...calls help\n");
        printf("           scrs_demo.exe   /student /display_all                                                            ...displays all students\n");
        printf("           scrs_demo.exe   /student /examine_all                                                           ...examine all\n");
        printf("           scrs_demo.exe   /student /display <student_id>                                                    ...display a single student\n");
        printf("           scrs_demo.exe   /student /isa <student_id>                                                        ...returns true/false\n");
        printf("           scrs_demo.exe   /student /add <student_id> <firstname> <middle_initial> <lastname>                ...adds a student\n");
        printf("           scrs_demo.exe   /student /remove <student_id>                                                     ...removes a student\n");
        printf("           scrs_demo.exe   /student /sort <field> <order>                                                    ...sort students\n");
        printf("           scrs_demo.exe   /course /display_all                                                             ...displays all courses \n");
        printf("           scrs_demo.exe   /course /examine_all                                                           ...examine all\n");
        printf("           scrs_demo.exe   /course /display  <course_id>                                                    ...display a single course\n");
        printf("           scrs_demo.exe    /course /isa <course_id>                                                         ...returns true/false\n");
        printf("           scrs_demo.exe   /course /add <course_id> <semester> <department> <number> <title> <hours>          ...adds a course\n");
        printf("           scrs_demo.exe   /course /remove <course_id>                                                         ...removes a course\n");
        printf("           scrs_demo.exe   /course /sort <field> <order>                                                     ...sort courses\n");
        printf("           scrs_demo.exe   /registration /display_all                                                        ...displays all registrations\n");
        printf("           scrs_demo.exe   /registration /examine_all                                                           ...examine all\n");
        printf("           scrs_demo.exe   /registration /display <course_id> <student_id>                                ...display a single registration\n");
        printf("           scrs_demo.exe    /registration /isa <course_id> <student_id>                                 ...returns true/false\n");
        printf("           scrs_demo.exe   /registration /add <course_id> <student_id>                                    ...adds a registration\n");
        printf("           scrs_demo.exe   /registration /change_grade <course_id> <student_id> <grade>                  ...updates the grade for a registration\n");
        printf("           scrs_demo.exe   /registration /remove <course_id> <student_id>                              ...removes a registration\n");
        printf("           scrs_demo.exe   /registration /sort <field> <order>                                          ...sort registration\n");

    }

