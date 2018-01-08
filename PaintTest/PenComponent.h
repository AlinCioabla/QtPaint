#pragma once

#include <QtCore/QObject>

class PenComponent : public QObject
{
  Q_OBJECT

public:
    PenComponent(QObject *parent);
    ~PenComponent();
};
