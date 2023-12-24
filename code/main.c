#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define H 21
#define W 79
#define SNOWFLAKE_COUNT 25
#define SNOWFLAKE_SPEED 1
#define clrscr() printf("\e[1;1H\e[2J")

typedef struct {
    int x, y;
} Snowflake;

Snowflake snowflakes[SNOWFLAKE_COUNT];

unsigned long long frame = 0;
char workingbuf[H][W][1];
char screenbuf[H][W][1];

void initialise() {
     for (size_t y = 0; y < H; y++) {
          for (size_t x = 0; x < W; x++) {
               workingbuf[y][x][0]=' ';
          }
     }

     for (int i = 0; i < SNOWFLAKE_COUNT; ++i) {
          snowflakes[i].x = rand() % W;
          snowflakes[i].y = rand() % H;
     }

}

void renderScreen() {
     for (size_t y = 0; y < H; y++) {
          for (size_t x = 0; x < W; x++) {
               printf("%c", screenbuf[y][x][0]);
          }
          printf("\n\r");
     }
     printf("Merry christmas!\n\r");
}

int randomX() {
     srand(time(0)); 
     return (rand() % (80));
}

void updateAndRenderSnow() {
     for (int i = 0; i < SNOWFLAKE_COUNT; ++i) {
          snowflakes[i].y += SNOWFLAKE_SPEED;
          if (snowflakes[i].y > H) {
               snowflakes[i].y = 0;
               snowflakes[i].x = randomX();
          }
          workingbuf[snowflakes[i].y][snowflakes[i].x][0] = '*';
     }
}

void renderTree() {
     char luminanceIndex[7] = "@&%*=-.";
     int w = 13;
     int l = H-14;
     for (size_t t = 2; t < 5; t++) {
          for (size_t i = t-1; i < (2*t); i++) {
               int lSize = (2*i)-1;
               for (size_t j =40-((lSize+1)/2); j < 39+((lSize+1)/2); j++) {
                    workingbuf[l][j][0] = luminanceIndex[i-1];
               }
               l++;
          }
     }
     for (size_t i = H-2; i < H; i++) {
          for (size_t j = 38; j < 41; j++) {
               workingbuf[i][j][0] = '.';
          }
     }
}

void renderSky() {
     char luminanceIndex[3] = "-. ";
     int currentL = 0;
     for (size_t y = 0; y < H; y++) {
          for (size_t x = 0; x < W; x++) {
               workingbuf[y][x][0]=luminanceIndex[currentL];
          }
          currentL=y/(H/3);
     }
}

void swapAndClearBufs() {
     for (size_t y = 0; y < H; y++) {
          for (size_t x = 0; x < W; x++) {
               screenbuf[y][x][0]=workingbuf[y][x][0];
               workingbuf[y][x][0]=' ';
          }
     }
}


int main() {
     initialise();


     while (1==1) {
          renderSky();
          updateAndRenderSnow();
          renderTree();

          swapAndClearBufs();
          clrscr();
          renderScreen();

          usleep(1000000);
     }
     
     
}
