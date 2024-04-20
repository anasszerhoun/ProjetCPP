
class voyageur{
    string nom,prenom,CIN,Destination;
    int age,PLACE;
    int numero_bus;
public:
    voyageur(){
        nom=nom;
        prenom=prenom;
        CIN=CIN;
        Destination=Destination;
        PLACE=PLACE;
        };
    voyageur(string first_name,string last_name,string Cin,string DEST,int PLACE){
        prenom=first_name;
        nom=last_name;
        CIN=Cin;
        Destination=DEST;
        this->PLACE=PLACE;
    };
    string GetPrenom(){return prenom;};
    string GetNom(){return nom;};
    string GetCin(){return CIN;};
    string GetDestination(){return Destination;};
    int GetPlace(){return PLACE;};
    int GetNumBus(){return numero_bus;}
    void SetNumBus(int n){numero_bus=n;}
    void SetDest(string s){Destination=s;}
    void recuperer_info(){
        string f_name,l_name,v_cin,v_dest;
                cout<<"\n\n";
                cout<<"\n\n                    PRENOM : ";
                cin>>f_name;
                prenom=f_name;
                cout<<"\n\n                    NOM : ";
                cin>>l_name;
                nom=l_name;
                cout<<"\n\n                    CIN : ";
                cin>>v_cin;
                CIN=v_cin;
    }
    void AjouterPlace(int p){
        PLACE=p;
        }
    string RetournerDestVoya(){
        return Destination;
    }
    void AjouterNumBus(int n){
        numero_bus=n;
    }
    int PlaceVide(){
        if(PLACE==NULL){
            return 1;
        }
    return 0;
    }

    void afficher_info(){
        cout<<"\n          ********************************"<<endl;
        cout<<"          *";
        cout<<"\n          *   NOM : "<<nom<<endl;
        cout<<"          *";
        cout<<"\n          *   PRENOM : "<<prenom<<endl;
        cout<<"          *";
        cout<<"\n          *   CIN: "<<CIN<<endl;
        cout<<"          *";
        cout<<"\n          *   Destination : "<<Destination<<endl;
        cout<<"          *";
        cout<<"\n          *   PLACE :"<<PLACE<<endl;
        cout<<"          *";
        cout<<"\n          *   N Bus : "<<numero_bus+1<<endl;
        cout<<"          *";
        cout<<"\n          **********************************"<<endl;
    }


};

