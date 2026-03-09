#include <iostream>

using namespace std;

struct SinglyLLNode{
    int value;
    SinglyLLNode *next;

    SinglyLLNode(){
        next = nullptr;
    }

    SinglyLLNode(int val){
        SinglyLLNode *newNode = new SinglyLLNode();
        next = newNode;
        next->value = val;
    }

    void addValue(int val){
        SinglyLLNode *curr = this;
        while(curr->next != nullptr){
            curr = curr->next;
        }

        SinglyLLNode *newNode = new SinglyLLNode();
        newNode->value = val;
        curr->next = newNode;
    }

    void deleteValue(int val){
        SinglyLLNode *last = this, *curr = this->next;
        if(curr == nullptr){
            return;
        }
        while(curr->next != nullptr && curr->value != val){
            last = curr;
            curr = curr->next;
        }

        if(curr->value == val){
            last->next = curr->next;
            delete curr;
        }
    }

    void printAll(){
        SinglyLLNode *curr = this->next;
        while(curr != nullptr){
            cout << curr->value;
            cout << " -> ";
            curr = curr->next;
        }
        cout << "END\n";
    }
};

struct DoublyLLNode{
    int value;
    DoublyLLNode *next;
    DoublyLLNode *last;

    DoublyLLNode(){
        next = nullptr;
        last = nullptr;
    }

    DoublyLLNode(int val){
        DoublyLLNode *newNode = new DoublyLLNode();
        next = newNode;
        next->value = val;
        next->last = this;
    }

    void addValue(int val){
        DoublyLLNode *curr = this;
        while(curr->next != nullptr){
            curr = curr->next;
        }

        DoublyLLNode *newNode = new DoublyLLNode();
        newNode->value = val;
        newNode->last = curr;
        curr->next = newNode;
    }

    void deleteValue(int val){
        DoublyLLNode *last = this, *curr = this->next;
        if(curr == nullptr){
            return;
        }
        while(curr->next != nullptr && curr->value != val){
            last = curr;
            curr = curr->next;
        }

        if(curr->value == val){
            last->next = curr->next;
            if(curr->next != nullptr){
                curr->next->last = last;
            }
            delete curr;
        }
    }

    void printAll(){
        DoublyLLNode *curr = this->next;
        while(curr != nullptr){
            cout << curr->value;
            cout << " <-> ";
            curr = curr->next;
        }
        cout << "END\n";
    }
};

struct CircularLLNode{
    int value;
    CircularLLNode *next;

    CircularLLNode(){
        next = this;
    }

    CircularLLNode(int val){
        CircularLLNode *newNode = new CircularLLNode();
        newNode->value = val;
        newNode->next = this;
        next = newNode;
    }

    void addValue(int val, int after = -1){
        if(after == -1){
            CircularLLNode *newNode = new CircularLLNode();
            newNode->value = val;
            newNode->next = this->next;
            next = newNode;
        }

        CircularLLNode *curr = this->next;

        while(curr->value != after && curr != this){
            curr = curr->next;
        }

        if(curr != this){
            CircularLLNode *newNode = new CircularLLNode(val);
            curr->next = newNode;
        }
    }

    void deleteValue(int val){
        CircularLLNode *last = this, *curr = this->next;
        if(last == curr){
            return;
        }

        while(curr->value != val && curr != this){
            last = curr;
            curr = curr->next;
        }
        
        if(curr != this){
            last->next = curr->next;
            delete curr;
        }
    }

    void printAll(){
        cout << "START -> ";
        CircularLLNode *curr = this->next;
        while(curr != this){
            cout << curr->value;
            cout << " -> ";
            curr = curr->next;
        }
        cout << "START\n";
    }
};

int main(){
    CircularLLNode *head = new CircularLLNode();
    head->addValue(2);
    head->addValue(3);
    /*head->addValue(4);
    head->addValue(5);
    head->addValue(6);*/
    head->printAll();
    head->deleteValue(2);
    head->printAll();
    head->deleteValue(3);
    head->printAll();
   /*head->deleteValue(4);
    head->printAll();
    head->deleteValue(5);
    head->printAll();
    head->deleteValue(6);
    head->printAll();*/

    system("pause");
    return 0;
}