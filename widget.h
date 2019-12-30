#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPrinter>
#include <poppler-qt5.h>

#include "pricingoptions.h"
#include "pageprice.h"
#include "documentprice.h"
#include "pricebreakdownmodel.h"

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

    PagePrice calculatePriceFor(QImage*);

// =============================================

signals:
    void documentFileNameDidSet(QString);
    void documentDidChecked(QString);
    void documentDidLoad();
    void documentDidRendered();
    void documentPriceCalculated();

private slots:
    void openDocument();
    void checkDocument(QString fileName);
    void loadDocument(QString fileName);
    void showDocInfo();
    void previewPages(QPrinter *printer);
    void doneRendering();

    void calculateDocumentPrice();
    void showDocumentPrice();

// =============================================

private:
    Ui::Widget *ui;
    Poppler::Document *pdfDoc;
    PricingOptions pricingOptions;
    DocumentPrice docPrice;
};

#endif // WIDGET_H
