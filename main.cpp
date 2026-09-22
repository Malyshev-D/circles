#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "input_func.h"
#include "circle.h"
char* str = "abc";
char** str_ptr = &str;
// TODO
//0) DONE TODOs
//1) DONE разделить на файлы !!!
//2) DONE разобраться с calloc
//3) DONE assert *

int main()
{
printf("X: %d\n", x);
    int radius = 0;
    printf("Hi! I can draw a circle array.\n"
           "Please, write the radius:\n");
    Correct_Input(&radius);

    int leng = Get_Array_Size(radius); //DONE TODO: get array size (naming)
    int* circle = (int*) calloc(leng, sizeof(int)); //TODO: if
    Circle_Print(circle, radius);

    Interactive(circle, leng, radius);

    free(circle);
    circle = NULL;
    return 0;
}
