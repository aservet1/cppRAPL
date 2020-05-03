#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

double randDouble()
{
	srand(time(0));
	double a = rand()%5;
	double b = rand()%5;
	return (double)rand()/RAND_MAX;
}

vector<double> r()
{
	srand(time(0));
	vector<double> v = {2,3,7,5,8,1,9,3,4};
	for (int i = 0; i < v.size(); i++)
		v[i]/=rand()%100+1;
	return v;
}

void print_vector(vector<double> &v)
{
	cout << "{ ";
	for (int i = 0; i < v.size()-1; i++)
		cout << v[i] << ", ";
	cout << v[v.size()-1] << " }" << endl;
}

void counting_sort(double arr[], int length)
{
	
}


int main(int argc, char *argv[])
{
	vector<double> v = r();
	print_vector(v);
	return 0;
}
