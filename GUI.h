#pragma once

#include <QMainWindow>
#include <QTabWidget>
#include <QPushButton>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QStyleFactory>
#include <QApplication>
#include <QHeaderView>
#include <QMessageBox>
#include <QtConcurrent>
#include <QSpinBox>

#include "Tests/FuncTests.h"
#include "Tests/LoadTests.h"
#include "Tests/OutputManager.h"
#include "Tests/PersonManualTests.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    QTabWidget* tabWidget;

    QWidget* functionalTestsTab;
    QPushButton* runFunctionalTestsButton;
    QTextEdit* functionalTestsOutput;

    QWidget* loadTestsTab;
    QPushButton* runLoadTestsButton;
    QTextEdit* loadTestsOutput;
    QTableWidget* loadTestsTable;

    QWidget* manualPersonTestsTab;
    QPushButton* generatePersonDataButton;
    QPushButton* startSortingButton;
    QPushButton* clearDataButton;
    QSpinBox* dataVolumeSpinBox;
    QComboBox* sortingMethodComboBox;
    QComboBox* sortingParameterComboBox;
    QTableWidget* personDataTable;

    void setupFunctionalTestsTab();
    void setupLoadTestsTab();
    void setupPersonManualTestsTab();

    void applyDarkTheme();

    void FuncTestsClicked();
    void LoadTestsClicked();
};
