#include <iostream>

using namespace std;

struct Stiva{
    int elemente[100];
    int capacitate;

    Stiva(){
        capacitate = 0;
    }
    
    void adauga(int element){
        if(capacitate < 100){
            elemente[capacitate] = element;
            ++capacitate;
        }
    }

    void scoate(){
        if(capacitate > 0){
            --capacitate;
            elemente[capacitate] = -1;
        }
    }

    int primul(){
        return elemente[capacitate - 1];
    }
};

struct Coada{
    int elemente[100];
    int capacitate;

    Coada(){
        capacitate = 0;
    }
    
    void adauga(int element){
        if(capacitate < 100){
            elemente[capacitate] = element;
            ++capacitate;
        }
    }

    void scoate(){
        for(int i = 0; i < capacitate - 1; i++){
            elemente[i] = elemente[i + 1];
        }

        if(capacitate > 0){
            --capacitate;
            elemente[capacitate] = -1;
        }
    }

    int primul(){
        return elemente[0];
    }
};

struct SinglyLLNode{
    int valoare;
    SinglyLLNode *next;

    SinglyLLNode(){
        next = nullptr;
    }

    SinglyLLNode(int val){
        SinglyLLNode *newNode = new SinglyLLNode();
        next = newNode;
        next->valoare = val;
    }

    void adaugaValoare(int val){
        SinglyLLNode *curr = this;
        while(curr->next != nullptr){
            curr = curr->next;
        }

        SinglyLLNode *newNode = new SinglyLLNode();
        newNode->valoare = val;
        curr->next = newNode;
    }

    void stergeValoare(int pos){
        SinglyLLNode *last = this, *curr = this->next;
        if(curr == nullptr){
            return;
        }
        int cnt = 1;
        while(curr->next != nullptr && cnt != pos){
            last = curr;
            curr = curr->next;
            ++cnt;
        }

        if(cnt == pos){
            last->next = curr->next;
            delete curr;
        }
    }

    int elementLaPozitia(int pos){
        int cnt = 0;
        SinglyLLNode *curr = this;
        while(curr->next != nullptr && cnt != pos){
            curr = curr->next;
            cnt++;
        }

        if(cnt != pos){
            return valoare;
        }
        return -1;
    }

    void afiseazaTot(){
        SinglyLLNode *curr = this->next;
        while(curr != nullptr){
            cout << curr->valoare;
            cout << " -> ";
            curr = curr->next;
        }
        cout << "SFARSIT\n";
    }
};

struct StivaDinamica{
    SinglyLLNode *head = new SinglyLLNode();
    int capacitate;

    StivaDinamica(){
        capacitate = 0;
    }
    
    void adauga(int element){
        if(capacitate < 100){
            head->adaugaValoare(element);
            ++capacitate;
        }
    }

    void scoate(){
        if(capacitate > 0){
            head->stergeValoare(capacitate);
            --capacitate;
        }
    }

    int primul(){
        return head->elementLaPozitia(capacitate);
    }
};

int main(){
    Stiva stiva;

    stiva.adauga(2);
    cout << stiva.primul() << endl;
    stiva.adauga(3);
    cout << stiva.primul() << endl;
    stiva.adauga(1);
    cout << stiva.primul() << endl;
    stiva.scoate();
    cout << stiva.primul() << endl;
    stiva.scoate();stiva.scoate();stiva.scoate();
    cout << stiva.primul() << endl;
    system("pause");
    return 0;
}