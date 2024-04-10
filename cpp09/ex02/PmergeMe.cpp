#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		int num;
		std::stringstream ss(argv[i]);
		ss >> num;
		if (ss.fail()) throw std::string("argument is not integer");
		if (num < 1) throw std::string("argument is not positive integer");
		v.push_back(std::vector<int>(1, num));
	}
}

PmergeMe::PmergeMe(const PmergeMe& copy)
	: v(copy.v) {};

PmergeMe::~PmergeMe() {};

PmergeMe& PmergeMe::operator=(const PmergeMe& copy)
{
	if (this != &copy)
		v = copy.v;
	return (*this);
}

int PmergeMe::getJacobsthalNumber(int k)
{
	if (k == 0) return (-1);
	int n = k % 2 ? -1 : 1;
	return ((std::pow(2, k + 1) + n) / 3 - 1);
}

void PmergeMe::mergeElement(int idx1, int idx2)
{
	while (!v[idx1].empty())
	{
		v[idx2].push_back(v[idx1].back());
		v[idx1].pop_back();
	}
	v.erase(v.begin() + idx1);
}

int PmergeMe::getSize()
{
	int vecSize = 0;
	int elementSize = v[0].size();

	for (int i = 0; i < static_cast<int>(v.size()); i++)
		if (static_cast<int>(v[i].size()) == elementSize)
			vecSize++;

	return (vecSize);
}

int PmergeMe::binarySearch(int val, int left, int right)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (v[mid][0] <= val)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (left);
}

void PmergeMe::insert(int idx, int insertIdx)
{
	std::vector<int> vInsert;
	for (int i = v[idx].size() / 2; i > 0; i--)
	{
		vInsert.push_back(v[idx].back());
		v[idx].pop_back();
	}
	vInsert.push_back(-1);
	v.insert(v.begin() + insertIdx, vInsert);
}

void PmergeMe::removeBIT()
{
	for (int i = 0; i < static_cast<int>(v.size()); i++)
	{
		if (v[i].back() & BIT)
			v[i].pop_back();
	}
}

void PmergeMe::printVec()
{
	for (int i = 0; i < static_cast<int>(v.size()); i++)
	{
		std::cout << "v[" << i << "]\n";
		for (int j = 0; j < static_cast<int>(v[i].size()); j++)
			std::cout << v[i][j] << " ";
		std::cout << std::endl;
	}
}

void PmergeMe::lastSort(int idx)
{
	int insertIdx = binarySearch(v[idx].front(), 0, idx - 1);
	v.insert(v.begin() + insertIdx, v[idx]);
	v.erase(v.begin() + idx + 1);
}

void PmergeMe::sort()
{
	int vecSize = getSize();

	if (vecSize == 1) return ;

	int i = 0;
	while (i < vecSize / 2)
	{
		if (v[i][0] < v[i + 1][0])
			mergeElement(i, i + 1);
		else
			mergeElement(i + 1, i);
		i++;
	}
	sort();

	int maxIdx = vecSize / 2 - 1;
	int AddNum = 0;
	int k = 1;
	int nextJN, preJN;
	do
	{
		preJN = getJacobsthalNumber(k - 1);
		nextJN = std::min(getJacobsthalNumber(k), maxIdx);
		int gap = nextJN - preJN;
		int idx = nextJN + AddNum;
		for (int i = 0; i < gap; i++)
		{
			if (v[idx].back() & BIT)
			{
				i--;
				idx--;
			}
			else
			{
				int insertIdx = binarySearch(v[idx].back(), 0, idx - 1);
				insert(idx, insertIdx);
				AddNum++;
			}
		}
		k++;
	} while (nextJN != maxIdx);
	removeBIT();
	if (vecSize & 1)
		lastSort(vecSize - 1);
	printVec();
}

std::vector<int> PmergeMe::getResult()
{
	std::vector<int> retVec;
	for (int i = 0; i < static_cast<int>(v.size()); i++)
		retVec.push_back(v[i][0]);
	return (retVec);
}
