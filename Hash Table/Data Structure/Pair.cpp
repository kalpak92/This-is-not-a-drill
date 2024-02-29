/**
 * std::pair is a class template that provides a way to store two heterogeneous objects as a single unit. 
 * A pair is a specific case of a std::tuple with two elements.
*/

#include <iostream>
#include <utility>
#include <vector>
#include <functional>

template<typename First, typename Second>
struct MyPair
{
    First key;
    Second value;
};

using student_t = std::pair<int, std::string>;

int main() {

    std::vector<student_t> students;
    for (int i = 0; i < 5; i++)
    {
        std::pair<int, std::string> student(1, "Kalpak");
        students.push_back(student);
    }

    for (auto elements : students) {
        std::cout << elements.first << " => " << elements.second << std::endl;
    }

    auto newPairUsingMakePair = std::make_pair(100L, 10.0f);

    long value = 100L;
    auto newpair = std::make_pair(std::ref(value), 10.0f);
    std::cout << newpair.first << " => " << newpair.second << std::endl;
    value = 150L;
    std::cout << newpair.first << " => " << newpair.second << std::endl;

    std::cout << std::get<float>(newpair) << std::endl; // helps with type checking in compile time

    return 0;
}