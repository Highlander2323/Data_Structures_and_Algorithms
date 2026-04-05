#include <iostream>

using namespace std;

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