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

#ifndef LINKLAYER_CROSSIDEALMAC_H_
#define LINKLAYER_CROSSIDEALMAC_H_

#include "inet/linklayer/ideal/IdealMac.h"
#include "inet/linklayer/ideal/IdealMacFrame_m.h"

using inet::IdealMacFrame;

class CrossIdealMac : public inet::IdealMac {

    public:
        CrossIdealMac();
        virtual ~CrossIdealMac();

    protected:
        cGate *crossInGate = nullptr;
        cGate *crossOutGate = nullptr;

        virtual void initialize(int) override;
        virtual void handleMessage(cMessage *msg) override;
        virtual bool dropFrameNotForUs(inet::IdealMacFrame *frame) override;

        void handleCrossLayerMessage(cMessage *msg);
        void sendCrossLayerMessage();
};

#endif /* LINKLAYER_CROSSIDEALMAC_H_ */
