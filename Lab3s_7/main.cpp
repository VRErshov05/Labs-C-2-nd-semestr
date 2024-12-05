#include "Lab3s_7.h"
#include <QtWidgets/QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsPolygonItem>
#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QRandomGenerator>
#include <QVector>
#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem>


// Базовый класс для всех фигур
class Shape : public QGraphicsItem {
public:
    Shape() {
        setFlags(ItemIsMovable | ItemIsSelectable);
    }

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override {
        setZValue(1);  // Поднимаем фигуру на передний план
        QGraphicsItem::mousePressEvent(event);
    }
};

// Прямоугольник
class Rectangle : public Shape {
public:
    QRectF boundingRect() const override {
        return QRectF(0, 0, 100, 50);
    }

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override {
        Q_UNUSED(widget)
            if (option->state & QStyle::State_Selected) {
                painter->setPen(QPen(Qt::red, 3));  // Красная рамка при выделении
            }
            else {
                painter->setPen(Qt::NoPen);
            }
        painter->setBrush(Qt::blue);
        painter->drawRect(boundingRect());
    }
};

// Эллипс
class Ellipse : public Shape {
public:
    QRectF boundingRect() const override {
        return QRectF(0, 0, 60, 60);
    }

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override {
        Q_UNUSED(widget)
            if (option->state & QStyle::State_Selected) {
                painter->setPen(QPen(Qt::red, 3));  // Красная рамка при выделении
            }
            else {
                painter->setPen(Qt::NoPen);
            }
        painter->setBrush(Qt::green);
        painter->drawEllipse(boundingRect());
    }
};

// Треугольник
class Triangle : public Shape {
public:
    QRectF boundingRect() const override {
        return QRectF(-30, -30, 60, 60);
    }

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override {
        Q_UNUSED(widget)
            if (option->state & QStyle::State_Selected) {
                painter->setPen(QPen(Qt::red, 3));  // Красная рамка при выделении
            }
            else {
                painter->setPen(Qt::NoPen);
            }
        QPolygon polygon;
        polygon << QPoint(0, -30) << QPoint(-30, 30) << QPoint(30, 30);
        painter->setBrush(Qt::yellow);
        painter->drawPolygon(polygon);
    }
};

// Класс для управления сценой и фигурами
class ShapeManager : public QWidget {
    Q_OBJECT
public:
    ShapeManager() {
        QVBoxLayout* layout = new QVBoxLayout(this);

        // Создаем сцену и вид
        scene = new QGraphicsScene(this);
        QGraphicsView* view = new QGraphicsView(scene);
        layout->addWidget(view);

        // Кнопки управления
        QPushButton* addRectButton = new QPushButton("Add a RECTANGLE");
        QPushButton* addEllipseButton = new QPushButton("Add a ELLIPSE");
        QPushButton* addTriangleButton = new QPushButton("Add a TRIANGLE");
        QPushButton* removeSelectedButton = new QPushButton("Delete the shapes");
        layout->addWidget(addRectButton);
        layout->addWidget(addEllipseButton);
        layout->addWidget(addTriangleButton);
        layout->addWidget(removeSelectedButton);

        // Подключение сигналов к слотам
        connect(addRectButton, &QPushButton::clicked, this, &ShapeManager::addRectangle);
        connect(addEllipseButton, &QPushButton::clicked, this, &ShapeManager::addEllipse);
        connect(addTriangleButton, &QPushButton::clicked, this, &ShapeManager::addTriangle);
        connect(removeSelectedButton, &QPushButton::clicked, this, &ShapeManager::removeSelectedShape);
    }

public slots:
    void addRectangle() {
        auto* rect = new Rectangle();
        rect->setPos(randomPosition());
        scene->addItem(rect);
    }

    void addEllipse() {
        auto* ellipse = new Ellipse();
        ellipse->setPos(randomPosition());
        scene->addItem(ellipse);
    }

    void addTriangle() {
        auto* triangle = new Triangle();
        triangle->setPos(randomPosition());
        scene->addItem(triangle);
    }

    void removeSelectedShape() {
        QList<QGraphicsItem*> selectedItems = scene->selectedItems();
        for (QGraphicsItem* item : selectedItems) {
            scene->removeItem(item);
            delete item;  // Удаляем объект из памяти
        }
    }

private:
    QGraphicsScene* scene;

    QPointF randomPosition() {
        int x = QRandomGenerator::global()->bounded(0, 400);
        int y = QRandomGenerator::global()->bounded(0, 400);
        return QPointF(x, y);
    }
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    ShapeManager manager;
    manager.setWindowTitle("Managing shapes");
    manager.resize(600, 600);
    manager.show();

    return app.exec();
}

#include "main.moc"

