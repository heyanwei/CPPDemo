#pragma once

//���Ȩ��//
#define RouteMaxWeight 1000000 
//��󳤶�//
#define RouteMaxLength 1000000 

//�ڽӾ���//
class AdjacencyMatrix
{
public:
	AdjacencyMatrix();
	~AdjacencyMatrix();

	//��A����BΪ�ڽӵ�//
	int segmentID;//��A����B�Ķ�ID//
	int weight;//��A����B��Ȩ��//
	int length;//��A����B�ĳ���//
};

