/***************************************************************************
 *   Copyright (C) 2016                                                    *
 *   by Fioratto Raffaele, Cardinale Claudio                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   As a special exception, if other files instantiate templates or use   *
 *   macros or inline functions from this file, or you compile this file   *
 *   and link it with other works to produce a work based on this file,    *
 *   this file does not by itself cause the resulting work to be covered   *
 *   by the GNU General Public License. However the source code for this   *
 *   file must still be made available in accordance with the GNU General  *
 *   Public License. This exception does not invalidate any other reasons  *
 *   why a work based on this file might be covered by the GNU General     *
 *   Public License.                                                       *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <http://www.gnu.org/licenses/>   *
 ***************************************************************************/

#ifndef LENGTHCALCULATOR_H
#define LENGTHCALCULATOR_H


class LengthCalculator {
public:
    LengthCalculator();
    float getLength(int acc, long long now);

private:
    void calculateLength(int period, float theta);
    float calculateTheta();
    int calculatePeriod();

private:
    const float ALPHA_ANGLE = 0.5; //low pass filter factor for angle
    const float ALPHA_LENGTH = 0.8; //low pass filter factor for length
    const float LENGTH_THRESHOLD = 0.1;
    const float ANGLE_THRESHOLD = 0.4; // 23°
    const int SCALE = 1;
    const float G = 9.81;

    float lastLength;
    bool decrementingY;
    float previousY;
    float minY;
    long long zeroTime;
    long long previousTime;
};

#endif /* LENGTHCALCULATOR_H */

