#include "node.hpp"
#include <cstring>
#include <iostream>

using namespace std;

Node::Node(){

}

Node::~Node(){
	delete next;
}

Node::Node(Person persona){
	next = new Node();
	setValue(persona);
}
	
Person Node::getValue(){
	return persona;
}

void Node::setValue(Person persona){
	this -> persona = persona;
}

void Node::setNext(Node* next){
	this -> next = next;
}

Node* Node::getNext(){
	return next;
}

bool Node::hasNext(){
	if (next == NULL){
		return false;
	}else{
		return true;
	}
}
