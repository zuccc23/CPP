#include "PmergeMe.hpp"

//CONSTRUCTOR(S)
PmergeMe::PmergeMe() {
	std::cout << "\033[90m✿PmergeMe constructor called✿\033[0m" << std::endl;
}

//COPY CONSTRUCTOR
PmergeMe::PmergeMe(const PmergeMe& to_copy) : _vector(to_copy._vector), _deque(to_copy._deque) {
	std::cout << "\033[90m✿PmergeMe copy constructor called✿\033[0m" << std::endl;
}

//COPY ASSIGNMENT
PmergeMe& PmergeMe::operator=(const PmergeMe& to_copy) {
	std::cout << "\033[90m✿PmergeMe copy assignment operator called✿\033[0m" << std::endl;
	if (this != &to_copy)
	{
		_vector = to_copy._vector;
		_deque = to_copy._deque;
	}
	return (*this);
}

//DESTRUCTOR
PmergeMe::~PmergeMe() {
	std::cout << "\033[90m~PmergeMe destructor called\033[0m" << std::endl;
}

//PUBLIC
void	PmergeMe::sort(int ac, char** av)
{
	parseInput(ac, av);
	// std::cout << "test" << std::endl;
}

//PRIVATE
void	PmergeMe::parseInput(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		std::string input = av[i];
		if (isInt(input) == false)
			throw std::runtime_error("Error: only positive integers are accepted");
		
		int number = atoi(input.c_str());
		_deque.push_back(number);
		_vector.push_back(number);
	}
}

bool	PmergeMe::isInt(std::string const &input)
{
	if (input.empty())
		return false;
	if (input.size() > 10)
		return false;

	for (int i = 0; (size_t)i < input.size(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(input[i])))
			return false;
	}
	long check = atol(input.c_str());
	if (check > 2147483647)
		return false;
	if (check < 0)
		return (false);
	return true;
}



// -----------------------------------------------------------------------------
// Binary search insertion BEFORE a certain limit index
// (search only inside chain[0 .. limitIndex-1])
// -----------------------------------------------------------------------------
int binarySearchLimited(const std::vector<int> &chain, int value, int limitIndex)
{
    int left = 0;
    int right = limitIndex; // we search BEFORE limitIndex

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (value <= chain[mid])
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

// -----------------------------------------------------------------------------
// Ford–Johnson (Merge-Insertion) Sort
// -----------------------------------------------------------------------------
void fordJohnsonSort(std::vector<int> &arr)
{
    int n = arr.size();
    if (n <= 1)
        return;

    // -------------------------------------------------------------------------
    // 1. Pair elements ↔ create big[] and small[]
    // -------------------------------------------------------------------------
    std::vector<int> big;
    std::vector<int> small;
    std::vector<int> smallForBig(n, -1); // maps big index → its small (or -1)

    for (int i = 0; i + 1 < n; i += 2)
    {
        int a = arr[i];
        int b = arr[i + 1];

        if (a < b)
        {
            small.push_back(a);
            smallForBig[big.size()] = a; // small paired with this big index
            big.push_back(b);
        }
        else
        {
            small.push_back(b);
            smallForBig[big.size()] = b;
            big.push_back(a);
        }
    }

    // If odd number of elements → last one is a "big"
    if (n % 2 == 1)
    {
        big.push_back(arr[n - 1]);
        // no small for this big index
        smallForBig[big.size() - 1] = -1;
    }

    // -------------------------------------------------------------------------
    // 2. Sort the big numbers → this is the main chain
    // -------------------------------------------------------------------------
    std::sort(big.begin(), big.end());

    // -------------------------------------------------------------------------
    // 3. Build mapping: for each sorted big, which small belongs to it?
    //    We need to know which small corresponds to the big *in sorted order*.
    // -------------------------------------------------------------------------
    std::vector<int> sortedSmallForBig(big.size(), -1);

    // First, create unsorted pairing:
    // bigOriginal[i] = big[i] before sorting
    std::vector<int> bigOriginal = big;
    std::sort(bigOriginal.begin(), bigOriginal.end());

    // But we lost the original order — so reconstruct:
    // We will rebuild a list of (bigValue → smallValue) using the original arr pairs.
    // To do that, redo the pairing logic but store in a temporary vector.

    // Build vector of pairs (big, small)
    std::vector<std::pair<int, int> > pairList;
    for (int i = 0; i + 1 < n; i += 2)
    {
        int a = arr[i];
        int b = arr[i + 1];
        if (a < b)
            pairList.push_back(std::make_pair(b, a));
        else
            pairList.push_back(std::make_pair(a, b));
    }
    // If odd → last big alone
    if (n % 2 == 1)
        pairList.push_back(std::make_pair(arr[n - 1], -1)); // no small

    // Now pairList[i] = {bigValue, smallValue or -1}

    // For each sorted big, find its small partner
    for (size_t i = 0; i < big.size(); ++i)
    {
        int bigValue = big[i];

        for (size_t j = 0; j < pairList.size(); ++j)
        {
            if (pairList[j].first == bigValue)
            {
                sortedSmallForBig[i] = pairList[j].second; // may be -1
                pairList[j].first = -999999; // mark as used
                break;
            }
        }
    }

    // -------------------------------------------------------------------------
    // 4. Insert smalls in the optimized FJ order (index 1 → 2 → 3 ... )
    // -------------------------------------------------------------------------

    // For big indices i = 1,2,3,… insert their smalls
    for (size_t i = 1; i < big.size(); ++i)
    {
        int s = sortedSmallForBig[i];
        if (s == -1)
            continue; // no small for this big

        // We know s must be inserted BEFORE chain[i]
        int pos = binarySearchLimited(big, s, i);
        big.insert(big.begin() + pos, s);
    }

    // Replace original arr with the sorted chain
    arr = big;
}



