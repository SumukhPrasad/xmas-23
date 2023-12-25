#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define H 21
#define W 79
#define S_C 25
#define S_S 1

/*

                   *
                  ***
                 *****/
                typedef
              struct {int
            x,y;} Snowflake;
          Snowflake snfks[S_C];
         char wbuf[H][W][1];char
     sbuf[H][W][1];void init() {for
             (size_t y = 0;
            y < H; y++) {for
          (size_t x = 0; x < W;
       x++) {wbuf[y][x][0]=' ';}}
      for(int i = 0; i < S_C; ++i)
    {snfks[i].x=rand() % W;snfks[i].y
  = rand() % H;}}void rsc() {for (size_t
          y = 0; y < H; y++) {for
         (size_t x = 0; x < W;/**/
        x++) {printf("%c",/*******/
       sbuf[y][x][0]);}printf("\n\r")
     ;}printf("Merry christmas!\n\r");}
  int raX() {srand(time(0)); return (rand()
% (80));}void rsn() {for (int i = 0; i < S_C;
              ++i){snfks[i].y
               += S_S;if/**/
                (snfks[i].y
               >H){/*****/
                snfks[i].y=
               0;snfks[i].x
= raX();}wbuf[snfks[i].y][snfks[i].x][0] = '*';}}void rt() {char lInd[7] = "@&%*=-.";int w = 13;int
l = H-14;for (size_t t = 2; t < 5; t++) {for (size_t i = t-1; i < (2*t); i++) {int lSize = (2*i)-1;
for (size_t j =40-((lSize+1)/2); j < 39+((lSize+1)/2); j++) {wbuf[l][j][0] = lInd[i-1];}l++;}}for(
size_t i = H-2; i < H; i++) {for (size_t j = 38; j < 41; j++){wbuf[i][j][0] = '.';}}}void rs()/**/
{char lInd[3] = "-. ";int currentL = 0;for (size_t y = 0; y < H; y++) {for (size_t x = 0; x < W/**/
;x++) {wbuf[y][x][0]=lInd[currentL];}currentL=y/(H/3);}}void scb() {for (size_t y = 0; y < H; y++)
{for (size_t x = 0; x < W; x++) {sbuf[y][x][0]=wbuf[y][x][0];wbuf[y][x][0]=' ';}}}int main()/****/
{init();while (1==1) {rs();rsn();rt();scb();printf("\e[1;1H\e[2J");rsc();usleep(1000000);}}/*****/