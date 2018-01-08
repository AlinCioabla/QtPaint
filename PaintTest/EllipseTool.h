#pragma once

#include "PaintScene.h"
#include "Tool.h"
#include <QtCore/QObject>
#include <QtGui/QtGui>
#include <QtWidgets/QGraphicsItem>

class EllipseTool : public Tool
{
  Q_OBJECT

public:
  EllipseTool(QObject *parent, PaintScene * scene);

  QGraphicsItem* drawShape(QPointF, QPointF) override;

  ~EllipseTool();
};
