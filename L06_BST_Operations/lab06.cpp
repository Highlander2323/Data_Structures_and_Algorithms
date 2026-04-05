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

// 3. DELETION (Stergere)
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
            radacina = temp; // Updates the parent's pointer automatically
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

void afisareInordine(NodArbore* radacina) {
    if (radacina == nullptr) return;
    afisareInordine(radacina->stang);
    cout << radacina->val << " ";
    afisareInordine(radacina->drept);
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
    afisareInordine(radacina);
    cout << endl;
    system("pause");
    return 0;
}