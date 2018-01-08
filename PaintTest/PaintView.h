#pragma once
#include <QtWidgets/QGraphicsView>

class PaintView : public QGraphicsView
{
  Q_OBJECT

public:
  PaintView(QWidget*);

  virtual	~PaintView();

  bool mousePressed();

protected:
  virtual	void mouseMoveEvent(QMouseEvent*);

  void mousePressEvent(QMouseEvent *event);

  void mouseReleaseEvent(QMouseEvent *event);

private:
  QPointF mousePressedPos;
  QPointF mouseReleasedPos;
  bool isMousePressed = false;


public:
  Q_SIGNALS :
            void drawShape();
            void previewShape(QPointF, QPointF);
            void UpdateMousePos(QPointF);
            void freeDraw(QPointF);

};

