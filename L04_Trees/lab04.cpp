#include <iostream>
#include <string.h>

using namespace std;

struct NodArbore {
    char nume[100];
    NodArbore* primulFiu;
    NodArbore* urmatorulFrate;

    NodArbore(char n[100]) {
        strcpy(nume, n);
        primulFiu = nullptr;
        urmatorulFrate = nullptr;
    }
};

// Adaugă un copil unui părinte
void adaugaCopil(NodArbore* parinte, char n[100]) {
    NodArbore* nou = new NodArbore(n);
    
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

    cout << nod->nume << " "; // Vizităm rădăcina
    traversarePreOrdine(nod->primulFiu);   // Vizităm recursiv copiii
    traversarePreOrdine(nod->urmatorulFrate); // Vizităm frații
}

// Traversare Post-Ordine: Copii -> Rădăcină
void traversarePostOrdine(NodArbore* nod) {
    if (nod == nullptr) return;

    traversarePostOrdine(nod->primulFiu);
    cout << nod->nume << " "; // Vizităm nodul după ce am terminat copiii
    traversarePostOrdine(nod->urmatorulFrate);
}

void afisareArbore(NodArbore* nod, int nivel) {
    if (nod == nullptr) return;

    for (int i = 0; i < nivel; i++) cout << "  "; // Indentare
    cout << "|_" << nod->nume << endl;

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


int main() {
    NodArbore* radacina = new NodArbore("C:");

    // Adăugăm copii pentru rădăcină
    adaugaCopil(radacina, "Fotografii");
    adaugaCopil(radacina, "Documente");
    adaugaCopil(radacina, "Descarcari");

    // Adăugăm copii pentru nodul 20 (nepoți pentru rădăcină)
    adaugaCopil(radacina->primulFiu, "chermeza.png");
    adaugaCopil(radacina->primulFiu, "selfie.jpeg");

    cout << "Structura Arborelui General:" << endl;
    afisareArbore(radacina, 0);

    cout << "\nTraversare Pre-Ordine: ";
    traversarePreOrdine(radacina);

    cout << "\nTraversare Post-Ordine: ";
    traversarePostOrdine(radacina);
    cout << endl;

    cout << "\nGrad maxim arbore: " << gradMaximArbore(radacina);

    cout << "\nAdancime arbore: " << calculeazaAdancime(radacina);

    return 0;
}