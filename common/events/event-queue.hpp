#pragma once

#include <queue>
#include <memory>
#include <atomic>

namespace rpg {
	namespace events {
		template <typename T>
		class EventDispatcher;

		template <class T>
		class EventQueue {
		public:
			EventQueue() : read_event_queue(new std::queue<std::shared_ptr<T>>()),
				write_event_queue(new std::queue<std::shared_ptr<T>>()) {
				EventDispatcher<T>::Get()->Subscribe(this);
			}
			virtual ~EventQueue() {}

			void ProcessEventQueue() {
				this->read_event_queue = write_event_queue.exchange(this->read_event_queue);

				while (!this->read_event_queue->empty()) {
					auto data = this->read_event_queue->front();
					this->read_event_queue->pop();

					static_cast<EventQueue<T>*>(this)->On(data);
				}
			}

			void QueueEvent(std::shared_ptr<T> event) {
				(*write_event_queue).emplace(event);
			}

			virtual void On(std::shared_ptr<T> event) {}
		protected:
			std::queue<std::shared_ptr<T>>* read_event_queue;
			std::atomic<std::queue<std::shared_ptr<T>>*> write_event_queue;
		};
	}
}