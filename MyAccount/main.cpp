#include "start.h"
#include "analyze.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "MyAccount_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    Start w;
    w.show();
    Analyze* Anal = new Analyze;
    int ans = Anal->AIAnalyze();
    // std::cout << ans << std::endl;
    return a.exec();
}
