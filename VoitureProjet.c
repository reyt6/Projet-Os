#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Voiture{
	int id;
	int tmpsSect[3];
	int tmpsTotal;
	int milli[4];

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

void setTemps(struct Voiture voiture[], int length){
	int section;
	time_t t;
	section = 3;
	srand((unsigned) time(&t));
	int i,j = 0,k;
	int randomNum(int, int);
	int toMinute(int);
	while(j<length){
		i = 0;
		voiture[j].tmpsTotal = 0;
		while(i < section){
			voiture[j].tmpsSect[i] = randomNum(45,55);
			voiture[j].tmpsTotal += voiture[j].tmpsSect[i];
			voiture[j].milli[i] = toMilli();
			i++;
		}
		voiture[j].milli[3] = toMilli();
		j++;
	}
	k = j;
	while(k<22){
		voiture[k].tmpsTotal = 100000;
		voiture[k].milli[i] = 0;
		k++;
	}
}

int compare(const void* v1, const void* v2){
	struct Voiture sv1 = *(const struct Voiture*)v1;
	struct Voiture sv2 = *(const struct Voiture*)v2;
	int compareVoiture = sv1.tmpsTotal - sv2.tmpsTotal;
	if (compareVoiture == 0)
		return sv1.milli[3] - sv2.milli[3];
	else
		return compareVoiture;
}
void sortVoiture(struct Voiture v[]){
	qsort(v, 22, sizeof(struct Voiture), compare);
}




int compareSect1(const void* v1, const void* v2){
	struct Voiture sv1 = *(const struct Voiture*)v1;
	struct Voiture sv2 = *(const struct Voiture*)v2;
	int compareSect = sv1.tmpsSect[0] - sv2.tmpsSect[0];
	if (compareSect == 0)
		return sv1.milli[0] - sv2.milli[0];
	else
		return compareSect;
}
void sortSect1(struct Voiture v[]){
	qsort(v, 22, sizeof(struct Voiture), compareSect1);
}



int compareSect2(const void* v1, const void* v2){
	struct Voiture sv1 = *(const struct Voiture*)v1;
	struct Voiture sv2 = *(const struct Voiture*)v2;
	int compareSect = sv1.tmpsSect[1] - sv2.tmpsSect[1];
	if (compareSect == 0)
		return sv1.milli[1] - sv2.milli[1];
	else
		return compareSect;
}
void sortSect2(struct Voiture v[]){
	qsort(v, 22, sizeof(struct Voiture), compareSect2);
}

int compareSect3(const void* v1, const void* v2){
	struct Voiture sv1 = *(const struct Voiture*)v1;
	struct Voiture sv2 = *(const struct Voiture*)v2;
	int compareSect = sv1.tmpsSect[2] - sv2.tmpsSect[2];
	if (compareSect == 0)
		return sv1.milli[2] - sv2.milli[2];
	else
		return compareSect;
}
void sortSect3(struct Voiture v[]){
	qsort(v, 22, sizeof(struct Voiture), compareSect3);
}

void showVoiture(struct Voiture voiture[], int length){
	int count=0;
	while(count<length){
		printf("%d) Voiture n° %d : | %d:%d:%d |\n",count+1, voiture[count].id , toMinute(voiture[count].tmpsTotal),toSeconde(voiture[count].tmpsTotal),voiture[count].milli[3]);
		count++;
	}
}
void showSect(struct Voiture voiture[],int i, int length){
	int count=0;
	while(count<length){
		printf("%d) Voiture n° %d : | %d.%d |\n",count+1, voiture[count].id,voiture[count].tmpsSect[i],voiture[count].milli[i]);
		count++;
	}
}

void showOrdreCourse(struct Voiture voiture[]){
	int count=0;
	while(count<22){
		printf("%d) Voiture n° %d\n",count+1, voiture[count].id);
		count++;
	}
}


void showcourse(struct Voiture voiture1[], struct Voiture voiture2[]){
	int count=0;
	printf("Meilleur Temps			Temps du tour passé\n");
	while(count<22){
		printf("%d) Voiture n° %d : | %d:%d:%d |    %d) Voiture n° %d : | %d:%d:%d |\n",count+1, voiture1[count].id , toMinute(voiture1[count].tmpsTotal),toSeconde(voiture1[count].tmpsTotal),voiture1[count].milli[3], count+1, voiture2[count].id , toMinute(voiture2[count].tmpsTotal),toSeconde(voiture2[count].tmpsTotal),voiture2[count].milli[3]);
		count++;
	}
}
int main(){
	printf("\e[1;1H\e[2J");
	printf("			Enter pour commencer");
	startRace();
	struct Voiture voiture[22], voitureCourse[22];
	struct Voiture voitureQ1[22], voitureQ2[22], voitureQ3[22];
	setID(voiture);
	int length = 22;
	int numTour = 10;
	int i = 0;
	
	printf("\e[1;1H\e[2J");
	printf("			Vendredi matin\n");
	printf("		 Seance d'essais libres(1h30)\n");
	setTemps(voiture,length);
	printf("\n\nMeilleur temps du premier secteur\n\n");
	sortSect1(voiture);
	showSect(voiture, 0,22);
	sleep(3);
	printf("\e[1;1H\e[2J");
	printf("			Vendredi matin\n");
	printf("		 Seance d'essais libres(1h30)\n");
	printf("\n\nMeilleur temps du second secteur\n\n");
	sortSect2(voiture);
	showSect(voiture, 1,22);
	sleep(3);
	printf("\e[1;1H\e[2J");
	printf("			Vendredi matin\n");
	printf("		 Seance d'essais libres(1h30)\n");
	printf("\n\nMeilleur temps du troisieme secteur\n\n");
	sortSect3(voiture);
	showSect(voiture, 2,22);
	sleep(3);
	printf("\e[1;1H\e[2J");
	printf("			Vendredi matin\n");
	printf("		 Seance d'essais libres(1h30)\n");
	printf("Resultat final\n\n");
	sortVoiture(voiture);
	showVoiture(voiture,22);

	printf("Enter pour continuer");
	startRace();

	printf("\e[1;1H\e[2J");
	printf("			Vendredi apres-midi\n");
	printf("		 Seance d'essais libres(1h30)\n");
	setTemps(voiture,length);
	printf("\n\nMeilleur temps du premier secteur\n\n");
	sortSect1(voiture);
	showSect(voiture, 0,22);
	sleep(3);
	printf("\e[1;1H\e[2J");
	printf("			Vendredi apres-midi\n");
	printf("		 Seance d'essais libres(1h30)\n");
	printf("\n\nMeilleur temps du second secteur\n\n");
	sortSect2(voiture);
	showSect(voiture, 1,22);
	sleep(3);
	printf("\e[1;1H\e[2J");
	printf("			Vendredi apres-midi\n");
	printf("		 Seance d'essais libres(1h30)\n");
	printf("\n\nMeilleur temps du troisieme secteur\n\n");
	sortSect3(voiture);
	showSect(voiture, 2,22);
	sleep(3);
	printf("\e[1;1H\e[2J");
	printf("			Vendredi apres-midi\n");
	printf("		 Seance d'essais libres(1h30)\n");
	printf("Resultat final\n\n");
	sortVoiture(voiture);
	showVoiture(voiture,22);

	printf("Enter pour continuer");
	startRace();

	printf("\e[1;1H\e[2J");
	printf("			Samedi matin\n");
	printf("		 Seance d'essais libres(1h)\n");
	setTemps(voiture,length);
	printf("\e[1;1H\e[2J");
	printf("			Samedi matin\n");
	printf("		 Seance d'essais libres(1h)\n");
	printf("\n\nMeilleur temps du premier secteur\n\n");
	sortSect1(voiture);
	showSect(voiture, 0,22);
	i = 0;
	sleep(2);
	printf("\e[1;1H\e[2J");
	printf("			Samedi matin\n");
	printf("		 Seance d'essais libres(1h)\n");
	printf("\n\nMeilleur temps du second secteur\n\n");
	sortSect2(voiture);
	showSect(voiture, 1,22);
	sleep(2);
	printf("\e[1;1H\e[2J");
	printf("			Samedi matin\n");
	printf("		 Seance d'essais libres(1h)\n");
	printf("\n\nMeilleur temps du troisieme secteur\n\n");
	sortSect3(voiture);
	showSect(voiture, 2,22);
	sleep(2);
	printf("\e[1;1H\e[2J");
	printf("			Samedi matin\n");
	printf("		 Seance d'essais libres(1h)\n");
	printf("Resultat final\n\n");
	sortVoiture(voiture);
	showVoiture(voiture,22);

	printf("Enter pour continuer");
	startRace();
		
	printf("\e[1;1H\e[2J");
	printf("			Samedi apres-midi\n");
	printf("		 Seance de qualifications(18min)\n");
	setTemps(voiture,length);
	printf("\n\nMeilleur temps du premier secteur\n\n");
	sortSect1(voiture);
	showSect(voiture, 0,length);
	sleep(2);
	printf("\e[1;1H\e[2J");
	printf("			Samedi apres-midi\n");
	printf("		 Seance de qualifications(18min)\n");
	printf("\n\nMeilleur temps du second secteur\n\n");
	sortSect2(voiture);
	showSect(voiture, 1,length);
	sleep(2);
	printf("\e[1;1H\e[2J");
	printf("			Samedi apres-midi\n");
	printf("		 Seance de qualifications(18min)\n");
	printf("\n\nMeilleur temps du troisieme secteur\n\n");
	sortSect3(voiture);
	showSect(voiture, 2,length);
	sleep(2);
	printf("\e[1;1H\e[2J");
	printf("			Samedi apres-midi\n");
	printf("		 Seance de qualifications(18min)\n");
	printf("Resultat final\n\n");
	sortVoiture(voiture);
	length = 16;
	showVoiture(voiture,length);
	while(length<22){
		voitureQ1[length] = voiture[length];
		length++;
	}

	printf("Enter pour continuer");
	startRace();

	length = 16;
	printf("\e[1;1H\e[2J");
	printf("			Samedi apres-midi\n");
	printf("		 Seance de qualifications(15min)\n");
	setTemps(voiture,length);
	printf("\n\nMeilleur temps du premier secteur\n\n");
	sortSect1(voiture);
	showSect(voiture, 0,length);
	sleep(2);
	printf("\e[1;1H\e[2J");
	printf("			Samedi apres-midi\n");
	printf("		 Seance de qualifications(15min)\n");
	printf("\n\nMeilleur temps du second secteur\n\n");
	sortSect2(voiture);
	showSect(voiture, 1,length);
	sleep(2);
	printf("\e[1;1H\e[2J");
	printf("			Samedi apres-midi\n");
	printf("		 Seance de qualifications(15min)\n");
	printf("\n\nMeilleur temps du troisieme secteur\n\n");
	sortSect3(voiture);
	showSect(voiture, 2,length);
	sleep(2);
	printf("\e[1;1H\e[2J");
	printf("			Samedi apres-midi\n");
	printf("		 Seance de qualifications(15min)\n");
	printf("Resultat final\n\n");
	sortVoiture(voiture);
	length = 10;
	showVoiture(voiture,length);
	while(length<16){
		voitureQ2[length] = voiture[length];
		length++;
	}


	printf("Enter pour continuer");
	startRace();

	length = 10;
	printf("\e[1;1H\e[2J");
	printf("			Samedi apres-midi\n");
	printf("		 Seance de qualifications(12min)\n");
	setTemps(voiture,length);
	printf("\n\nMeilleur temps du premier secteur\n\n");
	sortSect1(voiture);
	showSect(voiture, 0,length);
	sleep(2);
	printf("\e[1;1H\e[2J");
	printf("			Samedi apres-midi\n");
	printf("		 Seance de qualifications(12min)\n");
	printf("\n\nMeilleur temps du second secteur\n\n");
	sortSect2(voiture);
	showSect(voiture, 1,length);
	sleep(2);
	printf("\e[1;1H\e[2J");
	printf("			Samedi apres-midi\n");
	printf("		 Seance de qualifications(12min)\n");
	printf("\n\nMeilleur temps du troisieme secteur\n\n");
	sortSect3(voiture);
	showSect(voiture, 2,length);
	sleep(2);
	printf("\e[1;1H\e[2J");
	printf("			Samedi apres-midi\n");
	printf("		 Seance de qualifications(12min)\n");
	printf("Resultat final\n\n");
	sortVoiture(voiture);
	showVoiture(voiture,length);
	length = 0;
	while(length<10){
		voitureQ3[length] = voiture[length];
		length++;
	}
	length = 0;
	while(length < 10){
		voiture[length] = voitureQ3[length];
		voitureCourse[length] = voitureQ3[length];
		length++;
	}
	while(length < 16){
		voiture[length] = voitureQ2[length];
		voitureCourse[length] = voitureQ2[length];
		length++;
	}
	while(length < 22){
		voiture[length] = voitureQ1[length];
		voitureCourse[length] = voiture[length];
		length++;
	}

	printf("Enter pour continuer");
	startRace();

	length = 22;
	i = 0;
	printf("\e[1;1H\e[2J");
	printf("			Dimanche apres-midi\n");
	printf("				La course \n");
	printf("		Ordre de depart de la course \n");
	showOrdreCourse(voiture);

	printf("Enter pour continuer");
	startRace();

	numTour = 2;
	while(i<numTour){
		printf("\e[1;1H\e[2J");
		printf("			Dimanche apres-midi\n");
		printf("				La course \n");
		setTemps(voiture,length);
		printf("\n\nMeilleur temps du premier secteur\n\n");
		showSect(voiture, 0,length);
		sleep(2);
		printf("\e[1;1H\e[2J");
		printf("			Dimanche apres-midi\n");
		printf("				La course \n");
		printf("\n\nMeilleur temps du second secteur\n\n");
		showSect(voiture, 1,length);
		sleep(2);
		printf("\e[1;1H\e[2J");
		printf("			Dimanche apres-midi\n");
		printf("				La course \n");
		printf("\n\nMeilleur temps du troisieme secteur\n\n");
		showSect(voiture, 2,length);
		sleep(2);
		printf("\e[1;1H\e[2J");
		printf("			Dimanche apres-midi\n");
		printf("				La course \n");
		printf("Resultat du tour n°%d\n\n", i+1);
		length = 0;
		while(length < 22){
			if(voiture[length].tmpsTotal < voitureCourse[length].tmpsTotal ){
				voitureCourse[length] = voiture[length];
			}
			if(voiture[length].tmpsTotal == voitureCourse[length].tmpsTotal ){
				if (voiture[length].milli[3] < voitureCourse[length].milli[3]){
					voitureCourse[length] = voiture[length];
				}
			}
			length++;
		}
		showcourse(voitureCourse, voiture);
		
		printf("Enter pour continuer");
		startRace();
		
		i++;
	}
	printf("Enter pour continuer");
	startRace();

	printf("\e[1;1H\e[2J");
	printf("			Dimanche apres-midi\n");
	printf("				La course \n");
	printf("			Resultat de la course\n");
	sortVoiture(voitureCourse);
	showVoiture(voitureCourse, length);
}

