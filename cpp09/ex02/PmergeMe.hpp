#ifndef PMERGEME_HHP
#define PMERGEME_HHP

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <deque>


extern bool is_odd;
extern int comp;


class Compare {
public:
    int& comparison_count;  // Reference to the external counter

    Compare(int& count);
    bool operator()(int lhs, int rhs);
};

// struct Compare
// {
//     int& comparison_count;  // Reference to the external counter

//     Compare(int& count) : comparison_count(count)
// 	{

// 	}
//     bool operator()(int lhs, int rhs)
// 	{
//         ++comparison_count;  // Increment the comparison counter
//         return lhs < rhs;
//     }
// };

void printVector(const std::vector<int>& vec);
void printVector_B(const std::vector<int>& vec);
void printDeque(const std::deque<int>& deq);

/////////////////////////////////////////////////////////////////////////
template <typename Container>
Container Insert_elements(int ac, char **av)
{
    Container elements;
    for (int i = 1; i < ac; i++)
    {
        if (i > 10000)
        {
            std::cerr << "Error: more than 10000 numbers encountered." << std::endl;
            elements.clear();
            return elements;
        }
        std::stringstream ss((std::string(av[i])));
        std::cout << "ss: " << ss << std::endl;
        int value;
        if (ss >> value && value >= 0)
        {
            elements.push_back(value);
        }
        else
        {
            std::cerr << "Error: non-valid value encountered: " << av[i] << std::endl;
            elements.clear();
            return elements;
        }
    }
    return elements;
}


template <typename Container>
void divideAndCompare(const Container& input, Container& smallElements, Container& largeElements)
{
    for (size_t i = 0; i < input.size(); i += 2)
    {
        if (i + 1 < input.size())
        {
            if (input[i] < input[i + 1])
            {
                smallElements.push_back(input[i]);
                largeElements.push_back(input[i + 1]);
                comp++;
            }
            else
            {
                smallElements.push_back(input[i + 1]);
                largeElements.push_back(input[i]);
               comp++;
            }
        }
        else
        {
            smallElements.push_back(input[i]);
            is_odd = true;
        }
    }
}


template <typename Container>
void merge(Container& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Container leftArr(n1);
    Container rightArr(n2);

    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        rightArr[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            ++i;
            comp++;
        }
        else
        {
            arr[k] = rightArr[j];
            ++j;
            comp++;
        }
        ++k;
    }
    while (i < n1)
    {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }
    while (j < n2)
    {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

template <typename Container>
void mergeSort(Container& arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

template <typename Container>
Container getSortedMainChain(const Container& main_chain)
{
    Container sorted_chain = main_chain;
    mergeSort(sorted_chain, 0, sorted_chain.size() - 1);
    return sorted_chain;
}

template <typename Container>
int find_pending_element(Container& pending_chain, Container& main_chain, int value_sorted_main_chain)
{
    int position = 0;
    for (typename Container::iterator it = main_chain.begin(); it != main_chain.end(); ++it)
    {
        if (*it == value_sorted_main_chain)
        {
            break;
        }
        position++;
    }
    return pending_chain[position];
}

template <typename Container>
int find_index(Container& new_vec, int sorted_main_chain)
{
    int index = 0;
    for (typename Container::iterator it = new_vec.begin(); it != new_vec.end(); ++it)
    {
        if (*it == sorted_main_chain)
        {
            break;
        }
        index++;
    }
    return index;
}

template <typename Container>
void binary_insert(Container& new_vec, int pending_num, int sorted_main_chain)
{
    Compare compr(comp);
    typename Container::iterator itend = new_vec.begin() + find_index(new_vec, sorted_main_chain);
    typename Container::iterator pos = std::lower_bound(new_vec.begin(), itend, pending_num, compr);
    new_vec.insert(pos, pending_num);
}



// Template function to generate Jacobsthal sequence
template <typename Container>
Container generate_jacobsthal_sequence(int limit)
{
    Container jacobsthal;

    if (limit == 2)
    {
        jacobsthal.push_back(1);
        jacobsthal.push_back(2);
        return jacobsthal;
    }
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);
    int n = 2;
    while (true)
    {
        int next_value = jacobsthal[n - 1] + 2 * jacobsthal[n - 2];
        if (next_value > limit)
            break;
        jacobsthal.push_back(next_value);
        n++;
    }
    return jacobsthal;
}

// Template function to reorder Jacobsthal sequence
template <typename Container>
Container reorder_jacobsthal_sequence(const Container& jacobsthal, int limit)
{
    Container reordered;
    int size = jacobsthal.size() - 1;
    reordered.push_back(jacobsthal[0]);
    int i = 0;
    while (i < size)
    {
        i++;
        reordered.push_back(jacobsthal[i]);
        int decerment = jacobsthal[i] - jacobsthal[i - 1] - 1;
        while (decerment > 0)
        {
            int put_num = jacobsthal[i - 1] + decerment;
            reordered.push_back(put_num);
            decerment--;
        }
    }
    if (limit > jacobsthal.back())
    {
        int decerment = limit - jacobsthal.back();
        int put_num = 0;
        while (decerment > 0 && put_num <= jacobsthal.back())
        {
            int put_num = jacobsthal.back() + decerment;
            reordered.push_back(put_num);
            decerment--;
        }
    }
    reordered.erase(reordered.begin());
    return reordered;
}

// Template function to sort container
template <typename Container>
Container sort_container(Container& pinding_chain, Container& main_chain, Container& sorted_main_chain)
{
    int size = sorted_main_chain.size();
    Container jacobsthal = generate_jacobsthal_sequence<Container>(size);
    Container reordered_jacobsthal = reorder_jacobsthal_sequence(jacobsthal, size);
    Container sroted_main_chain_copy = sorted_main_chain;
    sroted_main_chain_copy.insert(sroted_main_chain_copy.begin(), find_pending_element(pinding_chain, main_chain, sorted_main_chain[0]));
    size -= 1;
    size_t j = 0;
    
    while (j < reordered_jacobsthal.size() && size > 0)
    {
        int i = reordered_jacobsthal[j] - 1;
        int pending_num = find_pending_element(pinding_chain, main_chain, sorted_main_chain[i]);
        // std::cout << "pending_num :" << pending_num << std::endl;
        binary_insert(sroted_main_chain_copy, pending_num, sorted_main_chain[i]);
        j++;
    }
    if (is_odd == true)
    {
       //binary_insert(sroted_main_chain_copy, pinding_chain.back() , sroted_main_chain_copy.back());
       if (sroted_main_chain_copy.back() > pinding_chain.back())
       {
           binary_insert(sroted_main_chain_copy, pinding_chain.back(), sroted_main_chain_copy.back());
       }
       else
       {
           sroted_main_chain_copy.push_back(pinding_chain.back());
           comp++;
       }
    }
    if (sroted_main_chain_copy.size() >= 10)
      comp -= 1;
    return sroted_main_chain_copy;
}

#endif // PMERGEME_HPP

