#pragma once
#include "If1Resource.h"

#include <QObject>
#include "BaseDocument.h"


#include "MainData.h"

class MainDocument : public BaseDocument
{
    Q_OBJECT
public:
    explicit MainDocument(QObject *parent = nullptr);

public:
    const MainData &data() const;
    void setData(const MainData &newData);

public:
    virtual DomStatus parseElements() override;


private:
    MainData mData;
};

