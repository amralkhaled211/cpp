#ifndef PMERGEME_HHP
#define PMERGEME_HHP

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <iomanip>

std::vector<int> Insert_elements(int ac, char **av);
void printVector(const std::vector<int>& vec);
void divideAndCompare(const std::vector<int>& input, std::vector<int>& smallElements, std::vector<int>& largeElements);
std::vector<int> getSortedMainChain(const std::vector<int>& main_chain);
int find_pending_elment(std::vector<int>& pending_chain, std::vector<int>& main_chain, int value_sorted_main_chain);
std::vector<int> sort_vector(std::vector<int>& pinding_chain, std::vector<int>& main_chain, std::vector<int>& sorted_main_chain);
std::vector<int> generate_jacobsthal_sequence(int limit);
std::vector<int> reorder_jacobsthal_sequence(const std::vector<int>& jacobsthal, int limit);
std::vector<int> sort_vector(std::vector<int>& pinding_chain, std::vector<int>& main_chain, std::vector<int>& sorted_main_chain);
void printVector_B(const std::vector<int>& vec);
void printPending(std::vector<int>& pending_chain, std::vector<int>& main_chain, std::vector<int>& sorted_main_chain);


#endif