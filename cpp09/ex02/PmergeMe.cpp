#include "PmergeMe.hpp"

bool is_odd = false;
int comp = 0;
int fixed_size = 0;

std::vector<int> Insert_elements(int ac, char **av)
{
    std::vector<int> elements;
    for (int i = 1; i < ac; i++)
    {
        std::stringstream ss((std::string(av[i])));
        int value;
        if (ss >> value && value >= 0)
        {
            elements.push_back(value);

            // Check if the value is already in the elements vector
            //bool is_unique = true;
            // for (std::vector<int>::iterator it = elements.begin(); it != elements.end(); ++it)
            // {
            //     if (*it == value)
            //     {
            //         is_unique = false;
            //         break;
            //     }
            // }
            // if (is_unique)
            // {
            //     elements.push_back(value);
            // }
            // else
            // {
            //     std::cerr << "Error: duplicate value encountered: " << value << std::endl;
            //     elements.clear();
            //     return elements;
            // }
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
    std::cout << "=====================================" << std::endl;
    std::cout << "Comparing piars and dividing the array into 2 vecotrs. big and small numbers : " << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    for (size_t i = 0; i < input.size(); i += 2)
    {
        if (i + 1 < input.size())
        {
            if (input[i] < input[i + 1])
            {
                smallElements.push_back(input[i]);
                largeElements.push_back(input[i + 1]);
                comp++;
                std::cout << "comparing " << input[i] << " < " << input[i + 1] << " comp = " << comp << std::endl;
            }
            else
            {
                smallElements.push_back(input[i + 1]);
                largeElements.push_back(input[i]);
                comp++;
                std::cout << "comparing " << input[i] << " > " << input[i + 1] << " comp = " << comp << std::endl;
            }
        }
        else
        {
            smallElements.push_back(input[i]);
            is_odd = true;
        }
    }
    std::cout << "largeElements: ";
    printVector(largeElements);
    std::cout << "smallElements: ";
    printVector(smallElements);
}

void merge(std::vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

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
            comp++;
            std::cout << "comparing " << leftArr[i] << " with " << rightArr[j] << " and comp :" << comp <<  std::endl;
            ++i;
        }
        else
        {
            arr[k] = rightArr[j];
            comp++;
            std::cout << "comparing " << leftArr[i] << " with " << rightArr[j] << " and comp :" << comp <<  std::endl;
            ++j;
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

// Merge sort function
void mergeSort(std::vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
// Function to get sorted main chain using merge sort
std::vector<int> getSortedMainChain(const std::vector<int>& main_chain)
{
    std::cout << "=====================================" << std::endl;
    std::cout << "second cmparison merge algorthim : "  << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::vector<int> sorted_chain = main_chain;
    mergeSort(sorted_chain, 0, sorted_chain.size() - 1);
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
   
    std::cout << "Third comparison: binary search " << std::endl;
    //std::cout << "--------------------------------------" << std::endl;
    int begin = 0;
    int end = new_vector.size() - fixed_size + 1;// i change this for the invalid read
    fixed_size -= 1;
    std::cout << "fixed_size is :" << fixed_size << std::endl;  
    std::cout << "end is :" << end << std::endl;
    int middle;
    while (begin <= end)
    {
        middle = begin + (end - begin) / 2;
        std::cout << "middle is :" << middle << std::endl;

        if (new_vector[middle] < pending_num)
        {
           begin = middle + 1;
           comp++;

           std::cout << "comparing " << new_vector[middle] << " with " << pending_num << " and comp :" << comp <<  std::endl;
        }
        else if (middle > 0 && ((new_vector[middle] >= pending_num && new_vector[middle - 1] <= pending_num)
            || (new_vector[middle - 1] == 0 && new_vector[middle] >= pending_num)))
        {
            comp++;
            std::cout << "comparing " << new_vector[middle] << " with " << pending_num << " and comp :" << comp <<  std::endl;
            new_vector.insert(new_vector.begin() + middle , pending_num);
            break;
        }
        else if (new_vector[middle] > pending_num)
        {
            end = middle - 1;
            comp++;
            std::cout << "comparing " << new_vector[middle] << " with " << pending_num << " and comp :" << comp <<  std::endl;
        }
    }
    if (begin > end) // and i added this to fix the invalid read
    {
        new_vector.insert(new_vector.begin() + begin, pending_num);
    }
}

//23 354 5 353 234 57 5 234
std::vector<int> sort_vector(std::vector<int>& pinding_chain, std::vector<int>& main_chain, std::vector<int>& sorted_main_chain)
{
    int size = sorted_main_chain.size() - 1;
    std::vector<int> jacobsthal = generate_jacobsthal_sequence(size);
    std::vector<int> reordered_jacobsthal = reorder_jacobsthal_sequence(jacobsthal, size);
    std::vector<int> sroted_main_chain_copy = sorted_main_chain;
    fixed_size = sroted_main_chain_copy.size();
    sroted_main_chain_copy.insert( sroted_main_chain_copy.begin(), find_pending_elment(pinding_chain, main_chain, sorted_main_chain[0]));
    std::cout << "=====================================" << std::endl;
    std::cout << "excuting the binary search" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    size_t j = 0;
    while (j < reordered_jacobsthal.size() && j < sorted_main_chain.size() - 1)
    {
        int i = reordered_jacobsthal[j];
        int pending_num = find_pending_elment(pinding_chain, main_chain, sorted_main_chain[i]);
        std::cout << "pending_num :" << pending_num << std::endl;
        binary_insert(sroted_main_chain_copy, pending_num);
        std::cout << "-------------------------------------" << std::endl;
        printVector(sroted_main_chain_copy);
        std::cout << "-------------------------------------" << std::endl;
        j++;
    }
    if (is_odd == true)
    {
        // if (sroted_main_chain_copy.back() > pinding_chain.back())
        // {
        binary_insert(sroted_main_chain_copy, pinding_chain.back());
        //     comp++;
        // }
        // else
        // {
        //     sroted_main_chain_copy.push_back(pinding_chain.back());
        //     comp++;
        // }
    }
    std::cout << "comp : " << comp << std::endl;
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