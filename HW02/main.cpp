 //========================DO-NOT-MODIFY-THE-FILE========================
#include <iostream>
#include <cstring>
#include "function.h"
#include "code.cpp"

void tryTestCase(Implement &inst)
{
    /*FILE * pFile;
    pFile = fopen(testfile.c_str(), "r");
    //std::ifstream ifs(testfile);

    if( !pFile )
        throw "[Missing Test File]";*/

    // parse each case
    char op[15];
    char result[2000];
    int value1, value2;
    bool isPass = false;
    
    while(std::cin >> op)
    {
    	//printf("%%%%%%\n");
        if(strcmp("InsertBack", op) == 0){
            std::cin >> value1;
            //std::cout << "InsertBack " << value1 << endl;
            inst.InsertBack(value1);
        }
		if(strcmp("InsertFront", op) == 0){
            std::cin >> value1;
            inst.InsertFront(value1);
        }
        else if(strcmp("InsertAfter", op) == 0){
            /*fscanf(pFile, "%d", &value1);
            fscanf(pFile, "%d", &value2);*/
            std::cin >> value1 >> value2;
            //std::cout << "InsertAfter " << value1 << " " << value2 <<endl;
            inst.InsertAfter(value1, value2);
        }
        else if(strcmp("Delete", op) == 0){ 
            //scanf(pFile, "%d", &value1);
            std::cin >> value1;
            //std::cout << "Delete " << value1 << endl;
            inst.Delete(value1);
        }
		else if(strcmp("DeleteFront", op) == 0){ 
            inst.DeleteFront();
        }
		else if(strcmp("DeleteBack", op) == 0){ 
            inst.DeleteBack();
        }
        else if(strcmp("Reverse", op) == 0) {
            //std::cout << "Reverse " << endl;
            inst.Reverse();
        }
        else if(strcmp("End", op) == 0) {
            //fscanf(pFile, "%s", result);
            //cin >> result;
            string urResultStr = inst.toString();
            std::cout << urResultStr << endl;
            //std:: cout << result << endl;
            // compare results
            //isPass = strcmp(urResultStr.c_str(), result);
            break;
        }
    }

}
int main(int argc, char *argv[])
{
    Implement inst = *(new Implement());
    tryTestCase(inst);
	return 0;
}

//========================DO-NOT-MODIFY-THE-FILE======================== 
