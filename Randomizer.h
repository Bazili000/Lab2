#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include "Person.h"

std::string generateRandomFirstName();
std::string generateRandomLastName();
int generateRandomBirthYear();
int generateRandomHeight();
int generateRandomWeight();
Person generateRandomPerson();
void generateRandomPersonArray(Person *array, int size);
int getRandomNum(int min, int max);
void generateRandomArray(int *array, int size);
