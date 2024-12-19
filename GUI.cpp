#include "GUI.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    setMinimumSize(500, 500);

    tabWidget = new QTabWidget(this);

    functionalTestsTab = new QWidget();
    loadTestsTab = new QWidget();
    manualPersonTestsTab = new QWidget();

    setupFunctionalTestsTab();
    setupLoadTestsTab();
    setupPersonManualTestsTab();

    tabWidget->addTab(functionalTestsTab, "Functional Tests");
    tabWidget->addTab(loadTestsTab, "Load Tests");
    tabWidget->addTab(manualPersonTestsTab, "Person Testings");

    tabWidget->setTabPosition(QTabWidget::North);
    setCentralWidget(tabWidget);

    applyDarkTheme();

    connect(runFunctionalTestsButton, &QPushButton::clicked, this, &MainWindow::FuncTestsClicked);
    connect(runLoadTestsButton, &QPushButton::clicked, this, &MainWindow::LoadTestsClicked);

    connect(generatePersonDataButton, &QPushButton::clicked, [this]() {
    int count = dataVolumeSpinBox->value();
    GenerateRandomPersonData(personDataTable, count);
    });

    connect(clearDataButton, &QPushButton::clicked, [this]() {
    personDataTable->clearContents();
    personDataTable->setRowCount(0);
    });

    connect(startSortingButton, &QPushButton::clicked, [this]() {
    QString sortingMethod = sortingMethodComboBox->currentText();
    QString sortingParameter = sortingParameterComboBox->currentText();
    SortPersonData(personDataTable, sortingMethod, sortingParameter);
    });

    connect(saveToFileButton, &QPushButton::clicked, this, &MainWindow::SaveToFileClicked);
    connect(loadFromFileButton, &QPushButton::clicked, this, &MainWindow::LoadFromFileClicked);
}


MainWindow::~MainWindow() {
    delete runFunctionalTestsButton;
    delete functionalTestsOutput;
    delete functionalTestsTab;

    delete runLoadTestsButton;
    delete loadTestsOutput;
    delete loadTestsTab;

    delete generatePersonDataButton;
    delete startSortingButton;
    delete clearDataButton;
    delete dataVolumeSpinBox;
    delete sortingMethodComboBox;
    delete sortingParameterComboBox;
    delete personDataTable;
    delete manualPersonTestsTab;

    delete saveToFileButton;
    delete loadFromFileButton;
}

void MainWindow::setupFunctionalTestsTab() {
    auto* layout = new QVBoxLayout(functionalTestsTab);
    runFunctionalTestsButton = new QPushButton("Run Functional Tests");
    functionalTestsOutput = new QTextEdit();
    functionalTestsOutput->setReadOnly(true);

    layout->addWidget(runFunctionalTestsButton);
    layout->addWidget(functionalTestsOutput);
}

void MainWindow::setupLoadTestsTab() {
    auto* layout = new QVBoxLayout(loadTestsTab);
    runLoadTestsButton = new QPushButton("Run Load Tests");
    loadTestsOutput = new QTextEdit();
    loadTestsOutput->setReadOnly(true);

    loadTestsTable = new QTableWidget();
    loadTestsTable->setColumnCount(3);
    loadTestsTable->setHorizontalHeaderLabels({"Sorting Method", "Data Size", "Sorting Time"});

    loadTestsTable->horizontalHeader()->setStretchLastSection(true);
    loadTestsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    layout->addWidget(runLoadTestsButton);
    layout->addWidget(loadTestsTable);
}

void MainWindow::setupPersonManualTestsTab() {
    auto* layout = new QVBoxLayout(manualPersonTestsTab);

    sortingMethodComboBox = new QComboBox();
    sortingMethodComboBox->addItems({"Quick Sort", "Bubble Sort", "Shaker Sort"});

    sortingParameterComboBox = new QComboBox();
    sortingParameterComboBox->addItems({"First Name", "Last Name", "Birth Year", "Height", "Weight"});

    generatePersonDataButton = new QPushButton("Generate Random Person Data");
    startSortingButton = new QPushButton("Start Sorting");
    clearDataButton = new QPushButton("Clear Data");

    personDataTable = new QTableWidget();
    personDataTable->setColumnCount(5);
    personDataTable->setHorizontalHeaderLabels({"First Name", "Last Name", "Birth Year", "Height", "Weight"});

    personDataTable->horizontalHeader()->setStretchLastSection(true);
    personDataTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    dataVolumeSpinBox = new QSpinBox();
    dataVolumeSpinBox->setRange(1, 10000);
    dataVolumeSpinBox->setValue(100);

    auto* fileButtonsLayout = new QHBoxLayout();
    loadFromFileButton = new QPushButton("Load from File");
    saveToFileButton = new QPushButton("Save to File");
    fileButtonsLayout->addWidget(loadFromFileButton);
    fileButtonsLayout->addWidget(saveToFileButton);

    layout->addWidget(new QLabel("Select Sorting Method:"));
    layout->addWidget(sortingMethodComboBox);
    layout->addWidget(new QLabel("Select Sorting Parameter:"));
    layout->addWidget(sortingParameterComboBox);
    layout->addWidget(new QLabel("Number of Persons to Generate:"));
    layout->addWidget(dataVolumeSpinBox);
    layout->addWidget(generatePersonDataButton);
    layout->addWidget(startSortingButton);
    layout->addWidget(clearDataButton);
    layout->addLayout(fileButtonsLayout);
    layout->addWidget(personDataTable);
}


void MainWindow::applyDarkTheme() {
    setStyle(QStyleFactory::create("Fusion"));
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(15, 15, 15));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Highlight, QColor(142, 45, 197).lighter());
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    qApp->setPalette(darkPalette);
}

void MainWindow::FuncTestsClicked() {
    functionalTestsOutput->clear();
    TestOutput output(functionalTestsOutput);
    RunFuncTests(output);
    QMessageBox::information(this, "All tests passed", "Сheck the results.");

}

void MainWindow::LoadTestsClicked() {
    loadTestsOutput->clear();
    TestOutput output(loadTestsOutput);

    QtConcurrent::run([this, &output]() {
        RunLoadTests(output, loadTestsTable);
    });
}

void MainWindow::SaveToFileClicked() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*.txt);;All Files (*)");
    
    if (fileName.isEmpty()) {
        return;
    }

    SavePersonDataToFile(personDataTable, fileName);
}

void MainWindow::LoadFromFileClicked() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt);;All Files (*)");

    if (fileName.isEmpty()) {
        return;
    }

    LoadPersonDataFromFile(personDataTable, fileName);
}

