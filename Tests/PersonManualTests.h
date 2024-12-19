#pragma once

#include <QTableWidget>
#include "../Randomizer.h"
#include "../Sorts/QuickSort.h"
#include "../Sorts/ShakerSort.h"
#include "../Sorts/BubbleSort.h"
#include "../PrevLabsContent/unique.h"
#include "../PrevLabsContent/ArraySequence.h"
#include "../GUI.h"
#include "../PrevLabsContent/unique.h"
#include "../Person.h"
#include <QString>
#include <vector>
#include <algorithm>
#include <chrono>

#include "PersonManualTests.h"

void GenerateRandomPersonData(QTableWidget* table, int count);

std::function<bool(const Person&, const Person&)> getComparator(const QString& parameter);

void SortPersonData(QTableWidget* table, const QString& method, const QString& parameter);
void SavePersonDataToFile(QTableWidget* table, const QString& fileName);
void LoadPersonDataFromFile(QTableWidget* table, const QString& fileName);