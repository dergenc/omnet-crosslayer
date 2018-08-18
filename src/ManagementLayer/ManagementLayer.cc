// Implementation for management layer

#include "ManagementLayer.h"
#include "../Message/CrossLayerMsg_m.h"

using std::ostream;
using inet::CrossSelfMsg;
using inet::CrossLinkMsg;
using inet::CrossTransMsg;
using inet::CrossLayerMsg;
using inet::CrossAppMsg;
using inet::CrossNetMsg;
using inet::CrossPhyMsg;

Define_Module(ManagementLayer);

ManagementLayer::ManagementLayer()
{
    EV << "ManagementLayer created." << endl;
}

ManagementLayer:: ~ManagementLayer()
{
    EV << "ManagementLayer destroyed." << endl;
}

void ManagementLayer::initialize() {
    // Initialize gates and periodic messages

    networkInGate = gate("networkIn");
    networkOutGate = gate("networkOut");
    transInGate = gate("transIn");
    transOutGate = gate("transOut");
    appInGate = gate("appIn");
    appOutGate = gate("appOut");
    dataInGate = gate("dataIn");
    dataOutGate = gate("dataOut");

    tickPeriod = par("tickPeriod");

    sendIndicator(inet::CHECK_TICK, tickPeriod);

    EV_INFO << "ManagementLayer initiated successfully." << endl;
}

void ManagementLayer::handleMessage(cMessage *msg) {
    // Handle incoming packets from other layers

    if(!(msg->isSelfMessage())) {
        if(msg->getArrivalGate() == transInGate) {
            // Packet from transport layer
            CrossTransMsg* cross_msg = ((CrossTransMsg*) msg);
        } else if(msg->getArrivalGate() == networkInGate) {
            // Packet from network layer
            CrossNetMsg* cross_msg = ((CrossNetMsg*) msg);
        } else if(msg->getArrivalGate()->isName("phyIn")) {
            // Packet from physical layer
            CrossPhyMsg* cross_msg = ((CrossPhyMsg*) msg);
        } else if(msg->getArrivalGate()->isName("linkIn")) {
            // Packet from link layer
            CrossLinkMsg* cross_msg = ((CrossLinkMsg*) msg);
        } else if(msg->getArrivalGate() == appInGate){
            // Packet from application layer
            CrossAppMsg* cross_msg = ((CrossAppMsg*) msg);
        }
    } else {
        // Periodically send packets to other layers
        CrossSelfMsg* cross_msg = ((CrossSelfMsg*) msg);
        sendInfo();
        sendIndicator(inet::CHECK_TICK, tickPeriod);
    }

    delete msg;
}

void ManagementLayer::sendIndicator(int type, float delay) {
    // Function wrap-up to trigger periodic actions

	CrossSelfMsg* packet = new CrossSelfMsg("CROSS_LAYER_SELF_MESSAGE");
	packet->setM_type(type);
	scheduleAt(simTime() + delay, packet);
}

void ManagementLayer::sendInfo() {
    // Example packet sending to other layers.
    // Message definitions are in Message package

    CrossAppMsg *udp_packet = new CrossAppMsg("CROSS_LAYER_SEND_MESSAGE");
    udp_packet->setM_type(inet::APP_GET_SELF);
    send(udp_packet, appOutGate);

    CrossTransMsg *trans_packet = new CrossTransMsg("CROSS_LAYER_SEND_MESSAGE");
    trans_packet->setM_type(inet::TRANS_GET_SELF);
    send(trans_packet, transOutGate);

    CrossNetMsg *net_packet = new CrossNetMsg("CROSS_LAYER_SEND_MESSAGE");
    net_packet->setM_type(inet::NET_GET_SELF);
    send(net_packet, networkOutGate);

    CrossLinkMsg *link_packet = new CrossLinkMsg("CROSS_LAYER_SEND_MESSAGE");
    link_packet->setM_type(inet::LINK_GET_SELF);
    send(link_packet, "linkOut", 0);

    CrossPhyMsg *phy_packet = new CrossPhyMsg("CROSS_LAYER_SEND_MESSAGE");
    phy_packet->setM_type(inet::PHY_GET_SELF);
    send(phy_packet, "phyOut", 0);
}

void ManagementLayer::finish() {
    // Signal emitting, manual garbage collection etc. performed here
}
