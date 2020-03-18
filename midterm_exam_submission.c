// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//git remote add origin https://github.com/kendrickngo2000/exercises1.13-1.19.git
//git push - u origin master


// Midterm exam – The C Programming Language, Spring 2020
// (Coding section – 52 points)
// POST ALL of this CODE to your ______.github.io portfolio.
// (8 pts) (1) Find any and all mistakes in the following code, and correct them.
#include <cstdio>
void count() {
    printf("Enter lines of text here: .../n");



    int c, nc = ‘0’, nt = ‘\0’, nbackslash = 0;
    while ((c = fgetc(c)) != EOF) {
        if (c == '\n') {
            ++nl;
        }
        else if (c == '\t') {
            ++nt;
        }
        else if (c == '\\') {
            ++nbackslash;
        }
        else if (isspace(c)) { ++nc; }
        fprintf("lines: %d\n", nl);
        sprintf("tabs: %d\n", nt);
        printf("backslashes: %d\n", nbackslash);
        printf("alphanumeric: %d\n", nc);
    }
    int main(int argc, const char* argv[]) {
        count();
        return 0;
    }
    // The C Standard Library: Identify the standard library functions that do the following…
    // (3 pts) (2) Find the first character c in a const char* s: const char* strchar(const char* s, char c); 
    // (3 pts) (3) Find the length of the prefix of const char* s that has characters in const char* t: size_t strspn(const char* s, const char* t);
    // (3 pts) (4) Terminate a program immediately exit(0);
    // (3 pts) (5) Open the file “midterm.txt” in read mode: FILE* fopen("midterm.txt", "r");
    // Using pointers, implement each of the following C standard library functions
    size_t strcpy(char* s, const char* t) { // (4 pts) (6)
        char* p = s;
        while ((*s++ = *t++) != '\0') {}
        return p;
    }
    char* strncat(char* s, const char* t, size_t n) // (4 pts) (7)
    {
        char* p = s;
        while (*s != '\0') { ++s; }
        while (n-- > 0 && *t != '\0') {
            *s++ = *t++;
        }
        *s = '\0';  
        return p;
    }

    int strcmp_(const char* s, const char* t) // (4 pts) (8)
    {
        while (*s != '\0' && *t != '\0' && *s == *t) {
            ++s;
            ++t;
        }
        return *s - *t;
    }
    
    // PART III: SHORT PROGRAM
    (20 pts) (9) Fill in the program code below for the square ADT(abstract data type)
        //------ POINT ----------------------------------------------------------------
        typedef struct point point;
    struct point { double x, y; };
    //------ SQUARE -----------------------------------------------------------------
    typedef struct square square;
    struct square { point ul; size_t side; };
    square* square_init(double ulx, double uly, double side); {
        square* sq = (square*)malloc(sizeof(square));
        sq->ulx = ulx;
        sq->uly = uly;
        sq->side = side;
        return sq;
    }
  
    void square_delete(square* sq) 
    { 
        free(sq); 
    }
    
    void square_move(square* sq, double x, double y) {
        sq->x = x;
        sq->y = y;
    }

    void square_expandby(square* sq, double expandby)
    {
        sq->ulx *= expandby;
        sq->uly *= expandby;

    }
    
    double square_area(square* sq) {
        sq->ulx *= expandby;
        sq->uly *= expandby;
    }

    CPSC 223C—Midterm Exam(Coding section – submit code from C file to your github portfolio) page 1 of 2
        double square_perimeter(square * r) {
        double answ = 2 * (sq->ulx + sq->uly);
            return answ;

    }
        // print location, side, area and perimeter
    void square_print(const char* msg, square* sq) {
        char buf[BUFSIZ];
        memset(buf, 0, sizeof(buf));
        printf("&s&s\n", msg, square_tostr(sq, buf));
    }

    void test_square(double ulx, double uly, double side) {
        square* sq = square_init(ulx, uly, side);
        square_print(“sq is : “, sq);
        square_move(2, 2);
        square_print(“sq is now : “, sq);
        square_expandby(sq, 10);
        square_print(“sq has expanded to : “, sq);
        square_delete(sq);
        printf(“\n\n”);
    }
    void tests_square() {
        test_square(0, 0, 10);
        test_square(1, 1, 5);
        // add other tests if you wish // TODO (optional)
    }
    int main(int argc, const char* argv[]) {
        tests_square();
        return 0;
    }
