#include <fstream>
#include <iostream>
#include <thread>
#include <vector>

namespace Fibo {

  // calcule le Nieme terme de la suite de "Fibonacci modulo 42"
  // precondition : N >= 0
  int FibonacciMod42(int N) {
    int f_curr = 0;
    int f_prec = 1;
    for (int i=1; i<=N; i++) {
      int tmp = f_curr;
      f_curr = (f_curr + f_prec) % 42;
      f_prec = tmp;
    }
    return f_curr;
  }

  //////////////////////////////////////////////////////////////////////

  // fonction pour repartir les calculs
  void calculerTout(std::vector<int> &data) {
    // effectue tous les calculs
    for (unsigned i=0; i<data.size(); i++) {
      data[i] = FibonacciMod42(i);
    }
  };

  std::vector<int> fiboSequentiel(int nbData) {
    // cree le tableau de donnees a calculer
    std::vector<int> data(nbData); 
    // calcule les donnees sequentiellement

    calculerTout(data);
    return data;
  }

  //////////////////////////////////////////////////////////////////////


 void calculerMoit(std::vector<int> &data,int debut,int fin) {
    // effectue tous les calculs
    for ( int i=debut; i<=fin; i++) {
      data[i] = FibonacciMod42(i);
    }
  };
  
  std::vector<int> fiboBlocs(int nbData) {
    // cree le tableau de donnees a calculer
    std::vector<int> data(nbData); 
    // calculer sur deux threads, par bloc
    // TODO
    std::thread thread1(calculerMoit,std::ref(data),0,data.size()/2);
    std::thread thread2(calculerMoit,std::ref(data),data.size()/2 +1,data.size());

    thread1.join();  
    thread2.join();

    return data;
  }


  //////////////////////////////////////////////////////////////////////

  void calculerCycl(std::vector<int> &data,int indiceDebut,int decallage) {
    // effectue tous les calculs
    for (int i=indiceDebut; i<=data.size(); i=i+decallage) {
      data[i] = FibonacciMod42(i);
    }
  };
  

  std::vector<int> fiboCyclique2(int nbData) {
    // cree le tableau de donnees a calculer
    std::vector<int> data(nbData); 
    // calculer sur deux threads, cycliquement
    // TODO
    
    std::thread thread1(calculerCycl,std::ref(data),0,2);
    std::thread thread2(calculerCycl,std::ref(data),1,2);

    thread1.join();  
    thread2.join();

    return data;
  }

  //////////////////////////////////////////////////////////////////////

  std::vector<int> fiboCycliqueN(int nbData, int nbProc) {
    // cree le tableau de donnees a calculer
    std::vector<int> data(nbData); 
    // calculer sur N threads, cycliquement
    // TODO

    std::vector<std::thread> tabThread(nbProc); 
    for(int i =0;i<nbProc;i++)
    {
      tabThread[i](calculerCycl,std::ref(data),i,nbProc);
    }

     for(int i =0;i<nbProc;i++)
    {
      tabThread[i].join();
    }

    return data;
  }

  //////////////////////////////////////////////////////////////////////

  void fiboCycliqueNFake(int nbData, int nbProc) {
    // calculer sur N threads, cycliquement, en ignorant le résultat
    // TODO
  }

}  // namespace Fibo

