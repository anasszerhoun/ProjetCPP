#include <iostream>
#include <vector>
#include "header.h"
#include "voyageur.h"
#include "billet.h"
#include <cstdlib>
using namespace std;

void checklogin(){
    string login="",pass="";

    while(pass!="admin" || login!="admin"){
        cout << "\x1b[36m";
        cout << "                                             ----------------------------------------------                 " << endl;
        cout << "                                             -                                            -                "<<endl;
        cout << "                                             -        Gare routiere Casablanca            -                "<<endl;
        cout << "                                             -                                            -               "<<endl;
        cout << "                                             ----------------------------------------------               \n\n\n\x1b[0m"<<endl;
        cout<<"\n\n\n";
        cout<<"\x1b[32m ";
        cout<<"                                                         - LOGIN :\x1b[0m ";
        cin>>login;
        cout<<"\n\n";
        cout<<"\x1b[32m ";
        cout<<"                                                         - PASSWORD :\x1b[0m ";
        cin>>pass;
        system("cls");

    }
}

void AjouterBus(vector<bus> &Buses){
    int nombre_lg,nombre_colone;
    date time_d,time_a;
    string marque,ville_arrivee;
    float tarif;
        cout << "\n\n\n\n\n\n                     Entrez le nombre de ligne  : ";
        cin>>nombre_lg;
        cout << "\n\n                     Entrez le nombre de colone : ";
        cin>>nombre_colone;
        cout << "\n\n                     Entrez heure de depart : ";
        cin>>time_d.h;
        cout<<"                                              ";
        cin>>time_d.m;
        cout << "\n\n                     Entrez heure d'arrivee : ";
        cin>>time_a.h;
        cout<<"                                              ";
        cin>>time_a.m;
        cout << "\n\n                     Entrez la destination du bus : ";
        cin>>ville_arrivee;
        cout << "\n\n                     Entrez la marque : ";
        cin>> marque;
        cout << "\n\n                     Tarif : ";
        cin>>tarif;
        bus bus1(nombre_lg,nombre_colone,time_d,time_a,ville_arrivee,marque,tarif);
        Buses.push_back(bus1);
    }
void AfficherBus(vector<bus> &Buses){
    int k=0;
    for(int i=0;i<Buses.size();i++){
        cout<<"\n\n                     *************************     Bus   "<<i+1<<"   *************************"<<endl;
            Buses[i].afficher_bus();
            k+=1;
        }
        if(k==0){
            cout<<"\n\n         AUCUN BUS EXISTE, VEUILLEZ AJOUTER DES NOUVEAUX BUS ! "<<endl;
        }
}

void AjouterReservation(vector<voyageur> &voyageurs,vector<bus> &buses){

        voyageur voy1;
        int place,confirmer=0;
        double code,numero_carte;
        string voy_des;
        int mode_paiement;
        int b,k=0;
        cout<<"\n\n\n\n\n\n               DONNEZ VOTRE DISTINATION :";
        cin>>voy_des;
        voy1.SetDest(voy_des);
        system("cls");

        for(int i=0;i<buses.size();i++){
            if(buses[i].GetDestinationBus()==voy_des){
                 cout<< "\n\n\n\n\n\n\n\n         LES lIGNES DISPONIBLES POUR VOTRE TRAJET : "<<endl;
                cout<<" \n\n                      BUS "<<i+1<<"                              "<<endl;
                buses[i].afficher_bus();
                k=k+1;
            }}
            if(k==0){
                cout<<"\n\n\n\n  CETTE DESTINATION N'EXISTE PAS !"<<endl;
            }
            else{
            cout<<"\n\n\n\n                    VEUILLEZ CHOISIR UN BUS  : ";
            cin>>b;

            while(b==0 || b>buses.size()){
                cout<<"\n\n\n\n                  CE BUS N'EXISTE PAS ! "<<endl;
                cout<<"\n\n\n\n  VEUILLEZ CHOISIR UN BUS  : ";
                cin>>b;
            }


             voy1.recuperer_info();
             cout<<"\n\n\n\n           VEUILLEZ CHOISIR VOTRE PLACE  :";
             cin>>place;

                while(buses[b-1].verifier_place(place)==1 || place==0)
                    {
                    cout<<"\n\n\n\n  CETTE PLACE N'EXISTE PAS !";
                    cout<<"\n\n\n\n  VEUILLEZ CHOISIR UNE PLACE  :";
                    cin>>place;
                }

// PAIEMENT

        while(confirmer==0){
            cout<<"       \n\n\n           VEUILLEZ CHOISIR LE MODE DE PAIEMENT : "<<endl;
            cout<<"           \n\n                1 : PAIEMENT ESPECE     2 : PAIEMENT AVEC CARTE BANCAIRE "<<endl;
            cout<<"\n                               ";
            cin>>mode_paiement;

            while(mode_paiement<1 || mode_paiement>2){
                system("cls");
                cout<<"     \n\n\n         VEUILLEZ CHOISIR LE MODE DE PAIEMENT : "<<endl;
                cout<<"         \n\n              1 : PAIEMENT ESPECE     2 : PAIEMENT AVEC CARTE BANCAIRE "<<endl;
                cout<<"\n                               ";
                cin>>mode_paiement;
            }

            if(mode_paiement==1){

                cout<<"     \n\n                     ----> TOTAL A PAYER : "<<"\x1b[34m"<<buses[b-1].GetTarif()<<"\x1b[0m"<<endl;

            }
            else{
                cout<<"\n              NUM CARTE : ";
                cin>>numero_carte;
                cout<<" \n             CODE : ";
                cin>>code;

            }

             cout<<"        \n\n \x1b[32m           1 - CONFIRMER LE PAIMENT \x1b[0m     \x1b[31m  0 - RETOUR  \x1b[0m"<<endl;
             cin>>confirmer;
            }
            system("cls");




// AJOUT DE RESERVAION

            voy1.SetNumBus(b-1);
            buses[b-1].modifier_place(place);
            voyageurs.push_back(voy1);


        for(int i=0;i<voyageurs.size();i++){
            if(voyageurs[i].PlaceVide()==1){
                voyageurs[i].AjouterPlace(place);
            }
        }
         cout<<"                   \n\n\n RESERVATION AJOUTE  "<<endl;
            }
}
void AfficherVoyageurs(int ch,vector<voyageur> &voyageurs){
    int k=0;
    system("cls");
    cout<<"\n\n\n         LA LISTE DES VOYAGEURS DANS LE BUS "<<ch<<" : "<<endl;
    for(int i=0;i<voyageurs.size();i++){
        if(voyageurs[i].GetNumBus()==ch-1){
            voyageurs[i].afficher_info();
            k+=1;
        }
    }
    if(k==0){
            cout<<"\n\n\n\n       LE BUS EST VIDE !"<<endl;
        }
}


//            MAIN


int main()
{
int choix,nb_bus,reponse2;
int place2;
int b;//pour acceder au tableau des voyageurs sans faire le parcours sur tous le tableau
int nv_ligne_nv_colone;


string voy_dest;
string reponse,reponse1;

vector<bus> buses;
vector<voyageur> voyageurs;

    checklogin();
    reponse="yes";

    while(reponse=="yes" || reponse=="YES" || reponse=="Yes" || reponse=="oui" || reponse=="OUI" || reponse=="Oui"){
    system("cls");
    cout << "                                              ----------------------------------------------                 " << endl;
    cout << "                                              -                                            -                "<<endl;
    cout << "                                              -        Gare routiere Casablanca            -                "<<endl;
    cout << "                                              -                                            -               "<<endl;
    cout << "                                              ----------------------------------------------               \n\n\n"<<endl;
    cout<<"\x1b[33m "<<endl;
    cout<<"                                    -----------------------------------------------------------------"<<endl;
    cout<<"                                    -                                                               -"<<endl;
    cout<<"                                    -       1 : AJOUTER BUS         2 : AFFICHER BUS                -"<<endl;
    cout<<"                                    -                                                               -"<<endl;
    cout<<"                                    -       3 : MODIFIER BUS        4 : AJOUTER RESERVATION         -"<<endl;
    cout<<"                                    -                                                               -"<<endl;
    cout<<"                                    -                5 : AFFICHER VOYAGEURS                         -"<<endl;
    cout<<"                                    -                                                               -"<<endl;
    cout<<"                                    -----------------------------------------------------------------\x1b[0m"<<endl;

    cout<<" \n\n\n Entrez votre choix : ";
    cin>>choix;
    system("cls");
    if (choix==1){
        AjouterBus(buses);

    }

    if(choix==2){
        AfficherBus(buses);
    }
    if(choix==3){

          AfficherBus(buses);
          if(buses.size()>0){
        cout<<"\n\n vous voulez modifier quel bus : ";
        cin>>nb_bus;
        while(nb_bus<=0 || nb_bus>buses.size()){
            cout<< " Ce numero ne correspondant a aucun bus ! "<<endl;
            cout<<"\n\n vous voulez modifier quel bus : ";
            cin>>nb_bus;
        };

        cout<<"\n\n 1:nombre de ligne      2:nombre de colone      3:heure de depart        4:heure d'arrivee        5:destination        6:marque"<<endl;
        cout<< "\n\n Quel information vous voulez modifer : ";
        cin>>reponse2;
        while(reponse2<=0 || reponse2>6){
            cout<< "ce choix n'est pas disponible !";
            cout<<"\n\n 1:nombre de ligne      2:nombre de colone      3:heure de depart        4:heure d'arrivee        5:destination        6:marque"<<endl;
            cout<< "\n\n Quel information vous voulez modifer : ";
            cin>>reponse2;
        };

        switch(reponse2){
    case 1:
        buses[nb_bus-1].modifier_bus(reponse2);
        break;
    case 2:
        buses[nb_bus-1].modifier_bus(reponse2);
        break;
    case 3:
        buses[nb_bus-1].modifier_bus(reponse2);
        break;
    case 4:
        buses[nb_bus-1].modifier_bus(reponse2);
        break;
    case 5:
        buses[nb_bus-1].modifier_bus(reponse2);
        break;
    case 6:
        buses[nb_bus-1].modifier_bus(reponse2);
        break;
        };
        }};
    if(choix==4){


            if(buses.size()>0)
                AjouterReservation(voyageurs,buses);
            else{
                cout<<" \n\n\n             AUCUN BUS EST TROUVE,  VEUILLEZ AJOUTER DES BUS !"<<endl;
            }

            }
    if(choix==5){
                if(buses.size()==0){
                    cout<<"\n\n\n AUCUN BUS EXISTE ! "<<endl;
                }
                else {

                int ch;
                     cout<<"                 ******************************************************** "<<endl;
                for(int i=0;i<buses.size();i++){

                     cout<<"\n                                   BUS "<<i+1<<endl;
                     cout<<"\n";
                     cout<<"\n                                   DESTINATION : "<<buses[i].GetDestinationBus()<<endl;
                     cout<<"\n";
                     cout<<"\n                                   DEPART TIME : "<<buses[i].GetHeureDepart().h<<" h "<<buses[i].GetHeureDepart().m<<" m \n"<<endl;
                     cout<<"\n";
                     cout<<"                  ******************************************************\n";
                }
                cout<<"\n\n                        VEUILLEZ CHOISIR UN BUS : ";
                cin>>ch;
                while(ch>buses.size() || ch<1){
                    cout<<"Ce CHOIX N'EXISTE PAS !"<<endl;
                    cout<<"\n\n       VEUILLEZ CHOISIR UN BUS : ";
                    cin>>ch;
                }

                AfficherVoyageurs(ch,voyageurs);
                }
            }

    cout << "\n\n Vous voulez continuer (yes ou non) :";
    cin>> reponse;
}
return 0;
}



