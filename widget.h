#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPrinter>
#include <poppler-qt5.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    void setupLayout();
    void setupInterplays();

// =============================================

signals:
    void documentFileNameDidSet(QString);
    void documentDidLoad();
    void documentDidRendered();

private slots:
    void openDocument();
    void loadDocument(QString fileName);
    void showDocInfo();
    void previewPages(QPrinter *printer);
    void doneRendering();

// =============================================

private:
    Ui::Widget *ui;
    Poppler::Document *pdfDoc;
};

#endif // WIDGET_H
