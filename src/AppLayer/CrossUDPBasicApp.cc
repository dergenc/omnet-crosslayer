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

#include "CrossUDPBasicApp.h"

using namespace omnetpp;
using inet::L3Address;
using inet::INITSTAGE_LOCAL;
using inet::CrossAppMsg;


CrossUDPBasicApp::CrossUDPBasicApp() : UDPBasicApp() {
    // TODO Auto-generated constructor stub
}

Define_Module(CrossUDPBasicApp);

CrossUDPBasicApp::~CrossUDPBasicApp() {
    // TODO Auto-generated destructor stub
}

void CrossUDPBasicApp::initialize(int stage) {
	UDPBasicApp::initialize(stage);

    if (stage == INITSTAGE_LOCAL) {
        crossInGate = gate("crossIn");
        crossOutGate = gate("crossOut");
    }
}

void CrossUDPBasicApp::handleMessage(cMessage *msg) {
    // Handling incoming packets

    if(msg->getArrivalGate() == crossInGate) {
        // Packets coming from management layer
        handleCrossLayerMessage(msg);
    } else {
        // Standard UDP packets
        UDPBasicApp::handleMessage(msg);
    }
}

void CrossUDPBasicApp::handleCrossLayerMessage(cMessage *msg) {
    // Handling packet coming from management layer

    CrossAppMsg* cross_msg = ((CrossAppMsg*) msg);
    int type = cross_msg->getM_type();

    if(type == inet::APP_GET_SELF) {
        EV << "CrossUDPBasicApp: Packet came from management layer." << endl;
    }
    sendCrossLayerMessage();
    delete msg;
}


void CrossUDPBasicApp::sendCrossLayerMessage() {
    // Sending packet to management layer

    CrossAppMsg* cross_msg = new CrossAppMsg("UDP_CROSSLAYER");
    send(cross_msg, crossOutGate);
}

