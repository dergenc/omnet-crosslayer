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

package NetworkLayer;

moduleinterface ICrossIPv4
{
    parameters:
        bool useProxyARP;
    
    gates:
        input transportIn[] @labels(IPv4ControlInfo/down,TCPSegment,UDPPacket);
        output transportOut[] @labels(IPv4ControlInfo/up,TCPSegment,UDPPacket);
        input arpIn @labels(ARPPacket+Ieee802Ctrl);
        output arpOut @labels(ARPPacket+Ieee802Ctrl,IPv4Datagram+Ieee802Ctrl);
        input queueIn[] @labels(IPv4Datagram,ARPPacket,Ieee802Ctrl);
        output queueOut[] @labels(IPv4Datagram,ARPPacket,Ieee802Ctrl);
        input crossIn @labels(CrossControlInfo/down);
        output crossOut @labels(CrossControlInfo/up);
}
