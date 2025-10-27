#include <iostream>
#include <fstream>
using namespace std;

struct element
{
    int key;
    int number;
};

int main()
{
    ifstream in;
    in.open("input.txt");

    int n = 0;
    in >> n;

    element* arr = new element[n];

    int arrSize = 1;
    int currNum;
    in >> currNum;
    element currEl;
    currEl.key = currNum;
    currEl.number = 1;
    arr[arrSize - 1] = currEl;

    for (int i = 1; i < n; i++)
    {
        in >> currNum;
        if (currNum > arr[arrSize - 1].key)
        {
            currEl.key = currNum;
            currEl.number = arrSize + 1;
            arr[arrSize] = currEl;
            arrSize++;
        }
        else
        {

            int j = 0, high = arrSize;
            while (j < high - 1) {
                int mid = j + (high - j) / 2;
                if (arr[mid].key > currNum) {
                    high = mid - 1;
                }
                else {
                    j = mid;
                }
            }

            if (arr[j].key < currNum)
            {
                arr[j + 1].key = currNum;
            }
        }
    }

    in.close();

    ofstream out;
    out.open("output.txt");
    out << arr[arrSize - 1].number;
    out.close();
}