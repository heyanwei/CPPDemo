#include "HWPoint.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

namespace route {
	HWPoint::HWPoint()
	{
		orgID = 0;
		x = 0;
		y = 0;
		angle = 0;
		curvature = 0;//����//
		plcBits = 0;
		plcWord = 0;
		plcWord2 = 0;
	}


	HWPoint::~HWPoint()
	{
	}

}
