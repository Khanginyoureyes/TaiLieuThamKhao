
void merge(int a[], int left, int right, int mid)
{
	int lengthSubArrayOne = mid - left + 1;
	int lengthSubArrayTwo = right - mid;

	int *subArrayOne = new int[lengthSubArrayOne];
	int	*subArrayTwo = new int[lengthSubArrayTwo];

	for (int i = 0; i < lengthSubArrayOne; i++)
	{
		subArrayOne[i] = a[left + i];
	}
	for (int j = 0; j < lengthSubArrayTwo; j++)
	{
		subArrayTwo[j] = a[mid + 1 + j];
	}

	int indexOfSubArrayOne = 0;
	int indexOfSubArrayTwo = 0;
	int indexOfArrayMerge = left;

	while (indexOfSubArrayOne < lengthSubArrayOne && indexOfSubArrayTwo < lengthSubArrayTwo)
	{
		if (subArrayOne[indexOfSubArrayOne] >= subArrayTwo[indexOfSubArrayTwo])
		{
			a[indexOfArrayMerge] = subArrayTwo[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		else
		{
			a[indexOfArrayMerge] = subArrayOne[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		indexOfArrayMerge++;
	}

	while (indexOfSubArrayOne < lengthSubArrayOne)
	{
		a[indexOfArrayMerge] = subArrayOne[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfArrayMerge++;
	}
	while (indexOfSubArrayTwo < lengthSubArrayTwo)
	{
		a[indexOfArrayMerge] = subArrayTwo[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfArrayMerge++;
	}
	delete []subArrayOne;
	delete []subArrayTwo;
}

void mergeSort(int a[], int left, int right)
{
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	mergeSort(a, left, mid);
	mergeSort(a, mid + 1, right);
	merge(a, left, right, mid);
}