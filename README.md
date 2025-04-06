 # DATA STRUCTURE AND ALGORITHM ASSIGNMENT 
 
# Linked List Implementation in C++

# Overview

This repository contains implementations of the following linked list types in C++:
   	  
        1   Single linked list
       2    Double linked list
       3   Circular single linked list
       4   Circular double linked list


Each implementation includes functions for:
     
     Insertion (At beginning, at end, and at a specific position)
     Deletion (At beginning, at end, and at a specific position)
     Display   (Traversal of the list)



# Getting Started
To use this implementation, A C++ compiler(Dev C++)


#  Example Usage

Insertion AtBeginning(Single Linked List)
void insertAtBeginning(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}


# DOUBLE LINKED LIST (AT THE END)	
void deleteAtEnd () {
    if (head == nullptr) return;
    Node* temp = nextNode;
    nextNode = nextNode ->Prev;
    while (nextNode ->next = nullptr);
nextNode=temp;
    delete temp;
}


# Display Circular Single linked list
void display () {
    if (head == nullptr) return;
    Node* temp = head;
    do {
        cout << temp->data << "  ";
        temp = temp->next;
    } 
while (temp!= head);
    cout << “->” <<”back to head:”<<endl;
}



Then after I compile and run this code, I screenshot my input data and output result.

And also I create new folder then, all of my source code and screenshot collect together in new folder and zipped this folder .

Now I download and installing Github.com software
next step of github  
           
          ->  create account of GitHub
           
           -> open GitHub
           
           ->? I get code
           
          ->  create repositor
           
           -> upload file
           
           -> I put file that I made zipped and I copy link then I sent this link

# Reference 
 
 1.Data structure and algorithm 
 
 2.Online tutorial

 3.C ++ programming language documentation
