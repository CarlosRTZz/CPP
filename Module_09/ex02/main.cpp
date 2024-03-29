#include "PmergeMe.hpp"

template <typename Container>
void printVec(const Container vec)
{
    for (std::size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << ' ';
        if (i >= 3)
        {
            std::cout << "[...]";
            return ;
        }
    }
}

template <typename Container>
void merge(Container &cont, int l, int m, int r)
{
    Container Left;
    Container Middle;

    size_t n1 = m - l + 1;
    size_t n2 = r - m;

    for (size_t i = 0; i < n1; i++)
        Left.push_back(cont[l + i]);
    for (size_t j = 0; j < n2; j++)
        Middle.push_back(cont[j + m + 1]);

    size_t i = 0;
    size_t j = 0;
    size_t k = l;

    while (i < n1 && j < n2)
    {
        if (Left[i] <= Middle[j])
        {
            cont[k] = Left[i];
            i++;
        }
        else
        {
            cont[k] = Middle[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        cont[k] = Left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        cont[k] = Middle[j];
        j++;
        k++;
    }
}

template <typename Container>
void insertSort(Container &cont, int l, int r)
{
    for (int i = l; i < r; i++)
    {
        int tmp = cont[i + 1];
        int j = i + 1;
        while (j > l && cont[j - 1] > tmp)
        {
            cont[j] = cont[j - 1];
            j--;
        }
        cont[j] = tmp;
    }
}

template <typename Container>
void mergeSort(Container &cont, int l, int r)
{
    if (r - l > 4)
    {
        int m = (l + r) / 2;
        mergeSort(cont, l, m);
        mergeSort(cont, m + 1, r);
        merge(cont, l, m, r);
    }
    else
    {
        insertSort(cont, l, r);
    }
}

int isDigits(const char *str)
{
    for (int i = 0; str[i]; i++)
    {
        if (!(str[i] >= 48 && str[i] <= 57 && str[i] != '-' && str[i] != '+'))
            return (1);
    }
    return (0);
}

template <typename Container>
Container createContainer(char **input)
{
    int i = 1;
    Container create;
    while (input[i])
    {
        create.push_back(std::atoi(input[i]));
        if (isDigits(input[i]))
        {
            std::cout << "Error" << std::endl;
            exit(1);
        }
        i++;
    }
    return (create);
}

int main(int ac, char** av) {
	if (ac < 2)
    {
        std::cout << "./PmergeMe [int list to sort]\n";
        return (1);
    }
	try {
		PmergeMe check;
		check.checkInput(ac, av);
	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
		return (1);
	}

	std::vector<int> vec;
    std::deque<int> deq;
    int n = ac - 1;

    clock_t start_t, end_t, start_t1, end_t1;

    std::vector<int> baseVec = createContainer<std::vector<int> >(av);
    std::cout << "before: ";
    printVec(baseVec);
    std::cout << "\n";

    start_t = clock();
    vec = createContainer<std::vector<int> >(av);
    mergeSort(vec, 0, vec.size() - 1);
    end_t = clock();
    double t1 = static_cast<double>(end_t - start_t) / CLOCKS_PER_SEC * 1000;

    start_t1 = clock();
    deq = createContainer<std::deque<int> >(av);
    mergeSort(deq, 0, deq.size() - 1);
    end_t1 = clock();
    double t2 = static_cast<double>(end_t1 - start_t1) / CLOCKS_PER_SEC * 1000;

    std::cout << "after: ";
    printVec(deq);
    std::cout << "\n";

    std::cout << "Time to process a range of  " << n << " elements with std::vector :  " << t1 << " ms"<< std::endl;
    std::cout << "Time to process a range of  " << n << " elements with std::deque  :  " << t2 << " ms"<< std::endl;
	return (0);
}