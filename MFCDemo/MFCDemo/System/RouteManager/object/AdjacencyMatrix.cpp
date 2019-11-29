#include "stdafx.h"
#include "AdjacencyMatrix.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

AdjacencyMatrix::AdjacencyMatrix()
{
	id = 0;
	weight = RouteMaxWeight;
}


AdjacencyMatrix::~AdjacencyMatrix()
{
}
