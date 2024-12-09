#include "FuncTests.h"

void RunFuncTests(TestOutput& output) {
    int dataSize = 100;

    std::function<bool(const int&, const int&)> intComp = [](const int& a, const int& b) { return a < b; };
    auto personComparators = std::vector<std::pair<std::string, std::function<bool(const Person&, const Person&)>>>{
        {"Persons by weight", Person::compareByWeight},
        {"Persons by height", Person::compareByHeight},
        {"Persons by birth year", Person::compareByBirthYear},
        {"Persons by first name", Person::compareByFirstName},
        {"Persons by last name", Person::compareByLastName},
    };

    BubbleSorter<int> bubbleSorterInt;
    ShakerSorter<int> shakerSorterInt;
    QuickSorter<int> quickSorterInt;

    std::vector<std::pair<std::string, ISorter<int>&>> intSorters = {
        {"BubbleSort<int>", bubbleSorterInt},
        {"ShakerSort<int>", shakerSorterInt},
        {"QuickSort<int>", quickSorterInt},
    };

    BubbleSorter<Person> bubbleSorterPerson;
    ShakerSorter<Person> shakerSorterPerson;
    QuickSorter<Person> quickSorterPerson;

    std::vector<std::pair<std::string, ISorter<Person>&>> personSorters = {
        {"BubbleSort<Person>", bubbleSorterPerson},
        {"ShakerSort<Person>", shakerSorterPerson},
        {"QuickSort<Person>", quickSorterPerson},
    };

    for (auto& [name, sorter] : intSorters) {
        RunTest(sorter, name, dataSize, output, intComp, generateRandomArray);
    }

    for (auto& [sorterName, sorter] : personSorters) {
        for (auto& [compName, comp] : personComparators) {
            RunTest(sorter, sorterName + " - " + compName, dataSize, output, comp, generateRandomPersonArray);
        }
    }
}
