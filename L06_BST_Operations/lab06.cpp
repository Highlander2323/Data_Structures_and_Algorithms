#include <iostream>
#include <string.h>

using namespace std;

struct NodArbore {
    int val;
    NodArbore *stang, *drept;
    NodArbore(int v) : val(v), stang(nullptr), drept(nullptr) {}
};

bool cauta(NodArbore* radacina, int val) {
    if (radacina == nullptr) return false;
    
    if (radacina->val == val) return true;
    
    if (val < radacina->val) 
        return cauta(radacina->stang, val);
    else 
        return cauta(radacina->drept, val);
}

void insereaza(NodArbore* &radacina, int val) {
    if (radacina == nullptr) {
        radacina = new NodArbore(val);
        return;
    }

    if (val < radacina->val)
        insereaza(radacina->stang, val);
    else if (val > radacina->val)
        insereaza(radacina->drept, val);
}

NodArbore* gasesteMinim(NodArbore* radacina) {
    while (radacina && radacina->stang != nullptr)
        radacina = radacina->stang;
    return radacina;
}

void sterge(NodArbore* &radacina, int val) {
    if (radacina == nullptr) return;

    // Step A: Find the node
    if (val < radacina->val)
        sterge(radacina->stang, val);
    else if (val > radacina->val)
        sterge(radacina->drept, val);
    
    // Step B: Node found, now delete it
    else {
        // Case 1 & 2: No child or only one child
        if (radacina->stang == nullptr) {
            NodArbore* temp = radacina->drept;
            delete radacina;
            radacina = temp;
        } 
        else if (radacina->drept == nullptr) {
            NodArbore* temp = radacina->stang;
            delete radacina;
            radacina = temp;
        } 
        // Case 3: Two children
        else {
            // Find the in-order successor (smallest in the right subtree)
            NodArbore* temp = gasesteMinim(radacina->drept);
            // Copy the successor's value to this node
            radacina->val = temp->val;
            // Delete the successor node
            sterge(radacina->drept, temp->val);
        }
    }
}

void afisareInordine(NodArbore* nod) {
    if (nod == nullptr) return;
    afisareInordine(nod->stang);
    cout << nod->val << " ";
    afisareInordine(nod->drept);
}

void afisarePreordine(NodArbore* nod){
    if (nod == nullptr) return;
    cout << nod->val << " ";
    afisarePreordine(nod->stang);
    afisarePreordine(nod->drept);
}

void afisarePostordine(NodArbore* nod){
    if (nod == nullptr) return;

    afisarePostordine(nod->stang);
    afisarePostordine(nod->drept);
    cout << nod->val << " ";
}

int numaraFrunze(NodArbore* nod){
    if(nod == nullptr) return 0;
    if(nod->stang == nullptr && nod->drept == nullptr) return 1;
    return numaraFrunze(nod->stang) + numaraFrunze(nod->drept);
}

int inaltime(NodArbore* nod){
    if(nod == nullptr) return 0;
    int inaltimeStanga = inaltime(nod->stang);
    int inaltimeDreapta = inaltime(nod->drept);
    return 1 + max(inaltimeStanga, inaltimeDreapta);
}

void identificaNivel(NodArbore* nod, int nivelCurent, int nivelDorit){
    if(nod == nullptr) return;
    if(nivelCurent == nivelDorit){
        cout << nod->val << " ";
    }
    identificaNivel(nod->stang, nivelCurent + 1, nivelDorit);
    identificaNivel(nod->drept, nivelCurent + 1, nivelDorit);
}

void afiseazaNivel(NodArbore* nod, int nivelDorit){
    identificaNivel(nod, 0, nivelDorit);
    cout << endl;
}

int main() {
    NodArbore* radacina = nullptr;

    insereaza(radacina, 50);
    insereaza(radacina, 30);
    insereaza(radacina, 70);
    insereaza(radacina, 60);
    insereaza(radacina, 80);
    insereaza(radacina, 1000);
    insereaza(radacina, 270);
    insereaza(radacina, 2280);
    insereaza(radacina, 1280);
    afisareInordine(radacina);
    cout << endl;
    cout << numaraFrunze(radacina) << endl;
    cout << inaltime(radacina) << endl;
    afiseazaNivel(radacina, 2);
    system("pause");
    return 0;
}