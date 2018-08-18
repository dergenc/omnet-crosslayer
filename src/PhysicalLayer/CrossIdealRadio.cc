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

#include "CrossIdealRadio.h"
#include "../Message/CrossLayerMsg_m.h"

using inet::INITSTAGE_LOCAL;
using inet::CrossPhyMsg;

Define_Module(CrossIdealRadio);

CrossIdealRadio::CrossIdealRadio():Radio() {
    // TODO Auto-generated constructor stub
}

CrossIdealRadio::~CrossIdealRadio() {
    // TODO Auto-generated destructor stub
}

void CrossIdealRadio::initialize(int stage)
{
	Radio::initialize(stage);
    if (stage == INITSTAGE_LOCAL) {
        crossInGate = gate("crossIn");
        crossOutGate = gate("crossOut");
    }
}

void CrossIdealRadio::handleMessage(cMessage *msg) {
    // Handling incoming packets

    if(msg->getArrivalGate() == crossInGate) {
        // Packets coming from management layer
        handleCrossLayerMessage(msg);
    } else {
        // Standard packets
        Radio::handleMessage(msg);
    }
}

void CrossIdealRadio::handleCrossLayerMessage(cMessage *msg) {
    // Handling packet coming from management layer

    CrossPhyMsg* cross_msg = ((CrossPhyMsg*) msg);
    int type = cross_msg->getM_type();

    if(type == inet::PHY_GET_SELF) {
        EV << "CrossIdealRadio: Packet came from management layer." << endl;
    }
    sendCrossLayerMessage();
    delete msg;
}

void CrossIdealRadio::sendCrossLayerMessage() {
    // Sending packet to management layer

    CrossPhyMsg* cross_msg = new CrossPhyMsg("PHY_CROSSLAYER");
    send(cross_msg, crossOutGate);
}

