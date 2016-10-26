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
  int moyenne ;
  int start = 0;
  while(start == 0){
  char c = getchar();
  if(c == '\n'){
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
   	srand((unsigned) time(&t));
	int i;   	
	while(i < section) 
  	 {
		temps = rand() % 3600;
		printf("Voiture : %i | %ld|\n", id ,temps);
		i++;  	 
	}
   
   return(0);
}
