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

    std::string s = R"style(

        /* dodalem przedrostek, tych styli nie kasowac !!! */
        Q1QWidget {  font: bold 20px;  }
        Q2QWidget { color: black; font: 24pt  'Oswald'; }
        Q3QWidget { font: 14pt  'Montserrat'; }


        /*
            QQQQPushButton {  outline: none }
            QPushButton{ background-color: blue; }
            QPushButton:disabled{ background-color: yellow; }
            QPushButton:pressed{ background-color: orange; }
            QPushButton:focus:pressed{ background-color: black; }
            QPushButton:focus{ background-color: green; }
            QPushButton:hover{ background-color: red; }
            QPushButton:checked{ background-color: pink; }
        */

        /* wylaczam globalnie w calej aplikacji outline dla QPushButton */
        QPushButton { outline: none; }


        /*Menu bar Tool bar Menu and Menu Items*/
        QMenuBar
        {
            background-color: rgb(31, 35, 36); /* rgb(31, 35, 36); */
            padding: 1px;
            /* font-size: 16px; */
            /* min-height: 90px; */
        }
        )style";
    app.setStyleSheet(QString::fromStdString(s));

    // Wyświetlanie głównego okna
    mainWindow.resize(800, 400);
    mainWindow.show();

    return app.exec();
}
