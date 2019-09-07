#pragma once

//最大权重//
#define RouteMaxWeight 1000000 
//最大长度//
#define RouteMaxLength 1000000 

//邻接矩阵//
class AdjacencyMatrix
{
public:
	AdjacencyMatrix();
	~AdjacencyMatrix();

	//点A到点B为邻接点//
	int segmentID;//点A到点B的段ID//
	int weight;//点A到点B的权重//
	int length;//点A到点B的长度//
};

