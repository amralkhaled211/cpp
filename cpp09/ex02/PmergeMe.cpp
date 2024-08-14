#include "PmergeMe.hpp"

bool is_odd = false;

std::vector<int> Insert_elements(int ac, char **av)
{
    std::vector<int> elements;
    for (int i = 1; i < ac; i++)
    {
        std::stringstream ss(std::string(av[i]));
        int value;
        if (ss >> value && value >= 0)
        {
            // Check if the value is already in the elements vector
            bool is_unique = true;
            for (std::vector<int>::iterator it = elements.begin(); it != elements.end(); ++it)
            {
                if (*it == value)
                {
                    is_unique = false;
                    break;
                }
            }
            if (is_unique)
            {
                elements.push_back(value);
            }
            else
            {
                std::cerr << "Error: duplicate value encountered: " << value << std::endl;
                elements.clear();
                return elements;
            }
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

void divideAndCompare(const std::vector<int>& input, std::vector<int>& smallElements, std::vector<int>& largeElements)
{
    for (size_t i = 0; i < input.size(); i += 2)
    {
        if (i + 1 < input.size())
        {
            if (input[i] < input[i + 1])
            {
                smallElements.push_back(input[i]);
                largeElements.push_back(input[i + 1]);
            }
            else
            {
                smallElements.push_back(input[i + 1]);
                largeElements.push_back(input[i]);
            }
        }
        else
        {
            smallElements.push_back(input[i]);
            is_odd = true;
        }
    }
}


std::vector<int> getSortedMainChain(const std::vector<int>& main_chain)// i have to perform here the merge sort algrothim
{
    std::vector<int> sorted_chain = main_chain;
    std::sort(sorted_chain.begin(), sorted_chain.end());
    return sorted_chain;
}


int find_pending_elment(std::vector<int>& pending_chain, std::vector<int>& main_chain, int value_sorted_main_chain)
{
    int postion = 0;
    for (std::vector<int>::iterator it = main_chain.begin(); it != main_chain.end(); ++it)
    {
        if (*it == value_sorted_main_chain)
        {
            break;
        }
        postion++;
    }
    return pending_chain[postion];
}



std::vector<int> generate_jacobsthal_sequence(int limit)
{
    std::vector<int> jacobsthal;
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

// Function to reorder Jacobsthal sequence as per the specified pattern
// so if the sequence is like this (1 , 3 , 5 , 11)
// the reordered sequence will be like this (1 , 3 , 2 , 5 , 4 , 11 , 10 , 9 , 8 , 7 , 6)
std::vector<int> reorder_jacobsthal_sequence(const std::vector<int>& jacobsthal, int limit)
{
    std::vector<int> reordered;
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
    return reordered;
}

void binary_insert(std::vector<int>& new_vector, int pending_num)
{
    int begin = 0;
    int end = new_vector.size() - 1;// i change this for the invalid read
    int middle;
    while (begin <= end)
    {
        middle = begin + (end - begin) / 2;

        if (new_vector[middle] < pending_num)
           begin = middle + 1;
        else if ((new_vector[middle] > pending_num && new_vector[middle - 1] < pending_num)
            || (!new_vector[middle - 1] && new_vector[middle] > pending_num))
        {
            new_vector.insert(new_vector.begin() + middle , pending_num);
            break;
        }
        else if (new_vector[middle] > pending_num)
            end = middle - 1;
    }
    if (begin > end) // and i added this to fix the invalid read
    {
        new_vector.insert(new_vector.begin() + begin, pending_num);
    }
}

//23 354 5 353 234 57 5 234
std::vector<int> sort_vector1(std::vector<int>& pinding_chain, std::vector<int>& main_chain, std::vector<int>& sorted_main_chain)
{
    // generate the jacobsthal sequence
    int size = sorted_main_chain.size() - 1;
    std::vector<int> jacobsthal = generate_jacobsthal_sequence(size);
    std::vector<int> reordered_jacobsthal = reorder_jacobsthal_sequence(jacobsthal, size);
    //create a copy of the sorted main chain
    std::vector<int> sroted_main_chain_copy = sorted_main_chain;
    sroted_main_chain_copy.insert( sroted_main_chain_copy.begin(), find_pending_elment(pinding_chain, main_chain, sorted_main_chain[0]));

    size_t j = 0;
    while (j < reordered_jacobsthal.size())
    {
        int i = reordered_jacobsthal[j];
        std::cout << "i : " << i << " and reordered_jacobsthal[j] :" << reordered_jacobsthal[j] << std::endl;
        if (i > size)
            break;
        int pending_num = find_pending_elment(pinding_chain, main_chain, sorted_main_chain[i]);
        std::cout << "pending_num :" << pending_num << std::endl;
        if ((sorted_main_chain[i + 1] && pending_num < sorted_main_chain[i + 1]) || (!sorted_main_chain[i + 1]))
        {
            binary_insert(sroted_main_chain_copy, pending_num);
            //std::cout << "sorted_main_chain after inserting element :" ;
            //printVector(sroted_main_chain_copy);
        }
        j++;
    }
    if (is_odd == true)
    {
        if (sroted_main_chain_copy.back() > pinding_chain.back())
            binary_insert(sroted_main_chain_copy, pinding_chain.back());
        else
            sroted_main_chain_copy.push_back(pinding_chain.back());
    }
    return sroted_main_chain_copy;
}

























// std::vector<int> sort_vector(std::vector<int>& pinding_chain, std::vector<int>& main_chain, std::vector<int>& sorted_main_chain)
// {
//     std::vector<int> new_vector;
//     int  i = 0;
//     new_vector.push_back(find_pending_elment(pinding_chain, main_chain, sorted_main_chain[i]));
//     new_vector.push_back(sorted_main_chain[i]);
//     //std::cout << "new_vector[0] :" << new_vector[0] << std::endl;
//     //std::cout << "new_vector[1] :" << new_vector[1] << std::endl;

//     int size = sorted_main_chain.size() - 1;
//     std::cout << "size :" << size << std::endl;
//     std::vector<int> jacobsthal = generate_jacobsthal_sequence(size);
//     std::vector<int> reordered_jacobsthal = reorder_jacobsthal_sequence(jacobsthal, size);
//    // printVector(reordered_jacobsthal);



//    std::vector<int> sroted_main_chain_copy = sorted_main_chain;
//    sroted_main_chain_copy.push_back(find_pending_elment(pinding_chain, main_chain, sorted_main_chain[i]));
//    std::cout << "sorted_main_chain before sorting :" ;
//    printVector(sorted_main_chain);

//     size_t j = 0;
//     while (j < reordered_jacobsthal.size())
//     {
//         int i = reordered_jacobsthal[j];
//         std::cout << "i : " << i << " and reordered_jacobsthal[j] :" << reordered_jacobsthal[j] << std::endl;


//         int pending_num = find_pending_elment(pinding_chain, main_chain, sorted_main_chain[i]);
//         std::cout << "pending_num :" << pending_num << std::endl;
        
//         if (  (pending_num < sorted_main_chain[i + 1] || !sorted_main_chain[i + 1]))
//         {
//            // std::cout << "inserted element :" << pending_num << std::endl;
//             new_vector.push_back(sorted_main_chain[i]);// the problem is here
//             binary_insert(new_vector, pending_num);
//             binary_insert(sroted_main_chain_copy, pending_num);

//            // std::cout << "new_vector after inserting element :" ;
//            // printVector(new_vector);
//         }
//         j++;
//     }
//     std::cout << "sorted_main_chain after sorting :" ;
//     printVector(sroted_main_chain_copy);



//     if (is_odd == true)
//     {
//         std::cout << "adding here" << std::endl;
//         if (new_vector.back() > pinding_chain.back())
//             binary_insert(new_vector, pinding_chain.back());
//         else
//             new_vector.push_back(pinding_chain.back());
//     }
//     return new_vector;
// }





// without jacob stahl
// std::vector<int> sort_vector(std::vector<int>& pinding_chain, std::vector<int>& main_chain, std::vector<int>& sorted_main_chain)
// {
//     std::vector<int> new_vector;
//     int i = 0;
//     int size;
//     int pending_num;

//     size = sorted_main_chain.size() - 1;
//     while (i <= size)///here i might need to change the iterating go jacop stayle
//     {
//         pending_num = find_pending_elment(pinding_chain, main_chain, sorted_main_chain[i]);
//         if (pending_num < sorted_main_chain[i + 1] || !sorted_main_chain[i + 1])
//         {
//             new_vector.push_back(sorted_main_chain[i]);
//             binary_insert(new_vector, pending_num);
//         }
//         i++;
//     }
//     if (is_odd == true)
//     {
//         if (new_vector.back() > pinding_chain.back())
//             binary_insert(new_vector, pinding_chain.back());
//         else
//             new_vector.push_back(pinding_chain.back());
//     }
//     return new_vector;
// }