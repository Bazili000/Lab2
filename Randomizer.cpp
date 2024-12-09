/* generating Person objects with random data, 
   generating random arrays                    */

#include "Randomizer.h"

const std::string firstNames[] = {
    "Alice", "Bob", "Charlie", "David", "Eva", "Frank", "Grace", "Hannah", "Ian", "Jack",
    "Liam", "Mia", "Noah", "Olivia", "Paul", "Quinn", "Riley", "Sophia", "Thomas", "Uma",
    "Vera", "Will", "Xander", "Yara", "Zoe", "Adrian", "Bella", "Caleb", "Diana", "Elena",
    "Felix", "Gina", "Henry", "Isla", "James", "Kara", "Lucas", "Madeline", "Nathan", "Opal",
    "Aiden", "Bryce", "Catherine", "Dylan", "Emma", "Finley", "Gabriella", "Hugo", "Ivy", "Julian",
    "Kendall", "Lola", "Max", "Nina", "Oscar", "Penelope", "Quincy", "Rosa", "Sam", "Tessa"
};

const std::string lastNames[] = {
    "Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor",
    "Anderson", "Thomas", "Jackson", "White", "Harris", "Martin", "Thompson", "Garcia", "Martinez", "Roberts",
    "Clark", "Rodriguez", "Lewis", "Walker", "Allen", "Young", "King", "Scott", "Adams", "Baker",
    "Carter", "Mitchell", "Evans", "Nelson", "Perez", "Gonzalez", "Hall", "Young", "Wright", "Cole",
    "Evans", "Morris", "Morgan", "Reed", "Simmons", "Stewart", "Phillips", "Jackson", "Curtis", "Bates",
    "Murray", "Simpson", "Porter", "Richards", "Craig", "Douglas", "Grant", "Chapman", "Foster", "Bishop"
};

int getRandomNum(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

std::string generateRandomFirstName() {
    return firstNames[getRandomNum(0, sizeof(firstNames) / sizeof(firstNames[0]) - 1)];
}

std::string generateRandomLastName() {
    return lastNames[getRandomNum(0, sizeof(lastNames) / sizeof(lastNames[0]) - 1)];
}


int generateRandomBirthYear() {
    return getRandomNum(1940, 2000);
}

int generateRandomHeight() {
    return getRandomNum(150, 210);
}

int generateRandomWeight() {
    return getRandomNum(40, 120);
}

Person generateRandomPerson() {
    std::string firstName = generateRandomFirstName();
    std::string lastName = generateRandomLastName();
    int birthYear = generateRandomBirthYear();
    int height = generateRandomHeight();
    int weight = generateRandomWeight();

    return Person(firstName, lastName, birthYear, height, weight);
}

void generateRandomPersonArray(Person *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = generateRandomPerson();
    }
}

void generateRandomArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = getRandomNum(0, 10000);
    }
}