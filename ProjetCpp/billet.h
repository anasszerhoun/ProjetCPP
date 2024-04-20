#include <iostream>
using namespace std;

class billet:public bus,public voyageur{

public:

    billet(date DD,date DA,int Place,string nom,string prenom,string CIN,string dest,float tarif):bus(NULL,NULL,DD,DA,"","",tarif),voyageur(prenom,nom,CIN,dest,Place){
    };
    void  afficherBillet(){
    cout<<"Prenom : "<<GetPrenom()<<endl<<"Nom : "<<GetNom()<<endl<<"Cin : "<<GetCin()<<endl<<"Destination : "<<GetDestination()<<endl<<"Place : "<<GetPlace()<<endl<<"Heure de depart : "<<GetHeureDepart().h<<"h"<<GetHeureDepart().m<<"m"<<endl<<"Heure d'arrivee : "<<GetHeureArrivee().h<<"h"<<GetHeureArrivee().m<<"m"<<endl;
    }
};
