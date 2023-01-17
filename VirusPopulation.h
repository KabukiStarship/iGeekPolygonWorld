/* Interactive Gym Environment and Educational Kit (iGeek) @version 0.x
@link    https://github.com/KabukiStarship/iGeek.git
@file    /VirusPopulation.h
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-21 Kabuki Starship <kabukistarship.com>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "Host.h"
#include "Virus.h"

namespace iGeek {

class VirusPopulation {
  static const ISC DefaultPopulationSize = 100;

  /* Constuctor */
  VirusPopulation(Host thisHost);

  /* Adds the virus to the population. */
  void addVirus(Virus virus);

  /* Returns the virus at the specified index. */
  Virus getVirus(ISC index);

  /* Selects a random virus from the population. */
  ISC selectRandomVirus();

  /* Function returns a value greater that -1 if this population contains
  thisGeneticPolygon.
  @return Returns -1 if the population doesn't contain thisGeneticPolygon.
  Else it will return the index of the Virus. */
  ISC contains(GeneticPolygon thisGeneticPolygon);

  /* Function that selects the virus  */
  ISC selectVirus(ISC x, ISC y);

  /* Returns the number of viruses. */
  ISC VirusCount();

  /* Updates the virus population with the new. */
  void Update();

  void draw(Graphics g);

  void BoxCollidingViruses(Graphics g);

  void BoxTwoViruses(Graphics g, Virus a, Virus b);

 private:
  ISC numViruses;   //< The number of Viruses.
  Virus[] viruses;  //< The array of Virus.
  Host host;        //< A pointer to the Host this VirusPopulation lives on.
}
