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
	Node* temp = head;

	for (int i = 0; i < posicion; i++){
		if (i == posicion){
			temp = temp -> getNext();
		}
	}

	Node* nuevo_nodo = new Node(persona);
	nuevo_nodo -> setNext(temp -> getNext());
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
	int  cont;
	Node* temp = head;
	while(temp -> hasNext()){
		if ((temp -> getValue().getName() == persona.getName()) == false){
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

}

Node* List::first(){

}