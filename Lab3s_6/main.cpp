#include "lab3s_6.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QScrollBar>
#include <QSpinBox>
#include <QWidget>
#include <QDebug>
#include <iostream>
#include <qtextcodec.h>

class WidgetCollection : public QWidget {
    Q_OBJECT

public:
    WidgetCollection(QWidget* parent = nullptr)
        : QWidget(parent) {
        layout = new QVBoxLayout(this);
        setLayout(layout);
    }

    void addWidget(QWidget* widget) {
        // Проверяем, поддерживается ли тип виджета
        if (qobject_cast<QLabel*>(widget) ||
            qobject_cast<QSlider*>(widget) ||
            qobject_cast<QScrollBar*>(widget) ||
            qobject_cast<QSpinBox*>(widget)) {
            widgets.append(widget);
            layout->addWidget(widget);
            qDebug() << "Добавлен виджет:" << widget->metaObject()->className();
        }
        else {
            qDebug() << "Ошибка: неподдерживаемый тип виджета";
        }
    }

    void connectWidgets() {
        for (QWidget* widget : widgets) {
            // Подключаем сигналы для изменяемых виджетов
            if (auto slider = qobject_cast<QSlider*>(widget)) {
                connect(slider, &QSlider::valueChanged, this, &WidgetCollection::updateWidgets);
            }
            else if (auto scrollbar = qobject_cast<QScrollBar*>(widget)) {
                connect(scrollbar, &QScrollBar::valueChanged, this, &WidgetCollection::updateWidgets);
            }
            else if (auto spinbox = qobject_cast<QSpinBox*>(widget)) {
                connect(spinbox, QOverload<int>::of(&QSpinBox::valueChanged), this, &WidgetCollection::updateWidgets);
            }
        }
    }

private slots:
    void updateWidgets(int value) {
        QWidget* senderWidget = qobject_cast<QWidget*>(sender());
        qDebug() << "Сигнал от:" << senderWidget->metaObject()->className() << ", значение:" << value;

        for (QWidget* widget : widgets) {
            if (widget == senderWidget) continue; // Пропускаем отправителя

            if (auto label = qobject_cast<QLabel*>(widget)) {
                // Изменяем только число
                QString currentText = label->text();
                int colonIndex = currentText.indexOf(':');
                if (colonIndex != -1) {
                    label->setText(currentText.left(colonIndex + 2) + QString::number(value));
                }
            }
            else if (auto slider = qobject_cast<QSlider*>(widget)) {
                slider->blockSignals(true);
                slider->setValue(value);
                slider->blockSignals(false);
            }
            else if (auto scrollbar = qobject_cast<QScrollBar*>(widget)) {
                scrollbar->blockSignals(true);
                scrollbar->setValue(value);
                scrollbar->blockSignals(false);
            }
            else if (auto spinbox = qobject_cast<QSpinBox*>(widget)) {
                spinbox->blockSignals(true);
                spinbox->setValue(value);
                spinbox->blockSignals(false);
            }
        }
    }


private:
    QVBoxLayout* layout;
    QList<QWidget*> widgets;
};

int main(int argc, char* argv[]) {
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    setlocale(LC_ALL, "RU");
    QApplication app(argc, argv);

    WidgetCollection window;
    window.resize(400, 200);
    // Создаем виджеты
    QLabel* label = new QLabel(QStringLiteral("Значение: "));
    QSlider* slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 100);
    QScrollBar* scrollbar = new QScrollBar(Qt::Horizontal);
    scrollbar->setRange(0, 100);
    QSpinBox* spinbox = new QSpinBox();
    spinbox->setRange(0, 100);

    // Добавляем виджеты в коллекцию
    window.addWidget(label);
    window.addWidget(slider);
    window.addWidget(scrollbar);
    window.addWidget(spinbox);

    // Подключаем виджеты
    window.connectWidgets();

    window.show();
    return app.exec();
}
#include "main.moc"