#pragma once

#include "PaintScene.h"
#include "Tool.h"
#include <QtCore/QObject>
#include <QtGui/QtGui>
#include <QtWidgets/QGraphicsItem>

class PenTool : public Tool
{
  Q_OBJECT

public:
  PenTool(QObject *parent, PaintScene * scene);

  QGraphicsItem* drawShape(QPointF, QPointF) override;

  ~PenTool();
};
