#include "PersonManualTests.h"

void GenerateRandomPersonData(QTableWidget* table, int count) {
    Person* persons = new Person[count];
    generateRandomPersonArray(persons, count);

    table->setRowCount(count);

    for (int i = 0; i < count; ++i) {
        const Person& randomPerson = persons[i];
        table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(randomPerson.getFirstName())));
        table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(randomPerson.getLastName())));
        table->setItem(i, 2, new QTableWidgetItem(QString::number(randomPerson.getBirthYear())));
        table->setItem(i, 3, new QTableWidgetItem(QString::number(randomPerson.getHeight())));
        table->setItem(i, 4, new QTableWidgetItem(QString::number(randomPerson.getWeight())));
    }

    delete[] persons;
}


std::function<bool(const Person&, const Person&)> getComparator(const QString& parameter) {
    if (parameter == "First Name") {
        return Person::compareByFirstName;
    }
    if (parameter == "Last Name") {
        return Person::compareByLastName;
    }
    if (parameter == "Birth Year") {
        return Person::compareByBirthYear;
    }
    if (parameter == "Height") {
        return Person::compareByHeight;
    }
    if (parameter == "Weight") {
        return Person::compareByWeight;
    }
    throw std::invalid_argument("Invalid sorting parameter");
}

void SortPersonData(QTableWidget* table, const QString& method, const QString& parameter) {
    int rowCount = table->rowCount();
    if (rowCount == 0) return;

    Person* persons = new Person[rowCount];
    for (int i = 0; i < rowCount; ++i) {
        QString firstName = table->item(i, 0)->text();
        QString lastName = table->item(i, 1)->text();
        int birthYear = table->item(i, 2)->text().toInt();
        int height = table->item(i, 3)->text().toInt();
        int weight = table->item(i, 4)->text().toInt();

        persons[i] = Person(firstName.toStdString(), lastName.toStdString(), birthYear, height, weight);
    }

    UnqPtr<ArraySequence<Person>> seq(new ArraySequence<Person>(persons, rowCount));
    delete[] persons;

    if (method == "Quick Sort") {
        QuickSorter<Person>().Sort(seq, getComparator(parameter));
    } else if (method == "Bubble Sort") {
        BubbleSorter<Person>().Sort(seq, getComparator(parameter));
    } else if (method == "Shaker Sort") {
        ShakerSorter<Person>().Sort(seq, getComparator(parameter));
    }

    table->setRowCount(seq->getLength());

    for (int i = 0; i < seq->getLength(); ++i) {
        const Person& person = seq->get(i);
        table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(person.getFirstName())));
        table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(person.getLastName())));
        table->setItem(i, 2, new QTableWidgetItem(QString::number(person.getBirthYear())));
        table->setItem(i, 3, new QTableWidgetItem(QString::number(person.getHeight())));
        table->setItem(i, 4, new QTableWidgetItem(QString::number(person.getWeight())));
    }
}