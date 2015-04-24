#pragma once
class Edge
{
public:
	double startXPosition;
	double startYPosition;

	double endXPosition;
	double endYPosition;

	Edge();
	Edge(double startX, double startY, double endX, double endY);

	~Edge();
};

