#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <string>


using namespace std;

//The data structure that present a node.
class Node
{
friend class Chain;
public:
    //the pointer to next node in the chain
	Node *next;

    //stores the data
    int data;

	//constructor and destructor
	Node(){
		this->next = NULL;
	}
	Node(const int e, Node* next = NULL){
		this->data = e;
		this->next = next;
	}
	~Node(){
		this->next = NULL;
	}
};



//It contains the fucntions that you have to override.
class Chain
{
public:
    virtual void InsertBack(int data)=0;
	virtual void InsertFront(int data)=0;
    virtual void InsertAfter(int data1, int data2)=0;
    virtual void Delete(int data)=0;
	virtual void DeleteFront()=0;
	virtual void DeleteBack()=0;
    virtual void Reverse()=0;

    string toString(){
		Node* tmp = this->head;
		string result = "";
		if(tmp == NULL){
			result.append("Empty");
		}
		while(tmp != NULL) {
			string num = std::to_string(tmp->data);
			result.append(num);
			if(tmp->next != NULL)
				result.append("->");
			tmp = tmp->next;
		}
	return result;
}

	Node* head = NULL;
};


class Implement: public Chain
{
public:
	void InsertBack(int data);
	void InsertFront(int data);
	void InsertAfter(int data1, int data2);
	void Delete(int data);
	void DeleteFront();
	void DeleteBack();
	void Reverse();
	
};
#endif
