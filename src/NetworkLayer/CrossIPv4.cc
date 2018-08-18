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

#include "CrossIPv4.h"
#include "../Message/CrossLayerMsg_m.h"

using inet::INITSTAGE_LOCAL;
using inet::CrossNetMsg;

CrossIPv4::CrossIPv4() {
	// TODO Auto-generated constructor stub

}

CrossIPv4::~CrossIPv4() {
	// TODO Auto-generated destructor stub
}

Define_Module(CrossIPv4);

void CrossIPv4::initialize(int stage)
{
	IPv4::initialize(stage);
    if (stage == INITSTAGE_LOCAL) {
        crossInGate = gate("crossIn");
        crossOutGate = gate("crossOut");
    }
}

void CrossIPv4::handleMessage(cMessage *msg) {
    // Handling incoming packets

    if (msg->getArrivalGate() == crossInGate) {
        // Packets coming from management layer
        handleCrossLayerMessage(msg);
    } else {
        // Standard IP packets
        inet::IPv4::handleMessage(msg);
    }
}

void CrossIPv4::handleCrossLayerMessage(cMessage *msg) {
    // Handling packet coming from management layer

	CrossNetMsg* cross_msg = ((CrossNetMsg*) msg);
    int type = cross_msg->getM_type();

    if(type == inet::NET_GET_SELF) {
        EV << "CrossIPv4: Packet came from management layer." << endl;
    }

    sendCrossLayerMessage();
    delete msg;
}

void CrossIPv4::sendCrossLayerMessage() {
    // Sending packet to management layer

    CrossNetMsg *cross_msg = new inet::CrossNetMsg("net_CROSSLAYER");
    send(cross_msg, "crossOut");
}
