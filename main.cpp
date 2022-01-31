#include <iostream>
#include <fstream>

#define MAXSTAZIONI 40
using namespace std;

typedef struct {
    char stazione[14];
    float min;
    float max;
} localita;

int Carica_da_File(localita ar[],char *nomefile){
fstream file;
file.open(nomefile,ios::in);
int i=0;
while (file.good()){
       file>>ar[i].stazione>>ar[i].min>>ar[i].max;
       i++;
    }
file.close();
    return i;
}

int SelezionaStazioni(localita ar[],localita ar1[],int tot){
    int sel=0,i,notSel;
    for(i=0;i<tot;i++)
        if(ar[i].min>10 && ar[i].max<30){
            ar1[sel]=ar[i];
            sel++;
        }
    notSel=sel;
    for(i=0;i<tot;i++)
        if(ar[i].min<=10 || ar[i].max>=30){
            ar1[notSel]=ar[i];
            notSel++;
        }

    return sel;
}

void Stampa(localita ar[],int sel){
    cout<<"Localita' con l'innevamento richiesto (>10 e <30 cm)"<<endl;
for(int i=0;i<sel;i++)
    cout<<ar[i].stazione<<" "<<ar[i].min<<" "<<ar[i].max<<endl;
}

float CercaInnevamentoMassimo(localita ar[],int quante){
    float max=0;
for(int i=0;i<quante;i++)
    if(ar[i].max>=max) max=ar[i].max;
    return max;
}

void StampaMigliori(char *nomefile,float max_livello){

    float sel=10*100/max_livello;
    cout<<"Localita' innevate non inferiore al 10%"<<endl;
    localita ar[MAXSTAZIONI];
    int size=Carica_da_File(ar,nomefile);

    for(int i=0;i<size;i++)
        if(ar[i].max>sel)
            cout<<ar[i].stazione<<" "<<ar[i].min<<" "<<ar[i].max<<endl;
}

int main() {
    char nomefile[]= "C:\\Users\\Thinkpad User\\CLionProjects\\neve_sci\\neve.dat";
    localita ar[MAXSTAZIONI];
    int size=Carica_da_File(ar,nomefile);

    float max=CercaInnevamentoMassimo(ar,size);
    cout<<endl;
    StampaMigliori(nomefile,max);
    localita ar1[MAXSTAZIONI];

    int sel=SelezionaStazioni(ar,ar1,size);
cout<<endl;
if(sel>0)
    Stampa(ar1,sel);

}