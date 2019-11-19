#pragma once

//最大权重//
#define RouteMaxWeight 1000000 

//邻接矩阵//
class AdjacencyMatrix
{
public:
	AdjacencyMatrix();
	~AdjacencyMatrix();

	//点A到点B为邻接点//
	int id;//点A到点B的ID//
	int weight;//点A到点B的权重//
};

