#ifndef DROPOFCONTROLLER_H
#define DROPOFCONTROLLER_H
#define HEADERFILE_H

#include "Controller.h"
#include "Tag.h"
#include <math.h>
#include <random_numbers/random_numbers.h>

class DropOffController : virtual Controller
{
public:
  DropOffController();
  ~DropOffController();

  void Reset() override;
  Result DoWork() override;
  bool ShouldInterrupt() override;
  bool HasWork() override;

  bool IsChangingMode();
  void SetCenterLocation(Point center);
  void SetCurrentLocation(Point current);
  void SetTargetPickedUp();
  void SetBlockBlockingUltrasound(bool blockBlock);
  void SetTargetData(vector<Tag> tags);
  bool HasTarget() {return targetHeld;}

  float GetSpinner() {return spinner;}

  void UpdateData(vector<Tag> tags);

  void SetCurrentTimeInMilliSecs( long int time );

private:

  void ProcessData();

  //Constants

  const float cameraOffsetCorrection = 0.020; //meters
  const float centeringTurnRate = 0.25; //radians // unused
  const int centerTagThreshold = 8;
  const int lostCenterCutoff = 4; //seconds before giving up on drop off beacuse center cannot be seen anymore
  const float collectionPointVisualDistance = 0.5; //in meters // was 0.2
  const float initialSpinSize = 0.5; //in meters aka 10cm
  const float spinSizeIncrement = 1.0; //in meters // was 0.50
  const float searchVelocity = 0.15; //in meters per second
  const float dropDelay = 0.5; //delay in seconds for dropOff // unused



  //Instance Variables

  /*
     *  Timers and Accumulators
     */

  //keep track of progression around a circle when driving in a circle
  float spinner;

  //Timer for return code (dropping the cube in the center)- used for timerTimeElapsed
  long int returnTimer; // starts when rover starts the spin search

  //Time since last exceeding the tag threshold
  long int lastCenterTagThresholdTime;

  //Previous tag count
  int prevCount;

  int targetCollectedCount;
  int targetCountMax;
  random_numbers::RandomNumberGenerator* rng;


  /*
     *  Cached External Information
     */

  //Count of tags on the left and right, respectively
  int countLeft;
  int countRight;

  //Center and current locations as of the last call to setLocationData
  Point centerLocation;
  Point currentLocation;

  //Time since modeTimer was started, in seconds
  float timerTimeElapsed;

  //The amount over initialSpinSize we've gotten to
  float spinSizeIncrease;

  /*
     *  Flags
     */

  //Flag indicating that a target has been picked up and is held
  bool targetHeld;

  //Flag indicating that we're in the center
  bool reachedCollectionPoint;

  //Flag indicating that we're driving in a circle to find the nest
  bool circularCenterSearching;

  //Flag for when we are entering the center circle
  bool centerApproach;

  //we have seen enough central collection tags to be certain we are either in or driving towards the nest.
  bool seenEnoughCenterTags;

  //Flag to indicate a switch to precision driving
  bool isPrecisionDriving;

  //Flag to indicate that we're starting to follow waypoints
  bool startWaypoint;

  Result result;

  long int current_time;

  bool interrupt = false;
  bool precisionInterrupt = false;
  bool finalInterrupt = false;
  bool first_center = true;


  bool startSpinSearchTimer = false;
  long int spinSearchStartTime;
  float spinDirection = 1;
  bool lostCenter = false;

  long int  timeWithoutSeeingCenterTags;
  bool timerStarted = false;
  long int timeStart;
  bool centerSeen;
  long int dropoffTimeStart;

};
#endif // end header define
