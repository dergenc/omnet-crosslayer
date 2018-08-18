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

#include "CrossUDP.h"
#include "../../Message/CrossLayerMsg_m.h"

using inet::INITSTAGE_LOCAL;
using inet::CrossTransMsg;

CrossUDP::CrossUDP(): UDP() {
    // TODO Auto-generated constructor stub
}

Define_Module(CrossUDP);

CrossUDP::~CrossUDP() {
    // TODO Auto-generated destructor stub
}

void CrossUDP::initialize(int stage) {
    UDP::initialize(stage);
    if (stage == INITSTAGE_LOCAL) {
        crossInGate = gate("crossIn");
        crossOutGate = gate("crossOut");
    }
}

void CrossUDP::handleMessage(cMessage *msg) {
    // Handling incoming packets

    if(msg->getArrivalGate() == crossInGate) {
        // Packets coming from management layer
        handleCrossLayerMessage(msg);
    } else {
        // Standard packets
        UDP::handleMessage(msg);
    }
}

void CrossUDP::handleCrossLayerMessage(cMessage *msg) {
    // Handling packet coming from management layer

    CrossTransMsg* cross_msg = ((CrossTransMsg*) msg);
    int type = cross_msg->getM_type();

    if(type == inet::TRANS_GET_SELF) {
        EV << "CrossudP: Packet came from management layer." << endl;
    }
    sendCrossLayerMessage();
    delete msg;
}

void CrossUDP::sendCrossLayerMessage() {
    // Sending packet to management layer

    CrossTransMsg* cross_msg = new CrossTransMsg("TRANS_CROSSLAYER");
    send(cross_msg, crossOutGate);
}

