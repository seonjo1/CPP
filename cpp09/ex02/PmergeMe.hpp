#ifndef PMERGEME_HPP
# define PMERGEME_HPP

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

	int getJacobsthalNumber(int k);
	void mergeElement(int idx1, int idx2);
	int getSize();
	int binarySearch(int val, int left, int right);
	void insert(int idx, int insertIdx);
	void removeZero();
	void printVec();
	void lastSort(int idx);

public:
	PmergeMe();
	PmergeMe(int argc, char **argv);
	PmergeMe(const PmergeMe& copy);
	~PmergeMe();
	PmergeMe& operator=(const PmergeMe& copy);
	void sort();
	std::vector<int> getResult();
};

#endif
