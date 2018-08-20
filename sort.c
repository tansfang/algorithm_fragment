#include <iostream>
#include <vector>
using namespace std;

class sort{
public:	
	void print(vector<int> &src)
	{
		for(int i = 0; i < src.size(); i++)
		{
			cout<<src[i]<<' ';
		}
		cout<<endl;
		return;
	}

	void bubble_sort(vector<int> &src)
	{
		if(src == NULL || src.size() == 0)
			return;

		int temp;

		for(int i = 0; i < src.size(); i++)
		{
			for( int j = 0; j < src.size() - i; j++)
			{
				if(src[j] > src[j+1])
				{
					temp = src[j];
					src[j] = src[j+1];
					src[j+1] = temp;
				}
			}
		}
	}	
	
};
vector<int> src (49,38,65,97,76,13,27);


int  main(void)
{
	sort example;
	example.bubble_sort(src);
	example.print(src);
	return 0;
}
