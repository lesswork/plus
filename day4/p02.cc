#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void display(int x)
{
	cout << x << " ";
}

bool isGreater(int x , int y)
{
	//decending
	return (x > y);
	
	// accending
	//return (x > y);
}

int main()
{
	vector<int> vec;
	vec.push_back(2);
	vec.push_back(33);
	vec.push_back(4);
	vec.push_back(13);
	vec.push_back(22);
	vec.push_back(7);

	cout << "vec.size : " << vec.size() << endl;
	//for(int i=0 ; i< vec.size() ; ++i) // its error. size will get updated every time
	for(int i=0 ; i< 4 ; ++i)
	{
		vec.push_back(i + 4);
	}
	for_each(vec.begin(), vec.end(), display);
	cout << endl;

	int cnt = count(vec.begin(), vec.end(), 33);
	cout << "33 count is : " << cnt << endl;

	sort(vec.begin(), vec.end(), isGreater);
	for_each(vec.begin(), vec.end(), display);
	cout << endl;

}
