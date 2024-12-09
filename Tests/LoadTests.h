#pragma once

#include <vector>
#include <string>
#include <chrono>
#include <iostream>
#include <iomanip>
#include "OutputManager.h"
#include "../Sorts/ISorter.h"
#include "../Sorts/BubbleSort.h"
#include "../Sorts/QuickSort.h"
#include "../Sorts/ShakerSort.h"
#include "../GUI.h"
#include "../Randomizer.h"


void RunLoadTests(TestOutput& output, QTableWidget* loadTestsTable);