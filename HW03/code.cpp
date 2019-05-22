#include "function.h"
#include <iostream>
#include <string>
using namespace std;

/*class Implement : public Heap
{
public :*/
string answer;
int print;
void Implement::Insert(int value)
{
	size++;
	//printf("	Insert : %d\n", value);
	int parent = 0;
	if(size == 1)
	{
		heap[size] = value;
		//printf("	%d insert in heap[%d]\n", heap[size], size);
	}
	else 
	{
		heap[size] = value;
		//printf("	%d insert in heap[%d]\n", heap[size], size);
		int current = size;
		for( parent = size/2 ; value > heap[parent] ; parent = parent / 2)
		{
			int tmp;
			if(parent == 1)
			{
				tmp = heap[parent];
				heap[parent] = value;
				heap[current] = tmp;
				break;
			}
			tmp = heap[parent];
			heap[parent] = value;
			heap[current] = tmp;
			
			current = parent;
			
		}
	}
	
/*	for(int i = 1; i <= size ; i++)
	{
		cout << heap[i] << " " ;
	}
	cout << endl;
*/
}

void Implement::DeleteMax()
{
	int value = heap[size];
	//printf("	The max %d will be deleted, repalced by %d\n", heap[1], value);
	heap[1] = value;
	heap[size] = 0;
	//printf("	The new heap %d\n", heap[1]);
	size--;
	
	int next = 1;
	int left_child = next * 2;
	int right_child = next * 2 + 1;
	int current = 1;
	
	while(1)
	{
		if( heap[left_child] > heap[right_child] )
			next = left_child;
		else
			next = right_child;
		

		
		//printf("	the next is heap[%d] : %d\n", next, heap[next]);
		if( value > heap[next])
		{
			break;
		}
		else if(next > size)
		{
			break;
		}
		else
		{
			heap[current] = heap[next];
			heap[next] = value;
			
		/*	for(int i = 1; i <= size ; i++)
			{
				cout << heap[i] << " " ;
			}
			cout << endl;*/
			
			current = next;
			left_child = next * 2;
			right_child = next * 2 + 1;
		}
	}
	//printf("	The true new heap is %d, and %d is in heap[%d]\n", heap[1], heap[current], current);
/*	for(int i = 1; i <= size ; i++)
	{
		cout << heap[i] << " " ;
	}
	cout << endl;
*/
}

int Implement::MaxPathWeight(int index)
{
	int current = 1;
	int left_child = current * 2;
	int right_child = current * 2 + 1;
	int next = 0;
	int max = heap[current];
	while(1)
	{
		left_child = current * 2;
		right_child = current * 2 + 1;
		
		//printf("current = %d\n", current);
		if(left_child > size)
			break;
		
		if( (heap[left_child] > heap[right_child]) || (left_child == size) )
		{
			next = left_child;
			max = max + heap[next];
			//printf("	Be added by heap[%d] = %d, and new max = %d\n", next, heap[next], max);
			current = next;
		}
		else if( (heap[left_child] < heap[right_child]) && (right_child <= size) )
		{
			next = right_child;
			max = max + heap[next];
			//printf("	Be added by heap[%d] = %d, and new max = %d\n", next, heap[next], max);
			current = next;
		}
	}
	
	return max;
}


string Implement::InorderTraversal(int index)
{
	if(index == 1)
	{
		answer = "";
		print = 1;
	}
	if(index > size)
		return "";
	else
	{
		InorderTraversal(index*2);//left
		if(print == 1)
		{
			answer.append(to_string(heap[index]));
			print = 0;
		}
		else	
		{
			answer.append(" " + to_string(heap[index]));
		}
		//printf("	heap[%d] = %d\n", index, heap[index]);
		InorderTraversal(index * 2 + 1);//right
		
		if(index != 1)
			return "";
	}
	return answer;
	
} 
string Implement::PreorderTraversal(int index)
{
	
	if(index == 1)
	{
		answer = "";
		print = 1;
	}	
	if(index > size)
		return "";
	else
	{
		if(print == 1)
		{
			answer.append(to_string(heap[index]));
			print = 0;
		}
		else	
		{
			answer.append(" " + to_string(heap[index]));
		}
		//printf("	heap[%d] = %d\n", index, heap[index]);
		PreorderTraversal(index*2);//left
		PreorderTraversal(index * 2 + 1);//right
		
		if(index != 1)
			return "";
	}
	return answer;
}

string Implement::PostorderTraversal(int index)
{
	if(index == 1)
	{
		answer = "";
		print = 1;
	}	
	if(index > size)
		return "";
	else
	{
		PostorderTraversal(index*2);//left
		PostorderTraversal(index * 2 + 1);//right
		if(print == 1)
		{
			answer.append(to_string(heap[index]));
			print = 0;
		}
		else	
		{
			answer.append(" " + to_string(heap[index]));
		}
		
		if(index != 1)
			return "";
	}
	return answer;
}
	
//};

