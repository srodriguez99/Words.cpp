
#ifndef Queue_h
#define Queue_h
#include <string>
#include <iostream>
using namespace std;
struct Link {
    string data;
    Link* next;
    
    Link(){
        data = "";
        next = NULL;
    }
    
    Link (string x){
        data = x;
        next = NULL;
    }
};

struct Queue {
    Link* front;
    Link* back;
    
    Queue (){
        front = NULL;
        back = NULL;
    }
    
    string peek () {
        return front->data;
    }
    
    void push(string value){
        if (isEmpty()){
            front = new Link(value);
            back = front;
        }
        else {
            back->next = new Link(value);
            back = back->next;
        }
    }
    
    bool find (string value){
        // Provide your code here
        Link* temp = front;
        
        while (temp != NULL){
            if (temp->data == value){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    
    bool isEmpty(){
        return (front == NULL);
    }
    
    string pop(){
        string val = front->data;
        
        Link* oldFront = front;
        front = front->next;
        
        delete oldFront;
        
        return val;
    }
    
    void print() {
        // Provide your code here
        Link* temp = front;
        while (temp != NULL){
            std::cout << temp->data << " ";
            temp = temp->next;
        }
    }
    
    ~Queue(){
        // Provide your code here
        while(!isEmpty()){
            pop();
        }
    }
};

#endif
