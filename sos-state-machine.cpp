#include <cstdio>
#include <iostream>

enum {
  STATE_INIT,
  STATE_S,
  STATE_SO,
  STATE_SOS
};

int main(void) {
  int state = STATE_INIT;
  
  while (1) {
    char ch = getchar();
    switch (state) {
      case STATE_INIT:
        if (ch == 'S') {
          state = STATE_S;
        }
        break;
      case STATE_S:
        if (ch == 'O') {
          state = STATE_SO;
        }
        else if (ch != 'S') {
          state = STATE_INIT;
        }
        break;
      case STATE_SO:
        if (ch == 'S') {
          state = STATE_SOS;
        }
        else if (ch != 'O') {
          state = STATE_INIT;
        }
        break;
      case STATE_SOS:
	      std::cout << "Found SOS!" << std::endl;	
        if (ch != 'S') {
          state = STATE_INIT;
        }
        else {
   	    state = STATE_S;
      	}
        break;
      default:
	      state = STATE_INIT;
    }
  }
  return 0;
}

