#include <iostream>
#include <math.h>

using namespace std;

struct Student{
    char nume[100];
    int *note;
    int numarNote;

    Student(char n[100]){
        for(int i = 0; i < 100; i++){
            nume[i] = n[i];
        }
        numarNote = 2;
        note = new int[numarNote];
    }

    void introducereNote(){
        int nr = 1;
        while(nr <= numarNote){
            cout << "Nota " << nr << " / " << numarNote << ": ";
            cin >> note[nr - 1];
            if(note[nr - 1] <= 0 || note[nr - 1] > 10){
                continue;
            }
            nr++;
        }
    }

    void afisareNote(){
        cout << "Notele studentului " << nume << ": ";
        for(int i = 0; i < numarNote; i++){
            cout << note[i] << " ";
        }
        cout << endl; 
    }
};


struct Complex{
    float parteReala;
    float parteImaginara;

    void setare(float re, float im){
        parteReala = re;
        parteImaginara = im;
    }

    void afisare(){
        cout << "Numarul complex este: ";
        cout << parteReala << ' ';
        if(parteImaginara >= 0){
            cout << "+ " << parteImaginara;
        }
        else{
            cout << parteImaginara;
        }
        cout << 'i' << endl;
    }

    void citire(){
        cout << "Introduceti numarul complex:\nPartea reala: ";
        cin >> parteReala;
        cout << "Partea imaginara: ";
        cin >> parteImaginara;
    }

    float modul(){
        return sqrt(parteImaginara * parteImaginara + parteReala * parteReala);
    }
};

Complex adunare(Complex a, Complex b){
    Complex rezultat;
    rezultat.parteReala = a.parteReala + b.parteReala;
    rezultat.parteImaginara = a.parteImaginara + b.parteImaginara;

    return rezultat;
}

Complex scadere(Complex a, Complex b){
    Complex rezultat;
    rezultat.parteReala = a.parteReala - b.parteReala;
    rezultat.parteImaginara = a.parteImaginara - b.parteImaginara;

    return rezultat;
}

int main(){
    Complex c1, c2;
    c1.parteReala = 4;
    c1.parteImaginara = 8.7;

    c2.setare(-2.3, 7);

    c1.afisare();
    c2.afisare();

    cout << "Modulul numarului: " << c1.modul() << endl;
    cout << "Modulul numarului: " << c2.modul() << endl;

    Complex adunat = adunare(c1, c2);
    Complex scazut = scadere(c1, c2);

    cout << "Adunare -> ";
    adunat.afisare();
    cout << "Scadere -> ";
    scazut.afisare();

    Complex numere[10];

    for(int i = 1; i <= 10; i++){
        numere[i].setare(i, i+1);
    }

    for(int i = 1; i <= 10; i++){
        numere[i].afisare();
    }

    Complex c3;
    c3.citire();
    cout << "Modul: " << c3.modul() << endl;
    c3.afisare();

    char nume[100] = "Radu Neamtu";
    Student s(nume);

    s.introducereNote();
    s.afisareNote();

    system("pause");
    return 0;
}