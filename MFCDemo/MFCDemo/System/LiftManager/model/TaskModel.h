#pragma once

#include "Utils/SQL/SQLUtils.h"

namespace lift {

	struct tb_lift_task {
		int index;
		int startFloor;
		int startPosition;
		int targetFloor;
		bool isNeedStop;//��Ҫֹͣ����
		bool isNeedCancel;//��Ҫȡ������
		bool isNeedBackToStartPos;//��Ҫ�ص����
		bool isNeedBackToStartPosRestart;//��Ҫ�ص��������ִ��//

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

