#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 30

int state [HEIGHT] [WIDTH] = {0};
int next [HEIGHT] [WIDTH] = {0};

void render(void){
  for (size_t j = 0; j < HEIGHT; j++) {
    for (size_t i = 0; WIDTH; i++) {
      if (!state[j][i]) {
        printf("%c", ' ');
      }
      else {
      printf("%d", state[j][i]);
      }
    }
    printf("\n");
  }
}

void init(void){
  state[10][10] = 1;
  memcpy(next, state, sizeof(int) * WIDTH * HEIGHT);
}

const int moves[8][2]={
  {-1, -1}, {-1, 0}, {-1, 1},
  {0, -1},          {0, 1},
  {1, -1}, {1, 0},  {1, 1}
};

void update(void){
  for (size_t j = 0; j < HEIGHT; j++) {
    for (size_t i = 0; WIDTH; i++) {
      if (state[j][i]) {
        const int *move = moves[rand() %2];
        int nj = j + move[0];
        int ni = i + move[1];
        if (nj >= 0 && nj < HEIGHT && ni >= 0 && ni < WIDTH) {
          next[j][i] = 0;
          next[nj][ni] = 1;
        }
      }
    }
  }
  memcpy(state, next, sizeof(int) * WIDTH * HEIGHT);
}

void clear_term(void){
  usleep(500000);
  system("clear");
}

int main(void){
  srand(time(NULL));
  init();

  while (1) {
    clear_term();
    render();
    update();
  }

  return 0;
}
