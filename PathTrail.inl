/* Interactive Gym Environment and Educational Kit (iGeek) @version 0.x
@link    https://github.com/KabukiStarship/iGeek.git
@file    /pathtrail.cc.inl
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-21 Kabuki Starship <kabukistarship.com>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include <_Config.h>

#include "pathtrail.h"

namespace _ {

PathTrail::PathTrail() {
  trailColor = DefaultTrailColor;
  maxNumPoints = DefaultMaxNumPoints;

  Initialize();
}

PathTrail::PathTrail(Color thisTrailColor) {
  if (thisTrailColor == null)
    trailColor = DefaultTrailColor;
  else
    trailColor = thisTrailColor;

  maxNumPoints = DefaultMaxNumPoints;

  Initialize();
}

PathTrail::PathTrail(Color thisTrailColor, ISC thisMaxNumPoints) {
  if (thisTrailColor == null)
    trailColor = DefaultTrailColor;
  else
    trailColor = thisTrailColor;

  if (thisMaxNumPoints < 0)
    maxNumPoints = DefaultMaxNumPoints;
  else
    maxNumPoints = thisMaxNumPoints;

  Initialize();
}

void PathTrail::Initialize() {
  startPoint = stopPoint = numPoints = 0;

  xpoints = new ISC[maxNumPoints];
  ypoints = new ISC[maxNumPoints];
}

void PathTrail::setTrailColor(Color newColor) {
  if (newColor != null) trailColor = newColor;
}

Color PathTrail::getTrailColor() { return trailColor; }

void PathTrail::draw(Graphics g) {
  // Print (ToString ());
  g.setColor(trailColor);

  for (ISC i = startPoint; i < stopPoint - 1; ++i) {
    if (i >= maxNumPoints) i = 0;

    g.drawLine(xpoints[i], ypoints[i], xpoints[i + 1], ypoints[i + 1]);
  }
  for (ISC i = 0; i <= stopPoint - 2; ++i) {
    g.drawLine(xpoints[i], ypoints[i], xpoints[i + 1], ypoints[i + 1]);
  }
}

void PathTrail::addPoint(ISC x, ISC y) {
  // Print ("\nAdding point { x = " + x + ", y = " + y + " }\n");

  if (numPoints < maxNumPoints) ++numPoints;

  // This is a circular que. This means that when we add at first, the stopIndex
  // is going to increment until we hit the maxNumPoints, then the startIndex
  // and stopIndex will increment and loop around such that startIndex =
  // stopIndex + 1.

  xpoints[stopPoint] = x;
  ypoints[stopPoint] = y;

  if (++stopPoint >= maxNumPoints) stopPoint = 0;

  if (stopPoint == startPoint) startPoint++;

  if (startPoint >= maxNumPoints) startPoint = 0;

  // Print (ToString ());
}

AString PathTrail::ToString() {
  AString returnString = "PathTrail: numPoints = " + numPoints +
                         ", startPoint = " + startPoint +
                         ", stopPoint = " + stopPoint + "\n";

  for (ISC i = 0; i < numPoints; i++)
    returnString += i + ".) x = " + xpoints[i] + ", y = " + ypoints[i] + "\n";

  return returnString;
}

}  //< namespace _
}
