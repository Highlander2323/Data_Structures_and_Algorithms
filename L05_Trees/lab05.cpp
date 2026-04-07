#include <iostream>
#include <string.h>

using namespace std;

struct NodArbore {
    int val;
    NodArbore* primulFiu;
    NodArbore* urmatorulFrate;

    NodArbore(int v) {
        val = v;
        primulFiu = nullptr;
        urmatorulFrate = nullptr;
    }
};

struct Fisier {
    char nume[100];
    Fisier* primulFiu;
    Fisier* urmatorulFrate;

    void initializare(char nume[100]){
        primulFiu = nullptr;
        urmatorulFrate = nullptr;
        strcpy(this->nume, nume);
    }
};

// Adaugă un copil unui părinte
void adaugaCopil(NodArbore* parinte, int val) {
    NodArbore* nou = new NodArbore(val);
    
    if (parinte->primulFiu == nullptr) {
        parinte->primulFiu = nou;
    } else {
        // Dacă are deja copii, mergem la capătul listei de frați
        NodArbore* temp = parinte->primulFiu;
        while (temp->urmatorulFrate != nullptr) {
            temp = temp->urmatorulFrate;
        }
        temp->urmatorulFrate = nou;
    }
}

// Traversare Pre-Ordine: Rădăcină -> Copii
void traversarePreOrdine(NodArbore* nod) {
    if (nod == nullptr) return;

    cout << nod->val << " "; // Vizităm rădăcina
    traversarePreOrdine(nod->primulFiu);   // Vizităm recursiv copiii
    traversarePreOrdine(nod->urmatorulFrate); // Vizităm frații
}

// Traversare Post-Ordine: Copii -> Rădăcină
void traversarePostOrdine(NodArbore* nod) {
    if (nod == nullptr) return;

    traversarePostOrdine(nod->primulFiu);
    cout << nod->val << " "; // Vizităm nodul după ce am terminat copiii
    traversarePostOrdine(nod->urmatorulFrate);
}

void afisareArbore(NodArbore* nod, int nivel) {
    if (nod == nullptr) return;

    for (int i = 0; i < nivel; i++) cout << "  "; // Indentare
    cout << "|_" << nod->val << endl;

    afisareArbore(nod->primulFiu, nivel + 1);    // Coborâm în ierarhie
    afisareArbore(nod->urmatorulFrate, nivel);   // Rămânem la același nivel pentru frați
}

// Calculează câți copii direcți are un nod specific
int gradNod(NodArbore* nod) {
    if (nod == nullptr || nod->primulFiu == nullptr) return 0;

    int contor = 0;
    NodArbore* copil = nod->primulFiu;
    while (copil != nullptr) {
        contor++;
        copil = copil->urmatorulFrate;
    }
    return contor;
}

// Calculează gradul maxim al întregului arbore (cel mai mare număr de copii)
int gradMaximArbore(NodArbore* nod) {
    if (nod == nullptr) return 0;

    int maxG = gradNod(nod); // Gradul nodului curent

    // Verificăm recursiv copiii și frații pentru a găsi un grad mai mare
    int gradFiu = gradMaximArbore(nod->primulFiu);
    int gradFrate = gradMaximArbore(nod->urmatorulFrate);

    if (gradFiu > maxG) maxG = gradFiu;
    if (gradFrate > maxG) maxG = gradFrate;

    return maxG;
}

int calculeazaAdancime(NodArbore* nod){
    if(nod == nullptr){
        return 0;
    }
    int gradCopil = 1 + calculeazaAdancime(nod->primulFiu);
    int gradFrate = calculeazaAdancime(nod->urmatorulFrate);

    return max(gradCopil, gradFrate);
}

void adaugaFolder(Fisier *root, Fisier* nou){;
    if(root->primulFiu == nullptr){
        root->primulFiu = nou;
    } else {
        Fisier* temp = root->primulFiu;
        while(temp->urmatorulFrate != nullptr){
            temp = temp->urmatorulFrate;
        }
        temp->urmatorulFrate = nou;
    }
}

void adaugaFisier(Fisier* parinte, Fisier* nou){
    if(parinte->primulFiu == nullptr){
        parinte->primulFiu = nou;
    } else {
        Fisier* temp = parinte->primulFiu;
        while(temp->urmatorulFrate != nullptr){
            temp = temp->urmatorulFrate;
        }
        temp->urmatorulFrate = nou;
    }
}

void afiseazaFisiere(Fisier* nod, int nivel){
    if(nod == nullptr){
        return;
    }

    int count = nivel;

    while(count > 0){
        if(count == 1){
            cout << "|_ ";    
        }else{
            cout << "\t";
        }
        count--;
    }
    cout << nod->nume << endl;
    afiseazaFisiere(nod->primulFiu, nivel + 1);
    afiseazaFisiere(nod->urmatorulFrate, nivel);
}

int main() {
    NodArbore* radacina = new NodArbore(0);

    // Adăugăm copii pentru rădăcină
    adaugaCopil(radacina, 10);
    adaugaCopil(radacina, 20);
    adaugaCopil(radacina, 30);

    adaugaCopil(radacina->primulFiu, 13);
    adaugaCopil(radacina->primulFiu, 14);

    cout << "Structura Arborelui General:" << endl;
    afisareArbore(radacina, 0);

    cout << "\nTraversare Pre-Ordine: ";
    traversarePreOrdine(radacina);

    cout << "\nTraversare Post-Ordine: ";
    traversarePostOrdine(radacina);
    cout << endl;

    cout << "\nGrad maxim arbore: " << gradMaximArbore(radacina);

    cout << "\nAdancime arbore: " << calculeazaAdancime(radacina);
    
    cout << endl;

    Fisier* sistemFisiere = new Fisier();
    sistemFisiere->initializare("C:");
    bool run = true;
    while(run){
        int opt;
        cout << "1. Adauga folder\n";
        cout << "2. Adauga fisier\n";
        cout << "3. Afișează structura\n";
        cout << "Optiune: ";
        cin >> opt;
        cin.ignore();
        switch(opt){
            case 1: {
                char nume[100];
                cout << "Nume folder: ";
                cin.getline(nume, 100);
                Fisier* nou = new Fisier();
                nou->initializare(nume);
                adaugaFolder(sistemFisiere, nou);
                break;
            }
            case 2: {
                char nume[100];
                Fisier* parinte;
                int folder;
                cout << "Nume fisier: ";
                cin.getline(nume, 100);
                Fisier* nou = new Fisier();
                nou->initializare(nume);

                cout << "Unde? : ";
                Fisier *temp = sistemFisiere->primulFiu;
                int count = 1;
                Fisier* foldere[100];
                while(temp != nullptr){
                    cout << count << ". " << temp->nume << " ";
                    foldere[count++] = temp;
                    temp = temp->urmatorulFrate;
                }
                cin >> folder;
                cin.ignore();

                adaugaFisier(foldere[folder], nou);
                break;
            }
            case 3: {
                afiseazaFisiere(sistemFisiere, 0);
                break;
            }
            default:
                run = false;
        }
    }
    return 0;
}