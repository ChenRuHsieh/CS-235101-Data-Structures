#include <string>
#include <iostream>
#include <list>
#include <stack>
#include "function.h"
/*
addEdge 1 2 2
addEdge 2 4 5
addEdge 1 4 2
addEdge 2 5 2 
delete 1 5
d
degree 2
degree 3
degree 4
isExistPath 1 5
number_of_component

deleteGraph
*/
void printgraph(GraphOperations &graph){
	for (std::list<Vertex>::iterator v=graph.VertexArr.begin(); v != graph.VertexArr.end(); ++v){
		std::cout << v->label << " : ";
		for (std::list<Neighbor>::iterator n=v->neighbors.begin(); n != v->neighbors.end(); ++n){
			std::cout << n->label << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void Implement::addEdge(const int label_1, const int label_2 , const int weight)
{
	std::list<Vertex>::iterator v, v1, v2;
	std::list<Neighbor>::iterator n, n1, n2;
	bool exist_1 = false;
	bool exist_2 = false;
	int count, pos1 = 0, pos2 = 0;
	
	if(label_1 == label_2)
		return;
		
	for(count = 0, v = VertexArr.begin(); v != VertexArr.end(); count++, v++){
		if(v->label == label_1){
			v1 = v;
			pos1 = count;
			exist_1 = true;
		}
		if(v->label == label_2){
			v2 = v;
			pos2 = count;
			exist_2 = true;
		}
	}
	
	if(!exist_1 && !exist_2){
		Vertex new_vertex1(label_1);
		Neighbor new_neigbor1(label_2, weight);
		new_vertex1.neighbors.push_back(new_neigbor1);
		VertexArr.push_back(new_vertex1);
		
		Vertex new_vertex2(label_2);
		Neighbor new_neigbor2(label_1, weight);
		new_vertex2.neighbors.push_back(new_neigbor2);
		VertexArr.push_back(new_vertex2);
	}
	else if(!exist_1 && exist_2){
		Vertex new_vertex1(label_1);
		Neighbor new_neigbor1(label_2, weight);
		new_vertex1.neighbors.push_back(new_neigbor1);
		VertexArr.push_back(new_vertex1);
		
		Neighbor new_neigbor2(label_1, weight);
		v2->neighbors.push_back(new_neigbor2);
	}
	else if(exist_1 && !exist_2){	
		Neighbor new_neigbor1(label_2, weight);
		v1->neighbors.push_back(new_neigbor1);
		
		Vertex new_vertex2(label_2);
		Neighbor new_neigbor2(label_1, weight);
		new_vertex2.neighbors.push_back(new_neigbor2);
		VertexArr.push_back(new_vertex2);
	}
	else if(exist_1 && exist_2){
		for(n = v1->neighbors.begin(); n != v1->neighbors.end(); n++){
			if(n->label == label_2)
				return;
		}
		
		Neighbor new_neigbor1(label_2, weight);
		v1->neighbors.push_back(new_neigbor1);
		Neighbor new_neigbor2(label_1, weight);
		v2->neighbors.push_back(new_neigbor2);
	}
	//printgraph(*this);
}

void Implement::deleteEdge(const int label_1, const int label_2)
{
	std::list<Vertex>::iterator v;
	std::list<Neighbor>::iterator n;
	
	for(v = VertexArr.begin(); v != VertexArr.end(); v++){
		if(v->label == label_1){
			for(n = v->neighbors.begin(); n != v->neighbors.end(); n++){
				if(n->label == label_2){
					v->neighbors.erase(n);
					break;
				}
			}
		}
		else if(v->label == label_2){
			for(n = v->neighbors.begin(); n != v->neighbors.end(); n++){
				if(n->label == label_1){
					v->neighbors.erase(n);
					break;
				}
			}
		}
	}
	//printgraph(*this);
}

void Implement::deleteVertex(const int label)
{
	std::list<Vertex>::iterator v, nOFv;
	std::list<Neighbor>::iterator n, nOFn;
	
	for(v = VertexArr.begin(); v != VertexArr.end(); v++){
		if(v->label == label){
			for(n = v->neighbors.begin(); n != v->neighbors.end(); n++){
				for(nOFv = VertexArr.begin(); nOFv != VertexArr.end(); nOFv++){
					if(nOFv->label == n->label){
						for(nOFn = nOFv->neighbors.begin(); nOFn != nOFv->neighbors.end(); nOFn++){
							if(nOFn->label == v->label){
								nOFv->neighbors.erase(nOFn);
								break;
							}
						}
					}
				}
			}
			VertexArr.erase(v);
			//printgraph(*this);		
			return ;
		}
	}
}

int Implement::degree(const int label)
{
	std::list<Vertex>::iterator v, v1;
	bool exist = false;
	
	for(v = VertexArr.begin(); v != VertexArr.end(); v++){
		if(v->label == label){
			v1 = v;
			exist = true;
		}
	}
	
	if(exist)
		return v1->neighbors.size();
	else
		return 0;
	
}

bool Implement::isExistPath(const int label_1, const int label_2)
{
	std::list<Vertex>::iterator v, v1, v2;
	Vertex current_v;
	std::list<Neighbor>::iterator n;
	bool exist_1 = false, exist_2 = false;
	std::stack<Vertex> s;
	std::list<int> path;
	std::list<int>::iterator p;
	int current = 0, max_label = 0;
	
	for(v = VertexArr.begin(); v != VertexArr.end(); v++){
		if(v->label > max_label){
			max_label = v->label;
		}
	}
	bool visited[100000];
	for(int i = 0; i < max_label+1; i++){
		visited[i] = false;
	}
	
	for(v = VertexArr.begin(); v != VertexArr.end(); v++){
		if(v->label == label_1){
			v1 = v;
			exist_1 = true;
		}
		else if(v->label == label_2){
			v2 = v;
			exist_2 = true;
		}
	}
	
	if(!exist_1 || !exist_2)
		return false;
	
	s.push(*v1);
	while( !s.empty() ){
		current = s.top().label;
		current_v = s.top();
		path.push_back(current);
		s.pop();
		
		if(!visited[current]){
			visited[current] = true;
			for(n = current_v.neighbors.begin(); n != current_v.neighbors.end(); n++){
				if(visited[n->label] == false){
					for(v = VertexArr.begin(); v != VertexArr.end(); v++){
						if(v->label == n->label){
							s.push(*v);
							break;
						}
					}
				}
			}
		}
	}
	
	for(p = path.begin(); p != path.end(); p++){
		if(*p == label_2)
			return true;
	}
	return false;
}

void Implement::deleteGraph()
{
	VertexArr.clear();
	//printgraph(*this);
}

int Implement::number_of_component()
{
	std::list<Vertex>::iterator v, v1, v2;
	Vertex current_v;
	std::list<Neighbor>::iterator n;
	std::stack<Vertex> s;
	int current = 0, count = 0, max_label = 0;
	
	for(v = VertexArr.begin(); v != VertexArr.end(); v++){
		if(v->label > max_label){
			max_label = v->label;
		}
	}
	bool visited[100000];
	
	for(int i = 0; i < 100000; i++){
		visited[i] = false;
	}
	for(v = VertexArr.begin(); v != VertexArr.end(); v++){
		if(visited[v->label] == false){
			s.push(*v);
			while( !s.empty() ){
				current = s.top().label;
				current_v = s.top();
				//path.push_back(current);
				s.pop();
				
				if(!visited[current]){
					visited[current] = true;
					for(n = current_v.neighbors.begin(); n != current_v.neighbors.end(); n++){
						if(visited[n->label] == false){
							for(v2 = VertexArr.begin(); v2 != VertexArr.end(); v2++){
								if(v2->label == n->label){  
									s.push(*v2);
									break;
								}
							}
						}
					}
				}
			}
			count++;
		}
	}
	return count;
}

bool Implement::isExistCycle()
{
	//printgraph(*this);
	int DFS_weight = 0, all_weight = 0;
	std::list<Vertex>::iterator v, v1, v2;
	//std::lise<Stack>::iterator it_s;
	Vertex current_v;
	std::list<Neighbor>::iterator n;
	std::stack<Vertex> s;
	int current = 0, count = 0, max_label = 0;
	int flag = 0;
	
	for(v = VertexArr.begin(); v != VertexArr.end(); v++){
		if(v->label > max_label){
			max_label = v->label;
		}
	}
	bool visited[max_label+1];
	bool stack[max_label+1];
	for(int i=0; i<max_label+1; i++){
		visited[i] = false;
		stack[i] = false;
	}
	
	for(v = VertexArr.begin(); v != VertexArr.end(); v++){
		if(visited[v->label] == false){
			s.push(*v);
			//std::cout << "	Push : " << v->label << std::endl;
			while( !s.empty() ){
				current = s.top().label;
				current_v = s.top();
				//path.push_back(current);
				s.pop();
				//std::cout << "	Pop : " << current_v.label << std::endl; 
				
				if(!visited[current]){
				//	std::cout << current << "	is visited" << std::endl; 
					visited[current] = true;
					for(n = current_v.neighbors.begin(); n != current_v.neighbors.end(); n++){
				//		std::cout << current << "	find neighbors" << std::endl;
						if(visited[n->label] == false){
				//			std::cout << n->label << "	is neighbor unvisited" << std::endl;
							for(v2 = VertexArr.begin(); v2 != VertexArr.end(); v2++){
				//				std::cout <<"	find vertex for " << n->label << std::endl;
								if(v2->label == n->label){
				//					std::cout << n->label << "	of vertex has been found" << std::endl;
									if(stack[n->label] == false){
										s.push(*v2);
										stack[n->label] = true;
				//						std::cout << "	Push : " << n->label << std::endl;
										DFS_weight += n->weight; 
										break;
									} 
								}
							}
						}
					}
				}
			}
		}
	}
	
	for(v = VertexArr.begin(); v != VertexArr.end(); v++){
		for(n = v->neighbors.begin(); n != v->neighbors.end(); n++){
			all_weight += n->weight;
		}
	}
	all_weight /= 2;
	//std::cout << "	DFS_weight = " << DFS_weight << std::endl;
	//std::cout << "	all_weight = " << all_weight << std::endl;
	
	if(all_weight == DFS_weight)
		return false;
	else	
		return true;
	
}
