#include <iostream>
#include <vector>
using namespace std;

class sort{
public:
	void print(vector<int> src)
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

	void insert_sort(vector<int> &src)
	{
	    int temp;

	    for(int i = 1; i < src.size(); i++)
        {
            if(src[i] < src[i-1])
            {
                temp = src[i];
                int j = i-1;
                while(temp < src[j] && j >= 0) {
                    src[j+1] = src[j];
                    j--;
                }
                src[j+1] = temp;
            }

        }
	}

	void shell_sort(vector<int> &src)
	{
	    int dk = src.size() / 2;
	    while(dk > 0)
        {
            for(int i = 0; i < src.size() - dk; i++)
            {
                if(src[i] > src[i + dk])
                {
                    int temp = src[i+dk];
                    int j = i;
                    src[i + dk] = src[i];
                    while(temp < src[j] && j >= 0)
                    {
                        src[j+dk] = src[j];
                        j = j-dk;
                    }
                    src[j + dk] = temp;
                }

            }
            dk = dk / 2;
        }
	}

	void select_sort(vector<int> &src)
	{
	    int temp;

	    for(int i = 0; i < src.size(); i++)
        {
            int min_index = i;
            for(int j = i+1; j < src.size(); j++)
            {
                if(src[j] < src[min_index])
                    min_index = j;
            }
            temp = src[min_index];
            src[min_index] = src[i];
            src[i] = temp;
        }
	}

	void merge_sort(vector<int> &src)
	{
        vector<int> temp(src);

        int length = src.size();

        merge_help(temp, src, 0, length - 1);
        return;
	}
	void merge_help(vector<int> &src, vector<int> &dist, int start, int stop)
	{
	    if(stop <= start)
        {
    //        src[stop] = dist[stop];
            return;
        }

        int middle = start + (stop - start) / 2;

        merge_help(dist, src, start,  middle);
        merge_help(dist, src,  middle + 1, stop);

        int i = start;
        int k = start;
        int j = middle + 1;

        while(k <= middle && j <= stop)
        {
            if(src[k] > src[j])
                dist[i++] = src[j++];
            else
                dist[i++] = src[k++];
        }
        while(k <= middle)
            dist[i++] = src[k++];
        while(j <= stop)
            dist[i++] = src[j++];

    /*     for(int p = start; p <= stop; p++)
            src[p] = dist[p];
*/
        return;
	}

    void quick_sort(vector<int> &src, int low, int high)
    {
        if(src.size() == 0 || low >= high)
            return;

         int index;
       index = quick_sort_partition(src, low, high);
       quick_sort(src, low, index - 1);
       quick_sort(src, index + 1, high);
    }

    int quick_sort_partition(vector<int> &src, int low, int high)
    {
        int privotkey = src[low];
        int temp;
        while(low < high)
        {
            while(high > low && src[high] >= privotkey)
                high--;
            temp = src[low];
            src[low] = src[high];
            src[high] = temp;
            while(high > low && src[low] <= privotkey)
                low++;
            temp = src[low];
            src[low] = src[high];
            src[high] = temp;
        }
        return low;
    }

};



int  sort_main(void)
{
    vector<int> src = {49,38,65,97,76,13,27};
	sort example;
	//example.bubble_sort(src);
	//example.insert_sort(src);
	//example.shell_sort(src);
	//example.select_sort(src);
	//example.merge_sort(src);
	example.quick_sort(src, 0, src.size() - 1);
	example.print(src);
	return 0;
}

