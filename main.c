#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct{
    int jour;
    int mois;
    int annee;
}datatime;


 typedef struct{
      char code [10];
      char nom [10];
      int quantite;
      float prix;
      float TTC;
      datatime dateT;
      int produitVendu;
      float totalvendu;

 }produit;
  produit info [1000];
  Tindix=0;





         void AjouterNVproduits(){    // ajoutee seul produit
           int i;
           printf(" AJOUTER UN NOUVEAU PRODUIT:\n");
           printf("---------------\n");
           printf(" Entrer le code de produit: ");
           scanf("%s",&info[Tindix].code);
           printf(" Entrer le nom de produit: ");
           scanf("%s",&info[Tindix].nom);
           printf(" Entrer la quantite de produit: ");
           scanf("%d",&info[Tindix].quantite);
           printf(" Entrer le prix de produit: ");
           scanf("%f",&info[Tindix].prix);
           info[i].TTC=info[i].prix+info[i].prix*0.15;
           Tindix++;
          }





      void  AjouterPLproduits(){      // ajouter plusieur produit
        int nbrP;
        int N=1;
            printf(" AJOUTER PLUSIUER PRODUIT:\n");
            printf(" ---------------\n");
            printf(" Entrez le nombre de produits que vous voulez ajouter: ");
            scanf("%d",&nbrP);
            printf(" ---------------\n");

        for(int i=0;i<nbrP;i++){
           printf(" Entrer le code de produit %d: ",N);
           scanf("%s",info[Tindix].code);
           printf(" Entrer le nom de produit %d: ",N);
           scanf("%s",info[Tindix].nom);
           printf(" Entrer la quantite de produit %d: ",N);
           scanf("%d",&info[Tindix].quantite);
           printf(" Entrer le prix de produit %d: ",N);
           scanf("%f",&info[Tindix].prix);
           info[i].TTC=info[i].prix+info[i].prix*0.15;
           printf(" --------------\n");
           Tindix++;
           N++;
     }
    }



        void TRIPARPRIX(){      // lister tous les produits selon l’ordre  décroissant du prix.

            int i,j;
            produit temp;
         for(i=0;i<Tindix-1;i++)
         {
             for(j=0;j<Tindix-i-1;j++){
                if(info[j].prix<info[j+1].prix){
                    temp = info[j];
                    info[j] = info[j+1];
                    info[j+1] = temp;
                }
             }
         }

       for(i=0;i<Tindix;i++){
            printf(" Le code: %s\n",info[i].code);
            printf(" La quantite: %d\n",info[i].quantite);
            printf(" Le nom: %s\n",info[i].nom);
            printf(" Le prix: %.2f\n",info[i].prix);
            printf(" Le prix TTC: %.2f\n",info[i].TTC);
            printf(" le total vendu de ce produits est: %.2fDH\n",info[i].totalvendu);
            printf(" ----------------\n");
        }
      }



      void TRIPARAPLPHA(){   //Lister tous les produits selon l’ordre alphabétique  croissant du nom.

          int i,j;
          produit c;
          for(i=0;i<Tindix;i++)
         {
             for(j=0;j<Tindix;j++){
                if(strcmp(info[i].nom, info[j].nom) < 0 ){
                    c = info[i];
                    info[i] = info[j];
                    info[j] = c;
                }
             }
         }

       for(i=0;i<Tindix;i++){
            printf(" Le code: %s\n",info[i].code);
            printf(" La quantite: %d\n",info[i].quantite);
            printf(" Le nom: %s\n",info[i].nom);
            printf(" Le prix: %.2f\n",info[i].prix);
            printf(" Le prix TTC: %.2f\n",info[i].TTC);
            printf("le total vendu de ce produits est: %.2f\n",info[i].totalvendu);
            printf(" ----------------\n");
        }
      }





    void RechercherProduitsCD(){    //Rechercher les produits Par CODE
    char CODE[10];
    int i;
    int x=0;
    printf("ENTREE LE CODE DE PRODUIT RECHERCHER: ");
    scanf("%s",CODE);
    for(i=0;i<Tindix;i++){
        if(strcmp(CODE,info[i].code)==0){
            x=1;
            printf(" ---------------\n");
            printf(" Le code de produit: %s\n",info[i].code);
            printf(" Le nom de produit: %s\n",info[i].nom);
            printf(" La quantite de produit: %d\n",info[i].quantite);
            printf(" Le prix de produit: %.2f DH\n",info[i].prix);
            printf(" Le code de produit TTC: %.2f DH\n",info[i].TTC);
            printf(" ---------------\n");

        }
      }
         if(x==0){
        printf(" Le produit n'existe pas!\n");

    }
  }






    void RechercherProduitsCT(){   // Rechercher les produits Par QUANTITE
    int QUANTITE;
    int i;
    int x=0;
    printf(" ENTREE LA QUANTITE DE PRODUIT RECHERCHER: ");
    scanf("%d",&QUANTITE);
    for(int i=0;i<Tindix;i++){
        if(QUANTITE==info[i].quantite){
            x=1;
            printf(" ---------------\n");
            printf(" Le code de produit: %s\n",info[i].code);
            printf(" Le nom de produit: %s\n",info[i].nom);
            printf(" La quantite de produit: %d\n",info[i].quantite);
            printf(" Le prix de produit: %.2f DH\n",info[i].prix);
            printf(" Le code de produit TTC: %.2f DH\n",info[i].TTC);
            printf(" ---------------\n");

        }
    }
         if(x==0){
        printf(" Cette quantite n'existe pas!\n");

    }
  }






   void SupprimerProduits(){   //Supprimer les produits par CODE

       int i,j;
       char CD [10];
       int x=0;
       printf(" SUPRIMMER UN PRODUIT! \n");
       printf(" ------------\n");
       printf("entrer le code de produit: ");
       scanf("%s",CD);

       for(i=0;i<Tindix;i++){
                if(strcmp(CD,info[i].code)==0){
                 x=1;
                 for(j=i;j<Tindix;j++){
                 info[j]=info[j+1];

       }
       printf(" LE PRODUIT EST SUPRIMMER!");
       Tindix--;
      }}
      if(x==0){
       printf("error!\n");
      }
   }




    void  EtatStock(){  //afficher les produits dont la quantité est inférieure à 3.
        int i;
        int q=0;
        for(i=0;i<Tindix;i++){
            if(info[i].quantite<3){
            printf(" LE PRODUIT DONT LA QUANTITE INFIRIEURE A 3 : \n");
            printf(" ---------------\n");
            printf(" Le code de produit: %s\n",info[i].code);
            printf(" Le nom de produit: %s\n",info[i].nom);
            printf(" La quantite de produit: %d\n",info[i].quantite);
            printf(" Le prix de produit: %.2f DH\n",info[i].prix);
            printf(" Le prix de produit TTC: %.2f DH\n",info[i].TTC);
            q=1;
            printf("---------------\n");
         }
        }
        if(q==0){
            printf(" TOUT LES PRODUIT DONT LA QUANTITE PLUS DE 3");
        }
       }



    void  AlimenterStock(){  //Alimenter le stock
        int cn,i,j=0;
        char cd [10];
        printf(" ALIMENTER LE STOCK.\n");
        printf(" ---------------\n");
        printf(" Entrer le code de produit: ");
        scanf("%s",cd);

        for(i=0;i<Tindix;i++){
            if(strcmp(cd,info[i].code)==0){
                printf(" ---------------\n");
                printf(" Entrer la quantite : ");
                scanf("%d",&cn);
                info[i].quantite+= cn;
                j=1;
            }
        }
        if(j==0){
          printf(" Le code incorrect!\n");
        }
    }





    void AcheterProduit(){      //achter un produit

        time_t t = time(NULL);
        struct tm tm = *localtime(&t); // FONCTION TIME

        int i,j=0;
        char cdd[10];
        int k;
        printf(" ACHTER UN PRODUIT!\n");
        printf(" ---------------\n");
        printf(" Entrez le code des produits que vous voulez achetez: ");
        scanf("%s",cdd);
        printf(" ---------------\n");
        for(i=0;i<Tindix;i++){
            if(strcmp(cdd,info[i].code)==0){       // verification de code
                printf(" Entrer la quantite: ");
                scanf("%d",&k);
                if(info[i].quantite>=k){        // esque la quantite acheter inferieure a la quantite de stock
                    info[i].produitVendu += k;
                    info[i].totalvendu = info[i].produitVendu * info[i].prix; //Quantite acheter fois prix
                    info[i].quantite-=info[i].produitVendu;  // desalimenter le stock
                    info[i].dateT.jour=tm.tm_mday;
                    info[i].dateT.mois=tm.tm_mon + 1;
                    info[i].dateT.annee=tm.tm_year + 1900;
                    j=1;
                    printf("---------------\n");
                    printf(" Votre achat est un success");
                }else{
                    printf("quantite non disponible\n");
                }
            }
        }
        if(j==0){
            printf("Le code incorrect!");
    }
  }





  void tritotalvendu(){  // le tri des total produit vendu
    produit temp;
    for(int i=0;i<Tindix - 1;i++){
        for(int j=i+1;j<Tindix;j++){
            if(info[i].totalvendu !=0){
            if(info[i].totalvendu < info[j].totalvendu){
                temp = info[i];
                info[i] = info[j];
                info[j] = temp;
                }
            }
        }
    }
}



   void  StatistiqueVente(){  // LES 4 statistic de vente

        time_t t = time(NULL);
        struct tm tm = *localtime(&t);

       int i;
     int h;
     printf(" 1: Afficher le total des prix des produits vendus en journee courante\n");
     printf(" ---------------\n");
     printf(" 2: Afficher la moyenne des prix des produits vendus en journee courante\n");
     printf(" ---------------\n");
     printf(" 3: Afficher le Max des prix des produits vendus en journee courante\n");
     printf(" ---------------\n");
     printf(" 4: Afficher le Min des prix des produits vendus en journee courante\n");
     printf(" ---------------\n");
     printf(" Entrer votre choix: ");
     scanf("%d",&h);
     printf(" ---------------\n");


     float moyenne=0;
     float somme=0;
     float x=0;
     if(h!=1&&h!=2&&h!=3&&h!=4){
        printf(" Choix incorrect!");
     }
     if(h==1){
      for(i=0;i<Tindix;i++){
        if( info[i].dateT.jour==tm.tm_mday && info[i].dateT.mois==tm.tm_mon + 1 && info[i].dateT.annee==tm.tm_year + 1900){

                 somme=somme+(info[i].produitVendu)*(info[i].prix); // calcule la somme des produit vendu
            }



     }
     printf(" Le total des prix des produits vendu est: %.2f DH\n",somme);
   }

     if(h==2){
      for(i=0;i<Tindix;i++){
        if( info[i].dateT.jour==tm.tm_mday && info[i].dateT.mois==tm.tm_mon + 1 && info[i].dateT.annee==tm.tm_year + 1900){
         if(info[i].produitVendu!=0){
            somme=somme+(info[i].produitVendu*info[i].prix);
            x+=info[i].produitVendu;

          }
        }
     }
     moyenne=somme/x; // la moyenne des produit vendu
     printf(" La moyenne des prix des produits vendu est: %.2f DH\n",moyenne);

  }



    if(h==3){    // pour afficher e Max des prix des produits vendu

        tritotalvendu(); // le tri des total produit vendu
      for(i=0;i<Tindix;i++){
        if( info[i].dateT.jour==tm.tm_mday && info[i].dateT.mois==tm.tm_mon + 1 && info[i].dateT.annee==tm.tm_year + 1900){

        printf(" le Max des prix des produits vendus est: %.2f DH\n",info[i].totalvendu);
        printf(" le prix: %.2f\n",info[i].prix);
        printf(" le code de produit: %s\n",info[i].code);
        printf(" le nom de produit: %s\n",info[i].nom);
        printf(" la quantite de produit: %d\n",info[i].quantite);
        break;
    }
  }
}



   if(h==4){  // pour afficher e Min des prix des produits vendu

         tritotalvendu(); // le tri des total produit vendu
      for(i =Tindix;i>  0;i--){
        if( info[i].dateT.jour==tm.tm_mday && info[i].dateT.mois==tm.tm_mon + 1 && info[i].dateT.annee==tm.tm_year + 1900){

        printf(" le Min des prix des produits vendus est: %.2f DH\n",info[i].totalvendu);
        printf(" le prix: %.2f\n",info[i].prix);
        printf(" le code de produit %s\n",info[i].code);
        printf(" le nom de produit %s\n",info[i].nom);
        printf(" la quantite de produit %d\n",info[i].quantite);
        break;

    }

  }
 }
}


  void menu(){
      int b,c;

     int choix;

     do{
  printf("\t\t\t\t\t\tWELCOME !\n");
  printf("\t\t\t\t\t GESTION DE PHARMACIE\n");
  printf("\t\t\t\t\t\t-------\n");
  printf(" 1:  Ajouter un nouveau produit.\n 2:  Ajouter plusieurs nouveaux produits.\n");
  printf(" 3:  Lister tous les produits.\n 4:  Acheter produit.\n");
  printf(" 5:  Rechercher les produits.\n");
  printf(" 6:  Etat du stock.\n");
  printf(" 7:  Alimenter le stock.\n 8:  Supprimer les produits.\n");
  printf(" 9:  Statistique de vente.\n 10: Quitter:\n");
  printf("\t\t\t\t\tENTRER VOTRE CHOIX : ");
  scanf("%d",&choix);

    switch(choix)
    {
    case 1:
       AjouterNVproduits();
       break;
    case 2:
       AjouterPLproduits();
       break;
    case 3:
         printf(" POUR AFFICHER LES PRODUIT PAR ORDRE CROISSANT ALPHABETIQUE ENTRER 1\n");
         printf("---------------\n");
         printf(" POUR AFFICHER LES PRODUIT PAR ORDRE DECROISSANT PAR PRIX ENTRER 2\n");
         printf("---------------\n");
         printf(" ENTRER VOTRE CHOIX: ");
         scanf("%d",&b);
         switch(b){
         case 2:
         TRIPARPRIX();
         break;
         case 1:
         TRIPARAPLPHA();
         break;
         default:
         printf("ERROR! ENTRER 1 OU 2");
         }
          break;
     case 4:
        AcheterProduit();
        break;
     case 5:
        printf("Entrer 1 pour Rechercher les produits Par code: \n");
        printf("Entrer 1 pour Rechercher les produits Par code: \n");
        printf(" -------------\n");
        scanf("%d",&c);
        switch(c){
        case 1:
        RechercherProduitsCD();
        break;
        case 2:
        RechercherProduitsCT();
        break;
        default:
        printf("ERROR! ENTER 1 OU 2\n");
        }
        break;
    case 6:
        EtatStock();
        break;
    case 7:
        AlimenterStock();
        break;
    case 8:
        SupprimerProduits();
        break;
    case 9:
        StatistiqueVente();
        break;
    default:
         printf("entrer un choix exacte");
         break;
        }
    }while(choix!=10);
}


  int main()
{
    menu();
    return 0;
}
