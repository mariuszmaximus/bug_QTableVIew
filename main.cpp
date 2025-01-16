#include <QApplication>
#include <QMainWindow>
#include <QTableView>
#include <QStandardItemModel>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Tworzenie głównego okna
    QMainWindow mainWindow;
    mainWindow.setWindowTitle("Przykład QTableView");

    // Tworzenie modelu danych
    QStandardItemModel model(3, 5); // 3 wiersze, 5 kolumn

    // Ustawianie nagłówków kolumn
    model.setHeaderData(0, Qt::Horizontal, "K1");
    model.setHeaderData(1, Qt::Horizontal, "K2");
    model.setHeaderData(2, Qt::Horizontal, "K3");
    model.setHeaderData(3, Qt::Horizontal, "K4");
    model.setHeaderData(4, Qt::Horizontal, "K5");

    // Dodawanie przykładowych danych
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 5; ++col) {
            QStandardItem *item = new QStandardItem(QString("Wiersz %1, Kolumna %2").arg(row + 1).arg(col + 1));
            model.setItem(row, col, item);
        }
    }

    // Tworzenie widoku tabeli
    QTableView *tableView = new QTableView;
    tableView->setModel(&model);

    // Ustawianie szerokości kolumn
    tableView->setColumnWidth(0, 50);
    tableView->setColumnWidth(1, 200);
    tableView->setColumnWidth(2, 100);
    tableView->setColumnWidth(3, 180);
    tableView->setColumnWidth(4, 120);

    // Ustawianie widoku tabeli jako centralnego widgetu
    mainWindow.setCentralWidget(tableView);

    std::string s1 = R"style(
        )style";  // FAIL 
    std::string s2 = R"style()style"; // OK 
    std::string s3 = R"style( )style"; // FAIL

std::string s4 = R"style(
    QTableView {
        border: 1px solid black;
        gridline-color: black;
    }
)style"; // FAIL      

    app.setStyleSheet(QString::fromStdString(s4));


    // Wyświetlanie głównego okna
    mainWindow.resize(800, 400);
    mainWindow.show();

    return app.exec();
}
