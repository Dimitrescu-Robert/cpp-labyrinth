#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

int lab[50][50],pozi,pozj,n,m,i,j,stadiuJoc=0,nivel=0;
char dir;

ifstream fin("labirint.txt");
ifstream fin1("labirint1.txt");
ifstream fin2("labirint2.txt");

// Afiseaza Labirintul

void afisare() {
	for(i=1; i<=n; i++) {
		cout<<endl;
		for(j=1; j<=m; j++) {
			if(i==pozi&&j==pozj) {
				cout<<"X ";
			}
			else if(pozi+1<i||pozi-1>i||pozj+1<j||pozj-1>j) {
				cout<<"* ";
			}
			else {
				cout<<lab[i][j]<<" ";
			}
		}
	}
	cout<<endl;
}

// Misca jucatorul

void movement() {
	int validare=0;
	cin>>dir;
	
	if(dir=='w') {
		if(lab[pozi-1][pozj]==0) {
			pozi=pozi-1;
		}
	}
	else if(dir=='a') {
		if(lab[pozi][pozj-1]==0) {
			pozj=pozj-1;
		}
	}
	else if(dir=='s') {
		if(lab[pozi+1][pozj]==0) {
			pozi=pozi+1;
		}
	}
	else if(dir=='d') {
		if(lab[pozi][pozj+1]==0) {
			pozj=pozj+1;
		}
	}
}

// Verifica stadiul jocului

void verJoc() {
	if(pozi==1||pozj==1||pozi==n||pozj==m) {
		stadiuJoc=1;
	}
}

int main()
{
	cout<<"Alege dintre nivelele: 1, 2 si 3."<<endl;
	while(nivel!=1&&nivel!=2&&nivel!=3) {
		cin>>nivel;
	}
	if(nivel==1) {
		fin>>pozi>>pozj>>n>>m;
		for(i=1; i<=n; i++) {
			for(j=1; j<=m; j++) {
				fin>>lab[i][j];
			}
		}
	}
	else if(nivel==2) {
		fin1>>pozi>>pozj>>n>>m;
		for(i=1; i<=n; i++) {
			for(j=1; j<=m; j++) {
				fin1>>lab[i][j];
			}
		}
	}
	else if(nivel==3) {
		fin2>>pozi>>pozj>>n>>m;
		for(i=1; i<=n; i++) {
			for(j=1; j<=m; j++) {
				fin2>>lab[i][j];
			}
		}
	}
	
	afisare();
	
	//Game Loop
	
	while(stadiuJoc==0) {
		movement();
		afisare();
		verJoc();
	}
}
