#include "function.h"

using namespace std;
//------------------------------------------------------
void Implement::InsertBack(int data)
{
	//return;
	Node* new_node = new Node(data);
	//printf("	InsertBack date = %d.\n", new_node->data);
	if(head == NULL)
	{
		head = new_node;
	}
	else 
	{ 
		Node* current = head;
		//printf("	current is head and data = %d.\n", current->data);
	    while (current->next != NULL) 
		{           
	        current = current->next;
	        //printf("	current is the next and data = %d.\n", current->data);
	    }
	    current->next = new_node;
	    //printf("	current is 倒數第2 and fianl data = %d.\n", current->next->data);
	} 
}

void Implement::InsertAfter(int data1, int data2)
{
	//return;
	if(head == NULL) return;
	Node* current = head;
		  //previous = new Node();
	Node* new_node = new Node(data2);
	
	//printf("	Insert %d After %d.\n", data1, data2);
	
	while( (current->data != data1) && (current->next != NULL) )
	{
		//previous = current;
		current = current->next;
	}
	//printf("	current of data is %d.\n", current->data);
	
	if(current->next == NULL && current->data == data1)
	{
		new_node->next = current->next;
		current->next = new_node;
		//printf("	current is final and data is %d, then be inserted %d.\n", current->data, current->next->data);
	}
	else if(current->next == NULL)
	{
		//cout << "	" << data1 << " dosen't exist." << endl;
		return;
	}
	/*else if(current == head)
	{
		new_node->next = current->next;
		current->next = new_node;
		//head = current;
	}*/
	else if(current->data == data1)
	{
		new_node->next = current->next;
		current->next = new_node;
		//printf("	current of data is %d, then be inserted %d.\n", current->data, current->next->data); 
	}
}

void Implement::InsertFront(int data)
{
	//return;
	Node* new_node = new Node(data);
	//printf("	InsertFront date = %d.\n", new_node->data);
	if(head == NULL)
	{
		head = new_node;
		//printf("	head of data = %d.\n", head->data);
	}
	else 
	{
	    new_node->next = head;                
	    head = new_node;
		//printf("	new head of data = %d.\n", head->data);                       
	}
}

void Implement::Delete(int data)
{
	//return;
	if(head == NULL) return;
	
	if( head->data == data ) 
	{
		if(head->next == NULL)
		{
			head = NULL;
		}
		else
		{
			head = head->next;
		}
		return ;
	}	
	
	Node* current = head;
	Node* previous = NULL;
	//printf("	Delete date = %d.\n", data);
	

	
	while( (current->data != data) && (current->next != NULL) )
	{
		previous = current;
		current = current->next;
	}
	//printf("	current of date is %d.\n", current->data);
	

	if(current->next == NULL && current->data == data)
	{
		previous->next = current->next;
		//printf("	current of data is %d, then be deleted.\n", current->data); 
		
		delete current;
		current = NULL;
	}
	else if( current->next == NULL )
	{
		//cout << "	" << data << " dosen't exist." << endl; 
		return ;
	}
	else if(current->data == data)
	{
		previous->next = current->next;
		//printf("	current of data is %d, then be deleted.\n", current->data); 
		
		delete current;
		current = NULL;
	}
	
}

void Implement::DeleteFront()
{
	//return;
	if(head == NULL) return;
	Node* current = head;
	//printf("	DeleteFront and its data is %d.\n", current->data);
	head = current->next;
	//printf("	new head of data is %d.\n", head->data);
	
	delete current;
	current = NULL;

}

void Implement::DeleteBack()
{
	//return;
	if(head == NULL) return;
	Node* current = head;
	Node* previous = new Node();
	
	
	while (current->next != NULL) 
	{           
		previous = current;
		current = current->next;
	}
	//printf("	current is the final and data = %d, then be deleted.\n", current->data);
	
	previous->next = NULL;
	//printf("	previous is the new final and data = %d.\n", previous->data);
	delete current;
	current = NULL;

}

void Implement::Reverse()
{
	//return;
	if(head == NULL) return;
	Node* current = head;
	Node* previous = NULL;
	Node* preceding = head->next;
	
	while (preceding != NULL) 
	{
        current->next = previous;      // 把current->next轉向
        previous = current;            // previous往後挪
        current = preceding;           // current往後挪
        preceding = preceding->next;   // preceding往後挪
    }
	
	current->next = previous;          // 此時current位於最後一個node, 將current->next轉向
    head = current;                   // 更新first為current  

}

