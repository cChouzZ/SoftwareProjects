/*
 *  File: Core.c
 *  Copy: Copyright (c) 2021 Zachary Chou 
 *  BlazerID: zchou
 *   
 *  Vers: 1.0.0 4/23/2021 ZC - Original Coding 
 *  Decs: Driver for testing concepts in Physics_demo 
 */

/* 
 * File:   Core.c
 * Author: choub
 *
 * Created on April 23, 2021, 10:18 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Core.h"

/* Name: file_read
 * Desc: How to read a file 
 *
 */
int file_read(char file_name [], char contents[]) {

    FILE *input;
    int count;
    char chunk;

    count = 0;
    input = fopen(file_name, "r");
    if (input != NULL) {
        while ((fscanf(input, "%c", &chunk) != EOF) && (count < chunk_length_max - 1)) {
            contents[ count ] = chunk;
            count++;
        }
        fclose(input);
    } else {
        printf(" Error: file does not exist!\n");
    }
    contents[ count ] = '\0';
    return ( count);
}

/* Name: file_read_line
 * Desc: How to read a file line by line  
 *
 */
int file_read_line(FILE *input, char line[]) {
    char chunk;
    int count;
    
    count = 0; 


    if (input != NULL) {
        while ((fscanf(input, "%c", &chunk) != EOF) && (chunk != '\n') && (count < chunk_length_max - 1)) {
            line[ count ] = chunk;
            count++;
        }

    } else {
        printf("Error: invalid file pointer!\n");
    }
    line[ count ] = '\0';
    return ( count);
}

/* Name: string_length
 * Desc: Determine string length    
 *
 */
int string_length(char const source[]) {
    int results;

    results = 0;
    while (source[ results ] != '\0') {
        results++;

    }

    return ( results);
}

/* Name: string_upper
 * Desc: Convert a string to upper case   
 *
 */
int string_upper(char destination[], char const source[]) {
    int results;
    int index;

    index = 0;
    results = 0;

    while (source[ index ] != '\0') {
        if ((source[ index ] >= 97) && (source[ index ] <= 122)) {
            destination[ index ] = source[ index ] - 32;
            results++;
        } else {
            destination[ index ] = source[ index ];
        }
        index++;
    }
    destination[ index ] = '\0';
    return ( results);

}

/* Name: string_lower
 * Desc: Convert a string to lower case   
 *
 */
int string_lower(char destination[], char const source[]) {
    int results;
    int index;


    index = 0;
    results = 0;

    while (source[ index ] != '\0') {
        if ((source[ index ] >= 65) && (source[ index ] <= 90)) {
            destination[ index ] = source[ index ] + 32;
            results++;
        } else {
            destination[ index ] = source[ index ];
        }
        index++;
    }
    destination[ index ] = '\0';
    return ( results);

}

/* Name: string_compare
 * Desc: Compares strings to one another
 */
int string_compare(char const first[], char const second[], case_sensitivity_enum sensitivity) {
    // first, second must be strings
    int first_length;
    int second_length;
    int shortest_length;
    int index;
    int results;
    char first_char;
    char second_char;

    first_length = string_length(first);
    second_length = string_length(second);
    index = 0;
    results = 0;

    if (first_length < second_length) {
        shortest_length = first_length;
    } else {
        shortest_length = second_length;
    }

    if (sensitivity == case_sensitive) {
        while ((index < shortest_length) && (results == 0)) {
            if (first[ index ] < second[ index ]) {
                results = -1; // first comes before the second 
            } else if (first[ index ] > second[ index ]) {
                results = 1; // first comes after the second
            } else {
                results = 0; // keep on matching...
            }
        }
        index++;

    } else if (sensitivity == case_insensitive) {
        while ((index < shortest_length) && (results == 0)) {
            first_char = first[ index ];
            second_char = second[ index ];
            if ((first_char >= 65) && (first_char <= 90)) {
                first_char = first_char + 32;
            }
            if ((second_char >= 65) && (second_char <= 90)) {
                second_char = second_char + 32;
            }
            if (first_char < second_char) {
                results = -1;
            } else if (first_char > second_char) {
                results = 1;
            } else {
                results = 0;
            }
        }
        index++;
        if (results == 0) {
            if (first_length < second_length) {
                results = -1;
            } else if (first_length > second_length) {
                results = 1;
            } else {
                results = 0;
            }
        }
    } else {
        printf("Error: Should not reach this: Unhandled case_sensitivity!\n");
    }

    return ( results);

}

/* Name: string_find
 * Decs: Find strings 
 */
int string_find(char contents[], char search[], int locations[]) {
    // contents is the string to search in...
    // search is the string to search for...
    // must have '/0' 
    // Ex: contents = "banana", search = "na" --> 2 4 
    // Ex: contents = "IEEE MEETING", search = "EE" --> 1 6
    // case sensitive for now... 

    int contents_length;
    int search_length;
    int contents_index;
    int search_index;
    int match;
    int count;

    contents_length = string_length(contents);
    search_length = string_length(search);
    contents_index = 0;
    search_index = 0;
    match = 1;
    count = 0;

    if (contents_length <= 0) {
        printf("Error: No valid contents string!\n");
    } else if (search_length <= 0) {
        printf("Error: No valid search string!\n");
    } else if (contents_length < search_length) {
        printf("Error: contents string is shorter than your search string!\n");
    } else {
        while ((contents_index < (contents_length - search_length + 1)) && (count < n_max)) {
            match = 1; //assume true
            search_index = 0;
            while ((match == 1) && (search_index < search_length)) {
                // we will compare characters...
                if (contents[ contents_index + search_index] == search[ search_index ]) {
                    //we still have a match... 
                    search_index++;
                } else {
                    // they differ --> no match 
                    match = 0;
                }
            }
            if (match == 1) {
                // we have found a match and need to store it... 
                locations[ count ] = contents_index;
                count++;
                contents_index = contents_index + search_index;
            } else {
                contents_index++;
            }
        }
    }

    return ( count);
}

/* Name: char_find
 * Decs: find characters within a text document
 */
int char_find(char contents[], int contents_length, char search, int locations[]) {
    // contents is char vector/array NOT a string --> contents_length
    // search is a single char
    // locations vector/array is going to store the locations/indexes of the search
    //     character in the contents
    int index;
    int count;
    index = 0;
    count = 0;

    while ((index < contents_length) && (count < n_max)) {
        if (contents[ index ] == search) {
            //we have found a match.
            locations[ count ] = index; // storing the index of the matches location    
            count++;
        } else {
            // we just keep looking...
        }
        index++;
    }

    return ( count);
}

/* Name: add_doublevector 
 * Desc: Adds double vectors of array 1D     
 *
 */
int add_doublevector(const double vector_01[], const double vector_02[], double vector_sum[], int n) {
    int results;
    int n_index;

    results = EXIT_SUCCESS;

    if (n <= 0) {
        results = EXIT_FAILURE;

    } else {
        for (n_index = 0; n_index < n; n_index++) {
            vector_sum[ n_index] = vector_01[ n_index] + vector_02[ n_index ];
        }

    }

    return (results);

}

/* Name: add_double2Darray 
 * Desc: Adds double vectors of array 2D     
 *
 */
int add_double2Darray(const double array_01[][m_max], const double array_02[][m_max], double array_sum[][m_max], int n, int m) {
    int results;
    int n_index;
    int m_index;


    results = EXIT_SUCCESS;

    if ((n <= 0) && (m <= 0) && (m > m_max)) {
        results = EXIT_FAILURE;
    } else {
        for (n_index = 0; n_index < n; n_index++) {
            for (m_index = 0; m_index < m; m_index++) {
                array_sum[ n_index ][ m_index ] = array_01[ n_index ][ m_index ] + array_02[ n_index ][ m_index ];
            }
        }
    }


    return (results);
}

/* Name: get_max_vector 
 * Desc: Find max vector     
 *
 */
int get_max_vector(const double vector [], int n, int *n_location, double *n_value) {
    int results;
    int n_index;
    double max;
    int max_location;

    results = EXIT_SUCCESS;
    //loop through each one of the elements looking for the largest value... 
    if (n <= 0) {
        results = EXIT_FAILURE;
    } else {
        // n >= 1
        max = vector[ 0 ];
        for (n_index = 1; n_index < n; n_index++) {

            if (vector[ n_index ] > max) {
                //we have found a new max
                max = vector[ n_index ];
                max_location = n_index;
            } else {
                //move to the next location (keep looking) 

            }
        }
        *n_value = max;
        *n_location = max_location;

    }
    return ( results);
}

/* Name: get_min_vector 
 * Desc: Find min vector     
 *
 */
int get_min_vector(const double vector [], int n, int *n_location, double *n_value) {
    int results;
    int n_index;
    double min;
    int min_location;

    results = EXIT_SUCCESS;
    //loop through each one of the elements looking for the largest value... 
    if (n <= 0) {
        results = EXIT_FAILURE;
    } else {
        // n >= 1
        min = vector[ 0 ];
        for (n_index = 1; n_index < n; n_index++) {

            if (vector[ n_index ] < min) {
                //we have found a new min 
                min = vector[ n_index ];
                min_location = n_index;
            } else {
                //move to the next location (keep looking) 

            }
        }
        *n_value = min;
        *n_location = min_location;

    }
    return ( results);
}

/* Name: get_mean_vector 
 * Desc: Find mean vector     
 *
 */
int get_mean_vector(const double vector [], int n, double *n_value) {
    int results;
    double sum;
    int n_index;

    results = EXIT_SUCCESS;
    sum = 0.0;

    if (n <= 0) {
        results = EXIT_FAILURE;
    } else {
        for (n_index = 0; n_index < n; n_index++) {
            sum = sum + vector[ n_index ];
        }
        *n_value = sum / ((double) n);
    }
    return (results);

}

/* Name: export_int2Darray 
 * Desc: export int 2D array      
 *
 */
int export_int2Darray(int array[n_max][m_max], int n, int m, const char filename[], const char delimiter[]) {
    int n_index;
    int m_index;
    int results;
    FILE *output;

    results = EXIT_SUCCESS;
    // results --> success or failure
    // results --> number of characters printed 
    // results --> number of pieces of data that was printed 

    if (n > n_max) {
        printf("Error: n = %d is larger than n_max = %d.\n", n, n_max);
        results = EXIT_FAILURE;
    } else if (m > m_max) {
        printf("Error: m = %d is larger than m_max = %d.\n", m, m_max);
        results = EXIT_FAILURE;
    } else if (string_length(filename) <= 0) {
        printf("Error: invalid filename!\n");
    } else {
        output = fopen(filename, "w");
        if (output != NULL) {
            for (n_index = 0; n_index < n; n_index++) {
                for (m_index = 0; m_index < (m - 1); m_index++) {
                    fprintf(output, "%d%s", array[ n_index ][ m_index ], delimiter);
                }
                fprintf(output, "%d\n", array[ n_index ][ m_index ]);
            }
            fclose(output);
        } else {
            printf("Error: Failed to open %s!\n", filename);
            results = EXIT_FAILURE;
        }

    }

    return ( results);

}

/* Name: export_double2Darray 
 * Desc: export double 2D array       
 *
 */
int export_double2Darray(double array[n_max][m_max], int n, int m, const char filename[], const char delimiter[]) {

    int n_index;
    int m_index;
    int results;
    FILE *output;

    results = EXIT_SUCCESS;
    // results --> success or failure
    // results --> number of characters printed 
    // results --> number of pieces of data that was printed 

    if (n > n_max) {
        printf("Error: n = %d is larger than n_max = %d.\n", n, n_max);
        results = EXIT_FAILURE;
    } else if (m > m_max) {
        printf("Error: m = %d is larger than m_max = %d.\n", m, m_max);
        results = EXIT_FAILURE;
    } else if (string_length(filename) <= 0) {
        printf("Error: invalid filename!\n");
    } else {
        output = fopen(filename, "w");
        if (output != NULL) {
            for (n_index = 0; n_index < n; n_index++) {
                for (m_index = 0; m_index < (m - 1); m_index++) {
                    fprintf(output, "%f%s", array[ n_index ][ m_index ], delimiter);
                }
                fprintf(output, "%f\n", array[ n_index ][ m_index ]);
            }
            fclose(output);
        } else {
            printf("Error: Failed to open %s!\n", filename);
            results = EXIT_FAILURE;
        }

    }

    return ( results);

}

/* Name: export_char2Darray
 * Desc: export char 2D array     
 *
 */
int export_char2Darray(char array[n_max][m_max], int n, int m, const char filename[], const char delimiter[]) {

    int n_index;
    int m_index;
    int results;
    FILE *output;

    results = EXIT_SUCCESS;
    // results --> success or failure
    // results --> number of characters printed 
    // results --> number of pieces of data that was printed 

    if (n > n_max) {
        printf("Error: n = %d is larger than n_max = %d.\n", n, n_max);
        results = EXIT_FAILURE;
    } else if (m > m_max) {
        printf("Error: m = %d is larger than m_max = %d.\n", m, m_max);
        results = EXIT_FAILURE;
    } else if (string_length(filename) <= 0) {
        printf("Error: invalid filename!\n");
    } else {
        output = fopen(filename, "w");
        if (output != NULL) {
            for (n_index = 0; n_index < n; n_index++) {
                for (m_index = 0; m_index < (m - 1); m_index++) {
                    fprintf(output, "%c%s", array[ n_index ][ m_index ], delimiter);
                }
                fprintf(output, "%c\n", array[ n_index ][ m_index ]);
            }
            fclose(output);
        } else {
            printf("Error: Failed to open %s!\n", filename);
            results = EXIT_FAILURE;
        }

    }

    return ( results);

}

/* Name: export_string2Darray
 * Desc: export string 2D array       
 *
 */
int export_string2Darray(char array[n_max][m_max][char_count_max], int n, int m, const char filename[], const char delimiter[]) {
    int n_index;
    int m_index;
    int results;
    FILE *output;

    results = EXIT_SUCCESS;
    // results --> success or failure
    // results --> number of characters printed 
    // results --> number of pieces of data that was printed 

    if (n > n_max) {
        printf("Error: n = %d is larger than n_max = %d.\n", n, n_max);
        results = EXIT_FAILURE;
    } else if (m > m_max) {
        printf("Error: m = %d is larger than m_max = %d.\n", m, m_max);
        results = EXIT_FAILURE;
    } else if (string_length(filename) <= 0) {
        printf("Error: invalid filename!\n");
    } else {
        output = fopen(filename, "w");
        if (output != NULL) {
            for (n_index = 0; n_index < n; n_index++) {
                for (m_index = 0; m_index < (m - 1); m_index++) {
                    fprintf(output, "%s%s", array[ n_index ][ m_index ], delimiter);
                }
                fprintf(output, "%s\n", array[ n_index ][ m_index ]);
            }
            fclose(output);
        } else {
            printf("Error: Failed to open %s!\n", filename);
            results = EXIT_FAILURE;
        }

    }

    return ( results);

}

/* Name: string_split
 * Desc: splitting a string    
 *
 */
int string_split(char contents[], char delimiter, char chunks[][chunk_length_max ]) {

    int contents_index;
    int results;
    int chunks_index; //the number of actual chunks 
    int chunk_index; // individual character within a chunk  

    results = 0; //number of chunks found 
    contents_index = 0;
    chunks_index = 0;
    chunk_index = 0;

    while ((contents [contents_index ] != '\0') && (chunks_index < chunk_length_max)) {
        if (contents[ contents_index ] == delimiter) {
            chunks[ chunks_index ][ chunk_index ] = '\0';
            chunks_index++;
            chunk_index = 0;

        } else {
            if (chunks_index < (chunk_length_max - 1)) {
                chunks[ chunks_index ][chunk_index ] = contents[ contents_index ];
                chunk_index++;
            } else {

            }

        }
        contents_index++;
    }
    chunks[ chunks_index ][ chunk_index ] = '\0';

    return ( chunks_index + 1);

}


