#include<windows.h>
#include<lmcons.h>
#include<iostream>
#include<stdio.h>

using namespace std;

void main (void)
{
	//Nom de l'utilisateur
	TCHAR username[UNLEN+1];
	DWORD taille = UNLEN+1;
	BOOL reussi;

	reussi = GetUserName(username, &taille);

	if(reussi)
	{
		wcout<<"Le nom de l'utilisateur est : "<<username<<endl;
		cout<<endl;
	}
	else
	{
		cout<<"Impossible de lire le nom de l'utilisateur !"<<endl;
		cout<<endl;
	}



	//Nom de l'ordinateur
	TCHAR name[MAX_COMPUTERNAME_LENGTH+1];
	taille = MAX_COMPUTERNAME_LENGTH+1;

	GetComputerName(name, &taille);

	if(reussi)
	{
		wcout<<"Le nom de l'ordinateur est : "<<name<<endl;
		cout<<endl;
	}
	else
	{
		cout<<"Impossible de lire le nom de l'ordinateur"<<endl;
		cout<<endl;
	}



	//Chemin fichier systeme DLL
	TCHAR chemin[500];
	taille = 500;

	GetSystemDirectory(chemin,taille);

	wcout<<"Les fichiers systeme se trouvent dans "<<chemin<<endl;
	cout<<endl;



	//Disques présent sur le pc 
	DWORD disque;
	DWORD masque=1;
	int i, resultat;
	disque = GetLogicalDrives();

	cout<<"Les disques sont : "<<endl;

	for(i='A'; i<='Z'; i++)
	{
		resultat = disque & masque;
		if(resultat !=0)
		{
			printf("- %c\n", i);
		}
		masque = masque<<1;
	}
	cout<<endl;


	//Espasce disque disponible et total
	DWORD SectorsPerCluster = 0;
	DWORD BytesPerSector = 0;
	DWORD FreeClusters = 0;
	DWORD TotalClusters = 0;
	int espaceDisponible, espaceTotal, pourcentageDisponible;

	GetDiskFreeSpace(NULL,&SectorsPerCluster,&BytesPerSector,&FreeClusters,&TotalClusters); 

	espaceDisponible = FreeClusters * SectorsPerCluster/1024 * BytesPerSector/1024/1024; 
	espaceTotal = TotalClusters * SectorsPerCluster/1024 * BytesPerSector/1024/1024;
	
	printf("Espace Total : %i Go\n", espaceTotal);
	printf("Espace Disponible : %i Go\n", espaceDisponible);
	pourcentageDisponible = (espaceDisponible / (float)espaceTotal) * 100;
	printf("Pourcentage espace disponible %i %% \n\n", pourcentageDisponible);
	

	system("pause");
}

