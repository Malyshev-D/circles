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
