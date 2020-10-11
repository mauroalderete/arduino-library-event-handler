#ifndef _EVENTHANDLER_HPP_
#define _EVENTHANDLER_HPP_

#include <Arduino.h>
#include <vector>

template <class... Args>
class EventHandler {
  private:
    void (*fn)(Args...);
    std::vector< void (*)(Args...) > events;
    
  public:
    EventHandler(){};
    
    void Add( void (*delegate)(Args...) ) {
      fn = delegate;
      events.push_back( delegate );
    };

    void Remove( void (*delegate)(Args...) ){
      fn = NULL;
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
      fn(arguments...);

      for (int i = 0; i< events.size(); i++){
        events[i](arguments...);
      }
    }
};

#endif