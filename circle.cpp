#include <stdio.h>
#include "circle.h"
#include "input_func.h"
#include <assert.h>

int Get_Array_Size(int rad)
{
    int number = 0;
    for (int y = 0; y < 2 * rad + 1; y ++)
    {
        for (int x = 0; x < 2 * rad + 1; x ++)
        {
            if (Is_In_Circle(x, y, rad))
            {
                number ++;
            }
        }
    }
    return number;
}

bool Is_In_Circle(int x, int y, int rad)
{
    return ((x - rad) * (x - rad) + (y - rad) * (y - rad) <= rad * rad + 3);
}


void Circle_Print(int* circle, int rad)
{
//TODO: проверка на NULL, if (...)     *assert
    assert(circle != 0);
    int idx = 0;
    for (int y = -1; y < 2 * rad + 1; y++)
    {
        if (y != -1)
        {
            printf("%-3d ", y);
        }
        else
        {
            printf("    ");
        }

        for (int x = 0; x < 2 * rad + 1; x++)
        {
            if (y == -1 && x != -1)
                printf("%3d", x);
            else
            {
                if (Is_In_Circle(x, y, rad))
                {
                    printf("%3d", circle[idx]);
                    idx++;
                }
                else
                {
                    printf("   ");
                }
            }
        }
        putchar('\n');
    }
}

void Circle_Reset(int* circle, int leng)
{
    for (int idx = 0; idx < leng; idx ++)
        circle[idx] = 0;
}


void Circle_Edit(int* circle, int rad)
{
    int x   = 0, y   = 0, idx   = 0;
    int x_0 = 0, y_0 = 0, value = 0;
    printf("Here you can change values by coordinates.\n");
    printf("Enter coordinate x: ");
    Correct_Input(&x_0);
    printf("Enter coordinate y: ");
    Correct_Input(&y_0);
    printf("Enter the value: ");
    Correct_Input(&value);

    for (int y = 0; y < 2 * rad + 1; y++)
    {
        for (int x = 0; x < 2 * rad + 1; x++)
        {
            if (Is_In_Circle(x, y, rad)) //DONE TODO: new function
            {
                if (x == x_0 && y == y_0)
                {
                    circle[idx] = value % MAX3DIGITS; //макс 3 цифры //DONE TODO: const
                    break;
                }
                idx++;
            }
        }
    }
}
