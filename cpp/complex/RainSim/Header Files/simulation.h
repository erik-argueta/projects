//
//  simulation.h
//  general-workspace
//
//  Created by Erik Argueta on 12/6/21.
//

#ifndef simulation_h
#define simulation_h


class Simulation {
public:
	Simulation();
	~Simulation();
	
	void setDimensions();
	void setChances();
	void confirmation();
	void print();
	void printDescription();
	void printCredits();
private:
	int length;
	int height;
	int chances;
};

#endif /* simulation_h */
