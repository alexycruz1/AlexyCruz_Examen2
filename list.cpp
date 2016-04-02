#include "list.hpp"
#include <cstring>
#include <iostream>

using namespace std;

List::List(){
	this -> head = head;
}

List::List(Person persona){
	this -> head = new Node(persona);
}

List::~List(){

}

void List::setHead(Person persona){
	this -> head = new Node(persona);
}

Person List::getHead(){
	return head -> getValue();
}

void List::insert(int posicion, Person persona){
	if (posicion > 0){
		if (!head -> hasNext()){
			if (posicion == 1){
				head -> setNext(new Node(persona));
			}else if(posicion > 1){
				cerr << "Index out of bound" << endl;
			}else{
				Node* temp = head;
				head -> setValue(persona);
				head -> setNext(temp);
			}
		}else{
			Node* temp = head;
			int cont = 0;
			if (size() >= posicion){
				while(cont < posicion - 1){
					temp = temp -> getNext();
					cont++;
				}
				Node* nuevo = new Node(persona);
				if (temp -> hasNext()){
					Node* temp2 = temp -> getNext();
					nuevo -> setNext(temp2);
				}
				temp -> setNext(nuevo);
			}
		}
	}else if (posicion == 0){
		if (head != NULL){
			Node* temp = head;
			setHead(persona);
			head -> setNext(temp);
		}else{
			setHead(persona);
		}
	}else{
		cerr << "Invalid position" << endl;
	}
}

Person List::at(int posicion){
	Node* temp = head;
	for (int i = 0; i <= posicion; ++i){
		if (i == posicion){
			return temp -> getValue();
		}
	}
}

void List::erase(int posicion){
	Node* temp = head;
	for (int i = 0; i < posicion; i++){
		temp = temp -> getNext();
	}

	Node* temp2 = temp -> getNext();
	temp -> setNext(temp2 -> getNext());
}

void List::concat(List* lista){
	Node* temp = head;

	while(temp -> hasNext()){
		temp = temp -> getNext();
	}

	temp -> setNext(lista -> first());
}

int List::find(Person persona){
	int cont = 0;
	Node* temp = head;

	while(temp -> hasNext()){
		if (strcmp(temp -> getValue().getName(), persona.getName()) == false){
			return cont;
		}else{
			cont++;
			temp = temp -> getNext();
		}
	}
}

int List::size(){
	int cont = 0;
	Node* temp = head;

	while(temp -> hasNext()){
		temp = temp -> getNext();
		cont++;
	}
	return cont;
}

void List::push_back(Person persona){
	Node* temp = head;
	if (head == NULL){
		while(temp -> hasNext()){
			temp = temp -> getNext();
		}	
		temp -> setNext(new Node(persona));
	}else{
		head = new Node(persona);
	}
}

Node* List::first(){
	return head;
}