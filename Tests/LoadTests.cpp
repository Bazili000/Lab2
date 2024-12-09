#include "LoadTests.h"

void RunLoadTests(TestOutput& output, QTableWidget* loadTestsTable) {
    std::function<bool(const int&, const int&)> intComp = [](const int& a, const int& b) { return a < b; };

    BubbleSorter<int> bubbleSorter;
    ShakerSorter<int> shakerSorter;
    QuickSorter<int> quickSorter;

    std::vector<std::pair<std::string, ISorter<int>&>> sorters = {
        {"BubbleSorter", bubbleSorter},
        {"ShakerSorter", shakerSorter},
        {"QuickSorter", quickSorter}
    };

    int row = 0;
    loadTestsTable->setRowCount(0);
    for (const auto& sorter : sorters) {
        std::vector<int> dataSizes = {100, 1000, 10000};
        for (int dataSize : dataSizes) {
            std::vector<int> data(dataSize);
            generateRandomArray(data.data(), dataSize);

            std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

            UnqPtr<ArraySequence<int>> seq(new ArraySequence<int>(data.data(), dataSize));
            sorter.second.Sort(seq, intComp);

            std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
            std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

            QString durationStr = (duration.count() < 1) ? "<1ms" : QString::number(duration.count()) + " ms";

            loadTestsTable->insertRow(row);

            loadTestsTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(sorter.first)));
            loadTestsTable->setItem(row, 1, new QTableWidgetItem(QString::number(dataSize)));
            loadTestsTable->setItem(row, 2, new QTableWidgetItem(durationStr));

            row++;
        }
    }
}
