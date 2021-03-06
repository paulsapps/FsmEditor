#ifndef FSMGRAPHICSSCENE_H
#define FSMGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QUndoStack>

class FsmConnectionGraphicsItem;
class FsmStateGraphicsItem;

class FsmGraphicsScene : public QGraphicsScene
{
    //Q_OBJECT
public:
    FsmGraphicsScene(QObject* pParent, QUndoStack& undoStack);
    bool Open(QString fileName);
    bool Save(QString fileName);

    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* pEvent) override;

    virtual void mousePressEvent(QGraphicsSceneMouseEvent* pMouseEvent) override;

    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* pMouseEvent) override;

    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* pMouseEvent) override;

    void DeleteSelection();

//public slots:
    //void SelectionChanged();

    QUndoStack& GetUndoStack() { return mUndoStack; }
    FsmStateGraphicsItem* StateGraphicsItemById(quint32 id);

private:

    void DeleteAllSegments(FsmConnectionGraphicsItem* connection);
    static FsmConnectionGraphicsItem* GetStartingSegment(FsmConnectionGraphicsItem* pArbitarySegment);

    void SplitLine(FsmConnectionGraphicsItem* pLineToSplit, QPointF splitPos);

    QUndoStack& mUndoStack;
    FsmConnectionGraphicsItem* mInProgressConnection = nullptr;
};

#endif // FSMGRAPHICSSCENE_H
