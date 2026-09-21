#include <stdio.h>
#define MAX3DIGITS 1000

void Correct_Input (int*  value);
void Interactive   (int*  circle, int leng, int radius);
void Clear_Input   (char* sym);

int  Get_Array_Size(int  rad);
bool Is_In_Circle  (int  x,      int y, int rad);
void Circle_Print  (int* circle, int rad);
void Circle_Reset  (int* circle, int leng);
void Circle_Edit   (int* circle, int rad);


// TODO:
//0) TODOs
//1) разделить на файлы !!!
//2) разобраться с calloc
//3) assert *

int main()
{
    int radius = 0;
    printf("Hi! I can draw a circle array.\n"
           "Please, write the radius:\n");
    Correct_Input(&radius);

    int leng = Get_Array_Size(radius); //DONE TODO: get array size (naming)
    int circle[leng] = {}; //TODO: calloc
    Circle_Print(circle, radius);

    Interactive(circle, leng, radius);
}

void Correct_Input(int* value)
{
    int  is_int = 0;
    char not_digit = 0;
    char check_space = 0;
    while (true)
    {
        is_int = scanf("%d", value);
        if (is_int == 1)
        {
            not_digit = getchar();
            if (not_digit == '\n') //DONE TODO: а если много пробелов
                break;

            if (not_digit == ' ')
            {
                check_space = not_digit;
                do
                {
                    continue;
                } while ((check_space = getchar()) == ' ');
                if (check_space == '\n')
                    break;

                else
                {
                    Clear_Input(&check_space);
                    printf("Incorrect input.\n"
                    "Please try again: ");
                }
            }
            else
            {
                Clear_Input(&not_digit);
                printf("Incorrect input.\n"
                "Please try again: ");
            }

        }
        else
        {
            Clear_Input(&not_digit);
            printf("Incorrect input.\n"
                "Please try again: ");
        }
    }
}

void Interactive(int* circle, int leng, int radius)
{
    char sym;
    char cycle = 1;
    while (cycle == 1)
    {
        printf("Write\n"
        "<c> to close program,\n"
        "<e> to edit your array,\n"
        "<p> to print your array,\n"
        "<r> to reset your array.\n"
        "Your choice: ");
        sym = getchar();
        switch ((int)sym)
        {
            case (int)'c':
                cycle = 0;
                break;

            case (int)'e':
                Circle_Edit(circle, radius);
                break;

            case (int)'p':
                Circle_Print(circle, radius);
                Clear_Input(&sym);
                break;

            case (int)'r':
                Circle_Reset(circle, leng);
                Clear_Input(&sym);
                break;

            default:
                printf("sorry\n");
                Clear_Input(&sym);
                break;
        }
    }
}

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

void Clear_Input(char* sym)
{
    while ((*sym = getchar()) != '\n')
        continue;
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

