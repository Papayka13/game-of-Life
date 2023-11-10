#include <stdio.h>

#define WIDE 8 + 2
#define HEIGHT 10+2

void print_screen(char dp[WIDE][HEIGHT]);
int neighbours(char dp[WIDE][HEIGHT], int i, int j);
void action(char dp[WIDE][HEIGHT], int act, int i, int j);

int main() {
    char borders[3] = { '+', '|', '-' };
    //                            0    1    2    3    4    5    6    7    8    9   10   11
    char mas[WIDE][HEIGHT] = { {'+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+'}, //0
                                {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'}, //1
                                {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'}, //2
                                {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'}, //3
                                {'|', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', '|'}, //4
                                {'|', ' ', ' ', ' ', ' ', '*',  '*', ' ', ' ', ' ', ' ', '|'}, //5
                                {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'}, //6
                                {'|', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '|'}, //7
                                {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'}, //8
                                {'+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+'} //9
    };




    for (;;) {
        print_screen(mas);
        Sleep(250);
        for (int i = 1; i < WIDE - 1; i++)
        {
            for (int j = 1; j < HEIGHT - 1; j++)
            {

                int neib = 0;
                neib = neighbours(mas, i, j);
                if ((2 == neib) || (neib == 3))
                    mas[i][j] = '*';
                else
                    mas[i][j] = ' ';


            }
        }

    }




    //print_screen(mas);
    return 0;
}



void action(char dp[WIDE][HEIGHT], int act, int i, int j) {
    /*
    0 - kill cell
    1 - make cell alive
    */
    if (dp[i][j] == '*')
    {
        if (act == 0)
            dp[i][j] = ' ';
        else if (act == 1)
            dp[i][j] = '*';
    }

}

int neighbours(char dp[WIDE][HEIGHT], int wide, int height) { //returns count of neighbours
    int i, j;
    int cnt = 0;
    for (i = (wide - 1); i <= (wide + 1); i++) {
        //printf("%d i",i);
        for (j = (height - 1); j <= (height + 1); j++) {
            //printf("%d j",j);
            if (dp[i][j] == '*')
                cnt++;
        }
    }
    if (dp[i][j] == '*')
        return cnt - 1;
    else
        return cnt;
}

void print_screen(char dp[WIDE][HEIGHT]) {
    for (int i = 0; i < WIDE; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            printf("%c", dp[i][j]);
        }
        printf("\n");
    }
}