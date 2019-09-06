#include "RouteFile.h"

#include <fstream>

#include "Utils/File/csv.hpp"

RouteFile::RouteFile()
{
}


RouteFile::~RouteFile()
{
}

bool RouteFile::ReadPoints(std::map<int, HWPoint>& pointsMap)
{
	try
	{
		csv::CSVReader reader("Layout\\points.txt");
		for (csv::CSVRow &row : reader)
		{
			HWPoint point;

			int para_index = 1;
			for (csv::CSVField &field : row)
			{
				switch (para_index)
				{
				case 1:
					point.orgID = field.get<int>();
					break;
				case 2:
					point.x = field.get<int>();
					break;
				case 3:
					point.y = field.get<int>();
					break;
				case 4:
					point.angle = field.get<int>();
					break;
				case 5:
					point.curvature = field.get<int>();
					break;
				case 6:
					point.plcBits = field.get<int>();
					break;
				case 7:
					point.plcWord = field.get<int>();
					break;
				case 8:
					point.plcWord2 = field.get<int>();
					break;
				}

				para_index++;
			}
			if (point.orgID != 0)
			{
				pointsMap[point.orgID] = point;
			}
		}
		return true;
	}
	catch (...)
	{
		std::cout << "read point file error..."<<std::endl;
	}

	return false;
}

bool RouteFile::ReadStations(std::map<int, HWStation>& stationsMap)
{
	try
	{
		csv::CSVReader reader("Layout\\stations.txt");
		for (csv::CSVRow &row : reader)
		{
			HWStation station;

			int para_index = 1;
			for (csv::CSVField &field : row)
			{
				switch (para_index)
				{
				case 1:
					station.stationID = field.get<int>();
					break;
				case 2:
					station.pointID = field.get<int>();
					break;
				case 3:
					station.type = field.get<std::string>();
					break;
				case 4:
					station.sysMode = field.get<int>();
					break;
				case 5:
					station.carrierTypes = field.get<int>();
					break;
				}

				para_index++;
			}
			if (station.stationID != 0)
			{
				stationsMap[station.stationID] = station;
			}
		}
		return true;
	}
	catch (...)
	{
		std::cout << "read station file error..." << std::endl;
	}

	return false;
}

bool RouteFile::ReadSegments(std::map<int, HWSegment>& segmentsMap)
{
	try
	{
		csv::CSVReader reader("Layout\\segments.txt");
		for (csv::CSVRow &row : reader)
		{
			HWSegment segment;

			int para_index = 1;
			for (csv::CSVField &field : row)
			{
				switch (para_index)
				{
				case 1:
					segment.orgID = field.get<int>();
					break;
				case 2:
					segment.startPoint = field.get<int>();
					break;
				case 3:
					segment.endPoint = field.get<int>();
					break;
				case 4:
					segment.segmentTemplate = field.get<std::string>();
					break;
				case 5:
					segment.vehicle = field.get<std::string>();
					break;
				case 6:
					segment.travelTime = field.get<int>();
					break;
				case 7:
					segment.startsAsStartPoint = field.get<int>();
					break;
				case 8:
					segment.endsAsEndPoint = field.get<int>();
					break;
				case 9:
					segment.direction = field.get<int>();
					break;
				case 10:
					segment.plcBits = field.get<int>();
					break;
				case 11:
					segment.plcWord = field.get<int>();
					break;
				case 12:
					segment.plcWord2 = field.get<int>();
					break;
				case 13:
					segment.addWeight = field.get<int>();
					break;
				case 14:
					segment.length = field.get<int>();
					break;
				case 15:
					segment.carrierTypes = field.get<int>();
					break;
				}

				para_index++;
			}
			if (segment.orgID != 0)
			{
				segmentsMap[segment.orgID] = segment;
			}
		}
		return true;
	}
	catch (...)
	{
		std::cout << "read segment file error..." << std::endl;
	}

	return false;
}

