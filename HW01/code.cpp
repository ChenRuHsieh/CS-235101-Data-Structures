#include <iostream>
#include <string>
#include "function.h"

class Implement : public Parenthesis
{
public :
		
		int top_bracket = -1;
		int top_char = -1;
		int top_op = -1;
		int top_out = -1;
		
		int size_char = 5;
		int size_bracket = 5;
		int size_op = 5;
		int size_out = 5;
		
		int correct = 1;
		
		char* stack_char;
		char* stack_bracket;
		char* stack_op ;
		int* stack_out;
		void isValid(std::string s)
		{
			
			int i = 0;
			top_char = -1;
			top_bracket = -1;
			top_op = -1;
			top_out = -1;
						
			size_char = 50;
			size_bracket = 50;
			size_op = 50;
			size_out = 50;
			
			stack_char = new char [size_char];
			stack_bracket = new char [size_bracket];
			stack_op = new char [size_op];
			stack_out = new int [size_out];

			
			correct = 1;
			
			for( i = 0 ; i < s.length() ; i++)
			{
				if( isdigit(s[i]) )
				{
					//std::cout << "Isdigit" << s[i] << std::endl;
					PushChar(s[i], stack_char, top_char, size_char);
				}
				else if( isOperator(s[i]) )
				{
					//std::cout << "IsOper" << s[i] << std::endl;
					PushChar(s[i], stack_char, top_char, size_char);
				}
				else if( isLeftBracket(s[i]) )
				{
					//std::cout << "IsLeBr" << s[i] << std::endl;
					PushChar(s[i], stack_char, top_char, size_char);
					PushChar(s[i], stack_bracket, top_bracket, size_bracket);
				}
				else if( isRightBracket(s[i]) )
				{
					//std::cout << "IsRiBr" << s[i] << std::endl;
					PushVaild(s[i]);	
				}
			}
			
			while(top_bracket != -1)
			{
				correct = 0;
				if(stack_bracket[top_bracket] == '(')
					PushChar(')', stack_char, top_char, size_char);
				else if(stack_bracket[top_bracket] == '[')
					PushChar(']', stack_char, top_char, size_char);
				else
					PushChar('}', stack_char, top_char, size_char);
				
				top_bracket--;
			}
			
			if(correct)
				std::cout << "True\n";
			else
			{
				std::cout << "False\n";	 
				
				for(i = 0 ; i <= top_char ; i++)
				{
					std::cout << stack_char[i];
				}
				std::cout << "\n";
			}
			
			
			for(i = 0 ; i <= top_char ; i++)
			{
				//std::cout << " top_char = "  << top_char << " i = " << i << std::endl;
				if( isdigit(stack_char[i]) )
				{
					int k = stack_char[i] - '0';
					PushInt(k, stack_out, top_out, size_out);
					//std::cout << " Input digit "  << top_out << " " << stack_out[top_out] << std::endl;
				}
				else if( isLeftBracket(stack_char[i]) )
				{
					PushChar(stack_char[i], stack_op, top_op, size_op);
					//std::cout << " Input op " << top_op << " " << stack_op[top_op] << std::endl;
				}
				else if( isOperator(stack_char[i]) )
				{
					if( stack_char[i] == '+' || stack_char[i] == '-')
					{
						if(top_op == -1)
						{
							PushChar(stack_char[i], stack_op, top_op, size_op);
							//std::cout << " Input op " << top_op << " " << stack_op[top_op] << std::endl;
						}
						else if( isOperator(stack_op[top_op]) )
						{	
							while(isOperator(stack_op[top_op]))
							{
								int op2 = PopOut();
								int op1 = PopOut();
								char op = PopOp();
								int result = 0;
								result = Operate(op1, op2, op);
								//std::cout << "result = " << result << std::endl;
								//printf("result = op1 %c op2 = %d %c %d = %d", op, op1, op, op2, result);
								
								PushInt(result, stack_out, top_out, size_out);
								//std::cout << " Input digit " << top_out << " " << stack_out[top_out] << std::endl;
								if(top_op == -1)
									break;
								
								//std::cout << " Input op " << top_op << " "<< stack_op[top_op] << std::endl;
							}
							PushChar(stack_char[i], stack_op, top_op, size_op);
						}
						else if(isLeftBracket(stack_op[top_op]))
						{
							PushChar(stack_char[i], stack_op, top_op, size_op);
							//std::cout << " Input op " << top_op << " " << stack_op[top_op] << std::endl;
						}
					}
					else //* / 
					{
						if(top_op == -1)
						{
							PushChar(stack_char[i], stack_op, top_op, size_op);
							//std::cout << " Input op " << top_op << " " << stack_op[top_op] << std::endl;
						}
						else if( stack_op[top_op] == '+' || stack_op[top_op] == '-' )
						{
							PushChar(stack_char[i], stack_op, top_op, size_op);
							//std::cout << " Input op " << top_op << " " << stack_op[top_op] << std::endl;
						}
						else if( stack_op[top_op] == '*' || stack_op[top_op] == '/' )
						{
							while(stack_op[top_op] == '*' || stack_op[top_op] == '/')
							{
								int op2 = PopOut();
								int op1 = PopOut();
								char op = PopOp();
								int result = 0;
								result = Operate(op1, op2, op);
								//printf("result = op1 %c op2 = %d %c %d = %d", op, op1, op, op2, result);
								PushInt(result, stack_out, top_out, size_out);
								//std::cout << " Input digit " << top_out << " " << stack_out[top_out] << std::endl;
								if(top_op == -1)
									break;
							}
							PushChar(stack_char[i], stack_op, top_op, size_op);
							//std::cout << " Input op " << top_op << " " << stack_op[top_op] << std::endl;
						}
						else if( isLeftBracket(stack_op[top_op]) )
						{
							PushChar(stack_char[i], stack_op, top_op, size_op);
							//std::cout << " Input op " << top_op << " " << stack_op[top_op] << std::endl;
						}
						
					}	
				}
				else if( isRightBracket(stack_char[i]) )
				{
					for(int j = top_op ; ; j--)
					{
						if( isLeftBracket(stack_op[j]) )
							break;
						int op2 = PopOut();
						int op1 = PopOut();
						char op = PopOp();
						int result = 0;
						result = Operate(op1, op2, op);
						//printf("result = op1 %c op2 = %d %c %d = %d", op, op1, op, op2, result);
						PushInt(result, stack_out, top_out, size_out);
						//std::cout << " Input digit " << top_out << " " << stack_out[top_out] << std::endl;
					}
					top_op--;
				}
			}
			
			while(top_op != -1)
			{
				int op2 = PopOut();
				int op1 = PopOut();
				char op = PopOp();
				int result = 0;
				result = Operate(op1, op2, op);
				//printf("result = op1 %c op2 = %d %c %d = %d", op, op1, op, op2, result);
				PushInt(result, stack_out, top_out, size_out);
				//std::cout << " Input digit " << top_out << " " << stack_out[top_out] << std::endl;			
			}
			if( top_out == -1)
				std::cout <<  "0" << std::endl;
			else
				std::cout <<  stack_out[top_out] << std::endl;
			
			delete [] stack_char;
			delete [] stack_op;
			delete [] stack_out;
			delete [] stack_bracket;
			
		}
		
		int Operate(int op1, int op2, char op)
		{
			if( op == '+')
				return	op1 + op2;
			else if(op == '-')
				return	op1 - op2;
			else if(op == '*')
				return	op1 * op2;
			else
				return	op1 / op2;
		}
		void PushChar(char t, char*& stack, int& top, int& size)
		{
			top++;
			if(top == size)
			{
				size = size * 2;
				//std::cout << "size = " << size << std::endl;
				char* new_stack = new char [size];
				for(int i = 0; i < top; i++)
				{
					new_stack[i] = stack[i];
				}
				delete [] stack;
				stack = new_stack;
			}
			stack[top] = t;
			//std::cout << top << " " << stack[top] << " " << size << std::endl;
			//std::cout << "Push " << top_bracket << " " << stack_bracket[top_bracket] << std::endl;
		}
		void PushInt(int t, int*& stack, int& top, int& size)
		{
			top++;
			if(top == size)
			{
				size *= 2;
				int* new_stack = new int [size];
				for(int i = 0; i < top; i++)
					new_stack[i] = stack[i];
									
				delete [] stack;
				stack = new_stack;
			}
			stack[top] = t;
			//std::cout << "Push " << top_bracket << " " << stack_bracket[top_bracket] << std::endl;
		}	
		
		void PopBracket()
		{
			
			/*for(int i = 0 ; i <= top_bracket ; i++)
			{
				//std::cout << stack_bracket[i];
			}*/
			//std::cout << "\n";
			top_bracket--;
		}
		
		int PopOut()
		{
			if(top_out == -1)
				return 0;
			int Pop = top_out;
			top_out--;
			return stack_out[Pop];
		}
		
		char PopOp()
		{
			if(top_op == -1)
			{
				std::cout << "run";
				return '1';
			}
			int Pop = top_op;
			//std::cout << "Pop op" << top_op << " = " << stack_op[Pop] << std::endl; 
			top_op--;
			return stack_op[Pop];
		}
		
		void PushVaild(char t)
		{
			int i = 0;
			
			if(top_bracket == -1)
				correct = 0;
			
			if( t == ')')
			{
				//std::cout << "PV " << t << std::endl;
				for( i = top_bracket ; i != -1 ; i-- )
				{
					if( stack_bracket[i] == '(' )
					{
						PushChar(t, stack_char, top_char, size_char);
						PopBracket();
						break;
						//std::cout << top << std::endl;
					}
					else if( stack_bracket[i] == '[' )
					{
						PushChar(']', stack_char, top_char, size_char);
						PopBracket();
						correct = 0;
						break;
					}
					else if( stack_bracket[i] == '{' )
					{
						PushChar('}', stack_char, top_char, size_char);
						PopBracket();
						correct = 0;
						break;
					}
				}
			}
			else if( t == ']')
			{
				//std::cout << "PV " << t << std::endl;
				for( i = top_bracket ; i != -1 ; i-- )
				{
					if( stack_bracket[i] == '(' )
					{
						PushChar(')', stack_char, top_char, size_char);
						PopBracket();
						correct = 0;
						break;
					}
					else if( stack_bracket[i] == '[' )
					{
						PushChar(t, stack_char, top_char, size_char);
						PopBracket();
						break;
					}
					else if( stack_bracket[i] == '{' )
					{
						PushChar('}', stack_char, top_char, size_char);
						PopBracket();
						correct = 0;
						break;
					}
				}				
			}
			else
			{
				//std::cout << "PV " << t << std::endl;
				for( i = top_bracket ; i != -1 ; i-- )
				{
					if( stack_bracket[i] == '(' )
					{
						PushChar(')', stack_char, top_char, size_char);
						PopBracket();
						correct = 0;
						break;
					}
					else if( stack_bracket[i] == '[' )
					{
						PushChar(']', stack_char, top_char, size_char);
						PopBracket();
						correct = 0;
						break;
					}
					else if( stack_bracket[i] == '{' )
					{
						PushChar(t, stack_char, top_char, size_char);
						PopBracket();
						break;
					}
				}				
			} 
		}
		
		bool isOperator(char t)
		{
			if( (t == '+') || (t == '-') || (t == '*') || (t == '/') )
				return 1;
			else
				return 0;
		}
		bool isLeftBracket(char t)
		{
			if( (t == '{') || (t == '[') || (t == '(') )
				return 1;
			else
				return 0;	
		}
		bool isRightBracket(char t)
		{
			if( (t == '}') || (t == ']') || (t == ')') )
				return 1;
			else
				return 0;	
		}
};
