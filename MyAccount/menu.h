#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QEvent>

class Menu : public QMainWindow
{
    Q_OBJECT
public:
    explicit Menu(QWidget *parent = nullptr);

signals:
};

#endif // MENU_H
