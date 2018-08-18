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
package Node;

import ManagementLayer.IManagementLayer;
import Node.CrossWirelessHost;

module AdhocNode extends CrossWirelessHost
{
    parameters:
        @display("i=device/cellphone");
        wlan[*].mgmtType = default("Ieee80211MgmtAdhoc");  // use adhoc management
        forwarding = default(true);
        string crossType = default("ManagementLayer");
       
    submodules:
        cross: <crossType> like IManagementLayer {
            @display("p=527,287");
        }
    connections allowunconnected:
        cross.networkOut --> networkLayer.crossIn;
        networkLayer.crossOut --> cross.networkIn;
        
        cross.transOut --> udp.crossIn;
        udp.crossOut --> cross.transIn;
            
        for i=0..sizeof(radioIn)-1 {
            cross.linkOut++ --> wlan[i].XmacIn;
       		wlan[i].XmacOut --> cross.linkIn++;
       		
       		cross.phyOut++ --> wlan[i].XphyIn;
       		wlan[i].XphyOut --> cross.phyIn++;
        }
        
        cross.appOut --> udpApp[0].crossIn;
   		udpApp[0].crossOut --> cross.appIn;   
   		
   		if numUdpApps > 1 {
   		    cross.dataOut --> udpApp[1].crossIn;
   			udpApp[1].crossOut --> cross.dataIn;  
   		}
   		       
}
