/* Interactive Gym Environment and Educational Kit (iGeek) @version 0.x
@link    https://github.com/KabukiStarship/iGeek.git
@file    /bezier.inl
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2015-2023 Kabuki Starship <kabukistarship.com>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include <_Config.h>

#include "bezier.h"

namespace _ {

BezierCurve::BezierCurve(FPD x_points[], FPD y_points[], ISC point_count) {
  DASSERT(y_points != null) : "Error creating BezierCurve. xPoings is null.";
  DASSERT(y_points != null) : "Error creating BezierCurve. y_points is null.";

  ISC tempX = x_points.length;

  DASSERT(tempX != point_count)
      : "Error creating BezierCurve. point_count doesn't match the length of "
        "the point arrays.";

  if (y_points == null || x_points == null || tempX != y_points.length ||
      tempX != point_count) {
    numPoints = 4;

    xpoints = new FPD[4];
    ypoints = new FPD[4];

    xpoints[0] = 0;
    ypoints[0] = 0;
    xpoints[1] = 0;
    ypoints[1] = 1;
    xpoints[2] = 1;
    ypoints[2] = -1;
    xpoints[3] = 1;
    ypoints[3] = 0;
  } else {
    numPoints = point_count;
    xpoints = new FPD[point_count];
    ypoints = new FPD[point_count];

    for (ISC i = 0; i < point_count; i++) {
      xpoints[i] = x_points[i];
      ypoints[i] = y_points[i];
    }
  }
}

BezierCurve::BezierCurve(FPD x0, FPD y0, FPD x1, FPD y1, FPD x2, FPD y2, FPD x3,
                         FPD y3) {
  numPoints = 4;
  xpoints = new FPD[4];
  ypoints = new FPD[4];

  xpoints[0] = x0;
  ypoints[0] = y0;
  xpoints[1] = x1;
  ypoints[1] = y1;
  xpoints[2] = x2;
  ypoints[2] = y2;
  xpoints[3] = x3;
  ypoints[3] = y3;
}

BezierCurve::BezierCurve(BezierCurve initState) {
  DASSERT(initState != null)
      : "Error creating BezierCurve using copy constructor. Input was null.";

  if (initState != null) {
    numPoints = 4;

    xpoints = new FPD[4];
    ypoints = new FPD[4];

    xpoints[0] = 0;
    ypoints[0] = 0;
    xpoints[1] = 0;
    ypoints[1] = 1;
    xpoints[2] = 1;
    ypoints[2] = -1;
    xpoints[3] = 1;
    ypoints[3] = 0;
  } else {
    numPoints = initState.numPoints;

    xpoints = new FPD[numPoints];
    ypoints = new FPD[numPoints];

    for (ISC i = 0; i < numPoints; i++) {
      xpoints[i] = initState.xpoints[i];
      ypoints[i] = initState.ypoints[i];
    }
  }
}

Point2D BezierCurve::getPoint(FPD t) {
  FPD x = 0,                        //< The x position to return.
      y = 0,                        //< The y position to return.
      factn = factoral(numPoints);  //< Local copy of n!.

  ISC n = numPoints;  //< Local copy of numPoints as a FPD.

  for (ISC i = 0; i <= n; i++) {
    FPD b = factn /
            (factoral(i) * factoral(n - i)),  //< Calculate binomial coefficient
        k = Math.pow(1 - t, n - i) * Math.pow(t, i);  //< Calculate powers

    // Add weighted points to totals
    x += b * k * xpoints[i];
    y += b * k * ypoints[i];
  }

  return new Point2D.Double(x, y);
}

static ISC BezierCurve::factoral(ISC value) {
  // return special case
  if (value == 0) return 1;

  if (value < 0) value *= -1;

  // Calculate factoral of value

  ISC total = value;
  while (--value > 1) total *= value;

  return total;
}

ISC BezierCurve::getNumPoints() { return numPoints; }

AString BezierCurve::ToString() {
  AString returnString = new AString("numPoints = " + numPoints + "\n");

  for (ISC i = 0; i < numPoints; i++) {
    returnString += ("x[" + i + "] = " + xpoints[i] + ", y[" + i +
                     "] = " + ypoints[i] + "\n");
  }
  returnString += ("\n");

  return returnString;
}
}  //< namespace _
}  //< namespace kabuki
