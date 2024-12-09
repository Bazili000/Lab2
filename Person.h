#pragma once

#include <string>
#include <iostream>

class Person {
    private:
        std::string firstName;
        std::string lastName;
        int birthYear;
        int height;
        int weight;

    public:
        Person() : firstName(""), lastName(""), birthYear(0), height(0), weight(0) {}

        Person(const std::string& firstName, const std::string& lastName, int birthYear, int height, int weight)
            : firstName(firstName), lastName(lastName), birthYear(birthYear), height(height), weight(weight) {}

        std::string getFirstName() const {
            return firstName;
        }

        std::string getLastName() const {
            return lastName;
        }

        int getBirthYear() const {
            return birthYear;
        }

        int getHeight() const {
            return height;
        }

        int getWeight() const {
            return weight;
        }

        static bool compareByBirthYear(const Person& p1, const Person& p2) {
            return p1.getBirthYear() < p2.getBirthYear();
        }

        static bool compareByHeight(const Person& p1, const Person& p2) {
            return p1.getHeight() < p2.getHeight();
        }

        static bool compareByWeight(const Person& p1, const Person& p2) {
            return p1.getWeight() < p2.getWeight();
        }

        static bool compareByFirstName(const Person& p1, const Person& p2) {
            return p1.getFirstName() < p2.getFirstName();
        }

        static bool compareByLastName(const Person& p1, const Person& p2) {
            return p1.getLastName() < p2.getLastName();
        }

        bool operator==(const Person& other) const {
            return firstName == other.firstName && lastName == other.lastName &&
                birthYear == other.birthYear && height == other.height && weight == other.weight;
        }

        bool operator!=(const Person& other) const {
            return !(*this == other);
        }
};