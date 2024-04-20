#include <iostream>
using namespace std;
struct date{
    int h,m;
};
class bus{
int ligne,colone,bus_number;
int** Place;
    string destination;
    string marque;
    date heure_depart,heure_arrivee;
    float tarif;
public :
 bus(int ligne,int colone,date heure_depart,date heure_arrivee,string destination,string marque,float tarif){
 	this->ligne=ligne;
 	this->colone=colone;
    this->marque=marque;
    this->destination=destination;
    this->heure_depart=heure_depart;
    this->heure_arrivee=heure_arrivee;
    this->tarif=tarif;
    Place=new int*[ligne];
    for(int i=0;i<ligne;i++){
        Place[i]=new int[colone];
    }
    initializePlace();
}
string GetDestinationBus(){return destination;};
date GetHeureDepart(){return heure_depart;};
date GetHeureArrivee(){return heure_arrivee;};
int getBusNumber(){return bus_number;}
float GetTarif(){return tarif;}
//int GetTotal(){return total;}
int GetNbPlaces(){return ligne*colone;}

void setBusNumber(int NvBusNumber){bus_number=NvBusNumber;}
void SetNbligne(int nv_ligne){ligne=nv_ligne;}
void SetNbcolone(int nv_colone){colone=nv_colone;}
void SetHeureDepart(date HD){heure_depart.h=HD.h;heure_depart.m=HD.m;}
void SetHeureArrivee(date HA){heure_arrivee.h=HA.h;heure_arrivee.m=HA.m;}
void SetDestination(string NvDest){destination=NvDest;}
void SetMarque(string NvMarque){marque=NvMarque;}
void SetTarif(int NvTarif){tarif=NvTarif;}
//void SetTotal(){total=total+1;}


void initializePlace(){
    int k = 1;
    for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < colone; j++) {
            Place[i][j] = k;
            k++;
        }
    }
}
int verifier_place(int place_choisie){
    int h;
    for(int i=0;i<ligne;i++){
        for(int j=0;j<colone;j++){
            if(place_choisie!=Place[i][j]){
                h++;
            }
            if(h==ligne*colone){
                return 1;
            }
        }
    }
return 0;
}
void modifier_place(int place_choisie){
    for(int i=0;i<ligne;i++){
        for(int j=0;j<colone;j++){
            if(Place[i][j]==place_choisie){
                Place[i][j]=0;
            }
        }
    }
}


void afficher_bus(){
 cout<<"                     *****************************************************************"<<endl;
 cout<<"\n";
 cout<<"                     *    nombre de place :  " <<ligne*colone<<endl;
 cout<<"\n";
 cout<<"                     *    Heure de depart : "<<heure_depart.h<<"h"<<heure_depart.m<<"m"<<"  ||   Heure d'arrivee : "<<heure_arrivee.h<<"h"<<heure_arrivee.m<<"m"<<endl;
 cout<<"\n";
 cout<<"                     *    Ville d'arrivee :  " <<destination<<endl;
 cout<<"\n";
 cout<<"                     *    La marque :        " <<marque<<endl;
 cout<<"\n";
 cout<<"                     *    Tarif  :        " <<tarif<<endl;
 cout<<"\n";
 cout<<"                     *****************************************************************\n"<<endl;

int k=1;
int i,j;
for(i=0;i<ligne;i++){
    cout<<"                                       ";
    for(j=0;j<colone;j++){
        if(Place[i][j]<10){
            cout<<" ";
            }
        cout<<"\x1b[32m   "<<Place[i][j]<<"\x1b[0m"<<" ";
        if((j+1)%2==0){
            cout<<"        ";
        }
    }
    cout<<"\n";
    cout<<endl;
    }
 }

 void modifier_bus(int rep){
 	int nv_ligne,nv_colone;
 	date nv_time,nv_time_a;
 	string nv_destination,nv_marque;

 	if(rep==1){
 		cout<<"\n\n\n\n\n                  Entrez le nouveau nombre de ligne :";
 		cin>>nv_ligne;
 		SetNbligne(nv_ligne);
 	}
	 else if(rep==2){
 		cout<<"\n                  Entrez le nouveau nombre de colone :";
 		cin>>nv_colone;
 		SetNbcolone(nv_colone);
	 }
	 else if(rep==3){
        cout<<"\n                  Entrez la nouvelle heure de depart :";
        cin>>nv_time.h>>nv_time.m;
        SetHeureDepart(nv_time);
	 }
     else if(rep==4){
        cout<<"\n                  Entrez la nouvelle heure d'arrivee :";
        cin>>nv_time_a.h>>nv_time_a.m;
        SetHeureArrivee(nv_time_a);
     }
	 else if(rep==5){
 		cout<<"\n                  Entrez la nouvelle destination  :";
 		cin>>nv_destination;
 		SetDestination(nv_destination);
	 }
	 else if(rep==6){
 		cout<<"\n                  Entrez la nouvelle marque  :";
 		cin>>nv_marque;
 		SetMarque(nv_marque);
	 }
 }

};
