#pragma once

#include "Utils/SQL/SQLUtils.h"

namespace lift {

	struct tb_floor
	{
		int index;
		int position;
		bool isEnable;

		tb_floor()
		{
			index = 0;
			position = 0;
			isEnable = 0;
		}
	};
	REFLECTION(tb_floor, index, position, isEnable)

	class FloorModel
	{
	private:
		void CreateTable();
		bool AddFloor(int index, int position, bool isEnable);
	};

}

