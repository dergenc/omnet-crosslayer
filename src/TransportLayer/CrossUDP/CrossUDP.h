//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef CROSSUDP_CROSSUDP_H_
#define CROSSUDP_CROSSUDP_H_

#include "inet/transportlayer/udp/UDP.h"

class CrossUDP : public inet::UDP {

    public:
        CrossUDP();
        virtual ~CrossUDP();

    protected:
        cGate *crossInGate = nullptr;
        cGate *crossOutGate = nullptr;

        virtual void initialize(int stage) override;
        virtual void handleMessage(cMessage *msg) override;
        void handleCrossLayerMessage(cMessage *msg);
        void sendCrossLayerMessage();
};

#endif /* CROSSUDP_CROSSUDP_H_ */
