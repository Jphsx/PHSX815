
class individual{
	private:
	//possible states of individual
	bool susceptible;
	bool exposed;
	bool infectious;
	bool immune;
	//exposed and infectiousDays=0 -> immune
	//immune -> susceptible = false
	//exposed -> susceptible = false
	//infectiousDays =0  -> infectious = false

	//position on sphere
	double r;
	double theta;
	double phi;

	//movement speed (max angular displacement per day)
	double speed;

	//countdown of days of infectiousness after exposure
	double infectiousDays;

	public:
	individual(double radius, double polar, double azimuth);
	
	//state changing functions
	void setR(double radius);
	void setTheta(double polar);
	void setPhi(double azimuth);
	void setPosition(double radius, double polar, double azimuth);
	void setSpeed(double omega);

	void setInfectiousDays(double days);
	void setSusceptible(bool state);
	void setExposed(bool state);
	void setInfectious(bool state);
	void setImmune(bool state);

	void decreaseInfectiousDays();
	void updateStatuses();

	
	//state checking functions
	double getR();
	double getTheta();
	double getPhi();
	double getSpeed();

	bool isSusceptible();
	bool isExposed();
	bool isInfectious();
	bool isImmune();



	

	

	
};
