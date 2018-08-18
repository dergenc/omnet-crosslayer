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

#ifndef MANAGEMENTLAYER_H_
#define MANAGEMENTLAYER_H_

#include <omnetpp.h>

using namespace omnetpp;
using namespace std;

class ManagementLayer : public cSimpleModule
{
	protected:
        cGate *networkInGate = nullptr;
        cGate *networkOutGate = nullptr;
        cGate *transInGate = nullptr;
        cGate *transOutGate = nullptr;
        cGate *appInGate = nullptr;
        cGate *appOutGate = nullptr;
        cGate *dataInGate = nullptr;
        cGate *dataOutGate = nullptr;

        double tickPeriod;

		virtual void initialize() override;
		virtual void handleMessage(cMessage *msg) override;
        void sendInfo();
        void sendIndicator(int type, float delay);

	public:
		ManagementLayer();
		virtual ~ManagementLayer();
		virtual void finish() override;
};

#endif /* MANAGEMENTLAYER_H_ */
