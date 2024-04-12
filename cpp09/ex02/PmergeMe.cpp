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
		d.push_back(std::deque<int>(1, num));
	}
}

PmergeMe::PmergeMe(const PmergeMe& copy)
	: v(copy.v), d(copy.d) {};

PmergeMe::~PmergeMe() {};

PmergeMe& PmergeMe::operator=(const PmergeMe& copy)
{
	if (this != &copy)
	{
		v = copy.v;
		d = copy.d;
	}
	return (*this);
}

// vector 버전

int PmergeMe::getElementSize()
{
	return (v.size());
}

int PmergeMe::getJacobsthalNumber(int k)
{
	if (k == 0) return (-1);
	int n = k % 2 ? -1 : 1;
	return ((std::pow(2, k + 1) + n) / 3 - 1);
}

void PmergeMe::mergeElementV(int idx1, int idx2)
{
	while (!v[idx1].empty())
	{
		v[idx2].push_back(v[idx1].back());
		v[idx1].pop_back();
	}
	v.erase(v.begin() + idx1);
}

int PmergeMe::getSizeV()
{
	int vecSize = 0;
	int elementSize = v[0].size();

	for (int i = 0; i < static_cast<int>(v.size()); i++)
		if (static_cast<int>(v[i].size()) == elementSize)
			vecSize++;

	return (vecSize);
}

int PmergeMe::binarySearchV(int val, int left, int right)
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

void PmergeMe::insertV(int idx, int insertIdx)
{
	std::vector<int> vInsert;
	for (int i = v[idx].size() / 2; i > 0; i--)
	{
		vInsert.push_back(v[idx].back());
		v[idx].pop_back();
	}
	v.insert(v.begin() + insertIdx, vInsert);
}

// void PmergeMe::printVec()
// {
// 	for (int i = 0; i < static_cast<int>(v.size()); i++)
// 	{
// 		std::cout << "v[" << i << "]\n";
// 		for (int j = 0; j < static_cast<int>(v[i].size()); j++)
// 			std::cout << v[i][j] << " ";
// 		std::cout << std::endl;
// 	}
// }

void PmergeMe::lastSortV(int idx)
{
	int insertIdx = binarySearchV(v[idx].front(), 0, idx - 1);
	v.insert(v.begin() + insertIdx, v[idx]);
	v.erase(v.begin() + idx + 1);
}

void PmergeMe::sortV()
{
	int vecSize = getSizeV();

	if (vecSize == 1) return ;

	int i = 0;
	while (i < vecSize / 2)
	{
		if (v[i][0] < v[i + 1][0])
			mergeElementV(i, i + 1);
		else
			mergeElementV(i + 1, i);
		i++;
	}
	sortV();

	int maxIdx = vecSize / 2 - 1;
	int AddNum = 0;
	int k = 1;
	int nextJN, preJN;
	int size = v[0].size();
	do
	{
		preJN = getJacobsthalNumber(k - 1);
		nextJN = std::min(getJacobsthalNumber(k), maxIdx);
		int gap = nextJN - preJN;
		int idx = nextJN + AddNum;
		for (int i = 0; i < gap; i++)
		{
			if (static_cast<int>(v[idx].size()) != size)
			{
				i--;
				idx--;
			}
			else
			{
				int insertIdx = binarySearchV(v[idx].back(), 0, idx - 1);
				insertV(idx, insertIdx);
				AddNum++;
			}
		}
		k++;
	} while (nextJN != maxIdx);
	if (vecSize & 1)
		lastSortV(vecSize - 1);
	// printVec();
}

std::vector<int> PmergeMe::getResultV()
{
	std::vector<int> retVec;
	for (int i = 0; i < static_cast<int>(v.size()); i++)
		retVec.push_back(v[i][0]);
	return (retVec);
}


// deque 버전

std::deque<std::deque<int> >::iterator PmergeMe::getIterD(int i)
{
	std::deque<std::deque<int> >::iterator iter = d.begin();
	
	for (int j = 0; j < i; j++)
		++iter;
	return (iter);
}

void PmergeMe::mergeElementD(int idx1, int idx2)
{
	while (!d[idx1].empty())
	{
		d[idx2].push_back(d[idx1].back());
		d[idx1].pop_back();
	}
	d.erase(getIterD(idx1));
}

int PmergeMe::getSizeD()
{
	int deqSize = 0;
	int elementSize = d[0].size();

	for (int i = 0; i < static_cast<int>(d.size()); i++)
		if (static_cast<int>(d[i].size()) == elementSize)
			deqSize++;

	return (deqSize);
}

int PmergeMe::binarySearchD(int val, int left, int right)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (d[mid][0] <= val)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (left);
}

void PmergeMe::insertD(int idx, int insertIdx)
{
	std::deque<int> dInsert;
	for (int i = d[idx].size() / 2; i > 0; i--)
	{
		dInsert.push_back(d[idx].back());
		d[idx].pop_back();
	}
	d.insert(getIterD(insertIdx), dInsert);
}

// void PmergeMe::printDeq()
// {
// 	for (int i = 0; i < static_cast<int>(d.size()); i++)
// 	{
// 		std::cout << "d[" << i << "]\n";
// 		for (int j = 0; j < static_cast<int>(d[i].size()); j++)
// 			std::cout << d[i][j] << " ";
// 		std::cout << std::endl;
// 	}
// }

void PmergeMe::lastSortD(int idx)
{
	int insertIdx = binarySearchD(d[idx].front(), 0, idx - 1);
	d.insert(getIterD(insertIdx), d[idx]);
	d.erase(getIterD(idx + 1));
}

void PmergeMe::sortD()
{
	int deqSize = getSizeD();

	if (deqSize == 1) return ;

	int i = 0;
	while (i < deqSize / 2)
	{
		if (d[i][0] < d[i + 1][0])
			mergeElementD(i, i + 1);
		else
			mergeElementD(i + 1, i);
		i++;
	}
	sortD();

	int maxIdx = deqSize / 2 - 1;
	int AddNum = 0;
	int k = 1;
	int nextJN, preJN;
	int size = d[0].size();
	do
	{
		preJN = getJacobsthalNumber(k - 1);
		nextJN = std::min(getJacobsthalNumber(k), maxIdx);
		int gap = nextJN - preJN;
		int idx = nextJN + AddNum;
		for (int i = 0; i < gap; i++)
		{
			if (static_cast<int>(d[idx].size()) != size)
			{
				i--;
				idx--;
			}
			else
			{
				int insertIdx = binarySearchD(d[idx].back(), 0, idx - 1);
				insertD(idx, insertIdx);
				AddNum++;
			}
		}
		k++;
	} while (nextJN != maxIdx);
	if (deqSize & 1)
		lastSortD(deqSize - 1);
	// printDeq();
}

std::deque<int> PmergeMe::getResultD()
{
	std::deque<int> retDeq;
	for (int i = 0; i < static_cast<int>(d.size()); i++)
		retDeq.push_back(d[i][0]);
	return (retDeq);
}
