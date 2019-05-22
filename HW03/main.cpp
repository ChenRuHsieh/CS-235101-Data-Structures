 //========================DO-NOT-MODIFY-THE-FILE========================
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

//It contains the functions that you have to override.
class Heap
{
public:
	int size=0;
	int *heap=new int[100000];
    void Insert(int value)
    {
	}
    void DeleteMax(int value)
	{
	}
	
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

void tryTestCase(Implement &inst)
{
    // parse each case
    std::string input;
	char op[20];
    int value;
	while(std::cin >> op)
	{
        if(strcmp("Insert", op) == 0){
            std::cin >> value;
            inst.Insert(value);
        }
        else if(strcmp("DeleteMax", op) == 0){ 
            inst.DeleteMax();
        }
		else if(strcmp("MaxPathWeight", op) == 0){ 
            std::cout << inst.MaxPathWeight(1) << std::endl;
        }
		else if(strcmp("InorderTraversal", op) == 0){ 
            std::cout << inst.InorderTraversal(1) << std::endl;
        }
		else if(strcmp("PreorderTraversal", op) == 0){ 
            std::cout << inst.PreorderTraversal(1) << std::endl;
        }
		else if(strcmp("PostorderTraversal", op) == 0){ 
            std::cout << inst.PostorderTraversal(1) << std::endl;
        }
        else if(strcmp("End", op) == 0) {
			string urResultStr = inst.toString();
            std::cout << urResultStr << endl;
            break;
        }
    }
}


int main(int argc, char* argv[])
{
	Implement inst = *(new Implement());
    tryTestCase(inst);

    return 0;
}
