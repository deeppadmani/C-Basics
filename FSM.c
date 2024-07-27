#include<stdio.h>

typedef enum {
  IDLE_STATE = 0,
  STATE_SET_BIT,
  STATE_CLEAR_BIT,
  STATE_TOGGLE_BIT,
  STATE_MAX
}MyStates;

int Bit = 0;
MyStates mainState = IDLE_STATE;

void printBinary(int num);
void idleState(int num);
int stateSetBit(int num,int BitNo);
int stateClearBit(int num,int BitNo);
int stateToggleBit(int num,int BitNo);

void main() {
  MyStates lastState = mainState;

   int num;
   printf("Enter No: ");
   scanf("%d", &num);
   while(1)
   {
       switch (mainState) {
        case IDLE_STATE:
            printf("IDLE_STATE\n");
            break;
        case STATE_SET_BIT:
            printf("STATE_SET_BIT\n");
            break;
        case STATE_CLEAR_BIT:
            printf("STATE_CLEAR_BIT\n");
            break;
        case STATE_TOGGLE_BIT:
            printf("STATE_TOGGLE_BIT\n");
            break;
      }
      
      if (mainState != STATE_MAX) {
        switch (mainState) {
          case IDLE_STATE:
            idleState(num);
            break;
          case STATE_SET_BIT:
            num = stateSetBit(num, Bit);
            mainState = IDLE_STATE;
            break;
          case STATE_CLEAR_BIT:
            num = stateClearBit(num, Bit);
            mainState = IDLE_STATE;
            break;
          case STATE_TOGGLE_BIT:
            num = stateToggleBit(num, Bit);
            mainState = IDLE_STATE;
            break;
          default:
            //
            break;
        }
      }
    
      
   }
}

void idleState(int num) {
  printf("Num = %d\n",num);
  printBinary(num);
  
  printf("1)Set a Bit\n2)Clear a bit\n3)Toggle a Bit\n");
  scanf(" %d",&mainState);
  
  printf("Bit No: ");
  scanf("%d", &Bit);
}

int stateSetBit(int num,int BitNo) {
  return (num | (1<<BitNo));
}

int stateClearBit(int num,int BitNo) {
  return (num & ~(1<<BitNo));
}

int stateToggleBit(int num,int BitNo) {
  return (num ^ (1<<BitNo));
}

void printBinary(int num)
{
     int i = 0;
     for(i = 31; i >= 0; i--)
        printf("%d", (num >> i) & 1);
    printf("\n");
}
