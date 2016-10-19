#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Voiture{
	int id;
	char tmpsSec1[10];
	char tmpsSec2[10];
	char tmpsSec3[10];
	double tmpsTotal;
	int place;
	int etat; 
};
int main(){
  int start = 0;
  while(start == 0){
    char c = getchar();
    if(c == '\n'){
      // double return pressed!
      break;
    }
    start =1;
  }
	struct Voiture Voiture;
	long temps;
	int id = Voiture.id = 00;
	int section;
	time_t t;
	section = 3;
  	id = 22;
   	/* Intializes random number generator */
   	srand((unsigned) time(&t));
   	/* Print 5 random numbers from 0 to 49 */
   	for(int i = 0 ; i < section ; i++ ) 
  	 {
		temps = rand() % 3600;
		printf("Voiture : %i | %ld|\n", id ,temps);
  	 }
   
   return(0);
}
// ceci est un test pour voir si je suis contributeur 
