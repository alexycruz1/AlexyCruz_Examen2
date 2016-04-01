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
	int cont = 0;
	Node* temp = head;
	while(temp -> hasNext()){
		if (cont == posicion){
			temp = new Node(persona);
			head -> setNext(temp);
		}else{
			temp -> setNext(head);
			cont++;
		}
	}
}

Person List::at(int posicion){
Person temp;
int cont = 0;
	while(head -> hasNext()){
		cont++;
		if (posicion == cont){
			temp = head -> getValue();
		}
		return temp;
	}
}

void List::erase(int posicion){
	Node* temp = head;
	for (int i = 0; i < posicion; i++){
		temp = temp -> getNext();
	}
	Node* temp2 = temp -> getNext();
	temp = setNext(temp2 -> getNext());
}

void List::concat(List* lista){

}

int List::find(Person persona){
	int  cont;
	Node* temp = head;
	while(temp -> hasNext()){
		if (temp -> getValue().getName() == persona.getName()){
			return cont;
		}else{
			if (temp -> hasNext()){
				temp -> setNext(temp -> getNext());
				cont++;
			}
		}
	}
}

int List::size(){
	int cont = 1;
	Node* temp = head;
	while(temp -> hasNext()){
		temp = temp -> getNext();
		cont++;
	}
	return cont;
}

void List::push_back(Person persona){
	Node* temp = new Node(persona);

}

Node* List::first(){

}