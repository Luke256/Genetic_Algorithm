//
// GA.hpp v0.1.0
//
//  Created by Luke on 2021/01/26.
//

#pragma once
#include<Siv3D.hpp>

class Genetic_Algorithm{
private:
    
public:
    int32 NumAgents,Actions,Samples,MutationRate,RandomSample;
    Grid<double>Agents;
    Genetic_Algorithm(int32 NumAgents_,int32 Actions_,int32 Samples_=2,double MutationRate_=0.01,int32 RandomSample_=1);
    Array<double> reply(Array<double>rewards);
};
