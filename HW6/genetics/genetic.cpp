#include "genetic.h"

void debugPrintTrip(cityTraversals* c){
	for(int i=0; i<c->getTrip().size(); i++){
		cout<<i<<" ("<<c->getTrip()[i]->getX()<<","<<c->getTrip()[i]->getY()<<") ";
	}
	cout<<endl<<endl;
}
void debugPrintTrip(vector<city*> c){
	cout<<"subset "<<endl;
	for(int i=0; i<c.size(); i++){
		cout<<i<<" ("<<c[i]->getX()<<","<<c[i]->getY()<<") ";
	}
	cout<<endl<<endl;
}
double getBest(population* p){
	double mincost = p->getPopulation()[0]->getTripCost();
	for(int i=1; i<p->getPopulation().size(); i++){
		if(p->getPopulation()[i]->getTripCost() < mincost){
			mincost = p->getPopulation()[i]->getTripCost();
		}
	}
	return mincost;	
}
int genetic::selectFittest(vector<cityTraversals*>& subSample){
	int fittestIndex = 0;
	double mincost = subSample[0]->getTripCost();
	for(int i=1; i<subSample.size(); i++){
		if( subSample[i]->getTripCost() < mincost ){
			mincost = subSample[i]->getTripCost();
			fittestIndex = i;
		}
	}
	return fittestIndex;
}
void genetic::mutate(cityTraversals*& candidate, RNGInt& gen, RNGgen& g){
	//generate 2 random indices and swap
	int randomIndex1 = gen(g);
	int randomIndex2 = gen(g);
	city* temp;
	temp = candidate->getTrip()[randomIndex1];
	candidate->getTrip()[randomIndex1] = candidate->getTrip()[randomIndex2];
	candidate->getTrip()[randomIndex2] = temp;

	
}
bool genetic::contains(vector<city*> set, city* c){
	for(int i=0; i<set.size(); i++){
		if( set[i]->getX() == c->getX() && set[i]->getY() == c->getY()) return true;
	}
	return false;
}
vector<city*> genetic::removeSubset(cityTraversals* set, vector<city*> subset){
	vector<city*> newsubset;
	bool containsflag =false;
	for(int i=0; i<set->getTrip().size(); i++){
		for(int j=0; j<subset.size(); j++){
			if( set->getTrip()[i]->getX() == subset[j]->getX() && set->getTrip()[i]->getY() == subset[j]->getY() ){
				 containsflag= true;
			}
		}
		if(containsflag == false ){
			city* c = new city(set->getTrip()[i]->getX(), set->getTrip()[i]->getY() );
			newsubset.push_back(c);
		}
		containsflag = false;
	}
	return newsubset;
	
}
cityTraversals* genetic::breed(cityTraversals* parent1, cityTraversals* parent2, RNGInt& gen, RNGgen& g){
	//select random continuous subset from parent, to place in child
	//cityTraversal* child;
	//vector<city*> childTrip[parent2->getTrip().size()];
	vector<city*> childTrip;
	//generate two unique random ints
	int randomIndex1 = gen(g);
	int randomIndex2 = gen(g);
	//never let them be the same
	while(randomIndex1 == randomIndex2){
		randomIndex2 = gen(g);
	}
	//make a temp vector to sort the indices
	vector<int> indices;
	if( randomIndex1 < randomIndex2){
		indices.push_back(randomIndex1);
		indices.push_back(randomIndex2);
	}
	else{
		indices.push_back(randomIndex2);
		indices.push_back(randomIndex1);
	}
	
	vector<city*> parent1Subset;
	for(int i=indices[0]; i<=indices[1]; i++){
		parent1Subset.push_back(parent1->getTrip()[i]);
	}
	vector<city*> parent2Subset = removeSubset(parent2, parent1Subset);

	//debugPrintTrip(parent1Subset);

	//debugPrintTrip(parent2Subset);

	//cout<<" PARENT 1 "<<endl;
	//debugPrintTrip(parent1);

	//cout<<" PARENT 2 "<<endl;
	//debugPrintTrip(parent2);

	//int subsetCounter = 0;
	//int parent2Counter = 0;
	/*for(int i=0; i<parent2->getTrip().size(); i++){
		if( i >= indices[0] && i <= indices[i] ){
			childTrip.push_back(parent1Subset[subsetCounter]);
			subsetCounter++;
		}
		else{
			while( contains(parent1Subset,parent2->getTrip()[parent2Counter])   ){
				parent2Counter++;
			 }
			childTrip.push_back(parent2->getTrip()[parent2Counter] );
		}
	}*/
	for(int i=0; i< indices[0]; i++){
		city* c = new city(parent2Subset[i]->getX(), parent2Subset[i]->getY());
		//childTrip[i] = c;
		childTrip.push_back(c);
	}
	for(int i=indices[0]; i<=indices[1]; i++){
		city* c = new city(parent1->getTrip()[i]->getX(), parent1->getTrip()[i]->getY());		
		//childTrip[i] = c;
		childTrip.push_back(c);
	}
	for(int i=indices[0]; i<parent2Subset.size(); i++){
		city* c = new city(parent2Subset[i]->getX(), parent2Subset[i]->getY());
		//childTrip[i] = c;
		childTrip.push_back(c);
	}
	
	cityTraversals* child = new cityTraversals(parent1->mastersize, childTrip);

		//debugPrintTrip(child);
		return child;
	

}
population* genetic::evolvePopulation(population* p, double sampleSize, RNGInt& gen, RNGgen& g, RNGInt& gen2){
	
	double mutationrate = 0.01;
	double popsize = p->getPopulation().size();
	double rand;
	population* newgeneration = new population(p->masterCityList);
	vector<cityTraversals*> p1;
	vector<cityTraversals*> p2;
	int fittest1;
	int fittest2;
	for(int i=0; i< p->getPopulation().size(); i++){
		p1 = p->getRandomSubSample(sampleSize,gen2,g);
		p2 = p->getRandomSubSample(sampleSize,gen2,g);
		//for(int j=0; j<p1.size(); j++){
			//cout<<p1.size()<<endl;
			//debugPrintTrip(p1[i]);
			/*for(int k=0; i<p1[j]->getTrip().size(); k++){
		cout<<"("<<p1[j]->getTrip()[k]->getX()<<","<<p1[j]->getTrip()[k]->getY()<<") ";
	}
	cout<<endl;*/
	//	}
		fittest1 = selectFittest(p1);
		fittest2 = selectFittest(p2);
		newgeneration->addTraversal(breed(p1[fittest1],p2[fittest2],gen,g));
		rand = (double) gen(g);
		if( rand/popsize <= mutationrate){
			mutate(newgeneration->getPopulation()[i],gen,g);
		}
	}

	return newgeneration;
	
	
}


void debugPrintPop(int numCities, int populationSize, population* p){
	for(int i=0; i<numCities; i++){
		for(int j=0; j<populationSize; j++){
			cout<< p->getPopulation()[j]->getTrip()[i]->getX()<< " "
				<<p->getPopulation()[j]->getTrip()[i]->getY() <<" | ";
		}
		cout<<endl;
	}
}
int main(){

	double samplesize = 20;
	cityio* io = new cityio("ch130.mydat");
	//primary population
	random_device rd;
  	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, io->getMasterList().size()-1);
	int populationSize = 75;
	uniform_int_distribution<> dist2(0,populationSize-1);
	

	population* p = new population(populationSize, dist,io->getMasterList(), gen);
	//debugPrintPop(io->getMasterList().size(), populationSize, p);
	genetic* g = new genetic();
	population* newgen = g->evolvePopulation(p,samplesize,dist,gen,dist2);

	population* testgen = g->evolvePopulation(p,samplesize,dist,gen,dist2);
	
	population* oldgen;
	delete p;
	//debugPrintPop(io->getMasterList().size(), populationSize, newgen);
	int generation = 1;
	//while(generation < 200){
	while( getBest(newgen) > 39500 ){
		oldgen = newgen;
		newgen = g->evolvePopulation(oldgen,10,dist,gen,dist2);
		delete oldgen;
		generation++;
		cout<< generation << " "<<getBest(newgen)<<endl;

	}
	cout<< "After "<<generation<<" generations, the best solution cost is "<<getBest(newgen)<<endl;
		//58 gens at pop
}
