#include "stdafx.h"
#include "AdjacencyMatrix.h"


AdjacencyMatrix::AdjacencyMatrix()
{
	segmentID = 0;
	length = RouteMaxLength;
	weight = RouteMaxWeight;
}


AdjacencyMatrix::~AdjacencyMatrix()
{
}
