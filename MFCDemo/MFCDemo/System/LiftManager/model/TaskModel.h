#pragma once

#include "Utils/SQL/SQLUtils.h"

namespace lift {

	struct tb_lift_task {
		int index;
		int startFloor;
		int startPosition;
		int targetFloor;
		bool isNeedStop;//需要停止运行
		bool isNeedCancel;//需要取消任务
		bool isNeedBackToStartPos;//需要回到起点
		bool isNeedBackToStartPosRestart;//需要回到起点重新执行//

		tb_lift_task()
		{
			index = 0;
			startFloor = 0;
			startPosition = 0;
			targetFloor = 0;
			isNeedStop = false;
			isNeedCancel = false;
			isNeedBackToStartPos = false;
			isNeedBackToStartPosRestart = false;
		}
	};
	REFLECTION(tb_lift_task, index, startFloor, startPosition, targetFloor, 
		isNeedStop, isNeedCancel, isNeedBackToStartPos, isNeedBackToStartPosRestart)

	class TaskModel
	{
		void CreateTable();
		bool AddTask(int index);
		bool DeleteTask(int index);
		bool UpdateTask(int index);
		bool GetTask(int index);
		bool GetTasks();
	};

}

