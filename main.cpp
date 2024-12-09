#include "GUI.h"

#include <iostream>

#include "../Randomizer.h"
#include "../Sorts/QuickSort.h"
#include "../Sorts/ShakerSort.h"
#include "../Sorts/BubbleSort.h"
#include "../GUI.h"
#include "../PrevLabsContent/ArraySequence.h"
#include "../PrevLabsContent/unique.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.setWindowTitle("Sorting Test System");
    mainWindow.resize(800, 600);
    mainWindow.show();

    return app.exec();
}
