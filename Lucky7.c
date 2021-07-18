#include<stdio.h>
#include<time.h>

#define True 1;
#define False 0;

int main(void)
{
  printf("----------------------------\n");
  printf("Poker Game:Bigger or Smaller?!\n");
  printf("----------------------------\n");
  printf("Press h for help.\n\n");

  int quit=1;
  int current=0;
  int money=1000, bet=100;
  int i, j, temp;
  srand(time(NULL));
  int shuffle = 1;
  int cards[52];
  char cmd;
  char points[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

  while(quit!=0)
  {

  printf("[$%d][Bet %d]Cards[%d]\n", money, bet, 52-current);
  printf("Bigger or Smaller than 7(b/s)?");
  scanf(" %c", &cmd);

  for(i=0;i<52;i++)
  {
    cards[i]=i;
  }

  if(shuffle == 1)
  {
    for(i=0;i<52;i++)
   {
    j=rand() % 52;
    temp = cards[i];
    cards[i] = cards[j];
    cards[j] = temp;
   }
  }
   shuffle = 0;

  switch(cmd)
  {
   case'h':
     printf("i for increasing your bet\n");
     printf("d for decreasing your bet\n");
     printf("b for guessing the card is bigger than 7\n");
     printf("s for guessing the card is smaller than 7\n");
     printf("r for shuffling the cards\n");
     printf("q for quit\n");
     break;
    case'i':
     if(bet == money)
       printf("Can't increase the bet!\n");
     else
       bet = (bet+10) <= money ? bet+10: money;
     break;
    case'd':
     if(bet == 100)
       printf("Minimum bet is 100!\n");
     else
       bet = (bet-10)>=100? bet-10 : 100;
     break;
    case'r':
     shuffle = True;
     current = 0;
     break;
    case'q':
     quit = True;
     break;
    case'b':
    switch(cards[current]/13)
    {
     case 0:
      printf("%c", '\x06');
      break;
     case 1:
      printf("%c", '\x03');
      break;
     case 2:
      printf("%c", '\x05');
      break;
     case 3:
      printf("%c", '\x04');
      break;
    }
     printf("%c,", points[cards[current]%13]);
    break;
    case's':
    switch(cards[current]/13)
    {
     case 0:
      printf("%c", '\x06');
      break;
     case 1:
      printf("%c", '\x03');
      break;
     case 2:
      printf("%c", '\x05');
      break;
     case 3:
      printf("%c", '\x04');
      break;
    }
     printf("%c,", points[cards[current]%13]);
    break;
  }

  if((cmd=='b')||(cmd=='s'))
  {
    if(((cmd=='b')&&(cards[current]%13>=6))||((cmd=='s')&&(cards[current]%13<=6)))
    {
      printf("You won!\n");
      money += bet*2;
    }
    else
    {
      printf("You lose!\n");
      money -= bet;
    }
    current++;
  }

  if(money<100)
  {
      printf("Game Over!\n");
      quit = True;
  }

  if(current == 41)
    shuffle = True;
  }
}
