#pragma once

#include "Utils/SQL/SQLUtils.h"

namespace lift {
	//Éý½µ»ú×´Ì¬//
	enum class Status {
		Error,
		Manual,
		Local,
		Free,
		Busy
	};

	struct tb_lift {
		int index;
		Status status;
		int floor;
		int position;
		bool isCanEnter;
		bool isCanDoTask;
		int alarmCode;

		tb_lift()
		{
			index = 0;
			status = Status::Error;
			floor = 0;
			position = 0;
			isCanEnter = false;
			isCanDoTask = false;
			alarmCode = 0;
		}
	};
	REFLECTION(tb_lift, index, status, floor, position, isCanEnter, isCanDoTask, alarmCode)

	class LiftModel
	{
	private:
		void CreateTable();
		bool AddLift(int index);
		bool AddLifts();
		bool DeleteLift(int index);
		bool UpdateLift(int index);
		bool GetLift(int index);
		bool GetLifts();
	};
}


