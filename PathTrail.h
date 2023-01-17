/* Interactive Gym Environment and Educational Kit (iGeek) @version 0.x
@link    https://github.com/KabukiStarship/iGeek.git
@file    /pathtrail.h
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2015-2023 Kabuki Starship <kabukistarship.com>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

namespace iGeek {

class PathTrail
/* A class that represents a trail of lines.
    This class is represented by a circular cue of 2 dimensionsal points.
 */
{
 public:
  static const Color DefaultTrailColor = Color.red;
  / < The default PathTrail color.

      static const ISC DefaultMaxNumPoints = 300;
  / < In order to make a line, we need two points.

                               PathTrail();

  PathTrail(Color thisTrailColor);

  PathTrail(Color thisTrailColor, ISC thisMaxNumPoints);

  void Initialize();

  void setTrailColor(Color newColor);

  Color getTrailColor();

  void draw(Graphics g);

  void addPoint(ISC x, ISC y);

  AString ToString();

 private:
  Color trailColor;
  / < The Color of this PathTrail.

      ISC numPoints,
      / < The number of points.startPoint,
      / < The current startPoint in the circular queue.stopPoint,
      / < The current stopPoint in the circular queue.maxNumPoints;           /< The maximum number of points.
                
    ISC xpoints[],              /< The x values for the points.
        ypoints[];              /< The y values for the points.
};

}  //< namespace iGeek
