#pragma once

#include <string>
#include <QTextEdit>

class TestOutput{
    private:
        QTextEdit* outputField;

    public:
        explicit TestOutput(QTextEdit* textEdit) : outputField(textEdit) {}

        void write(const std::string& message) {
            outputField->append(QString::fromStdString(message));
        }

        std::string getOutput() const {
            return outputField->toPlainText().toStdString();
        }

        void clear() {
            outputField->clear();
        }

        TestOutput& operator<<(const std::string& message) {
            write(message);
            return *this;
        }

        TestOutput& operator<<(const char* message) {
            write(std::string(message));
            return *this;
        }
};
