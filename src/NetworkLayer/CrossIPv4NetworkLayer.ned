package NetworkLayer;

import inet.networklayer.contract.IARP;
import inet.networklayer.configurator.ipv4.IPv4NodeConfigurator;
import inet.networklayer.contract.INetworkLayer;
import inet.networklayer.ipv4.ICMP;
import inet.networklayer.ipv4.IIGMP;
import inet.networklayer.ipv4.ErrorHandling;

//
// Cross network layer of an IPv4 node.
// It is mostly extended using IPv4NetworkLayer.ned and some cross-layer modifications added

module CrossIPv4NetworkLayer like ICrossNetworkLayer
{
    parameters:
        bool proxyARP = default(true);
        string igmpType = default("IGMPv2");
        string arpType = default("ARP");
        string IPvType = default("CrossIPv4");
        string interfaceTableModule;
        string routingTableModule;
        *.interfaceTableModule = default(absPath(interfaceTableModule));
        *.routingTableModule = default(absPath(routingTableModule));
        *.arpModule = default(absPath(".arp"));
        *.icmpModule = default(absPath(".icmp"));
        arp.respondToProxyARP = proxyARP;
        @display("i=block/fork");
    gates:
        input ifIn[] @labels(INetworkDatagram);
        output ifOut[] @labels(INetworkDatagram);
        input transportIn[] @labels(IPv4ControlInfo/down);
        output transportOut[] @labels(IPv4ControlInfo/up);
        input pingIn[] @labels(PingPayload/down);
        output pingOut[] @labels(PingPayload/up);
        input igmpIn;
        output igmpOut;
        input crossIn;
        output crossOut;
    submodules:
        configurator: IPv4NodeConfigurator {
            @display("p=39,158");
        }
		ip: <IPvType> like ICrossIPv4  {
            parameters:
                useProxyARP = true; // as routes with unspecified next-hop addr are quite common
                @display("p=85,95;q=queue");
            gates:
                queueIn[sizeof(ifIn)];
                queueOut[sizeof(ifOut)];
        }
        arp: <arpType> like IARP {
            parameters:
                @display("p=165,120;q=pendingQueue;is=s");
        }
        icmp: ICMP {
            parameters:
                @display("p=165,70");
        }
        igmp: <igmpType> like IIGMP {
            parameters:
                @display("p=39,33");
        }
        errorHandling: ErrorHandling {
            parameters:
                @display("p=239,70");
        }

    connections allowunconnected:
        for i=0..sizeof(transportIn)-1 {
            transportIn[i] --> { @display("m=n"); } --> ip.transportIn++;
        }
        for i=0..sizeof(transportOut)-1 {
            ip.transportOut++ --> { @display("m=n"); } --> transportOut[i];
        }

        ip.transportOut++ --> icmp.localIn;
        ip.transportIn++ <-- icmp.sendOut;

        ip.transportOut++ --> igmp.ipIn;
        ip.transportIn++ <-- igmp.ipOut;
        
        // Control messages for cross-layer controller
        crossIn --> ip.crossIn;
        ip.crossOut --> crossOut ;

        for i=0..sizeof(pingOut)-1 {
            icmp.pingOut++ --> { @display("m=n"); } --> pingOut[i];
        }
        for i=0..sizeof(pingIn)-1 {
            icmp.pingIn++ <-- { @display("m=n"); } <-- pingIn[i];
        }

        icmp.errorOut --> errorHandling.in;

        ip.arpOut --> arp.netwIn;
        ip.arpIn <-- arp.netwOut;

        igmp.routerOut --> igmpOut;
        igmp.routerIn <-- igmpIn;

        for i=0..sizeof(ifIn)-1 {
            ip.queueIn[i] <-- { @display("m=s"); } <-- ifIn[i];
        }
        for i=0..sizeof(ifOut)-1 {
            ip.queueOut[i] --> { @display("m=s"); } --> ifOut[i];
        }
}

