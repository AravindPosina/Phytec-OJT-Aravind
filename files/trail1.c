#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

// Structure of ball
struct ball {
    int x;
    int y;
    int radius;
    int speedx;
    int speedy;
} ball;

// Structure of Bat (b1, b2)
struct bat {
    int x;
    int y;
    int l;
    int w;
    int s;
} b1, b2;

struct score {
    int s;
} s1, s2;

char buff[3][100];
char t[15];
char n[25];
char k[50];
int i = 0;

void initialize() {
    replay:

    system("cls");

    ball.x = 40;
    ball.y = 10;
    ball.radius = 3;
    ball.speedx = 1;
    ball.speedy = 1;

    b1.x = 2;
    b1.y = 5;
    b1.l = 4;
    b1.w = 2;
    b1.s = 1;

    b2.x = 20;
    b2.y = 5;
    b2.l = 4;
    b2.w = 2;
    b2.s = 1;

    s1.s = 0;
    s2.s = 0;

    printf("PING PONG GAME\n");
    printf("Press 'q' to quit.\n");

    while (1) {
        system("cls");

        printf("A - %d\tB - %d\n", s1.s, s2.s);

        printf("Made BY SAMAGRA GUPTA\n");

        if (ball.x < b1.x || ball.x > b2.x + b2.w) {
            ball.x = 40;
            ball.y = 10;
            s2.s = s2.s + 1;
            printf("Game Over! Player B Wins!\n");
            getch();
            goto replay;
        }

        ball.x = ball.x + ball.speedx;
        ball.y = ball.y + ball.speedy;

        printf("Ball: (%d, %d)\n", ball.x, ball.y);

        printf("Player A\n");
        for (int i = 0; i < b1.l; i++) {
            for (int j = 0; j < b1.w; j++) {
                printf("A");
            }
            printf("\n");
        }

        printf("Player B\n");
        for (int i = 0; i < b2.l; i++) {
            for (int j = 0; j < b2.w; j++) {
                printf("B");
            }
            printf("\n");
        }

        if (kbhit()) {
            int c = getch();
            if (c == 113) {
                printf("Game Quit.\n");
                exit(0);
            }
        }
    }
}

int main() {
    initialize();
    return 0;
}

