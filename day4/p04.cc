#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class MyException
{
protected:
	int i;
public:
	MyException()
	{
		cout << "MyException cttor" << endl;
	}

	MyException(int a) : i(a)
	{
		cout << "MyException cttor" << endl;
	}

	~MyException()
	{
		cout << "MyException dttor" << endl;
	}

};

class IOException : public MyException
{
public:
	int i;
	IOException()
	{
		cout << "IOException cttor" << endl;
	}
	
	IOException(int a) : i(a)
	{
		cout << "IOException(int i) cttor" << endl;
	}
	
	~IOException()
	{
		cout << "IOException dttor" << endl;
	}
};

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
	
	//put in try catch block
	try
	{
		int denominator = 1;
		if(denominator == 0)
		{
			throw denominator;
		}
		int x = 30/denominator;

		
		/*for(unsigned int i=0 ; i< vec.size() ; ++i) // its error. size will get updated every time
		{
			if(vec.size() != 6)
			{
				string ob = "String Ex";
				throw ob;
			}
			vec.push_back(i + 4);
		}*/

		//throw MyException(10);
		throw IOException(10);
	}
	catch(int i)
	{
		cout << "Denomintor giving Exception" << endl;
	}
	catch(string ob)
	{
		cout << "string giving Exception" << endl;
	}
	//derived clas should defined first
	catch(IOException ob)
	{
		cout << "IOEception catched : " << ob.i << endl;
	}
	catch(MyException ob)
	{
		cout << "MyException Exception catch" << endl;
	}

	cout << "Out side" << endl;
	cout << endl;

}
