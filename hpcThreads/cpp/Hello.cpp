#include <iostream>
#include <thread>

namespace Hello {

  // fonction qui affiche l'id du thread qui l'execute
  void noyauCalcul() {
    std::thread::id idThread = std::this_thread::get_id();
    std::cout << "Bonjour, je suis le thread " << idThread << std::endl;
    
  }

  void truc() {
    std::cout<<"oui"<<std::endl;
    noyauCalcul();
  }

  void hello() {
    // affiche l'id du thread principal
    noyauCalcul();
    
    // exécute le noyau de calcul en parallèle sur 2 threads
    // TODO

    std::thread thread1(noyauCalcul);
    std::thread thread2(noyauCalcul);
    
    thread1.join();  // appel bloquant
    thread2.join();

    //idThread.join();
    //idThread2.join();

  }

}  // namespace Hello

