#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
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
	std::deque<std::deque<int> > d;


	int getJacobsthalNumber(int k);
	void mergeElementV(int idx1, int idx2);
	int getSizeV();
	int binarySearchV(int val, int left, int right);
	void insertV(int idx, int insertIdx);
	void lastSortV(int idx);
	// void printVec();

	void mergeElementD(int idx1, int idx2);
	int getSizeD();
	int binarySearchD(int val, int left, int right);
	void insertD(int idx, int insertIdx);
	void lastSortD(int idx);
	std::deque<std::deque<int> >::iterator getIterD(int i);
	// void printDeq();

public:
	PmergeMe();
	PmergeMe(int argc, char **argv);
	PmergeMe(const PmergeMe& copy);
	~PmergeMe();
	PmergeMe& operator=(const PmergeMe& copy);

	void sortV();
	void sortD();
	std::vector<int> getResultV();
	std::deque<int> getResultD();
	int getElementSize();
};


#endif
