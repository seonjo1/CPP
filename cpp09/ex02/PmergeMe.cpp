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
		l.push_back(std::list<int>(1, num));
	}
}

PmergeMe::PmergeMe(const PmergeMe& copy)
	: v(copy.v), l(copy.l) {};

PmergeMe::~PmergeMe() {};

PmergeMe& PmergeMe::operator=(const PmergeMe& copy)
{
	if (this != &copy)
	{
		v = copy.v;
		l = copy.l;
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


// list 버전

std::list<std::list<int> >::iterator PmergeMe::getIterL(int idx)
{
	std::list<std::list<int> >::iterator iter = l.begin();
	for (int i = 0; i < idx; i++)
		++iter;
	return (iter);
}

std::list<int>::iterator PmergeMe::getIterLL(int idx1, int idx2)
{
	std::list<int>::iterator iter = (*getIterL(idx1)).begin();
	for (int i = 0; i < idx2; i++)
		++iter;
	return (iter);
}

void PmergeMe::mergeElementL(int idx1, int idx2)
{
	while (!(*getIterL(idx1)).empty())
	{
		(*getIterL(idx2)).push_back((*getIterL(idx1)).back());
		(*getIterL(idx1)).pop_back();
	}
	l.erase(getIterL(idx1));
}

int PmergeMe::getSizeL()
{
	int lstSize = 0;
	int elementSize = (*getIterL(0)).size();

	for (int i = 0; i < static_cast<int>(l.size()); i++)
		if (static_cast<int>((*getIterL(i)).size()) == elementSize)
			lstSize++;
	return (lstSize);
}

int PmergeMe::binarySearchL(int val, int left, int right)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if ((*getIterLL(mid, 0)) <= val)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (left);
}

void PmergeMe::insertL(int idx, int insertIdx)
{
	std::list<int> lInsert;
	for (int i = (*getIterL(idx)).size() / 2; i > 0; i--)
	{
		lInsert.push_back((*getIterL(idx)).back());
		(*getIterL(idx)).pop_back();
	}
	l.insert(getIterL(insertIdx), lInsert);
}

// void PmergeMe::printLst()
// {
// 	for (int i = 0; i < static_cast<int>(l.size()); i++)
// 	{
// 		std::cout << "l[" << i << "]\n";
// 		for (int j = 0; j < static_cast<int>((*getIterL(i)).size()); j++)
// 			std::cout << (*getIterLL(i, j)) << " ";
// 		std::cout << std::endl;
// 	}
// }

void PmergeMe::lastSortL(int idx)
{
	int insertIdx = binarySearchL((*getIterL(idx)).front(), 0, idx - 1);
	l.insert(getIterL(insertIdx), (*getIterL(idx)));
	l.erase(getIterL(idx + 1));
}

void PmergeMe::sortL()
{
	int lstSize = getSizeL();

	if (lstSize == 1) return ;

	int i = 0;
	while (i < lstSize / 2)
	{
		if ((*getIterLL(i, 0)) < (*getIterLL(i + 1, 0)))
			mergeElementL(i, i + 1);
		else
			mergeElementL(i + 1, i);
		i++;
	}
	sortL();

	int maxIdx = lstSize / 2 - 1;
	int AddNum = 0;
	int k = 1;
	int nextJN, preJN;
	int size = (*getIterL(0)).size();
	do
	{
		preJN = getJacobsthalNumber(k - 1);
		nextJN = std::min(getJacobsthalNumber(k), maxIdx);
		int gap = nextJN - preJN;
		int idx = nextJN + AddNum;
		for (int i = 0; i < gap; i++)
		{
			if (static_cast<int>((*getIterL(idx)).size()) != size)
			{
				i--;
				idx--;
			}
			else
			{
				int insertIdx = binarySearchL((*getIterL(idx)).back(), 0, idx - 1);
				insertL(idx, insertIdx);
				AddNum++;
			}
		}
		k++;
	} while (nextJN != maxIdx);
	if (lstSize & 1)
		lastSortL(lstSize - 1);
	// printLst();
}

std::list<int> PmergeMe::getResultL()
{
	std::list<int> retLst;
	for (int i = 0; i < static_cast<int>(l.size()); i++)
		retLst.push_back((*getIterLL(i, 0)));
	return (retLst);
}
