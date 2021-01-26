//
// GA.cpp v0.1.0
//
//  Created by Luke on 2021/01/26.
//

#include "GA.hpp"
#include <Siv3D.hpp> // OpenSiv3D v0.4.3
#include <queue>

Genetic_Algorithm::Genetic_Algorithm(int32 NumAgents_,int32 Actions_,int32 Samples_,double MutationRate_,int32 RandomSample_):
NumAgents(NumAgents_),
Actions(Actions_),
Samples(Samples_),
MutationRate(MutationRate_),
RandomSample(RandomSample_)
{
    /*
     Numgents:個体数
     Actions:行動の種類数
     Samples:交配時に選ぶ個体数
     MutationRate:突然変異が起こる確率
     */
    Agents=Grid<double>(Actions,NumAgents);
    for(auto i:step(NumAgents)){
        for(auto j:step(Actions)){
            Agents[i][j]=Random();
        }
    }
}

Array<double> Genetic_Algorithm::reply(Array<double> rewards){
    /*
     適応度に基づいて個体の選別、交叉を行います
     選別方法はエリートをいくつか選んで、それらで交叉させます
     rewards:各個体の適応度(スコア)
     */
    // Rank
    std::priority_queue<std::pair<double, int>>que;
    for(auto i:step(NumAgents)){
        que.push(std::make_pair(rewards[i], i));
    }

    // Select some elites
    Grid<double>Elites(Actions,Samples);
    for(auto i:step(Samples)){
        for(auto j:step(Actions)){
            Elites[i][j]=Agents[int32(que.top().second)][j];
        }
        que.pop();
    }
    // make a next gene
    for(auto i:step(NumAgents-RandomSample)){
        Array<double>first,second;
        int32 i_f=Random(Samples-1),i_s=Random(Samples-1);
        for(auto j:step(Actions)){
            first<<Elites[i_f][j];
            second<<Elites[i_s][j];
        }
        
        int32 index=Random(Actions-1);
        for(auto j:step(index)){
            if(Random()<MutationRate)Agents[i][j]=Random();
            else Agents[i][j]=first[j];
        }
        for(auto j:step(Actions-index)){
            if(Random()<MutationRate)Agents[i][j+index]=Random();
            else Agents[i][j+index]=second[j+index];
        }
    }
    for(auto i:step(RandomSample)){
        for(auto j:step(Actions)) Agents[NumAgents-i-1][j]=Random();
    }
    
    Array<double>value; //return
    for(auto i:step(Actions)){
        value<<Elites[0][i];
    }
    
    return value;
}
