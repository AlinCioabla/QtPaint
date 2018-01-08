#pragma once

#include "PaintScene.h"
#include <QtCore/QObject>
#include <QtGui/QtGui>
#include <QtWidgets/QGraphicsItem>

class Tool : public QObject
{
  Q_OBJECT

public:
  Tool(QObject *parent, PaintScene * scene);

  Tool() {};

  virtual QGraphicsItem* drawShape(QPointF, QPointF) = 0;

  ~Tool();
protected:
  PaintScene * mScene;
};
