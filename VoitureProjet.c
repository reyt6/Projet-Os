#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Voiture{
	int id;
	int tmpsSect[3];
	int tmpsTotal;
	int place;
	int etat; 

};
int randomNum(int min, int max){
  int n = 0;		
    while(n < min || n > max){
      n = rand() % ((max - min +1) + min);
    }
    return n;
}
int startRace(){
  int start = 0;
  while(start == 0){
  char c = getchar();
  if(c == '\n'){
    break;
  }
    start =1;
  }
}
int toHeure(int sec){
	return toMinute(sec) / 60;
}
int toMinute(int sec){
	return sec / 60;
}
int toSeconde(int sec){
	return sec -60 * toMinute(sec);
}
int toMilli(){
	return randomNum(100, 999);
}
int main(){
	struct Voiture Voiture;
	Voiture.id = 22;
	Voiture.tmpsTotal = 0;
	int section;
	time_t t;
	section = 3;
   	srand((unsigned) time(&t));
	int i;   
	int randomNum(int, int);
	int toMinute(int);
	int startRace();
	startRace();	
	while(i < section) 
  	 {
		
		Voiture.tmpsSect[i] = randomNum(45,55);
		Voiture.tmpsTotal = Voiture.tmpsTotal + Voiture.tmpsSect[i];
		i++;
	}
	printf("Temps de Voiture n° %i : | %d:%d:%d |\n", Voiture.id ,toMinute(Voiture.tmpsTotal),toSeconde(Voiture.tmpsTotal),toMilli());
   
   return(0);
}
