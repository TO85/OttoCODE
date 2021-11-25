#pragma once
#include "IfObject.h"

#include <QtDebug>
#include <QtCore/QList>
#include <QtCore/QMetaType>

#include <eirType/SCRect.h>
#include <eirType/DetectRect.h>
#include <eirType/DetectRectMap.h>
#include <IfGeometry/FaceGeometry.h>

#include <eirBase/QtTypes.h>
#include <eirType/QQList.h>

#include "Quality.h"

class IFOBJECT_EXPORT ObjectResults
{
public:
    class IFOBJECT_EXPORT Item
    {
    public:
        typedef QQList<Item> List;
        typedef QMap<int, Item> Map;

    public:
        Item(const ObjectType otype=ObjectType::$null) : mType(otype) {;}
        Item(const ObjectType otype, const DetectRect firstResult) : mType(otype)
        { mIncludedResults.append(firstResult); }
        Item(const ObjectType otype, const DetectRect result, const DetectRectMap &included)
              : mType(otype), mResult(result), mIncludedResults(included) {;}
//        Item() = default;
//        Item(const Item &other) = default;
//        ~Item() = default;
//        Item &operator=(const Item &other) = default;

        ObjectType type() const { return mType; }
        DetectRect resultRect() const { return mResult; }
        int rank() const { return mRank; }
        DetectRectMap includedResults() const { return mIncludedResults; }

        bool isNull() const { return resultRect().isNull() || isIncludedEmpty(); }
        bool isRanked() const { return rank() != 0; }
        int includedRectCount() const { return mIncludedResults.count() ; }
        qreal distance() const { return mQuality.distance(); }
        unsigned quality() const { return mQuality.quality(); }
        int includedResultCount() const { return mIncludedResults.count() ; }
        bool isIncludedEmpty() const { return mIncludedResults.isEmpty(); }
        DetectRect firstIncluded() const { return mIncludedResults.first(); }
        QRectList includedQRectList() const;
        DetectRect unifiedDetectRect() const;
        QVariant toVariant() const;
        operator QVariant () const { return toVariant(); }
        DetectRect &resultRect() { return mResult; }

        void clear();
        void append(const DetectRect &rect) { mIncludedResults.append(rect); }
        void setResultRect(const DetectRect result) { mResult = result; }
        void setQualityDistance(const qreal distance) { mQuality.setDistance(distance); }
        void setRank(const int aRank) { mRank = aRank; }

    public: // static
        static Item fromVariant(const QVariant &vari);

    private:
        Item &it() { return *this; }
        Item it() const { return *this; }

    public: // debug
        QQStringList toDebugStrings() const;

    private:
        ObjectType mType=ObjectType::$null;
        DetectRect mResult;
        DetectRectMap mIncludedResults;
        int mRank=0;
        Quality mQuality;
    };

public:
    ObjectResults(const ObjectType otype=ObjectType::$null) : mType(otype) {;}
//    ObjectResults() = default;
//    ObjectResults(const ObjectResults &other) = default;
//    ~ObjectResults() = default;
//    ObjectResults &operator=(const ObjectResults &other) = default;

public: // access
    ObjectType type() const { return mType; }
    DetectRectMap orphans() const { return mOrphanRects; }
    Item &item(const int index) { return mItemMap[index] ;}
    Item item(const int index) const { return mItemMap[index]; }
    int maxScore() const { return mMaxScore; }
    Item::Map itemMap() const { return mItemMap; }
    Item::List itemList(const bool reversed=false) const;
    operator QVariant () const;

public: // status
    bool isEmpty() const { return mItemMap.isEmpty(); }
    bool notEmpty() const { return ! isEmpty(); }
    int itemCount() const { return mItemMap.count(); }
    Item firstItem() const { return notEmpty() ? mItemMap.first() : Item(); }
    Item rankItem(const int rank) const;
    DetectRectMap itemResults() const;

    void clearItems() { mItemMap.clear(); }
    void clearOrphans() { mOrphanRects.clear(); }
    void clear() { clearItems(), clearOrphans(); }
    void set(const ObjectResults &other);
    void setItem(const Item aItem) { mItemMap.insert(aItem.resultRect().score(), aItem); }
    void setItems(const Item::List aList);
    void setItemMap(const ObjectResults::Item::Map &aItemMap) { mItemMap = aItemMap; }
    void setMaxScore(int aScore) { mMaxScore = aScore; }
    void append(const Item &aItem) { mItemMap.insert(aItem.resultRect().score(), aItem); }
    void appendOrphan(const DetectRect dr) { mOrphanRects.append(dr); }
    void appendOrphan(const DetectRectList drl) { mOrphanRects.append(drl); }
    Item &at(const int index) { return mItemMap[index]; }

public: // static

private:
    ObjectResults &it() { return *this; }
    ObjectResults it() const { return *this; }

public: // debug
    QQStringList toDebugStrings() const;

private:
    ObjectType mType=ObjectType::$null;
    int mMaxScore;
    Item::Map mItemMap;
    DetectRectMap mOrphanRects;
};

typedef ObjectResults::Item ObjectResultItem;
Q_DECLARE_METATYPE(ObjectResultItem);
Q_DECLARE_METATYPE(ObjectResults);

extern IFOBJECT_EXPORT QDataStream &operator >> (QDataStream &ds, ObjectResults::Item &item);
extern IFOBJECT_EXPORT QDebug operator << (QDebug dbg, const ObjectResults::Item item);
extern IFOBJECT_EXPORT QDebug operator << (QDebug dbg, const ObjectResults &objres);
