#include <fstream>

void MergeSort(int* arr, int left, int right) // [l, r)
{
	if (right - left <= 1)
	{
		return;
	}
	int mid = (right - left) / 2;
	MergeSort(arr, left, left + mid);
	MergeSort(arr, left + mid, right);
	int* temp = new int[right - left];
	int l = left;
	int r = left + mid;
	int i = 0;
	while (l < left + mid && r < right)
	{
		if (arr[l] > arr[r])
		{
			temp[i] = arr[l];
			l++;
		}
		else
		{
			temp[i] = arr[r];
			r++;
		}
		i++;
	}

	while (l < left + mid)
	{
		temp[i] = arr[l];
		l++;
		i++;
	}

	while (r < right)
	{
		temp[i] = arr[r];
		r++;
		i++;
	}

	for (int j = 0; j < right - left; j++)
	{
		arr[left + j] = temp[j];
	}

	return;
}

int main()
{
	std::ifstream in("input.txt");
	int n, m;
	in >> n >> m;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		in >> a >> b;
		arr[a - 1] += 1;
		arr[b - 1] += 1;
	}

	in.close();

	MergeSort(arr, 0, n);

	std::ofstream out("output.txt");
	for (int i = 0; i < n; i++)
	{
		out << arr[i] << " ";
	}
	out.close();
}