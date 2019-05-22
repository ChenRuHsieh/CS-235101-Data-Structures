#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <string>

using namespace std;

//It contains the functions that you have to override.
class Heap
{
public:
	int size=0;
	int *heap=new int[100000];
    virtual void Insert(int value)=0;
    virtual void DeleteMax()=0;
    virtual int MaxPathWeight(int index)=0;
    virtual string InorderTraversal(int index)=0;
    virtual string PreorderTraversal(int index)=0;
    virtual string PostorderTraversal(int index)=0;
	
	string toString(){
		//levelorder traversal
		string result = "";
		for(int i=1;i<=size;i++){
			if(i==1)
				result.append(to_string(heap[i]));
			else
				result.append(" "+to_string(heap[i]));
		}
		return result;
	}
};


class Implement : public Heap
{
public:
    void Insert(int value);
    void DeleteMax();
    int MaxPathWeight(int index);
	string InorderTraversal(int index);
	string PreorderTraversal(int index);
	string PostorderTraversal(int index);
};

#endif
