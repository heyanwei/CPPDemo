#include "HWSegment.h"

HWSegment::HWSegment()
{
	orgID=0;
	startPoint=0;
	endPoint=0;
	segmentTemplate="";
	vehicle="";
	travelTime = 0;
	startsAsStartPoint = 0;
	endsAsEndPoint = 0;
	direction = 0;
	plcBits = 0;
	plcWord = 0;
	plcWord2 = 0;
	addWeight = 0;
	length = 0;
	carrierTypes = 0;
}


HWSegment::~HWSegment()
{
}
