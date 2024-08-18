#include "PmergeMe.hpp"
int comp = 0;
bool is_odd = false;


Compare::Compare(int& count) : comparison_count(count)
{
}

bool Compare::operator()(int lhs, int rhs)
{
    ++comparison_count;  // Increment the comparison counter
    return lhs < rhs;
}

void printPending(std::vector<int>& pending_chain, std::vector<int>& main_chain, std::vector<int>& sorted_main_chain)
{
    for (size_t i = 0; i < pending_chain.size(); i++)
    {
        int value = sorted_main_chain[i];
        int index = find_pending_element(pending_chain, main_chain, value);
        std::cout << "(" << value << ", " << index << ") ";
    }
    std::endl(std::cout);
}

void printVector_B(const std::vector<int>& vec)
{
    for (size_t i = 0; i < vec.size(); i += 2)
    {
        if (i + 1 < vec.size())
        {
            std::cout << "(" << vec[i] << ", " << vec[i + 1] << ") ";
        }
        else
        {
            std::cout << "(" << vec[i] << ", " << "null" << ") "; // Handle the case where the vector has an odd number of elements
        }
    }
    std::cout << std::endl;
}

void printVector(const std::vector<int>& vec)
{
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
	{
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void printDeque(const std::deque<int>& deq)
{
    for (std::deque<int>::const_iterator it = deq.begin(); it != deq.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
















































// std::vector<int> Insert_elements(int ac, char **av)
// {
//     std::vector<int> elements;
//     for (int i = 1; i < ac; i++)
//     {
//         std::stringstream ss((std::string(av[i])));
//         int value;
//         if (ss >> value && value >= 0)
//         {
//             elements.push_back(value);
//         }
//         else
//         {
//             std::cerr << "Error: non-valid value encountered: " << av[i] << std::endl;
//             elements.clear();
//             return elements;
//         }
//     }
//     return elements;
// }

// void divideAndCompare(const std::vector<int>& input, std::vector<int>& smallElements, std::vector<int>& largeElements)
// {
//     for (size_t i = 0; i < input.size(); i += 2)
//     {
//         if (i + 1 < input.size())
//         {
//             if (input[i] < input[i + 1])
//             {
//                 smallElements.push_back(input[i]);
//                 largeElements.push_back(input[i + 1]);
//                 comp++;
//             }
//             else
//             {
//                 smallElements.push_back(input[i + 1]);
//                 largeElements.push_back(input[i]);
//                 comp++;
//             }
//         }
//         else
//         {
//             smallElements.push_back(input[i]);
//             is_odd = true;
//         }
//     }
// }

// void merge(std::vector<int>& arr, int left, int mid, int right)
// {
//     int n1 = mid - left + 1;
//     int n2 = right - mid;
//     std::vector<int> leftArr(n1);
//     std::vector<int> rightArr(n2);

//     for (int i = 0; i < n1; ++i)
//         leftArr[i] = arr[left + i];
//     for (int i = 0; i < n2; ++i)
//         rightArr[i] = arr[mid + 1 + i];
//     int i = 0, j = 0, k = left;
//     while (i < n1 && j < n2)
//     {
//         if (leftArr[i] <= rightArr[j])
//         {
//             arr[k] = leftArr[i];
//             //comp++;
//             ++i;
//         }
//         else
//         {
//             arr[k] = rightArr[j];
//            // comp++;
//             ++j;
//         }
//         ++k;
//     }
//     while (i < n1)
//     {
//         arr[k] = leftArr[i];
//         ++i;
//         ++k;
//     }
//     while (j < n2)
//     {
//         arr[k] = rightArr[j];
//         ++j;
//         ++k;
//     }
// }

// // Merge sort function
// void mergeSort(std::vector<int>& arr, int left, int right)
// {
//     if (left < right)
//     {
//         int mid = left + (right - left) / 2;
//         mergeSort(arr, left, mid);
//         mergeSort(arr, mid + 1, right);
//         merge(arr, left, mid, right);
//     }
// }
// // Function to get sorted main chain using merge sort
// std::vector<int> getSortedMainChain(const std::vector<int>& main_chain)
// {
//     std::vector<int> sorted_chain = main_chain;
//     mergeSort(sorted_chain, 0, sorted_chain.size() - 1);
//     return sorted_chain;
// }

// int find_pending_elment(std::vector<int>& pending_chain, std::vector<int>& main_chain, int value_sorted_main_chain)
// {
//     int postion = 0;
//     for (std::vector<int>::iterator it = main_chain.begin(); it != main_chain.end(); ++it)
//     {
//         if (*it == value_sorted_main_chain)
//         {
//             break;
//         }
//         postion++;
//     }
//     return pending_chain[postion];
// }

// std::vector<int> generate_jacobsthal_sequence(int limit)
// {
//     std::vector<int> jacobsthal;

//     if (limit == 2)
//     {
//         jacobsthal.push_back(1);
//         jacobsthal.push_back(2);
//         return jacobsthal;
//     }
//     jacobsthal.push_back(1);
//     jacobsthal.push_back(3);
//     int n = 2;
//     while (true)
//     {
//         int next_value = jacobsthal[n - 1] + 2 * jacobsthal[n - 2];
//         if (next_value > limit)
//             break;
//         jacobsthal.push_back(next_value);
//         n++;
//     }
//     return jacobsthal;
// }

// std::vector<int> reorder_jacobsthal_sequence(const std::vector<int>& jacobsthal, int limit)
// {
//     std::vector<int> reordered;
//     int size = jacobsthal.size() - 1;
//     reordered.push_back(jacobsthal[0]);
//     int i = 0;
//     while (i < size)
//     {
//         i++;
//         reordered.push_back(jacobsthal[i]);
//         int decerment = jacobsthal[i] - jacobsthal[i - 1] - 1;
//         while (decerment > 0)
//         {
//             int put_num = jacobsthal[i - 1] + decerment;
//             reordered.push_back(put_num);
//             decerment--;
//         }
//     }
//     if (limit > jacobsthal.back())
//     {
//         int decerment = limit - jacobsthal.back();
//         int put_num = 0;
//         while (decerment > 0 && put_num <= jacobsthal.back())
//         {
//             int put_num = jacobsthal.back() + decerment;
//             reordered.push_back(put_num);
//             decerment--;
//         }
//     }
//     reordered.erase(reordered.begin());
//     return reordered;
// }


// int find_index(std::vector<int>& new_vec, int sorted_main_chain)
// {
//     int index = 0;
//     for (std::vector<int>::iterator it = new_vec.begin(); it != new_vec.end(); ++it)
//     {
//         if (*it == sorted_main_chain)
//         {
//             break;
//         }
//         index++;
//     }
//     return index;
// }

// void binary_insert(std::vector<int>& new_vec, int pending_num, int sorted_main_chain)
// {
//     int comp = 0;
//     Compare compr(comp);
//     std::vector<int>::iterator itend = new_vec.begin() + find_index(new_vec, sorted_main_chain) ;
//     std::vector<int>::iterator pos = std::lower_bound(new_vec.begin(), itend, pending_num, compr);
//     new_vec.insert(pos, pending_num);
// }

//23 354 5 353 234 57 5 234
// std::vector<int> sort_vector(std::vector<int>& pinding_chain, std::vector<int>& main_chain, std::vector<int>& sorted_main_chain)
// {
//     int size = sorted_main_chain.size();
//     //std::cout << "size  main_chain :" << size << std::endl;
//     std::vector<int> jacobsthal = generate_jacobsthal_sequence(size);
//     std::vector<int> reordered_jacobsthal = reorder_jacobsthal_sequence(jacobsthal, size);
//     std::vector<int> sroted_main_chain_copy = sorted_main_chain;
//     //printVector(sroted_main_chain_copy);
//     sroted_main_chain_copy.insert( sroted_main_chain_copy.begin(), find_pending_elment(pinding_chain, main_chain, sorted_main_chain[0]));
//     //printVector(sroted_main_chain_copy);
//     size -= 1;
//     //std::cout << "size  main_chain1 :" << size << std::endl;
//     size_t j = 0;
    
//     //printVector(reorder_jacobsthal_sequence(jacobsthal, size));
//     while (j < reordered_jacobsthal.size() && size > 0)
//     {
//         int i = reordered_jacobsthal[j] - 1;
//        // std::cout << "i : " << i << " and reordered_jacobsthal[j] :" << reordered_jacobsthal[j] << std::endl;
//         int pending_num = find_pending_elment(pinding_chain, main_chain, sorted_main_chain[i ]);
//         std::cout << "pending_num :" << pending_num << std::endl;
//        // std::cout << "sorted_main_chain[i] :" << sorted_main_chain[i] << std::endl;
//         binary_insert(sroted_main_chain_copy, pending_num, sorted_main_chain[i]);
//      //   std::cout << "-------------------------------------" << std::endl;
//         //printVector(sroted_main_chain_copy);
//        // std::cout << "-------------------------------------" << std::endl;
//         j++;
//     }
//     //if (is_odd == true)
//     //{
//     //    //binary_insert(sroted_main_chain_copy, pinding_chain.back() , sroted_main_chain_copy.back());
//     //    if (sroted_main_chain_copy.back() > pinding_chain.back())
//     //    {
//     //        binary_insert(sroted_main_chain_copy, pinding_chain.back(), sroted_main_chain_copy.back());
//     //    }
//     //    else
//     //    {
//     //        sroted_main_chain_copy.push_back(pinding_chain.back());
//     //        //comp++;
//     //    }
//     //}
//     //if (sroted_main_chain_copy.size() >= 10)
//     //   comp -= 1;
//    // std::cout << "comp : " << comp << std::endl;
//     return sroted_main_chain_copy;
// }
