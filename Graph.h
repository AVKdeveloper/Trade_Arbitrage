#ifndef GRAPH
#define GRAPH

#include <vector>
#include <list>
#include <math.h>
#include "Burse.h"

class Edge
{
	numbers from; //����� �������, ������ �����
	numbers to; //����� �������, ���� �����
	float weight; //��� �����

	friend class Graph; 
};

class Graph
{
	numbers VertexNumber;
	std::list<Edge> edges; //��� ����� ����� �������� � ����� ������
public:
	Graph(Burse B);
	bool findCycleByBellmanFord() const;
};

Graph::Graph(Burse B)
{
	VertexNumber = B.CurrencyNumber;
	for (numbers i = 0; i < VertexNumber; i++)
	{
		for (numbers j = 0; j < VertexNumber; j++)
		{
			if (j != i && B.ExchangeRates[i][j] > -1)
			{
				Edge currentEdge; //������� �������, ������� ����� �������� � list
				currentEdge.from = i;
				currentEdge.to = j;
				currentEdge.weight = -log(B.ExchangeRates[i][j]);
				edges.push_back(currentEdge);
			}
		}
	}
}

bool Graph::findCycleByBellmanFord() const
{
	std::vector<std::pair<bool, float>> lenght(VertexNumber);//������ ���: ���� �� �������� ����, ���������� �� ������ ������� �� i-��
	lenght[0] = std::make_pair(1, 0);
	for (numbers i = 1; i < VertexNumber; i++)
		lenght[i] = std::make_pair(0, 1E9);
	bool relaxation = false;//���� �� ���������� �� ���������� ������
	for (numbers i = 0; i < VertexNumber; i++)
	{
		relaxation = false;
		for (Edge e : edges)
		{
			if (lenght[e.from].first)
			{
				if (!lenght[e.to].first)
				{
					lenght[e.to].first = 1;
					lenght[e.to].second = lenght[e.from].second + e.weight;
					relaxation = true;
				}
				else if (lenght[e.to].second > lenght[e.from].second + e.weight)
				{
					lenght[e.to].second > lenght[e.from].second + e.weight;
					relaxation = true;
				}
			}
		}
	}
	return relaxation;
}

#endif

