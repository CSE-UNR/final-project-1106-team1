//Authors: Walter Meneses, Johnathan Cadler, Jesse Morgan
//Date: 12/10/2024
//Purpose: Final Project

#include <stdio.h>

#define FILE1 "madlib1.txt"
#define FILE2 "madlib2.txt"
#define length 1000


void contentFunc(FILE* fp, char content[length][length]);
void wordFunc(char content[length][length], char a[length][length], char v[length][length], char n[length][length]);
void displayFunc(char content[length][length], int aCount, int nCount, int vCount, char a[length][length], char n[length][length], char v[length][length]);
void eraseFunc(char content[length][length],char contentModified[length][length]);


int main(int argc, char* argv[]){
	
	FILE* fp;
	
	fp = fopen(argv[1], "r"); 
	if(fp == NULL){
		printf("Could not open %s. Goodybye!", argv[1]);
	}
	
	//Type in ./madlib madlib1.txt for version 1 of program
	//OR 
	//Type in ./madlib madlib2.txt for version 2 of program
	
	char content[length][length];
	char contentModified[length][length];
	contentFunc(fp, content);
	
		
	char a[length][length], n[length][length], v[length][length];
	wordFunc(content, a, v, n );
	
	eraseFunc(content,contentModified);
	
	int adjCounter, nounCounter, verbCounter; 
	displayFunc(contentModified, adjCounter, nounCounter, verbCounter, a, n, v);
	
		
	
return 0;
}

void wordFunc (char content[length][length], char a[length][length], char v[length][length], char n[length][length]){

	for(int i = 0; i < 22; i++){
	
	
	switch(content[i][0]){
	case 'A': printf("Please enter an adjective: ");
		scanf("%s", a);
		a++;
		break;
	
	case 'N': printf("Please enter a noun: ");
		scanf("%s", n);
		n++; 
		break;
		
	case 'V': printf("Please enter a verb: ");
		scanf("%s", v);
		v++; 
		break; 
		}
	}
}

void contentFunc(FILE* fp, char content[length][length]){
	
	for(int i = 0; i < length; i++){
		fgets(content[i], length, fp);
		}
	fclose(fp);
}
	
void displayFunc(char content[length][length], int aCount, int nCount, int vCount, char a[length][length], char n[length][length], char v[length][length]){
	
	for(int i = 0; i < 22; i++){
		if(content[i][0] == 'A'){
		printf(" %s", a[aCount]);
		aCount++;
		}
		else if(content[i][0] == 'V'){
		printf(" %s", v[vCount]);
		vCount++;
		}
		else if(content[i][0] == 'N'){
		printf(" %s", n[nCount]);
		nCount++;
		}
		else{
		printf(" %s", content[i]);
		}
	}
	printf("\n");
}

void eraseFunc(char content[length][length], char contentModified[length][length]){
	
	int i, j;
	for(i = 0; i < length; i++){
		for(j = 0; j < length; j++){
			if(content[i][j] != '\n'){
			contentModified[i][j] = content[i][j];
			}
		}
	}
}






