#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
int height = 30, width = 30, x, y,i,j;
int fruitX, fruitY;
int flag;
int gameover;
int score;

void fruits()
{
    gameover = 0;
    x = width / 2;
    y = height / 2;

label1:
    fruitX = rand() % 30;
    if (fruitX == 0)
    {
        goto label1;
    }
label2:
    fruitY = rand() % 30;
    if (fruitY == 0)
    {
        goto label2;
    }
    score = 0;
}

void boundary()
{
    system("cls");
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1)
            {
                printf("_");
            }
            else if (j == 0 || j == width - 1)
            {
                printf("|");
            }
            else
            {
                if (i == x && j == y)
                {
                    printf(">");
                }
                else if (i == fruitX && j == fruitY)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("score = %d\n", score);
    printf("To Exit the Game Press 'x' ...");
    
}

void movements()
{
    if (kbhit())
    {
        switch (getch())
        {
        case 'w':
            flag = 1;
            break;
        case 'a':
            flag = 2;
            break;
        case 'd':
            flag = 3;
            break;
        case 's':
            flag = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
}

void addScore()
{
    usleep(100000);
    switch (flag)
    {
    case 1:
        x--;
        break;
    case 2:
        y--;
        break;
    case 3:
        y++;
        break;
    case 4:
        x++;
        break;
    default:
        break;
    }

    if (x < 0 || x > height|| y < 0 || y > width)
    {
        gameover = 1;
    }

    // to count a score
    if (x == fruitX && y == fruitY)
    {
    label3:
        fruitX = rand() % 30;
        if (fruitX == 0)
        {
            goto label3;
        }

    label4:
        fruitY = rand() % 30;
        if (fruitY == 0)
        {
            goto label4;
        }

        score += 10;
    }
}
void main()
{
    
    fruits();

    while (gameover!=1)
    {
        boundary();
        addScore();
        movements();
        
    }
}