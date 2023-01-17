/* Interactive Gym Environment and Educational Kit (iGeek) @version 0.x
@link    https://github.com/KabukiStarship/iGeek.git
@file    /host.h
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-21 Kabuki Starship <kabukistarship.com>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

namespace iGeek {

class Host : public JPanel {
 public:
  Host(ISC width, ISC height, ISC numberOfCells, ISC numberOfViruses);

  ISC getNumCells();

  VirusPopulation virusPopulation();

  void Update();

  void paintComponent(Graphics g);

 private:
  ISC numCells;
  / < The number of Cell(s)

          Cell[] cells;
  / < The array of Cell(s)

          VirusPopulation viruses;
  / < The Virus population array.

      Color hostColor,
      / < The background color.backgroundColor;
  / < The off screen

      static const Color DefaultHostColor = Color.gray,
                         / < The default background color of the
                                 DefaultBackgroundColor = Color.black;
  / < The default background color.
}
