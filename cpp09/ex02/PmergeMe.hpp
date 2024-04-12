#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <vector>
# include <string>
# include <sstream>
# include <cmath>
# include <algorithm>
# include <iostream>

class PmergeMe
{
private:
	std::vector<std::vector<int> > v;
	std::list<std::list<int> > l;


	int getJacobsthalNumber(int k);
	void mergeElementV(int idx1, int idx2);
	int getSizeV();
	int binarySearchV(int val, int left, int right);
	void insertV(int idx, int insertIdx);
	void lastSortV(int idx);
	// void printVec();

	void mergeElementL(int idx1, int idx2);
	int getSizeL();
	int binarySearchL(int val, int left, int right);
	void insertL(int idx, int insertIdx);
	void lastSortL(int idx);
	// void printLst();
	std::list<std::list<int> >::iterator getIterL(int idx);
	std::list<int>::iterator getIterLL(int idx1, int idx2);

public:
	PmergeMe();
	PmergeMe(int argc, char **argv);
	PmergeMe(const PmergeMe& copy);
	~PmergeMe();
	PmergeMe& operator=(const PmergeMe& copy);

	void sortV();
	void sortL();
	std::vector<int> getResultV();
	std::list<int> getResultL();
	int getElementSize();
};

#endif
