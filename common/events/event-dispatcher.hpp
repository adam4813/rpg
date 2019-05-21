#pragma once

#include <list>
#include <memory>
#include <mutex>

#include "event-queue.hpp"

namespace rpg {
	namespace events {
		template <typename T>
		class EventDispatcher final {
		private:
			EventDispatcher() {}
			EventDispatcher(const EventDispatcher& right) {
				instance = right.instance;
			}
			EventDispatcher& operator=(const EventDispatcher& right) {
				if (this != &right) {
					instance = right.instance;
				}

				return *this;
			}
			static std::once_flag only_one;
			static std::shared_ptr<EventDispatcher<T>> instance;
		public:
			static std::shared_ptr<EventDispatcher<T>> Get() {
				std::call_once(EventDispatcher::only_one,
							   [] () {
								   EventDispatcher<T>::instance.reset(new EventDispatcher<T>());
							   }
				);

				return EventDispatcher<T>::instance;
			}
			~EventDispatcher() {}

			void Subscribe(EventQueue<T>* subscriber) {
				this->subscribers.push_back(subscriber);
			}

			void Unsubscribe(EventQueue<T>* subscriber) {
				if (this->subscribers.find(subscriber) != this->subscribers.end()) {
					this->subscribers.remove(subscriber);
				}
			}

			void Emit(std::shared_ptr<T> event) {
				for (EventQueue<T>* subscriber : subscribers) {
					subscriber->QueueEvent(event);
				}
			}

		private:
			std::list<EventQueue<T>*> subscribers;
		};

		template<typename T>
		std::once_flag EventDispatcher<T>::only_one;

		template<typename T>
		std::shared_ptr<EventDispatcher<T>> EventDispatcher<T>::instance = nullptr;
	}
}
