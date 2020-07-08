/************************************************
 *	ICM Consulting
 *      Poker Hand Game
 *
 *
 * **********************************************/


#include<stdio.h>
#include <string.h>
#include <stdlib.h>

void take_input( char* inputPlayerCard);
void sortArray(int player);
void is_highcard(int player);
int is_onepair(int player);
int is_twopair(int player);
int is_threeofkind(int player);
int is_straight(int player);
int is_flush(int player);
int is_fullhouse(int player);
int is_fourofkind(int player);
int is_straight_flush(int player);
int is_royal_flush(int player);
int check_player(int player);
int check_winner();


struct card
{
	char suit;
	int value;
};

struct player
{
        int rank;
	int reducedList[5];
        struct card gameCard[5];
};

struct  player gamePlayer[2];

/*
 * Parse each line from input file
 */

void take_input( char* inputPlayerCard){

	//printf("Value Entered %s \n", inputPlayerCard);
	
	int i = 0;
	int j = 0;

	int cardno = 0;
	int playerno = 0;

	char * token = strtok(inputPlayerCard, " ");

	for(i=0; i < 2; i++) {
	  for(j=0; j < 5; j++) {
	     gamePlayer[i].reducedList[j] = 0;
          }
        }

	while( token != NULL ) {

		gamePlayer[playerno].gameCard[cardno].suit = token[1];
		if(token[0] == 'A' ){
			gamePlayer[playerno].gameCard[cardno].value = 14;
		}
		 else if(token[0] == 'K' ){
			gamePlayer[playerno].gameCard[cardno].value = 13;
		}
		 else if(token[0] == 'Q' ){
			gamePlayer[playerno].gameCard[cardno].value = 12;
		}
		 else if(token[0] == 'J' ){
			gamePlayer[playerno].gameCard[cardno].value = 11;
		}
		 else if(token[0] == 'T' ){
			gamePlayer[playerno].gameCard[cardno].value = 10;
		}
		 else{

			gamePlayer[playerno].gameCard[cardno].value = atoi(&token[0]);
		}
	 
		cardno++;
		if ( cardno == 5 )
		{
		   cardno = 0;
		   playerno++;
		}
		token = strtok(NULL, " ");

	}

/*
	printf("The numbers given below \n");
	int i, n = 5;
	for (i = 0; i < n; ++i)
	{
	    printf("%d\n", gamePlayer[0].gameCard[i].value);
	    printf("%d\n", gamePlayer[1].gameCard[i].value);

	}
*/

}

int is_royal_flush(int player)
{

	int a,b,c,d,e;
	a = gamePlayer[player].gameCard[0].value;
	b = gamePlayer[player].gameCard[1].value;
	c = gamePlayer[player].gameCard[2].value;
	d = gamePlayer[player].gameCard[3].value;
	e = gamePlayer[player].gameCard[4].value;

	if ( a+b+c+d+e == 60 && is_flush(player) == 1 ){
		//printf("is_royal_flush");
		return 1;
	}
	else{
		return 0;
	}

}

int is_straight_flush(int player){
	if ( (is_flush(player) == 1)&&(is_straight(player) == 1) ){
		return 1;
	}
	else{
		return 0;
	}
}


int is_fourofkind(int player){
        int a,b,c,d,e;
        a = gamePlayer[player].gameCard[0].value;
        b = gamePlayer[player].gameCard[1].value;
        c = gamePlayer[player].gameCard[2].value;
        d = gamePlayer[player].gameCard[3].value;
        e = gamePlayer[player].gameCard[4].value;
        if ((a==b && b==c && c==d)){
		gamePlayer[player].reducedList[0] = a;
		gamePlayer[player].reducedList[1] = e;
                return 1;
        }
	else if ( (b==c && c==d && d==e) ){
                gamePlayer[player].reducedList[0] = b;
                gamePlayer[player].reducedList[1] = a;
                return 1;
	}
        else{
                return 0;
        }
}

void is_highcard(int player){
        int a,b,c,d,e;
        a = gamePlayer[player].gameCard[0].value;
        b = gamePlayer[player].gameCard[1].value;
        c = gamePlayer[player].gameCard[2].value;
        d = gamePlayer[player].gameCard[3].value;
        e = gamePlayer[player].gameCard[4].value;
	gamePlayer[player].reducedList[0] = a;
	gamePlayer[player].reducedList[1] = b;
	gamePlayer[player].reducedList[2] = c;
	gamePlayer[player].reducedList[3] = d;
	gamePlayer[player].reducedList[4] = e;
}



//function to check one pair
int is_onepair(int player){
	int a,b,c,d,e;
	a = gamePlayer[player].gameCard[0].value;
	b = gamePlayer[player].gameCard[1].value;
	c = gamePlayer[player].gameCard[2].value;
	d = gamePlayer[player].gameCard[3].value;
	e = gamePlayer[player].gameCard[4].value;
        if ((a==b))
        {
                gamePlayer[player].reducedList[0] = a;
                gamePlayer[player].reducedList[1] = c;
		gamePlayer[player].reducedList[2] = d;
                gamePlayer[player].reducedList[3] = e;
                return 1;

        }
        if ((b==c))
        {
                gamePlayer[player].reducedList[0] = b;
                gamePlayer[player].reducedList[1] = a;
                gamePlayer[player].reducedList[2] = d;
                gamePlayer[player].reducedList[3] = e;
                return 1;

        }
        if ((c==d))
        {
                gamePlayer[player].reducedList[0] = c;
                gamePlayer[player].reducedList[1] = a;
                gamePlayer[player].reducedList[2] = b;
                gamePlayer[player].reducedList[3] = e;
                return 1;

        }
        if ((d==e))
        {
                gamePlayer[player].reducedList[0] = d;
                gamePlayer[player].reducedList[1] = a;
                gamePlayer[player].reducedList[2] = b;
                gamePlayer[player].reducedList[3] = c;
                return 1;

        }

	return 0;
}

int is_twopair(int player){
	int a,b,c,d,e;
	a = gamePlayer[player].gameCard[0].value;
	b = gamePlayer[player].gameCard[1].value;
	c = gamePlayer[player].gameCard[2].value;
	d = gamePlayer[player].gameCard[3].value;
	e = gamePlayer[player].gameCard[4].value;
	if ((a==b) && (c==d)) 
	{
		gamePlayer[player].reducedList[0] = a;
                gamePlayer[player].reducedList[1] = c;
                gamePlayer[player].reducedList[2] = e;
		return 1;

	}
	if ((b==c) && (d==e))  
        {
                gamePlayer[player].reducedList[0] = b;
                gamePlayer[player].reducedList[1] = d;
                gamePlayer[player].reducedList[2] = a;
		return 1;

        }
	if ((a==b) && (d==e)) 
        {
                gamePlayer[player].reducedList[0] = a;
                gamePlayer[player].reducedList[1] = d;
                gamePlayer[player].reducedList[2] = c;
		return 1;
	}
	else{
		return 0;
	}
}

int is_fullhouse(int player){
        int a,b,c,d,e;
        a = gamePlayer[player].gameCard[0].value;
        b = gamePlayer[player].gameCard[1].value;
        c = gamePlayer[player].gameCard[2].value;
        d = gamePlayer[player].gameCard[3].value;
        e = gamePlayer[player].gameCard[4].value;
        if ( (a==b && b==c) && (d==e) ) {
		gamePlayer[player].reducedList[0] = a;
		gamePlayer[player].reducedList[1] = d;
                return 1;
        }
        else if ( (b==c && c==d) && (a==e) ){
		gamePlayer[player].reducedList[0] = b;
		gamePlayer[player].reducedList[1] = e;
                return 1;
        }
        else if ( (c==d && d==e) && (a==b) ){
		gamePlayer[player].reducedList[0] = c;
		gamePlayer[player].reducedList[1] = a;
                return 1;
        }
        else{
                return 0;
        }
}


int is_threeofkind(int player){
	int a,b,c,d,e;
	a = gamePlayer[player].gameCard[0].value;
	b = gamePlayer[player].gameCard[1].value;
	c = gamePlayer[player].gameCard[2].value;
	d = gamePlayer[player].gameCard[3].value;
	e = gamePlayer[player].gameCard[4].value;
	if ( (a==b && b==c) ){
		gamePlayer[player].reducedList[0] = a;
		gamePlayer[player].reducedList[1] = d;
		gamePlayer[player].reducedList[2] = e;
		return 1;
	}
	else if ( (b==c && c==d)  ){
		gamePlayer[player].reducedList[0] = b;
		gamePlayer[player].reducedList[1] = a;
		gamePlayer[player].reducedList[2] = e;
		return 1;
	}
	else if ( (c==d && d==e) ){
		gamePlayer[player].reducedList[0] = c;
		gamePlayer[player].reducedList[1] = a;
		gamePlayer[player].reducedList[2] = b;
		return 1;
	}
	else{
		return 0;
	}
}

//function to check straight
int is_straight(int player){
	int a,b,c,d,e;
	a = gamePlayer[player].gameCard[0].value;
	b = gamePlayer[player].gameCard[1].value;
	c = gamePlayer[player].gameCard[2].value;
	d = gamePlayer[player].gameCard[3].value;
	e = gamePlayer[player].gameCard[4].value;
	if( a==b+1 && b==c+1 && c==d+1 && d==e+1 ){
		gamePlayer[player].reducedList[0] = a;
		return 1;

	}
	else{
		return 0;
	}
}

int is_flush(int player){
	int a,b,c,d,e;
	a = gamePlayer[player].gameCard[0].suit;
	b = gamePlayer[player].gameCard[1].suit;
	c = gamePlayer[player].gameCard[2].suit;
	d = gamePlayer[player].gameCard[3].suit;
	e = gamePlayer[player].gameCard[4].suit;
	if( a==b && b==c && c==d && d==e ){
	 return 1;
	}
	else{
	 return 0;
	}
}


//function to check combination of player
//functions returns 1 for high card, 2->One pair and so on.
int check_player(int player){
	int combi = 1;

	if(is_royal_flush(player) == 1 ){
		combi = 10;
	}
	else if(is_straight_flush(player) == 1){
		combi = 9;
	}
	else if(is_fourofkind(player) == 1){
		combi = 8;
	}
	else if(is_fullhouse(player) == 1){
		combi = 7;
	}
	else if(is_flush(player) == 1){
		combi = 6;
	}
	else if(is_straight(player) == 1){
		combi = 5;
	}
	else if(is_threeofkind(player) == 1){
		combi = 4;
	}
	else if(is_twopair(player) == 1){
		combi = 3;
	}
	else if(is_onepair(player) == 1){
		combi = 2;
	}
	else{
		is_highcard(player);
	}
	gamePlayer[player].rank = combi;
	//printf("Rank %d \n", combi );
	return combi;
}



int check_winner(){

	int win1 = 0, win2 = 0 ;
	int combi;

	win1 = check_player(0);
	win2 = check_player(1);
	if ( win1 > win2 ){
		return 1;
	}
	else if ( win1 < win2 ){
		return 2;
	}
	else{
		combi = gamePlayer[0].rank;
		if (  combi != 0 )
                {

                        int i, n = 5;

                        for (i = 0; i < n; ++i)
                        {

                                if (gamePlayer[0].reducedList[i] > gamePlayer[1].reducedList[i])
                                {
                                        return 1;
                                }
                                if (gamePlayer[0].reducedList[i] < gamePlayer[1].reducedList[i])
                                {
                                        return 2;
                                }

                        }
			
			return 0;


		}

		return 0;
	//do yourself
	}
}

void sortArray(int player)
{

int i, j, a, n = 5;

for (i = 0; i < n; ++i) 
{

    for (j = i + 1; j < n; ++j)
    {

	if (gamePlayer[player].gameCard[i].value < gamePlayer[player].gameCard[j].value ) 
	{

	    a = gamePlayer[player].gameCard[i].value ;
	    gamePlayer[player].gameCard[i].value = gamePlayer[player].gameCard[j].value;
	    gamePlayer[player].gameCard[j].value = a;

	}

    }

}

/*

printf("The numbers arranged in desc order are given below \n");
for (i = 0; i < n; ++i)
    printf("%d\n", gamePlayer[player].gameCard[i].value);

*/

}

/*
 * The is entry function, Open file , read input line and close file.
 */

int main(int argc, char **argv)
{
  if (argc != 2) {
    printf("please specify a file.");
    exit(EXIT_FAILURE);
  }
  FILE *stream;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  int winner = 0;
  int player1 = 0;
  int player2 = 0;

  stream = fopen(argv[1], "r");
  if (stream == NULL)
    exit(EXIT_FAILURE);

  while ((read = getline(&line, &len, stream)) != -1) {
    //printf("%s", line);
    take_input(line);

        sortArray(0);
        sortArray(1);
	winner = check_winner();
	if (winner == 1){
		player1++;
		
//		printf("Player 1 wins\n");
	}
	else if ( winner == 2) {
		player2++;
//		printf("Player 2 wins\n");
	}
	else  {
//		printf("Its a tie \n");
	}


  }

  printf("Player1:  %d \n", player1);
  printf("Player2:  %d \n", player2);
	

  free(line);
  fclose(stream);
  exit(EXIT_SUCCESS);
}
