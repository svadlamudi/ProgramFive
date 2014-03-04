#ifndef _NODE_H
#define _NODE_H

#include <cstdlib>
#include <math.h>
#include <string>
#include <vector>
#include "LinkListPacket.h"

using namespace std;

class Node {
	public:
		// Constructor
		Node(int id = -1, int xCoord = -1, int yCoord = -1, LinkListPacket queue = *new LinkListPacket());

		// Accessors and Mutators
		int getId() const;
		string getNodeType() const;
		int getXCoord() const;
		int getYCoord() const;
		int getDirection() const;
		int getStartTime() const;
		int getSendNum() const;
		double getSumDelayTimeFCFS() const;
		double getSumDelayTimePQ() const;
		double getSumVarianceTimeFCFS() const;
		double getSumVarianceTimePQ() const;
		int getSendSize() const;
		vector<Node*> getSendRoute() const;
		Packet* getCurrentPacket();
		LinkListPacket getQueue();
		LinkListPacket getPQSmall();
		LinkListPacket getPQMedium();
		LinkListPacket getPQLarge();

		void setId(int id);
		void setNodeType(string nodeType);
		void setXCoord(int xCoord);
		void setYCoord(int yCoord);
		void setDirection(int direction);
		void setStartTime(int startTime);
		void setSendNum(int sendNum);
		void setSumDelayTimeFCFS(double sumDelayTimeFCFS);
		void setSumDelayTimePQ(double sumDelayTimePQ);
		void setSendSize(int sendSize);
		void setSendRoute(vector<Node*> sendRoute);
		void setCurrentPacket(Packet *currentPacket);
		void setQueue(LinkListPacket queue);
		void setPQSmall(LinkListPacket pQSmall);
		void setPQMedium(LinkListPacket pQMedium);
		void setPQLarge(LinkListPacket pQLarge);

		// Object Functions
		double propogationTime(Node recieveNode);
		void moveNode(vector<Node> nodeVector, int length, int width);
		void nodeHop(int length, int width);
		bool collisionCheck(vector<Node> nodeVector);
		void beginSimulation(int TIME, int& numPacketReceived, vector<Node> nodeVector, FILE *output);
		void beginSimulationPQ(int TIME, int& numPacketReceived, vector<Node> nodeVector, FILE *output);
		void calculateVarianceFCFS();
		void calculateVariancePQ();
		
	private:
		// All Node Use
		int id;
		string nodeType;
		int xCoord;
		int yCoord;
		int direction;
		Packet *currentPacket;
		Packet *currentPacketPQ;

		// All Source Node Use
		vector<Node*> sendRoute;
		int startTime;
		int sendSize;
		int sendNum;
		int sendNumPQ;

		// All Mule Node Use
		LinkListPacket queue;
		LinkListPacket pQSmall;
		LinkListPacket pQMedium;
		LinkListPacket pQLarge;
		
		// All Receiver Node Use
		double sumDelayTimeFCFS;
		double sumDelayTimePQ;
		double sumVarianceTimeFCFS;
		double sumVarianceTimePQ;
		vector<double> delayTimeFCFS;
		vector<double> delayTimePQ;
};

#endif

