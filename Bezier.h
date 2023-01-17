/* Interactive Gym Environment and Educational Kit (iGeek) @version 0.x
@link    https://github.com/KabukiStarship/iGeek.git
@file    /bezier.h
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2015-2023 Kabuki Starship <kabukistarship.com>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once

namespace iGeek {

/* A fourth order BezierCurve.
 */
class BezierCurve {
 public:
  static const ISC DefaultNumPoints = 4;

  ISC numPoints;

  FPD *xpoints,  //< An array of the
      *ypoints;

  /* Constructor initializes curve with the given points.
  @warning the length of x_points and y_points must equal point_count or curve
  will not be created correctly.
  */
  BezierCurve(FPD x_points[], FPD y_points[], ISC point_count);

  /* Constructor initializes curve with the given points.
   */
  BezierCurve(FPD x0, FPD y0, FPD x1, FPD y1, FPD x2, FPD y2, FPD x3, FPD y3) {
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

  /* Copy constructor initializes curve with the given points.
   */
  BezierCurve(BezierCurve initState);

  / Returns a Point2D along the path of the of curve at time t.Point2D getPoint(
        FPD t);

  static ISC factoral(ISC value);

  ISC getNumPoints();

  AString ToString();
};

}  //< namespace iGeek
