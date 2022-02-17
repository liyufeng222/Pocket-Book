#ifndef SNAPSHOTINTERFACE_H
#define SNAPSHOTINTERFACE_H
#include "snapshot.h"


class SnapshotInterface
{
public:
    // this function will return a snapshot of the object's current state
    virtual SnapShot& getSnapshot() = 0;

    // this function will apply a snapshot to the object.
    //This will revert the object back to the state that has been recorded in the snapshot
    virtual void applySnapshot(const SnapShot& snapshot) = 0;
};

#endif // SNAPSHOTINTERFACE_H
