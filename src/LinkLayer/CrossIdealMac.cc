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

#include "CrossIdealMac.h"
#include "../Message/CrossLayerMsg_m.h"
#include "inet/linklayer/ideal/IdealMacFrame_m.h"
#include <string>

using inet::IdealMacFrame;
using inet::INITSTAGE_LOCAL;
using inet::CrossLinkMsg;
using inet::CrossSelfMsg;

CrossIdealMac::CrossIdealMac() {
    // TODO Auto-generated constructor stub
}

CrossIdealMac::~CrossIdealMac() {
    // TODO Auto-generated destructor stub
}

Define_Module(CrossIdealMac);

void CrossIdealMac::initialize(int stage) {
    IdealMac::initialize(stage);
    if (stage == INITSTAGE_LOCAL) {
        crossInGate = gate("crossIn");
        crossOutGate = gate("crossOut");
    }
}

void CrossIdealMac::handleMessage(cMessage *msg) {
    // Handling incoming packets

    if (msg->getArrivalGate() == crossInGate) {
        // Packets coming from management layer
        handleCrossLayerMessage(msg);
    } else {
        // Standard MAC packets
        IdealMac::handleMessage(msg);
    }
}

void CrossIdealMac::handleCrossLayerMessage(cMessage *msg) {
    // Handling packet coming from management layer

    CrossLinkMsg* cross_msg = ((CrossLinkMsg*) msg);
    int type = cross_msg->getM_type();

    if(type == inet::LINK_GET_SELF) {
        EV << "CrossIdealMac: Packet came from management layer." << endl;
    }

    sendCrossLayerMessage();
    delete msg;
}

void CrossIdealMac::sendCrossLayerMessage() {
    // Sending packet to management layer

    CrossLinkMsg *cross_msg = new inet::CrossLinkMsg("LINK_CROSSLAYER");
    send(cross_msg, "crossOut");
}

bool CrossIdealMac::dropFrameNotForUs(IdealMacFrame *frame) {
    // Taken from IdealMac to remove dropPkNotForUsSignal emit(), it gives an strange error

    if (frame->getDest().equals(address))
        return false;

    if (frame->getDest().isBroadcast())
        return false;

    if (promiscuous || frame->getDest().isMulticast())
        return false;

    EV << "Frame `" << frame->getName() << "' not destined to us, discarding\n";
    //emit(dropPkNotForUsSignal, frame);

    delete frame;
    return true;
}
