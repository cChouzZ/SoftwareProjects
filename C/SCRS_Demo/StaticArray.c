/* 
 * File: StaticArray.c
 * Copy: Copyright (c) 2021 Zachary Chou 
 * BlazerID: zchou
 * Vers: 1.0.0 4/27/2021 ZC - Original Coding
 * Desc: file to complete the project 
 */

/* 
 * File:   StaticArray.c
 * Author: choub
 *
 * Created on April 27, 2021, 12:29 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Core.h"
#include "SCRS.h"
#include "StaticArray.h"

/* Name: import_students 
 * Desc: imports list of students 
 * Args: char filename[] - to read from 
 *       student_type students[] - array to hold information 
 *       int *count - number of valid students in the array
 *       returns - success/failure 
 */
int import_students(char const filename[], student_type students[], int *count) {
    int results;
    FILE *input;
    char line[ line_length_max ];
    char chunks[ chunk_count_max ][ chunk_length_max ];
    int locations[ 1 ];


    results = EXIT_SUCCESS;
    *count = 0;

    if ((filename == NULL) || (string_length(filename) < 5) || (string_find(filename, ".csv", locations) != 1)) {
        printf("Error: Invalid filename!\n");
        results = EXIT_FAILURE;
    } else if (students == NULL) {
        printf("Error: Invalid students array provided!\n");
        results = EXIT_FAILURE;
    } else {
        input = fopen(filename, "r");
        if (input != NULL) {
            // proceed in reading from it...
            while (file_read_line(input, line) > 0) {
                // attempt to parse the line... 
                if (string_split(line, ',', chunks) == 5) {
                    // atoi will return 0 (or unknown) if it is unable to parse chunks[ 0 ]
                    students[ *count ].student_status = atoi(chunks[ 0 ]);
                    // we want to validate chunks[ 1 ], chunks[ 2 ] and chunks[ 4 ]
                    // to have a length greater than 0
                    strcpy(students[ *count ].student_id, chunks[ 1 ]);
                    strcpy(students[ *count ].student_first_name, chunks[ 2 ]);
                    strcpy(students[ *count ].student_middle_initial, chunks[ 3 ]);
                    strcpy(students[ *count ].student_last_name, chunks[ 4 ]);

                    *count = *count + 1;

                } else {
                    printf("Warning: invalid line (%s) in the input file!\n", line);
                }
            }

            fclose(input);
        } else {
            printf("Error: Unable to open %s!\n", filename);
            results = EXIT_FAILURE;
        }
    }

    return ( results);
}

/* Name: display_students
 * Desc: Displays students on the registrant  
 * Args:  student_type const students[] - array of students  
 *       int count - number of students in the array
 *       returns - success/failure 
 *  
 */
int display_students(student_type const students[], int count) {
    int results;
    int index;

    results = EXIT_SUCCESS;

    for (index = 0; index < count; index++) {
        display_student(students[ index ]);

    }

    return ( results);

}

/* Name: examine_students
 * Desc: examine students (takes a closer look at the students array including memory address)  
 * Args: students_type students[] - student array to be examined 
 *       int count - number of students in the array
 */
int examine_students(student_type const students[], int count) {
    // note: for illustrative purposes only
    int index;

    printf("Description                         Value\n");
    printf("===========================================\n");
    printf("address of students:                  %p\n", students);
    for (index = 0; index < count; index++) {
        printf("address of students[ %d ]:                   %p\n", index, &students[ index ]);

        printf("students[ %d ].students_status:                   %d\n", index, students[ index ].student_status);
        printf("students[ %d ].students_id:                       %s\n", index, students[ index ].student_id);
        printf("students[ %d ].students_first_name:               %s\n", index, students[ index ].student_first_name);
        printf("students[ %d ].students_middle_initial:           %s\n", index, students[ index ].student_middle_initial);
        printf("students[ %d ].students_last_name:                %s\n", index, students[ index ].student_last_name);

        printf("address of students[ %d ].students_status:                   %p\n", index, &students[ index ].student_status);
        printf("address of students[ %d ].students_id:                       %p\n", index, &students[ index ].student_id);
        printf("address of students[ %d ].students_first_name:               %p\n", index, &students[ index ].student_first_name);
        printf("address of students[ %d ].students_middle_initial:           %p\n", index, &students[ index ].student_middle_initial);
        printf("address of students[ %d ].students_last_name:                %p\n", index, &students[ index ].student_last_name);

        printf("students[ %d ].students_status (alt):                        %d\n", index, (&students[ index ])->student_status);
        printf("students[ %d ].students_id (alt):                            %s\n", index, (&students[ index ])->student_id);
        printf("students[ %d ].students_first_name (alt):                    %s\n", index, (&students[ index ])->student_first_name);
        printf("students[ %d ].students_middle_initial (alt):                %s\n", index, (&students[ index ])->student_middle_initial);
        printf("students[ %d ].students_last_name (alt):                     %s\n", index, (&students[ index ])->student_last_name);

        printf("\n");


    }
    printf("===========================================\n");
}

/* Name: sort_students 
 * Desc: sorts students  
 * Args: students_type students[] - student array to be sorted 
 *       int count - number of students in the array
 *       student_fields _enum field - the field of students that we wish to sort by 
 *       order_enum order - ascending | descending 
 *       returns- count of moves in the array as the result of sorting 
 */
int sort_students(student_type students[], int count, student_fields_enum field, order_enum order) {
    int results = 0;
    int flag = 1;
    int index;
    int i;
    student_type student_temp;


    results = 0;

    if (field == student_id) {
        if (order == ascending) {
            while (flag > 0) {
                flag = 0;
                for (index = 0; index < count - 1; index++) {

                    if (string_compare(students[i].student_id, students[i + 1].student_id, case_insensitive) < 0) {

                    } else if (string_compare(students[i].student_id, students[i + 1].student_id, case_insensitive) > 0) {

                        copy_student(&student_temp, &students[i]);
                        copy_student(&students[i], &students[i + 1]);
                        copy_student(&students[i + 1], &student_temp);

                        results++;
                        flag = 1;

                    } else {
                    }
                }
            }
        } else if (order == descending) {
            while (flag > 0) {
                flag = 0;
                for (index = 0; index < count - 1; index++) {

                    if (string_compare(students[i].student_id, students[i + 1].student_id, case_insensitive) > 0) {

                    } else if (string_compare(students[i].student_id, students[i + 1].student_id, case_insensitive) < 0) {

                        copy_student(&student_temp, &students[i]);
                        copy_student(&students[i], &students[i + 1]);
                        copy_student(&students[i + 1], &student_temp);

                        results++;
                        flag = 1;

                    } else {
                    }
                }
            }

        } else {
            printf("Error: Unhandled enum!\n");
        }

    } else if (field == last_name) {
        if (order == ascending) {

            while (flag > 0) {
                flag = 0;
                for (index = 0; index < count - 1; index++) {

                    if (string_compare(students[i].student_last_name, students[i + 1].student_last_name, case_insensitive) < 0) {

                    } else if (string_compare(students[i].student_last_name, students[i + 1].student_last_name, case_insensitive) > 0) {

                        copy_student(&student_temp, &students[i]);
                        copy_student(&students[i], &students[i + 1]);
                        copy_student(&students[i + 1], &student_temp);

                        results++;
                        flag = 1;

                    } else {
                    }
                }
            }

        } else if (order == descending) {

            while (flag > 0) {
                flag = 0;
                for (index = 0; index < count - 1; index++) {

                    if (string_compare(students[i].student_last_name, students[i + 1].student_last_name, case_insensitive) > 0) {

                    } else if (string_compare(students[i].student_last_name, students[i + 1].student_last_name, case_insensitive) < 0) {

                        copy_student(&student_temp, &students[i]);
                        copy_student(&students[i], &students[i + 1]);
                        copy_student(&students[i + 1], &student_temp);

                        results++;
                        flag = 1;

                    } else {
                    }
                }
            }

        } else {
            printf("Error: Unhandled enum!\n");
        }

    } else if (field == student_status) {
        if (order == ascending) {

            while (flag > 0) {
                flag = 0;
                for (index = 0; index < count - 1; index++) {

                    if (students[i].student_status < students[i + 1].student_status) {

                    } else if (students[i].student_status > students[i + 1].student_status) {

                        copy_student(&student_temp, &students[i]);
                        copy_student(&students[i], &students[i + 1]);
                        copy_student(&students[i + 1], &student_temp);

                        results++;
                        flag = 1;

                    } else {
                    }
                }
            }

        } else if (order == descending) {

            while (flag > 0) {
                flag = 0;
                for (index = 0; index < count - 1; index++) {

                    if (students[i].student_status > students[i + 1].student_status) {

                    } else if (students[i].student_status < students[i + 1].student_status) {

                        copy_student(&student_temp, &students[i]);
                        copy_student(&students[i], &students[i + 1]);
                        copy_student(&students[i + 1], &student_temp);

                        results++;
                        flag = 1;

                    } else {
                    }
                }
            }

        } else {
            printf("Error: Unhandled enum!\n");
        }

    } else {
        printf("Error: Unhandled enum!\n");
    }

    return ( results);

}

/* Name: export_students
 * Desc: exports students 
 * Args: student_type const students[] - array of students 
 *       int count - number of students in the array 
 *       returns - success/failure  
 */
int export_students(char const filename[], student_type const students[], int count) {
    int results;
    FILE *output;
    int locations[ 2 ];
    int index;


    results = EXIT_SUCCESS;

    if ((filename == NULL) || (string_length(filename) < 5) || (string_find(filename, ".csv", locations) != 1)) {
        printf("Error: Invalid filename provided!\n");
        results = EXIT_FAILURE;
    } else if (students == NULL) {
        printf("Error: Invalid students array provided!\n");
        results = EXIT_FAILURE;
    } else {
        output = fopen(filename, "w");
        if (output != NULL) {
            for (index = 0; index < count; index++) {
                fprintf(output, "%d,%s,%s,%s,%s\n",
                        students[ index ].student_status,
                        students[ index ].student_id,
                        students[ index ].student_first_name,
                        students[ index ].student_middle_initial,
                        students[ index ].student_last_name
                        );


            }




            fclose(output);
        } else {
            printf("Error: Failed to open %s\n", filename);
        }
    }

    return ( results);

}

/* Name: add_student
 * Desc: adds students 
 * Args: student_type students[] - array of current students
 *       int *count - the number of students before/after the update
 *       student_type student - student whose information is to be added to the array
 *       returns - success/failure 
 */
int add_student(student_type students[], int *count, student_type student) {
    int results;
    int index;
    int found;


    index = 0;
    found = 0; // fasle
    results = EXIT_SUCCESS;

    if (string_length(student.student_id) == 0) {
        printf("Error: No valid student.student_id was provided!\n");
        results = EXIT_FAILURE;
    } else {

        while ((index < *count) && (found == 0)) {
            if (string_compare(students[ index ].student_id, student.student_id, case_insensitive) == 0) {
                // we have found a match. 
                found = 1; // true 
                students[ index ].student_status = active; // status_enum
            } else {
                // keep looking
                index++;
            }
        }
        if ((found == 0) && (*count < student_count_max)) {
            // students[ index ].student_status = student.student_status; 
            // field by field copy...
            // consider doing some additional validation on the student
            copy_student(&students[ index ], &student);
            *count = *count + 1;
        }
    }
    return ( results);

}

/* Name: remove_student
 * Desc: removes students 
 * Args: student_type students[] - array of current students
 *       int *count - the number of students before/after the update 
 *       student_type student - student whose information is to be removed/updated  
 *       returns - success/failure 
 */
int remove_student(student_type students[], int *count, student_type student) {
    int results;
    int index;
    int found;

    results = EXIT_SUCCESS;
    index = 0;
    found = 0; // false

    if (string_length(student.student_id) == 0) {
        printf("Error: No valid student.student_id was provided!\n");
        results = EXIT_FAILURE;
    } else {

        while ((index < *count) && (found == 0)) {
            // consider using our compare_student --> compare all relevant field 
            if (string_compare(students[ index ].student_id, student.student_id, case_insensitive) == 0) {
                // we have found a match. 
                students[ index ].student_status = inactive;
                found = 1; // true 
            }
            index++;
        }
    }

    return ( results);

}

/* Name: isa_student  
 * Desc: student id  
 * Args: student_type const students[] - array of students 
 *       int count - number of students in the array 
 *       char const student_id[] - id of the student to search for 
 *       returns - true/false  
 */
int isa_student(student_type const students[], int count, char const student_id[]) {
    //return true or false 
    int results;
    int index;


    results = 0; //false 
    index = 0;

    while ((index < count) && (results == 0)) {
        if (string_compare(students[ index ].student_id, student_id, case_insensitive) == 0) {
            // match was found
            results = 1; // true 
        } else {
            // we keep looking! 
            index++;
        }
    }

    return ( results);

}

/* Name: get_student
 * Desc: gets students  
 * Args: student_type const students[] - array of students
 *       int count - number of students in the array 
 *       char const student_id[] - id of the student to search for 
 *       student_type *student - variable to store the student info in if found  
 *       returns - true/false 
 */
int get_student(student_type const students[], int count, char const student_id[], student_type * student) {
    int results;
    int index;


    results = 0; //false
    index = 0;

    while ((index < count) && (results == 0)) {
        if (string_compare(students[ index ].student_id, student_id, case_insensitive) == 0) {
            // match has been found
            results = 1;

            /*
                        student->student_status = students[ index ].student_status;
                        strcpy(student->student_id, students[ index ].student_id);
                        strcpy(student->student_first_name, students[ index ].student_first_name);
                        strcpy(student->student_middle_initial, students[ index ].student_middle_initial);
                        strcpy(student->student_last_name, students[ index ].student_last_name);
             */
            copy_student(student, &students[ index ]);
        } else {
            // keep looking
        }
        index++;
    }

    return ( results);

}

/* Name: compare_students  
 * Desc: compares students  
 * Args: student_type first_student - first valid student 
 *       student_type second_student - second valid student 
 *       returns - 0 (no difference) or 1 (differences) 
 */
int compare_student(student_type first_student, student_type second_student) {
    int results;

    results = 0; //no difference between the two students 

    if ((first_student.student_status == second_student.student_status) &&
            (string_compare(first_student.student_id, second_student.student_id, case_insensitive) == 0) &&
            (string_compare(first_student.student_first_name, second_student.student_first_name, case_insensitive) == 0) &&
            (string_compare(first_student.student_middle_initial, second_student.student_middle_initial, case_insensitive) == 0) &&
            (string_compare(first_student.student_last_name, second_student.student_last_name, case_insensitive) == 0)
            ) {

        // we have match between the two students...
        results = 0; // no difference
    } else {
        results = 1; // we have no way of tracking what is different
        // could consider is having compare that... 
        // pick the field to compare
        // ordering the results (ex: -1, 0, 1) 
    }


    return ( results);

}

/* Name: copy_student 
 * Desc: copies students  
 * Args: student_type *destination - student to set info 
 *       student_type *source - student to get info from 
 *       returns - success/failure  
 */
int copy_student(student_type *destination, student_type const *source) {
    int results;

    results = EXIT_SUCCESS;

    if (destination == NULL) {
        printf("Error: No valid destination pointer was provided!\n");
        results = EXIT_FAILURE;
    } else if (source == NULL) {
        printf("Error: No valid source pointer was provided!\n");
        results = EXIT_FAILURE;
    } else {
        destination->student_status = source->student_status;
        strcpy(destination->student_id, source->student_id);
        strcpy(destination->student_first_name, source->student_first_name);
        strcpy(destination->student_middle_initial, source->student_middle_initial);
        strcpy(destination->student_last_name, source->student_last_name);

    }

    return ( results);

}

/* Name: display_student  
 * Desc: display students  
 * Args: student_type student - the student to display 
 *       returns - success/failure  
 */
int display_student(student_type student) {
    int results;


    results = EXIT_SUCCESS;

    printf("status:                     %d\n", student.student_status);
    printf("id:                         %s\n", student.student_id);
    printf("first_name:                 %s\n", student.student_first_name);
    printf("middle_initial:             %s\n", student.student_middle_initial);
    printf("last_name:                  %s\n", student.student_last_name);

    return ( results);

}

/*
/* Name: import_courses 
 * Desc: imports list of courses
 * Args: char filename[] - to read from 
 *       course_type courses[] - array to hold information for courses 
 *       int *count - number of valid courses in the array
 *       returns - success/failure 
 */
int import_courses(char const filename[], course_type courses[], int *count) {
    int results;
    FILE *input;
    char line[ line_length_max ];
    char chunks[ chunk_count_max ][ chunk_length_max ];
    int locations[ 1 ];


    results = EXIT_SUCCESS;
    *count = 0;

    if ((filename == NULL) || (string_length(filename) < 7) || (string_find(filename, ".csv", locations) != 1)) {
        printf("Error: Invalid filename!\n");
        results = EXIT_FAILURE;
    } else if (courses == NULL) {
        printf("Error: Invalid courses array provided!\n");
        results = EXIT_FAILURE;
    } else {
        input = fopen(filename, "r");
        if (input != NULL) {
            // proceed in reading from it...
            while (file_read_line(input, line) > 0) {
                // attempt to parse the line... 
                if (string_split(line, ',', chunks) == 7) {
                    // atoi will return 0 (or unknown) if it is unable to parse chunks[ 0 ]
                    courses[ *count ].course_status = atoi(chunks[ 0 ]);
                    // we want to validate chunks[ 1 ], chunks[ 2 ] and chunks[ 4 ]
                    // to have a length greater than 0
                    strcpy(courses[ *count ].course_id, chunks[ 1 ]);
                    strcpy(courses[ *count ].course_semester, chunks[ 2 ]);
                    strcpy(courses[ *count ].course_department, chunks[ 3 ]);
                    courses[ *count ].course_number = atoi(chunks[ 4 ]);
                    strcpy(courses[ *count ].course_title, chunks[ 5 ]);
                    courses[ *count ].course_hours = atoi(chunks[ 6 ]);

                    *count = *count + 1;

                } else {
                    printf("Warning: invalid line (%s) in the input file!\n", line);
                }
            }

            fclose(input);
        } else {
            printf("Error: Unable to open %s!\n", filename);
            results = EXIT_FAILURE;
        }
    }

    return ( results);

}

/* Name: display_courses
 * Desc: Displays courses on the registrant  
 * Args:  course_type const courses[] - array of courses  
 *       int count - number of courses in the array
 *       returns - success/failure 
 *  
 */
int display_courses(course_type const courses[], int count) {
    int results;
    int index;

    results = EXIT_SUCCESS;

    for (index = 0; index < count; index++) {
        display_course(courses[ index ]);

    }

    return ( results);

}

/* Name: examine_courses
 * Desc: examine courses (takes a closer look at the students array including memory address)  
 * Args: courses_type courses[] - course array to be examined 
 *       int count - number of courses in the array
 */
int examine_courses(course_type const courses[], int count) {
    // note: for illustrative purposes only
    int index;

    printf("Description                         Value\n");
    printf("===========================================\n");
    printf("address of courses:                  %p\n", courses);
    for (index = 0; index < count; index++) {
        printf("address of courses[ %d ]:                   %p\n", index, &courses[ index ]);

        printf("courses[ %d ].course_status:                   %d\n", index, courses[ index ].course_status);
        printf("courses[ %d ].course_id:                       %s\n", index, courses[ index ].course_id);
        printf("courses[ %d ].course_semester:                 %s\n", index, courses[ index ].course_semester);
        printf("courses[ %d ].course_department:               %s\n", index, courses[ index ].course_department);
        printf("courses[ %d ].course_number:                   %u\n", index, courses[ index ].course_number);
        printf("courses[ %d ].course_title:                    %s\n", index, courses[ index ].course_title);
        printf("courses[ %d ].course_hours:                    %u\n", index, courses[ index ].course_hours);

        printf("address of courses[ %d ].course_status:                   %p\n", index, &courses[ index ].course_status);
        printf("address of courses[ %d ].course_id:                       %p\n", index, &courses[ index ].course_id);
        printf("address of courses[ %d ].course_semester:                 %p\n", index, &courses[ index ].course_semester);
        printf("address of courses[ %d ].course_department:               %p\n", index, &courses[ index ].course_department);
        printf("address of courses[ %d ].course_number:                   %p\n", index, &courses[ index ].course_number);
        printf("address of courses[ %d ].course_title:                    %p\n", index, &courses[ index ].course_title);
        printf("address of courses[ %d ].course_hours:                    %p\n", index, &courses[ index ].course_hours);


        printf("courses[ %d ].courses_status (alt):                         %d\n", index, (&courses[ index ])->course_status);
        printf("courses[ %d ].courses_id (alt):                             %s\n", index, (&courses[ index ])->course_id);
        printf("courses[ %d ].course_semester (alt):                        %s\n", index, (&courses[ index ])->course_semester);
        printf("courses[ %d ].course_department (alt):                      %s\n", index, (&courses[ index ])->course_department);
        printf("courses[ %d ].course_number (alt):                          %u\n", index, (&courses[ index ])->course_number);
        printf("courses[ %d ].course_title (alt):                           %s\n", index, (&courses[ index ])->course_title);
        printf("courses[ %d ].course_hours (alt):                           %u\n", index, (&courses[ index ])->course_hours);


        printf("\n");


    }
    printf("===========================================\n");
}

/* Name: sort_courses
 * Desc: sorts courses 
 * Args: courses_type courses[] - courses array to be sorted 
 *       int count - number of courses in the array
 *       course_fields _enum field - the field of courses that we wish to sort by 
 *       order_enum order - ascending | descending 
 *       returns- count of moves in the array as the result of sorting 
 */
int sort_courses(course_type courses[], int count, course_fields_enum field, order_enum order) {
    int results = 0;
    int flag = 1;
    int index;
    int i;
    course_type course_temp; 


    results = 0;

    if (field == course_id) {
        if (order == ascending) {
            while (flag > 0) {
                flag = 0;
                for (index = 0; index < count - 1; index++) {

                    if (string_compare(courses[i].course_id, courses[i + 1].course_id, case_insensitive) < 0) {

                    } else if (string_compare(courses[i].course_id, courses[i + 1].course_id, case_insensitive) > 0) {

                        copy_course(&course_temp, &courses[i]);
                        copy_course(&courses[i], &courses[i + 1]);
                        copy_course(&courses[i + 1], &course_temp);

                        results++;
                        flag = 1;

                    } else {
                    }
                }
            }
        } else if (order == descending) {
            while (flag > 0) {
                flag = 0;
                for (index = 0; index < count - 1; index++) {

                    if (string_compare(courses[i].course_id, courses[i + 1].course_id, case_insensitive) > 0) {

                    } else if (string_compare(courses[i].course_id, courses[i + 1].course_id, case_insensitive) < 0) {

                        copy_course(&course_temp, &courses[i]);
                        copy_course(&courses[i], &courses[i + 1]);
                        copy_course(&courses[i + 1], &course_temp);

                        results++;
                        flag = 1;

                    } else {
                    }
                }
            }

        } else {
            printf("Error: Unhandled enum!\n");
        }

    } else if (field == course_department) {
        if (order == ascending) {

            while (flag > 0) {
                flag = 0;
                for (index = 0; index < count - 1; index++) {

                    if (string_compare(courses[i].course_department, courses[i + 1].course_department, case_insensitive) < 0) {

                    } else if (string_compare(courses[i].course_department, courses[i + 1].course_department, case_insensitive) > 0) {

                        copy_course(&course_temp, &courses[i]);
                        copy_course(&courses[i], &courses[i + 1]);
                        copy_course(&courses[i + 1], &course_temp);

                        results++;
                        flag = 1;

                    } else {
                    }
                }
            }

        } else if (order == descending) {

            while (flag > 0) {
                flag = 0;
                for (index = 0; index < count - 1; index++) {

                    if (string_compare(courses[i].course_department, courses[i + 1].course_department, case_insensitive) > 0) {

                    } else if (string_compare(courses[i].course_department, courses[i + 1].course_department, case_insensitive) < 0) {

                        copy_course(&course_temp, &courses[i]);
                        copy_course(&courses[i], &courses[i + 1]);
                        copy_course(&courses[i + 1], &course_temp);

                        results++;
                        flag = 1;

                    } else {
                    }
                }
            }

        } else {
            printf("Error: Unhandled enum!\n");
        }

    } else if (field == course_status) {
        if (order == ascending) {

            while (flag > 0) {
                flag = 0;
                for (index = 0; index < count - 1; index++) {

                    if (courses[i].course_status < courses[i + 1].course_status) {

                    } else if (courses[i].course_status > courses[i + 1].course_status) {

                        copy_course(&course_temp, &courses[i]);
                        copy_course(&courses[i], &courses[i + 1]);
                        copy_course(&courses[i + 1], &course_temp);

                        results++;
                        flag = 1;

                    } else {
                    }
                }
            }

        } else if (order == descending) {

            while (flag > 0) {
                flag = 0;
                for (index = 0; index < count - 1; index++) {

                    if (courses[i].course_status > courses[i + 1].course_status) {

                    } else if (courses[i].course_status < courses[i + 1].course_status) {

                        copy_course(&course_temp, &courses[i]);
                        copy_course(&courses[i], &courses[i + 1]);
                        copy_course(&courses[i + 1], &course_temp);

                        results++;
                        flag = 1;

                    } else {
                    }
                }
            }

        } else {
            printf("Error: Unhandled enum!\n");
        }

    } else {
        printf("Error: Unhandled enum!\n");
    }

    return ( results);

}

/* Name: export_courses
 * Desc: exports courses
 * Args: courses_type const courses[] - array of courses
 *       int count - number of students in the array 
 *       returns - success/failure  
 */
int export_courses(char const filename[], course_type const courses[], int count) {
    int results;
    FILE *output;
    int locations[ 2 ];
    int index;


    results = EXIT_SUCCESS;

    if ((filename == NULL) || (string_length(filename) < 7) || (string_find(filename, ".csv", locations) != 1)) {
        printf("Error: Invalid filename provided!\n");
        results = EXIT_FAILURE;
    } else if (courses == NULL) {
        printf("Error: Invalid courses array provided!\n");
        results = EXIT_FAILURE;
    } else {
        output = fopen(filename, "w");
        if (output != NULL) {
            for (index = 0; index < count; index++) {
                fprintf(output, "%d,%s,%s,%s,%u,&s,%u\n",
                        courses[ index ].course_status,
                        courses[ index ].course_id,
                        courses[ index ].course_semester,
                        courses[ index ].course_department,
                        courses[ index ].course_number,
                        courses[ index ].course_title,
                        courses[ index ].course_hours
                        );


            }




            fclose(output);
        } else {
            printf("Error: Failed to open %s\n", filename);
        }
    }

    return ( results);

}

/* Name: add_course
 * Desc: adds course
 * Args: course_type course[] - array of current course
 *       int *count - the number of course before/after the update
 *      course_type course - course whose information is to be added to the array
 *       returns - success/failure 
 */
int add_course(course_type courses[], int *count, course_type course) {
    int results;
    int index;
    int found;


    index = 0;
    found = 0; // fasle
    results = EXIT_SUCCESS;

    if (string_length(course.course_id) == 0) {
        printf("Error: No valid course.course_id was provided!\n");
        results = EXIT_FAILURE;
    } else {

        while ((index < *count) && (found == 0)) {
            if (string_compare(courses[ index ].course_id, course.course_id, case_insensitive) == 0) {
                // we have found a match. 
                found = 1; // true 
                courses[ index ].course_status = active; // status_enum
            } else {
                // keep looking
                index++;
            }
        }
        if ((found == 0) && (*count < course_count_max)) {
            // courses[ index ].course_status = course.course_status; 
            // field by field copy...
            // consider doing some additional validation on the course
            copy_course(&courses[ index ], &course);
            *count = *count + 1;
        }
    }
    return ( results);

}

/* Name: remove_course
 * Desc: removes course
 * Args: course_type course[] - array of current courses
 *       int *count - the number of courses before/after the update 
 *       course_type course - course whose information is to be removed/updated  
 *       returns - success/failure
 */
int remove_course(course_type courses[], int *count, course_type course) {
    int results;
    int index;
    int found;

    results = EXIT_SUCCESS;
    index = 0;
    found = 0; // false

    if (string_length(course.course_id) == 0) {
        printf("Error: No valid course.course_id was provided!\n");
        results = EXIT_FAILURE;
    } else {

        while ((index < *count) && (found == 0)) {
            // consider using our compare_student --> compare all relevant field 
            if (string_compare(courses[ index ].course_id, course.course_id, case_insensitive) == 0) {
                // we have found a match. 
                courses[ index ].course_status = inactive;
                found = 1; // true 
            }
        }
    }

    return ( results);

}

/* Name: isa_course 
 * Desc: course id  
 * Args: course_type const course[] - array of course
 *       int count - number of course in the array 
 *       char const course_id[] - id of the course to search for 
 *       returns - true/false  
 */
int isa_course(course_type const courses[], int count, char const course_id[]) {
    //return true or false 
    int results;
    int index;


    results = 0; //false 
    index = 0;

    while ((index < count) && (results == 0)) {
        if (string_compare(courses[ index ].course_id, course_id, case_insensitive) == 0) {
            // match was found
            results = 1; // true 
        } else {
            // we keep looking! 
            index++;
        }
    }

    return ( results);

}

/* Name: get_course
 * Desc: gets courses  
 * Args: course_type const course[] - array of courses
 *       int count - number of courses in the array 
 *       char const course_id[] - id of the course to search for 
 *       course_type *course - variable to store the course info in if found  
 *       returns - true/false 
 */
int get_course(course_type const courses[], int count, char const course_id[], course_type * course) {
    int results;
    int index;


    results = 0; //false
    index = 0;

    while ((index < count) && (results == 0)) {
        if (string_compare(courses[ index ].course_id, course_id, case_insensitive) == 0) {
            // match has been found
            results = 1;

            /*
                        student->student_status = students[ index ].student_status;
                        strcpy(student->student_id, students[ index ].student_id);
                        strcpy(student->student_first_name, students[ index ].student_first_name);
                        strcpy(student->student_middle_initial, students[ index ].student_middle_initial);
                        strcpy(student->student_last_name, students[ index ].student_last_name);
             */
            copy_course(course, &courses[ index ]);
        } else {
            // keep looking
        }
        index++;
    }

    return ( results);

}

/* Name: compare_course 
 * Desc: compares courses 
 * Args: course_type first_course - first valid course
 *       course_type second_course - second valid course
 *       returns - 0 (no difference) or 1 (differences) 
 */
int compare_course(course_type first_course, course_type second_course) {
    int results;

    results = 0; //no difference between the two courses 

    if ((first_course.course_status == second_course.course_status) &&
            (string_compare(first_course.course_id, second_course.course_id, case_insensitive) == 0) &&
            (string_compare(first_course.course_semester, second_course.course_semester, case_insensitive) == 0) &&
            (string_compare(first_course.course_department, second_course.course_department, case_insensitive) == 0) &&
            (string_compare(first_course.course_number, second_course.course_number, case_insensitive) == 0) &&
            (string_compare(first_course.course_title, second_course.course_number, case_insensitive) == 0) &&
            (string_compare(first_course.course_hours, second_course.course_number, case_insensitive) == 0)
            ) {

        // we have match between the two courses...
        results = 0; // no difference
    } else {
        results = 1; // we have no way of tracking what is different
        // could consider is having compare that... 
        // pick the field to compare
        // ordering the results (ex: -1, 0, 1) 
    }


    return ( results);

}

/* Name: copy_course
 * Desc: copies course  
 * Args: course_type *destination - course to set info 
 *      course_type *source - course to get info from 
 *       returns - success/failure  
 */
int copy_course(course_type *destination, course_type const *source) {
    int results;

    results = EXIT_SUCCESS;

    if (destination == NULL) {
        printf("Error: No valid destination pointer was provided!\n");
        results = EXIT_FAILURE;
    } else if (source == NULL) {
        printf("Error: No valid source pointer was provided!\n");
        results = EXIT_FAILURE;
    } else {
        destination->course_status = source->course_status;
        strcpy(destination->course_id, source->course_id);
        strcpy(destination->course_semester, source->course_semester);
        strcpy(destination->course_department, source->course_department);
        strcpy(destination->course_number, source->course_number);
        strcpy(destination->course_title, source->course_title);
        strcpy(destination->course_hours, source->course_hours);

    }

    return ( results);

}

/* Name: display_course  
 * Desc: display course  
 * Args: course _type course  - the course to display 
 *       returns - success/failure  
 */
int display_course(course_type course) {
    int results;


    results = EXIT_SUCCESS;

    printf("status:                 %d\n", course.course_status);
    printf("id:                     %s\n", course.course_id);
    printf("semester:               %s\n", course.course_semester);
    printf("department:             %s\n", course.course_department);
    printf("number:                 %u\n", course.course_number);
    printf("title:                  %s\n", course.course_title);
    printf("hours:                  %u\n", course.course_hours);

    return ( results);

}

/* Name: import_registrations
 * Desc: imports list of registrations
 * Args: char filename[] - to read from 
 *       registration_type registrations[] - array to hold information 
 *       int *count - number of valid registrations in the array
 *       returns - success/failure 
 */
int import_registrations(char const filename[], registration_type registrations[], int *count) {
    int results;
    FILE *input;
    char line[ line_length_max ];
    char chunks[ chunk_count_max ][ chunk_length_max ];
    int locations[ 1 ];


    results = EXIT_SUCCESS;
    *count = 0;

    if ((filename == NULL) || (string_length(filename) < 4) || (string_find(filename, ".csv", locations) != 1)) {
        printf("Error: Invalid filename!\n");
        results = EXIT_FAILURE;
    } else if (registrations == NULL) {
        printf("Error: Invalid registrations array provided!\n");
        results = EXIT_FAILURE;
    } else {
        input = fopen(filename, "r");
        if (input != NULL) {
            // proceed in reading from it...
            while (file_read_line(input, line) > 0) {
                // attempt to parse the line... 
                if (string_split(line, ',', chunks) == 4) {
                    // atoi will return 0 (or unknown) if it is unable to parse chunks[ 0 ]
                    registrations[ *count ].registration_status = atoi(chunks[ 0 ]);
                    // we want to validate chunks[ 1 ], chunks[ 2 ] and chunks[ 4 ]
                    // to have a length greater than 0
                    strcpy(registrations[ *count ].registration_student_id, chunks[ 1 ]);
                    strcpy(registrations[ *count ].registration_course_id, chunks[ 2 ]);
                    registrations[ *count ].registration_grade = atoi(chunks[ 3 ]);

                    *count = *count + 1;

                } else {
                    printf("Warning: invalid line (%s) in the input file!\n", line);
                }
            }

            fclose(input);
        } else {
            printf("Error: Unable to open %s!\n", filename);
            results = EXIT_FAILURE;
        }
    }

    return ( results);

}

/* Name: display_registrations
 * Desc: Displays registrations on the registrant  
 * Args:  registrations_type const registrations[] - array of registrations
 *       int count - number of registrations in the array
 *       returns - success/failure 
 *  
 */
int display_registrations(registration_type const registrations[], int count) {
    int results;
    int index;

    results = EXIT_SUCCESS;

    for (index = 0; index < count; index++) {
        display_registration(registrations[ index ]);

    }

    return ( results);

}

/* Name: examine_registrations
 * Desc: examine registrations (takes a closer look at the students array including memory address)  
 * Args: registrations_type registrations[] - course array to be examined 
 *       int count - number of registrations in the array
 */
int examine_registrations(registration_type const registrations[], int count) {
    // note: for illustrative purposes only
    int index;

    printf("Description                         Value\n");
    printf("===========================================\n");
    printf("address of registrations:                  %p\n", registrations);
    for (index = 0; index < count; index++) {
        printf("address of  registrations[ %d ]:                   %p\n", index, &registrations[ index ]);

        printf(" registrations[ %d ].registration_status:                              %d\n", index, registrations[ index ].registration_status);
        printf(" registrations[ %d ].registration_student_id:                          %s\n", index, registrations[ index ].registration_student_id);
        printf(" registrations[ %d ].registration_course_id:                           %s\n", index, registrations[ index ].registration_course_id);
        printf(" registrations[ %d ].registration_grade:                               %u\n", index, registrations[ index ].registration_grade);


        printf("address of  registrations[ %d ].registration_status:                   %p\n", index, &registrations[ index ].registration_status);
        printf("address of  registrations[ %d ].registration_student_id:               %p\n", index, &registrations[ index ].registration_student_id);
        printf("address of  registrations[ %d ].registration_course_id:                %p\n", index, &registrations[ index ].registration_course_id);
        printf("address of  registrations[ %d ].registration_grade:                    %p\n", index, &registrations[ index ].registration_grade);



        printf("registrations[ %d ].registration_status (alt):                        %d\n", index, (&registrations[ index ])->registration_status);
        printf("registrations[ %d ].registration_student_id (alt):                    %s\n", index, (&registrations[ index ])->registration_student_id);
        printf("registrations[ %d ].registration_course_id (alt):                     %s\n", index, (&registrations[ index ])->registration_course_id);
        printf("registrations[ %d ].registration_grade (alt):                         %u\n", index, (&registrations[ index ])->registration_grade);



        printf("\n");


    }
    printf("===========================================\n");
    
    return (EXIT_SUCCESS); 
}


/* Name: sort_registrations
 * Desc: sorts registrations
 * Args: registrations_type registrations[] - registrations array to be sorted 
 *       int count - number of registrations in the array
 *       registrations_fields _enum field - the field of registrations that we wish to sort by 
 *       order_enum order - ascending | descending 
 *       returns- count of moves in the array as the result of sorting 
 */
int sort_registrations(registration_type registrations[], int count, registration_fields_enum field, order_enum order) {
    int results = 0;
    int flag = 1;
    int index;
    int i;
    //student_type student_temp


    results = 0;

    if (field == registration_status) {
        if (order == ascending) {
            while (flag > 0) {
                flag = 0;
                for (index = 0; index < count - 1; index++) {

                    if (registrations[i].registration_status < registrations[ i + 1].registration_status) {

                  //  } else if (string_compare(registration[i].registration_status, registration[i + 1], case_insensitive) > 0) {

/*
                        copy_registration(&registration_temp, &registration[i]);
                        copy_registration(&registrations[i], &registration[i + 1]);
                        copy_registration(&registration[i + 1], &registration_temp);
*/

                        results++;
                        flag = 1;

                    } else {
                    }
                }
            }
        } else if (order == descending) {

        } else {
            printf("Error: Unhandled enum!\n");
        }
    }
    return ( results);


}

/* Name: export_registrations
 * Desc: exports registrations
 * Args: registrations_type const registrations[] - array of registrations
 *       int count - number of registrations in the array 
 *       returns - success/failure  
 */
int export_registrations(char const filename[], registration_type const registrations[], int count) {
    int results;
    FILE *output;
    int locations[ 2 ];
    int index;


    results = EXIT_SUCCESS;

    if ((filename == NULL) || (string_length(filename) < 4) || (string_find(filename, ".csv", locations) != 1)) {
        printf("Error: Invalid filename provided!\n");
        results = EXIT_FAILURE;
    } else if (registrations == NULL) {
        printf("Error: Invalid courses array provided!\n");
        results = EXIT_FAILURE;
    } else {
        output = fopen(filename, "w");
        if (output != NULL) {
            for (index = 0; index < count; index++) {
                fprintf(output, "%d,%s,%s,%u\n",
                        registrations[ index ].registration_status,
                        registrations[ index ].registration_student_id,
                        registrations[ index ].registration_course_id,
                        registrations[ index ].registration_grade
                        );


            }




            fclose(output);
        } else {
            printf("Error: Failed to open %s\n", filename);
        }
    }

    return ( results);

}

/* Name: add_registration
 * Desc: adds registration
 * Args: registration_type registration[] - array of current registration
 *       int *count - the number of registration before/after the update
 *      registration_type registration - registration whose information is to be added to the array
 *       returns - success/failure 
 */
int add_registration(registration_type registrations[], int *count, registration_type registration) {
    int results;
    int index;
    int found;


    index = 0;
    found = 0; // fasle
    results = EXIT_SUCCESS;

    if (string_length(registration.registration_student_id) == 0) {
        printf("Error: No valid registration.registration_student_id was provided!\n");
        results = EXIT_FAILURE;
    } else {

        while ((index < *count) && (found == 0)) {
            if (string_compare(registrations[ index ].registration_student_id, registration.registration_student_id, case_insensitive) == 0) {
                // we have found a match. 
                found = 1; // true 
                registrations[ index ].registration_status = active; // status_enum
            } else {
                // keep looking
                index++;
            }
        }
        if ((found == 0) && (*count < student_count_max)) {
            // students[ index ].student_status = student.student_status; 
            // field by field copy...
            // consider doing some additional validation on the student
            copy_registration(&registrations[ index ], &registration);
            *count = *count + 1;
        }
    }
    return ( results);

}

/* Name: remove_registration
 * Desc: removes registration
 * Args: registration_type registration[] - array of current registrations
 *       int *count - the number of registrations before/after the update 
 *       registration_type registration - registration whose information is to be removed/updated  
 *       returns - success/failure
 */
int remove_registration(registration_type registrations[], int *count, registration_type registration) {
    int results;
    int index;
    int found;

    results = EXIT_SUCCESS;
    index = 0;
    found = 0; // false

    if (string_length(registration.registration_student_id) == 0) {
        printf("Error: No valid registration.registration_student_id was provided!\n");
        results = EXIT_FAILURE;
    } else {

        while ((index < *count) && (found == 0)) {
            // consider using our compare_student --> compare all relevant field 
            if (string_compare(registrations[ index ].registration_student_id, registration.registration_student_id, case_insensitive) == 0) {
                // we have found a match. 
                registrations[ index ].registration_status = inactive;
                found = 1; // true 
            }
        }
    }

    return ( results);

}

/* Name: isa_registration 
 * Desc: registration id  
 * Args: registration_type const registrations[] - array of registration
 *       int count - number of registration in the array 
 *       char const registration_id[] - id of the registration to search for 
 *       returns - true/false  
 */
int isa_registration(registration_type const registrations[], int count, char const registration_student_id[], char const registration_course_id[]) {
   //return true or false 
    int results;
    int index;


    results = 0; //false 
    index = 0;

    while ((index < count) && (results == 0)) {
        if (string_compare(registrations[ index ].registration_student_id, student_id, case_insensitive) && (string_compare(registrations[ index ].registration_course_id, course_id, case_insensitive) == 0)) {
            // match was found
            results = 1; // true 
        } else {
            // we keep looking! 
            index++;
        }
    }

    return ( results);
}

/* Name: get_registration
 * Desc: gets registration 
 * Args: registration_type registration course[] - array of registration
 *       int count - number of registrations in the array 
 *       char const registration_id[] - id of the registration to search for 
 *      registration_type *registration - variable to store the registration info in if found  
 *       returns - true/false 
 */
int get_registration(registration_type const registrations[], int count, char const course_id[], char const student_id) {
    int results;
    int index;


    results = 0; //false
    index = 0;

    while ((index < count) && (results == 0)) {
        if (string_compare(registrations[ index ].registration_student_id, student_id, case_insensitive) == 0) {
            // match has been found
            results = 1;

            /*
                        student->student_status = students[ index ].student_status;
                        strcpy(student->student_id, students[ index ].student_id);
                        strcpy(student->student_first_name, students[ index ].student_first_name);
                        strcpy(student->student_middle_initial, students[ index ].student_middle_initial);
                        strcpy(student->student_last_name, students[ index ].student_last_name);
             */
            copy_registration(registrations, &registrations[ index ]);
        } else {
            // keep looking
        }
        index++;
    }

    return ( results);
}

/* Name: compare_registration
 * Desc: compares registrations 
 * Args: registration_type registration_course - first valid registration
 *       registration_type registration_course - second valid registration
 *       returns - 0 (no difference) or 1 (differences) 
 */
int compare_registration(registration_type first_registration, registration_type second_registration) {
    int results;

    results = 0; //no difference between the two courses 

    if ((first_registration.registration_status == second_registration.registration_status) &&
            (string_compare(first_registration.registration_student_id, second_registration.registration_student_id, case_insensitive) == 0) &&
            (string_compare(first_registration.registration_course_id, second_registration.registration_course_id, case_insensitive) == 0) &&
            (string_compare(first_registration.registration_grade, second_registration.registration_grade, case_insensitive) == 0)

            ) {

        // we have match between the two courses...
        results = 0; // no difference
    } else {
        results = 1; // we have no way of tracking what is different
        // could consider is having compare that... 
        // pick the field to compare
        // ordering the results (ex: -1, 0, 1) 
    }


    return ( results);
}

/* Name: copy_registration
 * Desc: copies registration  
 * Args: registration_type *destination - registration to set info 
 *      registration_type *source - registration to get info from 
 *       returns - success/failure  
 */
int copy_registration(registration_type *destination, registration_type const *source) {
    int results;

    results = EXIT_SUCCESS;

    if (destination == NULL) {
        printf("Error: No valid destination pointer was provided!\n");
        results = EXIT_FAILURE;
    } else if (source == NULL) {
        printf("Error: No valid source pointer was provided!\n");
        results = EXIT_FAILURE;
    } else {
        destination->registration_status = source->registration_status;
        strcpy(destination->registration_student_id, source->registration_student_id);
        strcpy(destination->registration_course_id, source->registration_course_id);
        strcpy(destination->registration_grade, source->registration_grade);
    }
    return ( results);
}

/* Name: display_registration   
 * Desc: display registration  
 * Args: registration  _type registration   - the registration  to display 
 *       returns - success/failure  
 */
int display_registration(registration_type registration) {
    int results;

    results = EXIT_SUCCESS;

    printf("status:                 %d\n", registration.registration_status);
    printf("student_id:             %s\n", registration.registration_student_id);
    printf("course_id:              %s\n", registration.registration_course_id);
    printf("grade:                  %u\n", registration.registration_grade);

    return ( results);
}