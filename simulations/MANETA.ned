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

import Node.AdhocNode;

import inet.common.figures.DelegateSignalConfigurator;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import inet.node.inet.INetworkNode;
import inet.physicallayer.contract.packetlevel.IRadioMedium;
import inet.visualizer.contract.IIntegratedVisualizer;
import inet.common.lifecycle.LifecycleController;
import inet.common.scenario.ScenarioManager;

network MANETA
{
    parameters:
        string hostType = default("AdhocNode");
        string mediumType = default("IdealRadioMedium");
        int numHosts = default(5);
        bool isHybridRouting = default(true);
        
        @display("bgb=250,250;bgg=100,1,grey95");
        @figure[title](type=label; pos=0,-1; anchor=sw; color=darkblue);

    submodules:
        visualizer: <default("IntegratedCanvasVisualizer")> like IIntegratedVisualizer if hasVisualizer() {
            @display("p=950,100");
        }
        configurator: IPv4NetworkConfigurator {
            @display("p=950,175");
        }
        radioMedium: <mediumType> like IRadioMedium {
            @display("p=950,225");
        }
        figureHelper: DelegateSignalConfigurator {
            @display("p=950,300");
        }
       	lifecycleController: LifecycleController {
            @display("p=950,350");
        }
        host[numHosts]: <hostType> like INetworkNode {
        
        }
}

//##### (marker for doxygen)

