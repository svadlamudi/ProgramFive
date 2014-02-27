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
		int getId();
		string getNodeType();
		int getXCoord();
		int getYCoord();
		int getDirection();
		int getStartTime();
		int getSendNum();
		int getSendSize();
		vector<Node*> getSendRoute();
		Packet* getCurrentPacket();
		LinkListPacket getQueue();

		void setId(int id);
		void setNodeType(string nodeType);
		void setXCoord(int xCoord);
		void setYCoord(int yCoord);
		void setDirection(int direction);
		void setStartTime(int startTime);
		void setSendNum(int sendNum);
		void setSendSize(int sendSize);
		void setSendRoute(vector<Node*> sendRoute);
		void setCurrentPacket(Packet *currentPacket);
		void setQueue(LinkListPacket queue);

		// Object Functions
		double propogationTime(Node recieveNode);
		void moveNode(vector<Node> nodeVector, int length, int width);
		void nodeHop(int length, int width);
		bool collisionCheck(vector<Node> nodeVector);
		void beginSimulation(int TIME, int& numPacketReceived, FILE *output);
		
	private:
		int id;
		string nodeType;
		int xCoord;
		int yCoord;
		int direction;
		int startTime;
		int sendNum;
		int sendSize;
		vector<Node*> sendRoute;
		Packet *currentPacket;
		LinkListPacket queue;
};

#endif
