#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PRODUCTS 100 
#define MAX_PERSONS 100 
#define MAX_FOURNI 100 
#define FILENAME_PRODUCTS "produits.dat" 
#define FILENAME_CLIENTS "clients.dat" 
#define FILENAME_FOURNIS "fournisseurs.dat" 


struct produit {
    int id;
    char name[50];
    float prix;
    int quantite;
};

struct DataProduit {
    struct produit produits[MAX_PRODUCTS];
    int count;
};

struct Client {
    int id;
    char name[50];
    char email[50];
    int ptsfidelite;
};

struct DataClient {
    struct Client clients[MAX_PERSONS];
    int count;
};

struct fournisseur {
    int id;
    char name[50];
    char mail[50];
};

struct DataFournisseur {
    struct fournisseur fournisseurs[MAX_FOURNI];
    int count;
    char *historique[100];
    int counthistorique;
};

void initalisation(struct DataProduit *produitDB,struct DataClient *clientDB,struct DataFournisseur *fourniDB);
void ajouterproduit(struct DataProduit *produitDB);
void modifierproduit(struct DataProduit *produitDB);
void voirproduit(struct DataProduit *produitDB);
void voirclients(struct DataClient *clientDB);
void fairevente(struct DataProduit *produitDB,struct DataClient *clientDB,struct DataFournisseur *fourniDB);
void ajouterfourni(struct DataFournisseur *fourniDB);
void modifierfourni(struct DataFournisseur *fourniDB);
void enregistrerclient(struct DataClient *clientDB);
void modifierclient(struct DataClient *clientDB);
void modifstock(struct DataProduit *produitDB);
void voirnotif(struct DataProduit *produitDB);
void voirhisto(struct DataFournisseur *fourniDB);
void voirfourni(struct DataFournisseur *fourniDB);

int main (){
    struct DataProduit produitDB;
    struct DataClient clientDB;
    struct DataFournisseur fourniDB; 

    int monchoix,mdp;
    int wile = 0;


    while (wile == 0) {
        printf("\n=== Menu ===\n");
        printf("1. Gestionnaire Commerce\n");
        printf("2. Client\n");
        printf("3. Fournisseur\n");
        printf("4. Quitter\n");
        printf("5. Initialise (Pour initialiser les fichiers)\n");
        printf("Qui etes-vous ? (entrez numero) : \n");
        scanf("%d", &monchoix);
    
        switch (monchoix){
            case (1):
                printf("\nBonjour bienvenue dans : Gestionnaire du Commerce\n");
                printf("\nMOT DE PASSE :  (1234 pour correction) \n");
                scanf("%d",&mdp);

                if (mdp == 1234){
                wile = 1 ;
                while (wile == 1) {
                    printf("\n=== Menu ===\n");
                    printf("1. Gestion des Produits\n");
                    printf("2. Gestion des Ventes\n");
                    printf("3. Gestion des Clients\n");
                    printf("4. Gestion des Fournisseurs\n");
                    printf("5. Quitter\n");
                    printf("Que voulez-vous ? (entrez numero) : \n");
                    scanf("%d", &monchoix);

                    switch (monchoix){
                        case (1):
                            printf("\nGestion de produit\n");
							wile = 2;
                            while (wile == 2) {
				printf("\n=== Menu ===\n");
				printf("1. Ajouter\n");
                               printf("2. Modifier\n");
                               printf("3. Voir Produit\n");
                               printf("4. Quitter\n");
                               printf("Que voulez-vous ? (entrez numero) : \n");
                               scanf("%d", &monchoix);

                                switch (monchoix)
                                {
                                case (1):
                                        ajouterproduit(&produitDB);
                                    break;
                                case (2):
                                        modifierproduit(&produitDB);
                                    break;
                                case (3):
                                        voirproduit(&produitDB);
                                    break;
                                case (4):
                                    printf("\nAu Revoir\n");
                                    wile = 1;
                                    break;
                                default:
                                    printf("\nChoix invalide. Veuillez entrer un nombre entre 1 et 3.\n");
                                    break;
                                }
                            }
                            break;                    
                        case (2):
                            	printf("\nGestion des Ventes\n");
				                wile = 2;
                            	while (wile == 2) {
                                    printf("\n=== Menu ===\n");
                                    printf("1. Faire Une Vente\n");
                                    printf("2. Historique des ventes\n");
                                    printf("3. Quitter\n");
                                    printf("Que voulez-vous ? (entrez numero) : \n");
                                    scanf("%d", &monchoix);

                                	switch (monchoix)
		                        {
		                        	case (1):
		                                	fairevente(&produitDB,&clientDB,&fourniDB);
		                            		break;
		                        	case (2):
		                                	printf("Ne fonctionne pas\n");
		                            		break;
		                        	case (3):
		                            		printf("\nAu Revoir\n");
		                            		wile = 1;
		                            		break;
		                       	default:
		                            		printf("\nChoix invalide. Veuillez entrer un nombre entre 1 et 3.\n");
		                            		break;
		                        }
		                    }
		                    break;
                        case (3):
                            printf("\nGestion des Clients\n");
							wile = 2;
                            while (wile == 2) {
                                printf("\n=== Menu ===\n");
                                printf("1. Enregistrer un nouveau Client\n");
                                printf("2. Voir client\n");
                                printf("3. Modifier Information client\n");
                                printf("4. Quitter\n");
                                printf("Que voulez-vous ? (entrez numero) : \n");
                                scanf("%d", &monchoix);

                                switch (monchoix)
                                {
                                case (1):
                                        enregistrerclient(&clientDB);
                                    break;
                                case (2):
                                        voirclients(&clientDB);
                                    break; 
                                case (3):
                                        modifierclient(&clientDB);
                                    break;
                                case (4):
                                    printf("\nAu Revoir\n");
                                    wile = 1;
                                    break;
                                default:
                                    printf("\nChoix invalide. Veuillez entrer un nombre entre 1 et 4.\n");
                                    break;
                                }
                            }
                            break;
                        case (4):
                            printf("\nGestion des Fournisseur\n");
							wile = 2;
                            while (wile == 2) {
                                printf("\n=== Menu ===\n");
                                printf("1. Ajouter un fournisseur\n");
                                printf("2. Voir Fournisseur\n");
                                printf("3. Modifier les informations sur les fournisseurs\n");
                                printf("4. Suivre commandes passees\n");
                                printf("5. Quitter\n");
                                printf("Que voulez-vous ? (entrez numeero) : \n");
                                scanf("%d", &monchoix);

                                switch (monchoix)
                                {
                                case (1):
                                        ajouterfourni(&fourniDB);
                                    break;
                                case(2):
                                        voirfourni(&fourniDB);
                                        break;
                                case (3):
                                        modifierfourni(&fourniDB);
                                    break;
                                case (4):
                                        voirhisto(&fourniDB);
                                    break;
                                case (5):
                                    printf("\nAu Revoir\n");
                                    wile = 1;
                                    break;
                                default:
                                    printf("\nChoix invalide. Veuillez entrer un nombre entre 1 et 4.\n");
                                    break;
                                }
                            }
                            break;
                        case (5):
                            printf("\nAu Revoir\n");
                            wile = 0;
                            break;
                        default:
                            printf("\nChoix invalide. Veuillez entrer un nombre entre 1 et 4.\n");
                            break;
                    }
                }
                }else
                    printf("\n Mot de Passe incorect \n");   
                
                break;
            case (2):
                printf("\nBienvenue : Client\n");
                wile = 1;
                while (wile == 1) {
                    printf("\n=== Menu ===\n");
                    printf("1. Voir Produit\n");
                    printf("2. Acheter Produit\n");
                    printf("3. Quitter\n");
                    printf("Que voulez-vous ? (entrez numero) : \n");
                    scanf("%d", &monchoix);

                    switch (monchoix){
                        case (1):
                            voirproduit(&produitDB);
                            break;
                        case (2): 
                            fairevente(&produitDB,&clientDB,&fourniDB);
                            break;
                        case (3):
                            printf("\nAu Revoir\n");
                            wile = 0;
                            break;
                        default:
                            printf("\nChoix invalide. Veuillez entrer un nombre entre 1 et 3.\n");
                            break;

                    }
                }
                break; 
            case (3):
                printf("\nBienvenue : Fournisseur\n");
                printf("\nMOT DE PASSE :  (4321 pour correction)\n");
                scanf("%d",&mdp);

                if (mdp == 4321){

                wile = 1;
                while (wile == 1) {
                	printf("\n=== Menu ===\n");
			printf("1. Modifier les informations sur les fournisseurs \n");
			printf("2. Suivre commandes passees\n");
			printf("3. Mise à jour des stocks\n");
			printf("4. Voir Notifications\n");
                    	printf("5. Voir Produit\n");
		      	printf("6. Quitter\n");
		      	printf("Que voulez-vous ? (entrez numero) : \n");
		      	scanf("%d", &monchoix);

                    switch (monchoix){
                        case (1):
                            modifierfourni(&fourniDB);
                            break;
                        case (2): 
                            voirhisto(&fourniDB);
                            break;
                        case (3):
                            modifstock(&produitDB);
                            break;
                        case (4):
                            voirnotif(&produitDB);
                            break;
                        case (5):
                            voirproduit(&produitDB);
                            break;
                        case (6):
                            printf("\nAu Revoir\n");
                            wile = 0;
                            break;
                        default:
                            printf("\nChoix invalide. Veuillez entrer un nombre entre 1 et 3.\n");
                            break;

                    }
                }
                }else 
                    printf("\n Mot de Passe incorect \n");  
                    
                break;
            case (4):
                wile = -1;
                break;
            case (5): 
                initalisation(&produitDB,&clientDB,&fourniDB);
                break;
            default: 
                printf("\nChoix invalide. Veuillez entrer un nombre entre 1 et 3.\n");
                break;
        
        }
    }
    printf("\nCIAO, MERCI et A BIENTOOOOT\n");
    return 0;    
}


void initalisation(struct DataProduit *produitDB, struct DataClient *clientDB, struct DataFournisseur *fourniDB) {
    FILE *file1;
    FILE *file2;
    FILE *file3;

    file1 = fopen(FILENAME_PRODUCTS, "wb"); 
    file2 = fopen(FILENAME_CLIENTS, "wb"); 
    file3 = fopen(FILENAME_FOURNIS, "wb"); 

    produitDB->count = 0;
    clientDB->count = 0;
    fourniDB->count = 0;
    fourniDB->counthistorique = 0;

    fwrite(&produitDB->count, sizeof(int), 1, file1);
    fwrite(&clientDB->count, sizeof(int), 1, file2);
    fwrite(&fourniDB->count, sizeof(int), 1, file3);
    
    fclose(file1);
    fclose(file2);
    fclose(file3);
    printf("fait");
} 





void ajouterproduit(struct DataProduit *produitDB) {
    FILE *file;
    int id;

    file = fopen(FILENAME_PRODUCTS, "rb+");

    if (file == NULL) {
    	printf("Erreur lors de l'ouverture du fichier.\n");
    	return;
    }
	
	fread(&produitDB->count, sizeof(int), 1, file);
   	produitDB->count = produitDB->count +1;
   	id = produitDB->count;
 
    printf("ID produit : %d\n", id);
    printf("Entrez le nom du produit : \n");
    scanf("%s", produitDB->produits[id].name);
    printf("Entrez le prix du produit : \n");
    scanf("%f", &produitDB->produits[id].prix);
    printf("Entrez la quantite : \n");
    scanf("%d", &produitDB->produits[id].quantite);

    produitDB->produits[id].id = id;
	

    
    fseek(file, 0, SEEK_SET);
   
    fwrite(&produitDB->count, sizeof(int), 1, file);

    fseek(file, sizeof(int) + id * sizeof(struct produit), SEEK_SET);

    fwrite(&produitDB->produits[id], sizeof(struct produit), 1, file);

    fclose(file);
}


void ajouterfourni(struct DataFournisseur *fourniDB) {
    FILE *file;
    int id;

    file = fopen(FILENAME_FOURNIS, "rb+");

    if (file == NULL) {
    	printf("Erreur lors de l'ouverture du fichier.\n");
    	return;
    }
	
	fread(&fourniDB->count, sizeof(int), 1, file);
   	fourniDB->count = fourniDB->count +1;
   	id = fourniDB->count;
 

    printf("Entrez le nom du fournisseur : \n");
    scanf("%s", fourniDB->fournisseurs[id].name);
    printf("Entrez le mail du fournisseur : \n");
    scanf("%s", fourniDB->fournisseurs[id].mail);

    printf("ID Fournisseur : %d\n", id);
    

    fourniDB->fournisseurs[id].id = id;
	

    
    fseek(file, 0, SEEK_SET);
   
    fwrite(&fourniDB->count, sizeof(int), 1, file);

    fseek(file, sizeof(int) + id * sizeof(struct fournisseur), SEEK_SET);

    fwrite(&fourniDB->fournisseurs[id], sizeof(struct fournisseur), 1, file);

    fclose(file);
}


void enregistrerclient(struct DataClient *clientDB) {
    FILE *file;
    int id;

    file = fopen(FILENAME_CLIENTS, "rb+");

    if (file == NULL) {
    	printf("Erreur lors de l'ouverture du fichier.\n");
    	return;
    }
	
	fread(&clientDB->count, sizeof(int), 1, file);
   	clientDB->count = clientDB->count +1;
   	id = clientDB->count;
 
    
    printf("ID Client : %d\n", id);
    printf("Entrez le nom du client : \n");
    scanf("%s", clientDB->clients[id].name);
    printf("Entrez l'email du client : \n");
    scanf("%s", clientDB->clients[id].email);
    printf("Initialisation de la cagnotte à 0 \n");
    clientDB->clients[id].ptsfidelite = 0;

    clientDB->clients[id].id = id;
	

    
    fseek(file, 0, SEEK_SET);
   
    fwrite(&clientDB->count, sizeof(int), 1, file);

    fseek(file, sizeof(int) + id * sizeof(struct Client), SEEK_SET);

    fwrite(&clientDB->clients[id], sizeof(struct Client), 1, file);

    fclose(file);
}





void modifierfourni(struct DataFournisseur *fourniDB) {
    FILE *file;
    int id;

    file = fopen(FILENAME_FOURNIS, "rb+");

    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    printf("Donnez l'ID du fournisseur : \n");
    scanf("%d", &id);

    fread(&fourniDB->count, sizeof(int), 1, file);

    if (id < 1 || id > fourniDB->count) {
        printf("ID invalide.\n");
        fclose(file);
        return;
    }

    printf("Fournisseur : %s\n", fourniDB->fournisseurs[id].name);
    printf("Entrez le nouveaux nom du fournisseur (pour l'ID %d) : \n", id);
    scanf("%s", fourniDB->fournisseurs[id].name);
    printf("Entrez le nouveaux mail du fournisseur (pour l'ID %d) : \n", id);
    scanf("%s", fourniDB->fournisseurs[id].mail);
    printf("Nouvelle produit mise à jour. Merci.\n");

    fseek(file, sizeof(int) + (id) * sizeof(struct fournisseur), SEEK_SET);
    fwrite(&fourniDB->fournisseurs[id], sizeof(struct fournisseur), 1, file);

    fclose(file);
}


void modifierproduit(struct DataProduit *produitDB) {
    FILE *file;
    int id;

    file = fopen(FILENAME_PRODUCTS, "rb+");

    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    printf("Donnez l'ID du produit : \n");
    scanf("%d", &id);

    fread(&produitDB->count, sizeof(int), 1, file);

    if (id < 1 || id > produitDB->count) {
        printf("ID invalide.\n");
        fclose(file);
        return;
    }

    printf("Produit : %s\n", produitDB->produits[id].name);
    printf("Entrez le nouveaux nom du produit (pour l'ID %d) : \n", id);
    scanf("%s", produitDB->produits[id].name);
    printf("Entrez le nouveaux prix du produit (pour l'ID %d) : \n", id);
    scanf("%f", &produitDB->produits[id].prix);
    printf("Entrez la nouvelle quantite du produit (pour l'ID %d) : \n", id);
    scanf("%d", &produitDB->produits[id].quantite);
    printf("Nouvelle produit mise à jour. Merci.\n");

    fseek(file, sizeof(int) + (id) * sizeof(struct produit), SEEK_SET);
    fwrite(&produitDB->produits[id], sizeof(struct produit), 1, file);

    fclose(file);
}






void voirnotif(struct DataProduit *produitDB){
    FILE *file;
    int notif = 0;

    file = fopen(FILENAME_PRODUCTS, "rb+");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    if (fread(&produitDB->count, sizeof(int), 1, file) != 1) {
        printf("Erreur lors de la lecture du nombre de produits dans le fichier.\n");
        fclose(file);
        return;
    }

    fseek(file, sizeof(int), SEEK_SET); 

    for (int i = 0; i <= produitDB->count; i++) {
        if (fread(&produitDB->produits[i], sizeof(struct produit), 1, file) != 1) {
            printf("Erreur de lecture des donnees du produit depuis le fichier.\n");
            fclose(file);
            return;
        }

        if (produitDB->produits[i].quantite <= 5){
            if (produitDB->produits[i].id != 0){
                notif = notif +1;
                printf("\nNotif %d : Attention !! Il reste %d %s\n",notif,produitDB->produits[i].quantite,produitDB->produits[i].name);
            }
        }
    }
    if (notif == 0) 
        printf("Il n'y a pas de notification \n");

    fclose(file);
}


void voirproduit(struct DataProduit *produitDB) {
    FILE *file;

    file = fopen(FILENAME_PRODUCTS, "rb+");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    
    if (fread(&produitDB->count, sizeof(int), 1, file) != 1) {
        printf("Erreur lors de la lecture du nombre de produits dans le fichier.\n");
        fclose(file);
        return;
    }

    fseek(file, sizeof(int), SEEK_SET); 

    for (int i = 0; i <= produitDB->count; i++) {
        if (fread(&produitDB->produits[i], sizeof(struct produit), 1, file) != 1) {
            printf("Erreur de lecture des donnees du produit depuis le fichier.\n");
            fclose(file);
            return;
        }

        if (produitDB->produits[i].id != 0){
            printf("\nID Produit : %d\n", produitDB->produits[i].id);
            printf("Nom : %s\n", produitDB->produits[i].name);
            printf("Prix : %.2f\n", produitDB->produits[i].prix);
            printf("Quantite : %d\n", produitDB->produits[i].quantite);
        }
    }

    fclose(file);
}


void voirclients(struct DataClient *clientDB) {
    FILE *file;

    file = fopen(FILENAME_CLIENTS, "rb+");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    
    if (fread(&clientDB->count, sizeof(int), 1, file) != 1) {
        printf("Erreur lors de la lecture du nombre de clients dans le fichier.\n");
        fclose(file);
        return;
    }

    fseek(file, sizeof(int), SEEK_SET); 

    for (int i = 0; i <= clientDB->count; i++) {
        if (fread(&clientDB->clients[i], sizeof(struct Client), 1, file) != 1) {
            printf("Erreur de lecture des données du client depuis le fichier.\n");
            fclose(file);
            return;
        }

        if (clientDB->clients[i].id != 0){
            printf("\nID Client : %d\n", clientDB->clients[i].id);
            printf("Nom : %s\n", clientDB->clients[i].name);
            printf("Email : %s\n", clientDB->clients[i].email);
            printf("Points de fidelite : %d\n", clientDB->clients[i].ptsfidelite);
        }
    }

    fclose(file);
}


void voirfourni(struct DataFournisseur *fourniDB) {
    FILE *file;

    file = fopen(FILENAME_FOURNIS, "rb+");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

   
    if (fread(&fourniDB->count, sizeof(int), 1, file) != 1) {
        printf("Erreur lors de la lecture du nombre de produits dans le fichier.\n");
        fclose(file);
        return;
    }

    fseek(file, sizeof(int), SEEK_SET); 

    for (int i = 0; i <= fourniDB->count; i++) {
        if (fread(&fourniDB->fournisseurs[i], sizeof(struct fournisseur), 1, file) != 1) {
            printf("Erreur de lecture des données du fournisseur depuis le fichier.\n");
            fclose(file);
            return;
        }

        if (fourniDB->fournisseurs[i].id != 0){
            printf("\nID Fournisseur : %d\n", fourniDB->fournisseurs[i].id);
            printf("Nom : %s\n", fourniDB->fournisseurs[i].name);
            printf("Prix : %s\n", fourniDB->fournisseurs[i].mail);
        }
    }

    fclose(file);
}




void fairevente(struct DataProduit *produitDB, struct DataClient *clientDB, struct DataFournisseur *fourniDB) {
    	int id, quantitee,choix,idd;
    	float tot;
    	

    	FILE *file1;
    	FILE *file2;
    	FILE *file3;
    	
    	

    	file1 = fopen(FILENAME_PRODUCTS, "rb+"); 
    	file2 = fopen(FILENAME_CLIENTS, "rb+"); 
    	file3 = fopen(FILENAME_FOURNIS, "rb+"); 
    	
    	if (file1 == NULL || file2 == NULL || file3 == NULL) {
       	printf("Erreur lors de l'ouverture du fichier.\n");
		fclose(file1);
		fclose(file2);
		fclose(file3);
		return;
    	}

    	printf("\nDonnez l'id du produit que vous voulez acheter : \n");
    	scanf("%d", &id);

        fread(&produitDB->count, sizeof(int), 1, file1);

    	for (int i = 0; i <= produitDB->count; i++) {
        	if (produitDB->produits[i].id == id) {
            		float prixx = produitDB->produits[i].prix;
                    	printf("Le produit est : %s\n",produitDB->produits[i].name);
            		printf("Le prix de l'article est de : %.2f\n", prixx);
                    	printf("Il en reste %d : \n",produitDB->produits[i].quantite);
                    	
                    	if (produitDB->produits[i].quantite <= 0){
                    		printf("Le produit est sold out pardon :( \n");
                    		return;
                    	}
                    	
            		printf("Combien de quantite voulez-vous ? : \n");
            		scanf("%d", &quantitee);
            		
            		if (produitDB->produits[i].quantite - quantitee <0 ){
            			printf("Vous ne pouvez pas en prendre autant désolé :(");
            			return;
            		}

            		tot = quantitee * prixx;

            		printf("Vous devez payer : %.2f\n", tot);

            		produitDB->produits[i].quantite -= quantitee;
            		
            		fseek(file1, sizeof(int) + id * sizeof(struct produit), SEEK_SET);

   			fwrite(&produitDB->produits[id], sizeof(struct produit), 1, file1);
                    
            }
    	}

         
	choix=0;
    	printf("Etes-vous client ? (1.oui ou 2.non) : \n");
    	scanf("%d",&choix);

    	if (choix == 1) {
        	
        	printf("Merci aux clients fidèles.\n");
        	printf("Donnez votre ID : \n");
        	scanf("%d", &id);
            
            	fread(&clientDB->count, sizeof(int), 1, file2);

        	for (int i = 0; i <= clientDB->count; i++) {
            		if (id == clientDB->clients[i].id) {
                		int pts = clientDB->clients[i].ptsfidelite;

                		printf("Vous avez %d de points, voulez les utiliser maintenant ? (1.oui ou 2.non) : \n", pts);
                		scanf("%d",&choix);

                		if (choix == 1){
                			if (pts >= tot){
                				tot -= tot ;
                				clientDB->clients[i].ptsfidelite = pts - tot ;
                				pts = pts - tot;
                				printf("Ok, vous devez maintenant payer : %.2f\n", tot);
                				printf("il vous reste : %d\n points", pts);
                    			}else{
                    				tot -= pts ;
                    				clientDB->clients[i].ptsfidelite = pts - tot;
                				printf("Ok, vous devez maintenant payer : %.2f\n", tot);
                				pts = tot - pts ;
                				printf("il vous reste : %d\n points \n", pts);
                    			}
                    		
                		}
                		clientDB->clients[i].ptsfidelite = pts;
                		clientDB->clients[i].ptsfidelite = clientDB->clients[i].ptsfidelite + 2;
                		printf("On rajoute 2 points sur votre compte fidélité.\n");  // 2 points par vente pour le client
                		
                		fseek(file2, sizeof(int) + id * sizeof(struct Client), SEEK_SET);
                		
                		fwrite(&clientDB->clients[i], sizeof(struct Client), 1, file2);
            	}
        	}
    	}
	
	fread(&fourniDB->counthistorique, sizeof(int), 1, file3);
	
	fourniDB->counthistorique = fourniDB->counthistorique +1 ;
	idd = fourniDB->counthistorique;
	fourniDB->historique[idd] = "mamam";
	
	fseek(file3, sizeof(int) + id * sizeof(struct DataFournisseur), SEEK_SET);       		
        fwrite(&fourniDB->historique[idd], sizeof(struct DataFournisseur), 1, file3);
	
	fseek(file3, 0, SEEK_SET);
  	fwrite(&fourniDB->counthistorique, sizeof(int), 1, file3);
	
    	printf("Merci de Votre Achat\n");

    	fclose(file1);
    	fclose(file2);
    	fclose(file3);
    	
	
    	return;
}



void modifierclient(struct DataClient *clientDB) {
    	FILE *file;
    	int id;

    	file = fopen(FILENAME_CLIENTS, "rb+");

    	if (file == NULL) {
        	printf("Erreur lors de l'ouverture du fichier.\n");
        	fclose(file);
        	return;
    	}

        fread(&clientDB->count, sizeof(int), 1, file);

    	printf("Donnez l'ID du client : \n");
    	scanf("%d", &id);
    	if (id < 1 || id > clientDB->count) {
        	printf("ID invalide.\n");
        	fclose(file);
        	return;
    	}

    	printf("Entrez le nouveau nom du client (pour l'ID %d) : \n", id);
    	scanf("%s", clientDB->clients[id].name);
    
    	printf("Entrez le nouvel email (pour l'ID %d) : \n", id);
    	scanf("%s", clientDB->clients[id].email);
    
    	printf("Entrez la nouvelle cagnotte fidelite (pour l'ID %d) : \n", id);
    	scanf("%d", &clientDB->clients[id].ptsfidelite);

    	fseek(file, sizeof(int) + id * sizeof(struct Client), SEEK_SET);
    	fwrite(&clientDB->clients[id], sizeof(struct Client), 1, file);

    	fclose(file);
    	return;
}


void modifstock(struct DataProduit *produitDB) {
 FILE *file;
    int id;

    file = fopen(FILENAME_PRODUCTS, "rb+");

    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    printf("Donnez l'ID du produit : \n");
    scanf("%d", &id);

    fread(&produitDB->count, sizeof(int), 1, file);

    if (id < 1 || id > produitDB->count) {
        printf("ID invalide.\n");
        fclose(file);
        return;
    }

    printf("Produit : %s\n", produitDB->produits[id].name);
    printf("Quantite actuel : %d\n", produitDB->produits[id].quantite);
    printf("Entrez la nouvelle quantite du produit : %d \n", id);
    scanf("%d", &produitDB->produits[id].quantite);
    printf("Nouvelle produit mise à jour. Merci.\n");

    fseek(file, sizeof(int) + (id) * sizeof(struct produit), SEEK_SET);
    fwrite(&produitDB->produits[id], sizeof(struct produit), 1, file);

    fclose(file);
}


 void voirhisto (struct DataFournisseur *fourniDB){
   	 FILE *file;
   	 int idd;

    	file = fopen(FILENAME_FOURNIS, "rb+");

    	if (file == NULL) {
        	printf("Erreur lors de l'ouverture du fichier.\n");
        	return;
    	}
	fseek(file, sizeof(int), SEEK_SET); 
	fread(&fourniDB->counthistorique, sizeof(int), 1, file);
    	
    	idd = fourniDB->counthistorique;

	int notif = 0;
    	for (int i = 1; i <= idd; i++){
    		
    		notif = notif +1 ;
    		fread(&fourniDB->historique[i], sizeof(char), 1, file);
       	printf("Hisorique %d : %s \n",i,fourniDB->historique[i]);
   	}	
	
	if (notif == 0) 
        	printf("\nIl n'y a pas d'historique \n");
    	
    	fclose(file);
}

 
