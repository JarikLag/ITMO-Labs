#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "IterativeAlgorithm.h"
#include "RecursiveAlgorithm.h"
#include "ExponentialAlgorithm.h"
#include "EuclideanMetric.h"
#include "ManhattanMetric.h"
#include "BritishRailMetric.h"

#define add(name, type) {#name, new name##type()}

std::map<std::string, AlgorithmI*> algorithms = {
	add(Iterative, Algorithm),
	add(Recursive, Algorithm),
	add(Exponential, Algorithm)
};

std::map<std::string, MetricI*> metrics = {
	add(Euclidean, Metric),
	add(BritishRail, Metric),
	add(Manhattan, Metric)
};

int main()
{
	std::ifstream inputStream("input.txt");
	std::string algorithmName, metricName;
	//"Choose algorithm (Iterative, Recursive, Exponential)"
	inputStream >> algorithmName;
	//"Choose metric (Euclidean, Manhattan, BritishRail)"
	inputStream >> metricName;

	auto algorithmIterator = algorithms.find(algorithmName);
	auto metricIterator = metrics.find(metricName);
	if (algorithmIterator == algorithms.end()) {
		std::cout << "No such algorithm. Try again.";
		return 0;
	}
	if (metricIterator == metrics.end()) {
		std::cout << "No such metric. Try again.";
		return 0;
	}

	MetricI* metric = metricIterator->second;
	AlgorithmI* algorithm = algorithmIterator->second;
	std::vector<Point> points;
	Route result;
	int numberOfPoints, bound;

	inputStream >> numberOfPoints >> bound;
	for (int i = 0; i < numberOfPoints; ++i) {
		double x, y;
		inputStream >> x >> y;
		points.push_back(std::make_pair(x, y));
	}
	inputStream.close();

	double currentLength = 0;
	result = algorithm->calculateRoute(points, bound, metric);
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result[i].size() - 1; ++j) {
			currentLength += metric->calculateDistance(result[i][j], result[i][j + 1]);
		}
	}
	std::cout << "Length: " << currentLength << std::endl;
	for (int i = 0; i < result.size(); ++i) {
		std::cout << "Path #" << i + 1 << std::endl;
		for (int j = 0; j < result[i].size(); ++j) {
			std::cout << result[i][j].first << ' ' << result[i][j].second << std::endl;
		}
	}
	return 0;
}