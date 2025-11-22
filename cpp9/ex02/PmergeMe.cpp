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
    if (_deque.size() <= 1 || _vector.size() <= 1)
        throw std::runtime_error("Error: too few elements to sort");
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
int PmergeMe::binarySearchLimited(const std::vector<int> &chain, int value, int limitIndex)
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
void PmergeMe::fordJohnsonVector(std::vector<int> &arr)
{

	std::vector<int> big;
	std::vector<int> small;
	std::pair<int, int> pairs;
	int odd = -1;
	size_t arrSize = arr.size();

	//make pairs (smaller=first bigger=second)
	for (size_t i = 0; i + 1 < arrSize; i += 2)
	{
		int a = arr[i];
		int b = arr[i + 1];

		if (a > b)
			std::swap(a, b);
		pairs.first = a;
		pairs.second = b;
	}
	if (arrSize % 2 == 1)
		odd = arr[arrSize - 1];
	
	//sort biggest pair
	for (size_t i = 0; i < arrSize / 2; i++)
	{
		for (size_t j = i+1; j < arrSize / 2; j++)
		{

		}
	}

}

void	printPairs(std::vector< std::pair<int,int> > pairs)
{
	for (size_t i = 0; i < pairs.size(); i++)
		std::cout << "first: " << pairs[i].first << " sec: " << pairs[i].second << std::endl;
	std::cout << "-----" << std::endl;
}

int	getPair(int num, std::vector< std::pair<int,int> > pairs)
{
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (num == pairs[i].second)
			return pairs[i].first;
	}
	return -1;
}

int	getInsertPos(int toInsert, int limitIndex, std::vector<int> &tabToSearch)
{
	int left = 0;
	int right = 0;

	while (tabToSearch[right] != limitIndex)
	{
		right++;
	}
	

	while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (tabToSearch[mid] < toInsert)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

std::vector<size_t> generateJacobsthal(size_t maxSize)
{
    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    
    size_t j = 1;
    while (j < maxSize)
    {
        j = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(j);
    }
    
    return jacobsthal;
}

std::vector<size_t> createInsertionSequence(size_t pairCount)
{
    std::vector<size_t> jacobsthal = generateJacobsthal(pairCount);
    std::vector<size_t> sequence;
    
    size_t lastIndex = 0;
    
    for (size_t i = 2; i < jacobsthal.size() && jacobsthal[i] <= pairCount; i++)
    {
        size_t currentJacob = jacobsthal[i];
        
        // Insérer les indices en ordre décroissant entre lastIndex et currentJacob
        for (size_t j = currentJacob; j > lastIndex; j--)
        {
            sequence.push_back(j - 1);  // -1 car les indices commencent à 0
        }
        
        lastIndex = currentJacob;
    }
    
    // Ajouter les indices restants s'il y en a
    for (size_t j = lastIndex; j < pairCount; j++)
    {
        sequence.push_back(j);
    }
    
    return sequence;
}


void reducePairs(const std::vector<int> &input, std::vector<int> &result) 
{
	// final pair: swap sort
	if (input.size() == 2) {
		result = input;
		if (result[0] > result[1])
			std::swap(result[0], result[1]);
		// std::cout << result[0] << " " << result[1] << std::endl;
		return;
	}

	// Create adjacent pairs
	std::vector< std::pair<int,int> > pairs;
	std::vector<int> big;

	for (size_t i = 0; i + 1 < input.size(); i += 2) 
	{
		int a = input[i];
		int b = input[i + 1];
		if (a > b)
			std::swap(a, b);

		std::pair<int, int> p(a, b);
		pairs.push_back(p);

		big.push_back(b);
	}

	// If odd number, set pair to -1 and put it in big
	if (input.size() % 2 != 0) 
	{
		std::pair<int, int> p(-1, input.back());
		pairs.push_back(p);
		big.push_back(input.back());
	}

	// Recurse on the "big" list
	reducePairs(big, result);
	// printPairs(pairs);
	// std::cout <<std::endl << "--BEFORE--" << std::endl;
	// for (size_t i = 0; i < result.size(); i++)
	// 	std::cout << result[i] << " ";

	//INSERT BACK THE REMAINING NUMBERS
	std::vector<size_t> insertSeq = createInsertionSequence(pairs.size());
	std::vector<int> newRes = result;

	// std::cout << "------" << std::endl;
	// for (size_t i = 0; i < insertSeq.size(); i++)
	// 	std::cout << insertSeq[i] << " " << std::endl;
	std::cout << "------" << std::endl;
	for (size_t i = 0; i < insertSeq.size(); i++)
	{
		size_t bigIndex = insertSeq[i];

		int smallPair = getPair(result[bigIndex], pairs);
		if (smallPair != -1)
		{											//resulr[bigIndex]
			int insertIndex = getInsertPos(smallPair, result[bigIndex], newRes);
			std::cout << "added: " << smallPair << std::endl;
			std::cout << "num: " << result[bigIndex] << " pair: " << smallPair << std::endl;
			newRes.insert(newRes.begin() + insertIndex, smallPair);
			// i++;
		}
			
		// std::cout << "num: " << newRes[bigIndex] << " pair: " << smallPair << std::endl;
	}
	result = newRes;
	
	// std::vector<size_t> sequence = createInsertionSequence(30);
	// std::cout << "------" << std::endl;
	// for (size_t i = 0; i < sequence.size(); i++)
	// 	std::cout << sequence[i] + 1 << " " << std::endl;
}



// for (size_t i = 0; i < result.size(); i++)
// 	{

// 		int smallPair = getPair(result[i], pairs);
// 		if (smallPair != -1)
// 		{
// 			int insertIndex = getInsertPos(smallPair, i, result);
// 			std::cout << "added: " << smallPair << std::endl;
// 			newRes.insert(result.begin() + insertIndex, smallPair);
// 			i++;
// 		}
			
// 		std::cout << "num: " << result[i] << " pair: " << smallPair << std::endl;
// 	}