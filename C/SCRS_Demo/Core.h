/* 
 * File: Core.h
 * Copy: Copyright (c) 2020 Gregory C. Myers
 * BlazerID: gmyers
 * Vers: 1.0.0 11/17/2020 GCM - Original Coding
 * Desc: Header file for aggregating core functions 
 */

#if !defined core_defined

#define char_count_max 20
#define chunk_count_max 20
#define chunk_length_max 1000
#define line_length_max 1000
#define n_max 100
#define m_max 100

typedef enum 
    { ascending, descending }
order_enum;

typedef enum
    { case_sensitive, case_insensitive }
case_sensitivity_enum;

typedef enum
    { data, count }
column_name_enum;

int file_read( char file_name[], char contents[] );
int file_read_line( FILE *input, char line[] );

int char_find( char contents[], int contents_length, char search, int locations[]);

int string_find( char contents[], char search[], int locations[]);
int string_split( char contents[], char delimiter, char chunks[][chunk_length_max]);
int string_compare( char const first[], char const second[], case_sensitivity_enum sensitivity );
int string_length( char const source[] );
int string_upper( char destination[], char const source[] );
int string_lower( char destination[], char const source[] );

int export_int2Darray(int array[n_max][m_max], int n, int m, const char filename[], const char delimiter[]);
int export_double2Darray(double array[n_max][m_max], int n, int m, const char filename[], const char delimiter[]);
int export_char2Darray(char array[n_max][m_max], int n, int m, const char filename[], const char delimiter[]);
int export_string2Darray(char array[n_max][m_max][char_count_max], int n, int m, const char filename[], const char delimiter[]);

int get_max_doublevector(const double vector[], int n, int *n_location, double *n_value);
int get_min_doublevector(const double vector[], int n, int *n_location, double *n_value);
int get_mean_doublevector(const double vector[], int n, double *n_value);

int add_doublevector(const double vector_01[], const double vector_02[], double vector_sum[], int n);
int add_double2Darray(const double array_01[][m_max], const double array_02[][m_max], double array_sum[][m_max], int n, int m);

#define core_defined

#endif
