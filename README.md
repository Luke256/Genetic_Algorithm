# Genetic_Algorithm
Genetic Algorithm on OpenSiv3D

```C++
Genetic_Algorithm(int32 NumAgents_,int32 Actions_,int32 Samples_=2,double MutationRate_=0.01,int32 RandomSample_=1);
```
NumAgents_:個体数<br>
Actions_:行動の種類数(特徴数)<br>
Samples_:選別のときに選ぶ個体数 <br>
MutationRate_:突然変異を起こす確率<br>
RandomSample_:各世代で、ランダムに生成する個体の個数<br>

## Genetic_Algorithm について
遺伝的アルゴリズムのためのクラスです。各個体は0~1までの乱数(浮動小数点数)からなる遺伝子を持ちます。<br>
学習は、<br>
最も適応できた個体をいくつか選別<br>
↓<br>
それらを2つずつ交配させて新しい世代を作成<br>
という流れです。

## メンバ関数
```C++
Array<double> reply(Array<double>rewards);
```
rewards:各個体の適応度の格納したArray配列<br>

戻り値:その世代の中で最も優秀だった個体の遺伝子を返します。

わからないこと・問題点等あれば、Issuesに投げていただけば回答します
