#include <iostream>
#include <algorithm>

using namespace std;

struct Item
{
	int value, weight;
	Item(int v, int w) :value(v), weight(w){}
};

bool cmp(struct Item a, struct Item b)
{
	double r1 = (double)a.value / a.weight;
	double r2 = (double)b.value / b.weight;
	return r1 > r2;
}

double fractionalKnapsack(int W, struct Item arr[], int n)
{
	sort(arr, arr + n, cmp);

	int currentWeight = 0;
	double finalValue = 0.0;

	for (int i = 0; i < n; i++)
	{
		if (currentWeight + arr[i].weight <= W)
		{
			currentWeight += arr[i].weight;
			finalValue += arr[i].value;
		}
		else
		{
			int remain = W - currentWeight;
			finalValue += arr[i].value*((double)remain / arr[i].weight);
			break;
		}
	}
	return finalValue;
}

int main()
{
	int W = 50;
	Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Maximum value we can obtain="
		<< fractionalKnapsack(W, arr, n)
		<< endl;
	return 0;
}
