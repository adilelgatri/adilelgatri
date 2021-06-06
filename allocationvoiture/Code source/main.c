#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include<windows.h>
#include <conio.h>
typedef struct{
unsigned int jour;
unsigned int mois;
unsigned int annes;
}date;
typedef struct voiture {
int idvoiture;
char marque[50];
char nomvoiture[50];
char couleur[10];
int nbplaces;
int prixjour;
char enlocation[4];

}voiture;
typedef struct contrat{
float numcontrat;
int idvoiture;
int idclient;
date debut;
date fin;
int cout;

}contrat;
typedef struct client{
int idclient;
char nom[20];
char prenom[20];
int cin;
char adresse[50];
long int telephone;

}client;
voiture V;
contrat Co;
client Cl;
void (*menu3[5])();/*les function de gestion des client*/
void (*menu2[5])();/*les function de gestion des voiture*/
void (*menu1[5])();/*les fonction de menu location*/
void (*menu[4])();/*menu des menu(location-client-voiture-exit*/
/*****************************fontions auxiliaires********************************/
int  rechClient(int num){
  FILE *F;
  F=fopen("client.txt","r");
  do{
  	 fscanf(F,"%d:%s:%s:%d:%s:%ld\n",&Cl.idclient,&Cl.nom,&Cl.prenom,&Cl.cin,&Cl.adresse,&Cl.telephone);
  	 fflush(stdin);
  	 if(Cl.idclient==num)
  	   {
  	     fclose(F);
  	     return 1;
		 }

    }while(!feof(F));

  	     fclose(F);
  	     return 0;
 }
int  rechV(int IdV){
  FILE *F;
  F=fopen("voiture.txt","r");
  do{
  	 fscanf(F,"%d : %s : %s : %s : %d : %d : %s\n",&V.idvoiture,&V.marque,&V.nomvoiture,&V.couleur,&V.nbplaces,&V.prixjour,&V.enlocation);
  	 fflush(stdin);
  	 if(V.idvoiture==IdV)
  	   {
  	     fclose(F);
  	     return 1;
		 }

    }while(!feof(F));
 	fclose(F);
  	     return 0;
 }
int  rechcontra(float IdV){
  FILE *F;
  F=fopen("location.txt","r");
  do{
  	 fscanf(F,"%f : %d : %d : %d-%d-%d : %d-%d-%d : %d\n",&Co.numcontrat,&Co.idvoiture,&Co.idclient,&Co.debut.jour,&Co.debut.mois,&Co.debut.annes,&Co.fin.jour,&Co.fin.mois,&Co.fin.annes,&Co.cout);
  	 fflush(stdin);
  	 if(Co.numcontrat==IdV)
  	   {
  	     fclose(F);
  	     return 1;
		 }

    }while(!feof(F));
 	fclose(F);
  	     return 0;
 }
void __exit(){
system("pause");}
/*****************************menu des menu principal********************************/
void menuvoiture(){
    int choix;
    system("cls");
    do {
             printf("\n                                      \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                                      \xb3 Menu Voiture  \xb3");
	printf("\n                                      \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
     printf("\n\t\t\t\t\t\t\t\t1)liste voiture\n\t\t\t\t\t\t\t\t2)ajouter une voiture\n\t\t\t\t\t\t\t\t3)modifier voiture\n\t\t\t\t\t\t\t\t4)supprimer une voiture\n\t\t\t\t\t\t\t\t5)retour\n\t\t\t\t\t\tchoissez votre choix:");
     scanf("%d",&choix);}while(choix<=0||choix>5);
    return menu2[choix-1](); }
void menuclient(){
    int choix;
    system("cls");
    do {
             printf("\n                                      \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                                      \xb3 Menu Client  \xb3");
	printf("\n                                      \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
     printf("\n\t\t\t\t\t\t\t\t1)liste des client\n\t\t\t\t\t\t\t\t2)Ajouter client\n\t\t\t\t\t\t\t\t3)Modifier client\n\t\t\t\t\t\t\t\t4)Supprimer client\n\t\t\t\t\t\t\t\t5)retour\n\t\t\t\t\t\tchoissez votre choix:");
     scanf("%d",&choix);}while(choix<=0||choix>5);
    return menu3[choix-1]();}
void menulocation(){
    int choix;
    system("cls");
    do {
             printf("\n                                      \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                                      \xb3 location  \xb3");
	printf("\n                                      \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
     printf("\n\t\t\t\t\t\t\t\t1)Visualiser contrat\n\t\t\t\t\t\t\t\t2)Louer voiture\n\t\t\t\t\t\t\t\t3)Modifier contrat\n\t\t\t\t\t\t\t\t4)Supprimer contrat\n\t\t\t\t\t\t\t\t5)Retour\n\t\t\t\t\tchoissez votre choix:");
     scanf("%d",&choix);}while(choix<=0||choix>5);
    return menu1[choix-1]();}
/*****************************menu principal********************************/
void menup(){
    system("cls");
    int choix;
    do{
    printf("\n                                      \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                                      \xb3 Menu Principal  \xb3");
	printf("\n                                      \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

    printf("\n\n");

    printf("\n                                      \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n                                      \xba                                              \xba");
    printf("\n                                      \xba    Location..............................1   \xba");
    printf("\n                                      \xba    Gestion voitures......................2   \xba");
    printf("\n                                      \xba    Gestion clients.......................3   \xba");
    printf("\n                                      \xba    exit..................................4   \xba");
    printf("\n                                      \xba                                              \xba");
    printf("\n                                      \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    printf("\n\n                                    Votre choix  :  ");
    scanf("%d",&choix);
      }while(choix<=0||choix>4);
    return menu[choix-1]();}
/*****************************fontions menu location********************************/
void visualisercontrat(){
int s;
FILE* loc=NULL;
loc=fopen("location.txt","r");
if(!loc){ printf("probleme d'ouverture de fichier location.txt \n"); exit(-1);}
printf("entre le numero de contrat\n");
scanf("%d",&s);
do{
    fscanf(loc,"%f : %d : %d : %d-%d-%d : %d-%d-%d : %d\n",&Co.numcontrat,&Co.idvoiture,&Co.idclient,&Co.debut.jour,&Co.debut.mois,&Co.debut.annes,&Co.fin.jour,&Co.fin.mois,&Co.fin.annes,&Co.cout);
    if(s==Co.numcontrat){
        printf("lenumero du contrat est: %d \n",s);
        printf("le id de voiture est: %d\n",Co.idvoiture);
        printf("le id du client est:%d\n",Co.idclient);
        printf("le date du debut de contrat est: %d/%d/%d\n",Co.debut.jour,Co.debut.mois,Co.debut.annes);
        printf("le date du fin de contrat est:%d/%d/%d\n",Co.fin.jour,Co.fin.mois,Co.fin.annes);
        printf("le cout total est: %d\n",Co.cout);
        fclose(loc);
        sleep(30);
        return menu[0]();}
}while(!feof(loc));
   printf("votre numero den contrat n'est pas valide");
   sleep(5);
   fclose(loc);
               return menu[0]();    }
void LouerVoiture(){
 FILE *F;
 F=fopen("location.txt","a");
   printf("\nEntrer le numero de Contrat :");
   scanf("%d",&Co.numcontrat);
   fflush(stdin);
   printf("\nEntrer le id de voiture :");
   scanf("%d",&Co.idvoiture);
   fflush(stdin);
   printf("\nEntrer le id de client :");
   scanf("%d",&Co.idclient);
   fflush(stdin);
   printf("\nEntrer la date debut (jj/mm/AAAA) :");
   scanf("%d",&Co.debut.jour);printf("/");
   scanf("%d",&Co.debut.mois);printf("/");
   scanf("%d",&Co.debut.annes);
   fflush(stdin);
   printf("\nEntrer la date de fin (jj/mm/AAAA) :");
   scanf("%d",&Co.fin.jour);printf("/");
   scanf("%d",&Co.fin.mois);printf("/");
   scanf("%d",&Co.fin.annes);
   fflush(stdin);
   printf("\nEntrer le cout :");
   scanf("%d",&Co.cout);
   fflush(stdin);
   fprintf(F,"%f : %d : %d : %d-%d-%d : %d-%d-%d : %d\n",Co.numcontrat,Co.idvoiture,Co.idclient,Co.debut.jour,Co.debut.mois,Co.debut.annes,Co.fin.jour,Co.fin.mois,Co.fin.annes,Co.cout);
   fclose(F);
   return menu[0]();
 }
void ModifierContrat() {
 float num;
 printf("\n\n\t\t     entrer le numero de contrat a Modifier : ");
 scanf("%f",&num);
 fflush(stdin);
 if(rechcontra(num)==1)
   {
   	  FILE *F,*Fich;
	  F=fopen("location.txt","r");
	  Fich=fopen("templocation.txt","a");
	  do{
	  	fscanf(F,"%f : %d : %d : %d-%d-%d : %d-%d-%d : %d\n",&Co.numcontrat,&Co.idvoiture,&Co.idclient,&Co.debut.jour,&Co.debut.mois,&Co.debut.annes,&Co.fin.jour,&Co.fin.mois,&Co.fin.annes,&Co.cout);
	  	if(num==Co.numcontrat)
	  	  {

	  	    printf("\nEntrer le nouveau numero de Contrat :");
            scanf("%f",&Co.numcontrat);
            fflush(stdin);
            printf("\nEntrer le nouveau id de voiture :");
            scanf("%d",&Co.idvoiture);
            fflush(stdin);
            printf("\nEntrer le nouveau id de client :");
            scanf("%d",&Co.idclient);
            fflush(stdin);
            printf("\nEntrer le nouveau date debut (jj/mm/AAAA) :");
            scanf("%d",&Co.debut.jour);printf("/");
            scanf("%d",&Co.debut.jour);printf("/");
            scanf("%d",&Co.debut.annes);
            fflush(stdin);
            printf("\nEntrer le nouveau date de fin (jj/mm/AAAA) :");
            scanf("%d",&Co.fin.jour);printf("/");
            scanf("%d",&Co.fin.mois);printf("/");
            scanf("%d",&Co.fin.annes);
            fflush(stdin);
            printf("\nEntrer le nouveau cout :");
            scanf("%d",&Co.cout);
            fflush(stdin);}
            fprintf(Fich,"\n%f : %d : %d : %d-%d-%d : %d-%d-%d : %d\n",Co.numcontrat,Co.idvoiture,Co.idclient,Co.debut.jour,Co.debut.mois,Co.debut.annes,Co.fin.jour,Co.fin.mois,Co.fin.annes,Co.cout);

	   }while(!feof(F));
	  fclose(F);
        fclose(Fich);
        remove("location.txt");
        rename("Templocation.txt","location.txt");
        printf("\nModification a Reusi!!");
        sleep(5);
        system("cls");
        return menu[0]();
	 }
 else
   {
   printf("\n\n -------------------- Ce num de contrat n'existe Pas !! --------------------");
   sleep(5);
   system("cls");
   }
   return menu[0]();
}
void SupprimerContrat(){
 float num;
 printf("\n\n\t\t Entrer le numero de contrat a supprimer : ");
 scanf("%f",&num);
 fflush(stdin);
 if(rechcontra(num)==1)
   {

   	  FILE *F,*Fich;
	  F=fopen("location.txt","r");
	  Fich=fopen("Templocation.txt","a");
	  do{
	  	fscanf(F,"%f : %d : %d : %d-%d-%d : %d-%d-%d : %d\n",&Co.numcontrat,&Co.idvoiture,&Co.idclient,&Co.debut.jour,&Co.debut.mois,&Co.debut.annes,&Co.fin.jour,&Co.fin.mois,&Co.fin.annes,&Co.cout);
	  	if(num!=Co.numcontrat)
	  	  {
	  	  	fprintf(Fich,"%f : %d : %d :%d-%d-%d : %d-%d-%d : %d \n",Co.numcontrat,Co.idvoiture,Co.idclient,Co.debut.jour,Co.debut.mois,Co.debut.annes,Co.fin.jour,Co.fin.mois,Co.fin.annes,Co.cout);
		  }
	   }while(!feof(F));
	   fclose(Fich);
	   fclose(F);
	   remove("location.txt");
	   rename("Templocation.txt","location.txt");
	   printf("\nSuppression Effectuee avec succees!!");
	   sleep(5);
	   system("cls");
	   return menu[0]();
	  }
 else
  {
  printf("\n\n -------------------- Ce num de contrat n'existe Pas !! --------------------");
  sleep(5);
  system("cls");
  return menu[0]();
  }
}
/*****************************fontions menu voiture********************************/
void ListVoiture(){
  FILE *F;
  F=fopen("voiture.txt","r");
  printf(" \n\n               --------------- La liste des voitures --------------- \n\n");
  printf("IdVoiture\t marque\t\t NomVoiture\t\t couleur\t Nbplaces\t prixJour\t Enlocation \n");
  do{
  	 fscanf(F,"%d : %s : %s : %s : %d : %d : %s\n",&V.idvoiture,&V.marque,&V.nomvoiture,&V.couleur,&V.nbplaces,&V.prixjour,&V.enlocation);
  	 printf("%d\t\t %s\t\t %s\t\t %s\t\t %d\t\t %d\t\t %s \n",V.idvoiture,V.marque,V.nomvoiture,V.couleur,V.nbplaces,V.prixjour,V.enlocation);
	}while(!feof(F));
	fclose(F);
	sleep(20);
	system("cls");
	return menu[1]();
 }
void AjouterVoiture() {
 FILE *F;
 int Id;
 F=fopen("voiture.txt","a");
 printf("\n  > Entrer le id de nouveau voiture : ");
 scanf("%d",&Id);
 fflush(stdin);
 if(rechV(Id)==1)
   {
 	printf("\n  Ce Id exist deja !!");
 	fclose(F);
 	sleep(5);
 	return menu[1]();
   }
   V.idvoiture=Id;
   printf("\n  > Entrer la marque de Voiture :  ");
   gets(V.marque);
   fflush(stdin);
   printf("\n  > Entrer nom de Voiture :  ");
   gets(V.nomvoiture);
   fflush(stdin);
   printf("\n  > Entrer la couleur de Voiture :  ");
   gets(V.couleur);
   fflush(stdin);
   printf("\n  > Entrer le nombre de places dans Voiture :  ");
   scanf("%d",&V.nbplaces);
   fflush(stdin);
   printf("\n  > Entrer le prix de jour (Dh):  ");
   scanf("%d",&V.prixjour);
   fflush(stdin);
   printf("\n  > Entrer En location:  ");
   gets(V.enlocation);
   fflush(stdin);
   fprintf(F,"%d : %s : %s : %s : %d : %d : %s\n",V.idvoiture,V.marque,V.nomvoiture,V.couleur,V.nbplaces,V.prixjour,V.enlocation);
   fclose(F);
   return menu[1]();
 }
void ModifierVoiture() {
 int Id;
 printf("\n\n\t\t   Entrer le id voiture a modifier : ");
 scanf("%d",&Id);
 fflush(stdin);
 if(rechV(Id)==1)
   {
   	  FILE *F,*Fich;
	  F=fopen("voiture.txt","r");
	  Fich=fopen("Tempvoiture.txt","a");
	  do{
	  	fscanf(F,"%d : %s : %s : %s : %d : %d : %s\n",&V.idvoiture,&V.marque,&V.nomvoiture,&V.couleur,&V.nbplaces,&V.prixjour,&V.enlocation);
	  	if(Id==V.idvoiture)
	  	  {
	  	  V.idvoiture=Id;
	  	  printf("\n > Entrer le id de nouveau voiture :  ");
 	      scanf("%d",&V.idvoiture);
 	      fflush(stdin);
          printf("\n  > Entrer le nouveau marque de Voiture :  ");
          gets(V.marque);
          fflush(stdin);
          printf("\n  > Entrer le nouveau nom de Voiture :  ");
          gets(V.nomvoiture);
          fflush(stdin);
          printf("\n  > Entrer le nouveau couleur de Voiture :  ");
          gets(V.couleur);
          fflush(stdin);
          printf("\n  > Entrer le nouveau nombre de places dans Voiture :  ");
          scanf("%d",&V.nbplaces);
          fflush(stdin);
          printf("\n  > Entrer le nouveau prix de jour (Dh):  ");
          scanf("%d",&V.prixjour);
          fflush(stdin);
          printf("\n  > Entrer le nouveau En location:  ");
          scanf("%d",&V.enlocation);
          fflush(stdin);
          }
		  fprintf(Fich,"%d : %s : %s : %s : %d : %d : %s\n",V.idvoiture,V.marque,V.nomvoiture,V.couleur,V.nbplaces,V.prixjour,V.enlocation);
	    }while(!feof(F));

	     fclose(Fich);
	     fclose(F);
	     remove("voiture.txt");
	     rename("Tempvoiture.txt","voiture.txt");
	     printf("\n\nla modification a Reusi!!");
	     fclose(F);
	     sleep(5);
	     system("cls");
         return menu[1]();
  }
  else
   {
   printf("\n\n -------------------- Ce id de voiture n'existe Pas !! -------------------- \n");
   sleep(5);
   system("cls");
   return menu[1]();
   }
 }
void SupprimerVoiture(){
 int Id;
 printf("\n\n\t\t   Entrer le id voiture a supprimer : ");
 scanf("%d",&Id);
 fflush(stdin);
 if(rechV(Id)==1)
   {
    FILE *F,*Fich;
    F=fopen("voiture.txt","r");
    Fich=fopen("Tempvoiture.txt","a");
    do{
     fscanf(F,"%d : %s : %s : %s : %d : %d : %s\n",&V.idvoiture,&V.marque,&V.nomvoiture,&V.couleur,&V.nbplaces,&V.prixjour,&V.enlocation);
     if(Id!=V.idvoiture)
      {
        fprintf(Fich,"%d : %s : %s : %s : %d : %d : %s\n",V.idvoiture,V.marque,V.nomvoiture,V.couleur,V.nbplaces,V.prixjour,V.enlocation);
      }
	   }while(!feof(F));
	   fclose(Fich);
	   fclose(F);
	   remove("voiture.txt");
	   rename("Tempvoiture.txt","voiture.txt");
	   printf("\n\nSuppression Effectuee avec succees!!");
	   fclose(F);
       sleep(5);
       system("cls");
        return menu[1]();
   }

 else
  {
  printf("\n\n -------------------- Ce id de voiture n'existe Pas !! --------------------");
  sleep(5);
  system("cls");
  return menu[1]();
  }
}
/*****************************fontions menu client********************************/
void ListClient(){
  FILE *F;
  F=fopen("client.txt","r");
  printf(" \n--------- La liste des clients : ---------\n");
  printf("IdClient\t Nom\t Prenom\t CIN\t Adresse\t Telephone \n");
  do{
  	 fscanf(F,"%d : %s : %s : %d : %s : %ld\n",&Cl.idclient,&Cl.nom,&Cl.prenom,&Cl.cin,&Cl.adresse,&Cl.telephone);
  	 printf("%d\t %s\t %s\t %d\t %s\t %ld\n",Cl.idclient,Cl.nom,Cl.prenom,Cl.cin,Cl.adresse,Cl.telephone);
    }while(fgetc(F)!=EOF);
 	fclose(F);
 	sleep(60);
 	system("cls");
 	return menu[2]();
 }
void AjouterClient() {
 FILE *F;
 int Id;
 F=fopen("client.txt","a");
 printf("\n  > Entrer le id de nouveau client : ");
 scanf("%d",&Id);
 fflush(stdin);
 if(rechClient(Id)==1)
   {
 	printf("\n Ce Id exist deja");
 	fclose(F);
 	Sleep(5);
 	return menu[2]();
   }
   Cl.idclient=Id;
   printf("\n  => Entrer le nom de client :  ");
   gets(Cl.nom);
   fflush(stdin);
   printf("\n  => Entrer prenom de client :  ");
   gets(Cl.prenom);
   fflush(stdin);
   printf("\n  => Entrer le cin :");
   scanf("%d",&Cl.cin);
   fflush(stdin);
   printf("\n  => Entrer l'adresse de client :  ");
   gets(Cl.adresse);
   fflush(stdin);
   printf("\n  => Entrer le telephone de client :  ");
   scanf("%d",&Cl.telephone);
   fflush(stdin);
   fprintf(F,"%d : %s : %s : %d : %s : %ld\n",Cl.idclient,Cl.nom,Cl.prenom,Cl.cin,Cl.adresse,Cl.telephone);
   fclose(F);
 }
void ModifierClient() {
 int Id;
 printf("entrer le id client a Modifier : ");
 scanf("%d",&Id);
 fflush(stdin);
 if(rechClient(Id)==1)
   {
    FILE *F,*Fich;
    F=fopen("client.txt","r");
    Fich=fopen("Tempclient.txt","a");
    do{
     fscanf(F,"%d : %s : %s : %d : %s : %ld\n",&Cl.idclient,&Cl.nom,&Cl.prenom,&Cl.cin,&Cl.adresse,&Cl.telephone);
      if(Id==Cl.idclient)
       {
        Cl.idclient=Id;
        printf("\n  => Entrer le nom de client :  ");
        gets(Cl.nom);
        fflush(stdin);
        printf("\n  => Entrer prenom de client :  ");
        gets(Cl.prenom);
        fflush(stdin);
        printf("\n  => Entrer le cin :");
        scanf("%d",&Cl.cin);
        fflush(stdin);
        printf("\n  => Entrer l'adresse de client :  ");
        gets(Cl.adresse);
        fflush(stdin);
        printf("\n  => Entrer le telephone de client :  ");
        scanf("%d",&Cl.telephone);
        fflush(stdin);
       }
		 fprintf(F,"%d : %s : %s : %d : %s : %ld\n",Cl.idclient,Cl.nom,Cl.prenom,Cl.cin,Cl.adresse,Cl.telephone);
	   }while(!feof(F));
	   fclose(Fich);
	   fclose(F);
	   remove("client.txt");
	   rename("Tempclient.txt","client.txt");
	   printf("\nModification a Reusi!!");
       sleep(5);
       system("cls");
       return menu[2]();

  }
  else
  {
   printf("\n---------- Ce id de voiture n'existe Pas !! ------------\n");
   sleep(5);
   system("cls");
   return menu[2]();
  }
}
void SupprimerClient(){
 int Id;
 printf("\n\t  entrer le id client a supprimer : ");
 scanf("%d",&Id);
 fflush(stdin);
 if(rechClient(Id)==1)
   {
    FILE *F,*Fich;
    F=fopen("client.txt","r");
    Fich=fopen("Tempclient.txt","a");
    do{
    fscanf(F,"%d : %s : %s : %d : %s : %ld\n",&Cl.idclient,&Cl.nom,&Cl.prenom,&Cl.cin,&Cl.adresse,&Cl.telephone);
    if(Id!=Cl.idclient)
      {
        fprintf(Fich,"%d : %s : %s : %d : %s : %ld\n",Cl.idclient,Cl.nom,Cl.prenom,Cl.cin,Cl.adresse,Cl.telephone);
      }
      }while(!feof(F));
     fclose(Fich);
     fclose(F);
     remove("client.txt");
     rename("Tempclient.txt","client.txt");
     printf("\nSuppression Effectuee avec succees!!");
     sleep(5);
     system("cls");
     return menu[2]();
   }

 else
  {
  printf("\n\n -------------------- Ce id de voiture n'existe Pas !! -------------------- ");
  sleep(5);
  system("cls");
  return menu[2]();
  }
}
void main(){
/*****************************Initialisation des function menu de la menu principal********************************/
 menu[0]=menulocation;
 menu[1]=menuvoiture;
 menu[2]=menuclient;
 menu[3]=__exit;
 /*****************************Initialisation des function de la menu localisation********************************/
 menu1[0]=visualisercontrat;
 menu1[1]=LouerVoiture;
 menu1[2]=ModifierContrat;
 menu1[3]=SupprimerContrat;
 menu1[4]=menup;
 /*****************************Initialisation des function de la menu voiture********************************/
 menu2[0]=ListVoiture;
 menu2[1]=AjouterVoiture;
 menu2[2]=ModifierVoiture;
 menu2[3]=SupprimerVoiture;
 menu2[4]=menup;
 /*****************************Initialisation des function de la menu client********************************/
 menu3[0]=ListClient;
 menu3[1]=AjouterClient;
 menu3[2]=ModifierClient;
 menu3[3]=SupprimerClient;
 menu3[4]=menup;
 /*****************************lancez la menu principal********************************/
 menup();
 }
