#ifndef DELEGATE_INCLUDE
#define DELEGATE_INCLUDE

#include <functional>
#include <unordered_map>
#include <mutex>

/*
//Weston McNamara 2020
//Licensed Under MIT https://mit-license.org/
//https://github.com/wmcnamara/delegate

This class is a modification of delegate intended for use in the Crynn game engine.

It performs automatic locking of the underlying event structures, and is thread safe.
*/

namespace crynn
{
	/// <summary>
	/// Simple event class
	/// </summary>
	/// <typeparam name="...T">Parameter types</typeparam>
	template<typename ... T>
	class Event
	{
	private:
		typedef std::function<void(T...)> Func_T;
	public:
		//Invokes each function added to this delegate. 
		inline void Invoke(T... param)
		{
			if (m_handlers.empty())
				return;

			for (const auto& key : m_handlers)
			{
				key.second(param...); //Invoke the function
			}
		}

		//Adds a single function to the delegate.
		inline uint64_t AddHandler(Func_T func)
		{
			static std::atomic_uint64_t nextID = 1; //0 is reserved

			std::lock_guard<std::mutex> guard(eventMutex);

			m_handlers.insert(std::pair<uint64_t, Func_T>(nextID, func));

			//Return the ID, and increment it.
			return nextID++;
		}

		//Removes a single function from the delegate
		inline void RemoveHandler(uint64_t ID)
		{
			if (ID == 0)
				return;

			std::lock_guard<std::mutex> guard(eventMutex);

			m_handlers.erase(ID);
		}

		inline void RemoveAllHandlers()
		{
			std::lock_guard<std::mutex> guard(eventMutex);

			m_handlers.clear();
		}

		Event() = default;
		~Event() = default;

		Event(const Event & other) = delete;
		Event operator=(const Event & other) = delete;
		Event(Event && other) = delete;
		Event operator=(Event && other) = delete;
	private:
		
		std::mutex eventMutex;
		std::unordered_map<uint64_t, Func_T> m_handlers;
	};

	/// <summary>
	/// Creates an event that takes no parameters
	/// </summary>
	template<>
	class Event<void>
	{
	private:
		typedef std::function<void()> Func_T;
	public:
		//Invokes each function added to this delegate. 
		inline void Invoke()
		{
			if (m_handlers.empty())
				return;

			for (const auto& key : m_handlers)
			{
				key.second(); //Invoke the function
			}
		}

		//Adds a single function to the delegate.
		inline uint64_t AddHandler(Func_T func)
		{
			static std::atomic_uint64_t nextID = 0;

			std::lock_guard<std::mutex> guard(eventMutex);

			m_handlers.insert(std::pair<uint64_t, Func_T>(nextID, func));

			//Return the ID, and increment it.
			return nextID++;
		}

		//Removes a single function from the delegate using its ID
		inline void RemoveHandler(uint64_t ID)
		{
			if (ID == 0)
				return;

			std::lock_guard<std::mutex> guard(eventMutex);

			m_handlers.erase(ID);
		}

		inline void RemoveAllHandlers()
		{
			std::lock_guard<std::mutex> guard(eventMutex);

			m_handlers.clear();
		}

		Event() = default;
		~Event() = default;

		Event(const Event& other) = delete;
		Event operator=(const Event& other) = delete;
		Event (Event&& other) = delete;
		Event operator=(Event&& other) = delete;
	private:
		std::mutex eventMutex;
		std::unordered_map<uint64_t, Func_T> m_handlers;
	};
}
#endif //DELEGATE_INCLUDE