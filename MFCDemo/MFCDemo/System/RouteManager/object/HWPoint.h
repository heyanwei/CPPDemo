#pragma once

namespace route {
	class HWPoint
	{
	public:
		HWPoint();
		~HWPoint();

	public:
		int orgID;
		int x;
		int y;
		int angle;
		int curvature;//����//
		int plcBits;
		int plcWord;
		int plcWord2;
	};
}


