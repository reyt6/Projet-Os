#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Voiture{
	int id;
	int tmpsSect[3];
	int tmpsTotal;
	int milli;

};
int randomNum(int min, int max){
  int n = 0;		
    while(n < min || n > max){
      n = rand() % ((max - min +1) + min);
    }
    return n;
}
void startRace(){
  int start = 0;
  while(start == 0){
  char c = getchar();
  if(c == '\n'){
    break;
  }
    start = 1;
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
void setID(struct Voiture voiture[]){
    voiture[0].id = 44;
    voiture[1].id = 6;
    voiture[2].id = 5;
    voiture[3].id = 7;
    voiture[4].id = 3;
    voiture[5].id = 33;
    voiture[6].id = 19;
    voiture[7].id = 77;
    voiture[8].id = 11;
    voiture[9].id = 27;
    voiture[10].id = 26;
    voiture[11].id = 55;
    voiture[12].id = 14;
    voiture[13].id = 22;
    voiture[14].id = 9;
    voiture[15].id = 12;
    voiture[16].id = 20;
    voiture[17].id = 30;
    voiture[18].id = 8;
    voiture[19].id = 21;
    voiture[20].id = 31;
    voiture[21].id = 94;
}
void showVoiture(struct Voiture voiture[]){
	int count=0;
	while(count<22){
		printf("Temps de Voiture n° %d : | %d:%d:%d |\n", voiture[count].id , toMinute(voiture[count].tmpsTotal),toSeconde(voiture[count].tmpsTotal),voiture[count].milli);
		count++;
	}
}
void setTemps(struct Voiture voiture[]){
	int section;
	time_t t;
	section = 3;
	srand((unsigned) time(&t));
	int i,j = 0;
	int randomNum(int, int);
	int toMinute(int);
	while(j<22){
		i = 0;
		voiture[j].tmpsTotal = 0;
		while(i < section){
			voiture[j].tmpsSect[i] = randomNum(45,55);
			voiture[j].tmpsTotal += voiture[j].tmpsSect[i];
			i++;
		}
		voiture[j].milli = toMilli();
		j++;
	}
}
int compare(const void* v1, const void* v2){
	struct Voiture sv1 = *(const struct Voiture*)v1;
	struct Voiture sv2 = *(const struct Voiture*)v2;
	int compareVoiture = sv1.tmpsTotal - sv2.tmpsTotal;
	if (compareVoiture == 0) 
		return sv1.milli - sv2.milli;
	else
		return compareVoiture;
}
void sortVoiture(struct Voiture v[]){
	qsort(v, 22, sizeof(struct Voiture), compare);
}
int main(){
	struct Voiture voiture[22];
	setID(voiture);
	void startRace();
	startRace();	
	setTemps(voiture);
	printf("-------Voitures non organisées----------\n");
	showVoiture(voiture);
	printf("--------------Voitures organisées--------\n");
	sortVoiture(voiture);
	showVoiture(voiture);
	return(0);
}

