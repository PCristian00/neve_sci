#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#define MAXSTAZIONI 40
using namespace std;
typedef struct {
    char stazione[14];
    float min;
    float max;
} localita;
int Carica_da_File(localita ar[],char *nomefile){
fstream file;
file.open(nomefile);
int i=0;
while (file){
       file>>ar[i].stazione>>ar[i].min>>ar[i].max;
       i++;
    }
    return i;
}
int SelezionaStazioni(localita ar[],localita ar1[],int tot){

}
void Stampa(localita ar1[],int sel){

}
float CercaInnevamentoMassimo(localita ar[],int quante){

}
void StampaMigliori(char *nomefile,float max_livello){

}
int main(int argc, char *argv[]) {
    char *nomefile="C:\\Users\\Thinkpad User\\CLionProjects\\neve_sci\\neve.dat";
    localita *ar;
    int size=Carica_da_File(ar,nomefile);
}