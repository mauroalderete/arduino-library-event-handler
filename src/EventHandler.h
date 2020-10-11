#ifndef _EVENTHANDLER_HPP_
#define _EVENTHANDLER_HPP_

#include <Arduino.h>
#include <vector>

template <class... Args>
class EventHandler {
  private:
    std::vector< void (*)(Args...) > events;
    
  public:
    EventHandler(){};
    
    void Add( void (*delegate)(Args...) ) {
      events.push_back( delegate );
    };

    void Remove( void (*delegate)(Args...) ){
      for (int i = 0; i< events.size(); i++){
        if ( events[0] == delegate ){
          events.remove(i);
          break;
        }
      }
    }

    void Clear(){
      events.clear();
    }

    void Invoke( Args... arguments) {
      for (int i = 0; i< events.size(); i++){
        events[i](arguments...);
      }
    }
};

#endif