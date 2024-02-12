#include "Sorts.h"


int main()
{
	std::vector<float> vq, vb, vs, vh, vi;
	float meanq = 0, meanb = 0, means = 0, meanh = 0, meani = 0;
	const int N = 100;
	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		std::cout << i+1 << " iteration" << std::endl;
		const int iSize = 1000;
		auto sort = new Sorts<int>();
		for (int i = 0; i < iSize; i++)
		{
			int num = rand() % iSize;
			sort->arrayList.push_back(num);
			sort->bubbleArray.push_back(num);
			sort->shakeArray.push_back(num);
			sort->heapArray.push_back(num);
			sort->insertionArray.push_back(num);
		}

		std::cout << "Time to Quick sort from stl>" << std::endl;
		unsigned int start_time = clock(); // начальное время
		sort->arrayList.sort();
		unsigned int end_time = clock(); // конечное время
		unsigned int search_time = end_time - start_time; // искомое время
		std::cout << (float)search_time / CLOCKS_PER_SEC << std::endl;
		vq.push_back((float)search_time / CLOCKS_PER_SEC);
		vb.push_back(sort->BubbleSort());
		vs.push_back(sort->ShakeSort());
		vh.push_back(sort->HeapSort());
		vi.push_back(sort->InsertionSort());
		meanq += vq[i];
		meanb += vb[i];
		means += vs[i];
		meanh += vh[i];
		meani += vi[i];
		//sort->PrintArray(0);
		//sort->PrintArray(1);
		//sort->PrintArray(2);
		//sort->PrintArray(3);
		//sort->PrintArray(4);
		sort->arrayList.clear();
		sort->bubbleArray.clear();
		sort->shakeArray.clear();
		sort->heapArray.clear();
		sort->insertionArray.clear();
		std::cout << "end of "<< i + 1 <<" iteration" << std::endl;
	}
	std::cout << "Results:" << std::endl;
	std::cout << "Mean quick=" << (float)meanq / N << std::endl;
	std::cout << "Mean bubble=" << (float)meanb / N << std::endl;
	std::cout << "Mean shake=" << (float)means / N  << std::endl;
	std::cout << "Mean heap=" << (float)meanh / N  << std::endl;
	std::cout << "Mean insertion=" << (float)meani / N << std::endl;
	return 0;
}