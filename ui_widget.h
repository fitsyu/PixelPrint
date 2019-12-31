/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtPrintSupport/QPrintPreviewWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *openDocumentButton;
    QLabel *documentFileNameLabel;
    QPrintPreviewWidget *previewWidget;
    QSpacerItem *horizontalSpacer;
    QWidget *SummaryWidget;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formDocumentInfo;
    QLabel *title;
    QLabel *titleLabel;
    QLabel *author;
    QLabel *authorLabel;
    QLabel *creator;
    QLabel *creatorLabel;
    QLabel *createdAt;
    QLabel *createdAtLabel;
    QLabel *pages;
    QLabel *pagesCountLabel;
    QFrame *separatorLine1;
    QFormLayout *formOptions;
    QLabel *paperPriceLabel;
    QLabel *BlackInkLabel;
    QLabel *printInColorLabel;
    QLineEdit *paperPriceLineEdit;
    QLineEdit *blackInkCostLineEdit;
    QPushButton *printInColorSwitch;
    QLabel *colorInkLabel;
    QLineEdit *colorInkCostLineEdit;
    QFrame *separatorLine2;
    QFormLayout *formPricing;
    QLabel *pixels;
    QLabel *totalPixelsCountLabel;
    QLabel *price;
    QLabel *finalPriceLabel;
    QTableView *tableView;
    QPushButton *printButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(987, 725);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(16);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        openDocumentButton = new QPushButton(Widget);
        openDocumentButton->setObjectName(QString::fromUtf8("openDocumentButton"));
        openDocumentButton->setMinimumSize(QSize(0, 40));
        openDocumentButton->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(openDocumentButton);

        documentFileNameLabel = new QLabel(Widget);
        documentFileNameLabel->setObjectName(QString::fromUtf8("documentFileNameLabel"));
        documentFileNameLabel->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(documentFileNameLabel);

        previewWidget = new QPrintPreviewWidget(Widget);
        previewWidget->setObjectName(QString::fromUtf8("previewWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(previewWidget->sizePolicy().hasHeightForWidth());
        previewWidget->setSizePolicy(sizePolicy);
        previewWidget->setMinimumSize(QSize(0, 0));
        previewWidget->setMaximumSize(QSize(400, 400));

        verticalLayout->addWidget(previewWidget);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(16, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        SummaryWidget = new QWidget(Widget);
        SummaryWidget->setObjectName(QString::fromUtf8("SummaryWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(SummaryWidget->sizePolicy().hasHeightForWidth());
        SummaryWidget->setSizePolicy(sizePolicy1);
        SummaryWidget->setMaximumSize(QSize(2000, 16777215));
        verticalLayout_2 = new QVBoxLayout(SummaryWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        formDocumentInfo = new QFormLayout();
        formDocumentInfo->setSpacing(6);
        formDocumentInfo->setObjectName(QString::fromUtf8("formDocumentInfo"));
        formDocumentInfo->setSizeConstraint(QLayout::SetDefaultConstraint);
        formDocumentInfo->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formDocumentInfo->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formDocumentInfo->setHorizontalSpacing(8);
        formDocumentInfo->setVerticalSpacing(8);
        formDocumentInfo->setContentsMargins(8, 8, 8, 8);
        title = new QLabel(SummaryWidget);
        title->setObjectName(QString::fromUtf8("title"));

        formDocumentInfo->setWidget(2, QFormLayout::LabelRole, title);

        titleLabel = new QLabel(SummaryWidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));

        formDocumentInfo->setWidget(2, QFormLayout::FieldRole, titleLabel);

        author = new QLabel(SummaryWidget);
        author->setObjectName(QString::fromUtf8("author"));

        formDocumentInfo->setWidget(3, QFormLayout::LabelRole, author);

        authorLabel = new QLabel(SummaryWidget);
        authorLabel->setObjectName(QString::fromUtf8("authorLabel"));

        formDocumentInfo->setWidget(3, QFormLayout::FieldRole, authorLabel);

        creator = new QLabel(SummaryWidget);
        creator->setObjectName(QString::fromUtf8("creator"));

        formDocumentInfo->setWidget(4, QFormLayout::LabelRole, creator);

        creatorLabel = new QLabel(SummaryWidget);
        creatorLabel->setObjectName(QString::fromUtf8("creatorLabel"));

        formDocumentInfo->setWidget(4, QFormLayout::FieldRole, creatorLabel);

        createdAt = new QLabel(SummaryWidget);
        createdAt->setObjectName(QString::fromUtf8("createdAt"));

        formDocumentInfo->setWidget(5, QFormLayout::LabelRole, createdAt);

        createdAtLabel = new QLabel(SummaryWidget);
        createdAtLabel->setObjectName(QString::fromUtf8("createdAtLabel"));

        formDocumentInfo->setWidget(5, QFormLayout::FieldRole, createdAtLabel);

        pages = new QLabel(SummaryWidget);
        pages->setObjectName(QString::fromUtf8("pages"));

        formDocumentInfo->setWidget(6, QFormLayout::LabelRole, pages);

        pagesCountLabel = new QLabel(SummaryWidget);
        pagesCountLabel->setObjectName(QString::fromUtf8("pagesCountLabel"));

        formDocumentInfo->setWidget(6, QFormLayout::FieldRole, pagesCountLabel);


        verticalLayout_2->addLayout(formDocumentInfo);

        separatorLine1 = new QFrame(SummaryWidget);
        separatorLine1->setObjectName(QString::fromUtf8("separatorLine1"));
        separatorLine1->setMinimumSize(QSize(0, 1));
        separatorLine1->setMaximumSize(QSize(16777215, 1));
        separatorLine1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 84);"));
        separatorLine1->setFrameShape(QFrame::StyledPanel);
        separatorLine1->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(separatorLine1);

        formOptions = new QFormLayout();
        formOptions->setSpacing(6);
        formOptions->setObjectName(QString::fromUtf8("formOptions"));
        formOptions->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formOptions->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        paperPriceLabel = new QLabel(SummaryWidget);
        paperPriceLabel->setObjectName(QString::fromUtf8("paperPriceLabel"));

        formOptions->setWidget(0, QFormLayout::LabelRole, paperPriceLabel);

        BlackInkLabel = new QLabel(SummaryWidget);
        BlackInkLabel->setObjectName(QString::fromUtf8("BlackInkLabel"));

        formOptions->setWidget(1, QFormLayout::LabelRole, BlackInkLabel);

        printInColorLabel = new QLabel(SummaryWidget);
        printInColorLabel->setObjectName(QString::fromUtf8("printInColorLabel"));

        formOptions->setWidget(3, QFormLayout::LabelRole, printInColorLabel);

        paperPriceLineEdit = new QLineEdit(SummaryWidget);
        paperPriceLineEdit->setObjectName(QString::fromUtf8("paperPriceLineEdit"));

        formOptions->setWidget(0, QFormLayout::FieldRole, paperPriceLineEdit);

        blackInkCostLineEdit = new QLineEdit(SummaryWidget);
        blackInkCostLineEdit->setObjectName(QString::fromUtf8("blackInkCostLineEdit"));
        blackInkCostLineEdit->setClearButtonEnabled(true);

        formOptions->setWidget(1, QFormLayout::FieldRole, blackInkCostLineEdit);

        printInColorSwitch = new QPushButton(SummaryWidget);
        printInColorSwitch->setObjectName(QString::fromUtf8("printInColorSwitch"));
        printInColorSwitch->setCheckable(true);
        printInColorSwitch->setChecked(true);
        printInColorSwitch->setFlat(true);

        formOptions->setWidget(3, QFormLayout::FieldRole, printInColorSwitch);

        colorInkLabel = new QLabel(SummaryWidget);
        colorInkLabel->setObjectName(QString::fromUtf8("colorInkLabel"));

        formOptions->setWidget(2, QFormLayout::LabelRole, colorInkLabel);

        colorInkCostLineEdit = new QLineEdit(SummaryWidget);
        colorInkCostLineEdit->setObjectName(QString::fromUtf8("colorInkCostLineEdit"));

        formOptions->setWidget(2, QFormLayout::FieldRole, colorInkCostLineEdit);


        verticalLayout_2->addLayout(formOptions);

        separatorLine2 = new QFrame(SummaryWidget);
        separatorLine2->setObjectName(QString::fromUtf8("separatorLine2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(separatorLine2->sizePolicy().hasHeightForWidth());
        separatorLine2->setSizePolicy(sizePolicy2);
        separatorLine2->setMinimumSize(QSize(2, 1));
        separatorLine2->setMaximumSize(QSize(16777215, 1));
        separatorLine2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 84);"));
        separatorLine2->setFrameShape(QFrame::StyledPanel);
        separatorLine2->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(separatorLine2);

        formPricing = new QFormLayout();
        formPricing->setSpacing(6);
        formPricing->setObjectName(QString::fromUtf8("formPricing"));
        formPricing->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formPricing->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        pixels = new QLabel(SummaryWidget);
        pixels->setObjectName(QString::fromUtf8("pixels"));

        formPricing->setWidget(2, QFormLayout::LabelRole, pixels);

        totalPixelsCountLabel = new QLabel(SummaryWidget);
        totalPixelsCountLabel->setObjectName(QString::fromUtf8("totalPixelsCountLabel"));

        formPricing->setWidget(2, QFormLayout::FieldRole, totalPixelsCountLabel);

        price = new QLabel(SummaryWidget);
        price->setObjectName(QString::fromUtf8("price"));

        formPricing->setWidget(3, QFormLayout::LabelRole, price);

        finalPriceLabel = new QLabel(SummaryWidget);
        finalPriceLabel->setObjectName(QString::fromUtf8("finalPriceLabel"));

        formPricing->setWidget(3, QFormLayout::FieldRole, finalPriceLabel);

        tableView = new QTableView(SummaryWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setAlternatingRowColors(true);
        tableView->horizontalHeader()->setHighlightSections(false);
        tableView->verticalHeader()->setCascadingSectionResizes(false);
        tableView->verticalHeader()->setDefaultSectionSize(24);

        formPricing->setWidget(1, QFormLayout::SpanningRole, tableView);


        verticalLayout_2->addLayout(formPricing);

        printButton = new QPushButton(SummaryWidget);
        printButton->setObjectName(QString::fromUtf8("printButton"));
        printButton->setMinimumSize(QSize(0, 40));

        verticalLayout_2->addWidget(printButton);


        horizontalLayout->addWidget(SummaryWidget);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        openDocumentButton->setText(QApplication::translate("Widget", "Open Document", nullptr));
        documentFileNameLabel->setText(QApplication::translate("Widget", "Document File Name", nullptr));
        title->setText(QApplication::translate("Widget", "Title", nullptr));
        titleLabel->setText(QApplication::translate("Widget", "Document Title", nullptr));
        author->setText(QApplication::translate("Widget", "Author", nullptr));
        authorLabel->setText(QApplication::translate("Widget", "AuthorLabel", nullptr));
        creator->setText(QApplication::translate("Widget", "Created In", nullptr));
        creatorLabel->setText(QApplication::translate("Widget", "CreatorLabel", nullptr));
        createdAt->setText(QApplication::translate("Widget", "Created At", nullptr));
        createdAtLabel->setText(QApplication::translate("Widget", "CreatedAtLabel", nullptr));
        pages->setText(QApplication::translate("Widget", "Pages", nullptr));
        pagesCountLabel->setText(QApplication::translate("Widget", "PagesCountLabel", nullptr));
        paperPriceLabel->setText(QApplication::translate("Widget", "Paper Price / Piece", nullptr));
        BlackInkLabel->setText(QApplication::translate("Widget", "Black Ink Cost", nullptr));
        printInColorLabel->setText(QApplication::translate("Widget", "Print All In Color", nullptr));
        blackInkCostLineEdit->setText(QApplication::translate("Widget", "0.010", nullptr));
        printInColorSwitch->setText(QApplication::translate("Widget", "Yes", nullptr));
        colorInkLabel->setText(QApplication::translate("Widget", "Color Ink Cost", nullptr));
        colorInkCostLineEdit->setText(QApplication::translate("Widget", "0.015", nullptr));
        pixels->setText(QApplication::translate("Widget", "Pixels", nullptr));
        totalPixelsCountLabel->setText(QApplication::translate("Widget", "TotalPixelsCountLabel", nullptr));
        price->setText(QApplication::translate("Widget", "Price", nullptr));
        finalPriceLabel->setText(QApplication::translate("Widget", "FinalPriceLabel", nullptr));
        printButton->setText(QApplication::translate("Widget", "PRINT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
